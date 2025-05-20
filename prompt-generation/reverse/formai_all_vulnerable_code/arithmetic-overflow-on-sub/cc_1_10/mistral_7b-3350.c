//MISTRAL-7B DATASET v1.0 Category: RAM usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

long total_memory;
long free_memory;

void get_memory_info() {
    struct stat mem_stats;
    if (stat("/proc/meminfo", &mem_stats) == -1) {
        perror("Error getting memory info");
        exit(EXIT_FAILURE);
    }

    char mem_info[BUF_SIZE];
    if (readlink("/proc/meminfo", mem_info, BUF_SIZE) < 0) {
        perror("Error reading meminfo");
        exit(EXIT_FAILURE);
    }

    char *mem_line = strtok(mem_info, "\n");
    while (mem_line != NULL) {
        if (strstr(mem_line, "MemTotal:") != NULL) {
            sscanf(mem_line, "MemTotal: %ld kB", &total_memory);
            total_memory *= 1024;
        } else if (strstr(mem_line, "MemFree:") != NULL) {
            sscanf(mem_line, "MemFree: %ld kB", &free_memory);
            free_memory *= 1024;
        }

        mem_line = strtok(NULL, "\n");
    }
}

int main() {
    get_memory_info();

    long initial_heap_size = malloc(1);
    long current_heap_size = (long) mmap(NULL, 0, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);

    printf("Initial heap size: %.2f KB\n", (float) initial_heap_size / 1024.0);
    printf("Total memory: %.2f MB\n", (float) total_memory / 1024.0 / 1024.0);
    printf("Free memory: %.2f MB\n", (float) free_memory / 1024.0 / 1024.0);

    long used_memory = total_memory - free_memory - initial_heap_size;
    printf("Used memory: %.2f MB\n", (float) used_memory / 1024.0 / 1024.0);

    munmap(NULL, current_heap_size);
    free(initial_heap_size);

    while (1) {
        get_memory_info();
        used_memory = total_memory - free_memory - initial_heap_size;
        printf("Used memory: %.2f MB\n", (float) used_memory / 1024.0 / 1024.0);
        sleep(1);
    }

    return 0;
}