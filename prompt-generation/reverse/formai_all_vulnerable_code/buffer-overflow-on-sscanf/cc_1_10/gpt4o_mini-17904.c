//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256
#define UPDATE_INTERVAL 1  // seconds

typedef struct {
    int total_mem;
    int free_mem;
    int available_mem;
    pthread_mutex_t lock;
} memory_info_t;

memory_info_t mem_info;

void* update_memory_info(void* arg) {
    while (1) {
        FILE* mem_file = fopen("/proc/meminfo", "r");
        if (!mem_file) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        pthread_mutex_lock(&mem_info.lock);

        char line[BUFFER_SIZE];
        while (fgets(line, sizeof(line), mem_file)) {
            if (sscanf(line, "MemTotal: %d kB", &mem_info.total_mem) == 1) {
                continue;
            }
            if (sscanf(line, "MemFree: %d kB", &mem_info.free_mem) == 1) {
                continue;
            }
            if (sscanf(line, "MemAvailable: %d kB", &mem_info.available_mem) == 1) {
                continue;
            }
        }
        fclose(mem_file);

        pthread_mutex_unlock(&mem_info.lock);
        sleep(UPDATE_INTERVAL);
    }
    return NULL;
}

void display_memory_info() {
    while (1) {
        pthread_mutex_lock(&mem_info.lock);
        int used_mem = mem_info.total_mem - mem_info.free_mem;
        printf("\rTotal Memory: %d kB | Free Memory: %d kB | Used Memory: %d kB | Available Memory: %d kB",
               mem_info.total_mem, mem_info.free_mem, used_mem, mem_info.available_mem);
        fflush(stdout);
        pthread_mutex_unlock(&mem_info.lock);
        sleep(UPDATE_INTERVAL);
    }
}

int main() {
    pthread_t update_thread;
    mem_info.total_mem = 0;
    mem_info.free_mem = 0;
    mem_info.available_mem = 0;
    pthread_mutex_init(&mem_info.lock, NULL);

    // Create a thread to update memory info
    if (pthread_create(&update_thread, NULL, update_memory_info, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Display memory info
    display_memory_info();

    // Cleanup
    pthread_join(update_thread, NULL);
    pthread_mutex_destroy(&mem_info.lock);

    return 0;
}