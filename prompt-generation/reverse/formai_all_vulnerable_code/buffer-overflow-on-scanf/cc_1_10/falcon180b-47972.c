//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_SAMPLES 100

typedef struct {
    char name[20];
    unsigned long long int usage;
} process_info;

process_info samples[MAX_SAMPLES];
int num_samples = 0;

void* monitor_thread(void* args) {
    while (1) {
        sleep(5);
        system("free -m >> ram.log");
        FILE* file = fopen("ram.log", "r");
        char line[100];
        while (fgets(line, 100, file)) {
            if (strstr(line, "MemTotal")) {
                char* token = strtok(line, " ");
                int mem_total = atoi(token);
                mem_total *= 1024; // convert to bytes
                for (int i = 0; i < num_samples; i++) {
                    samples[i].usage = mem_total - samples[i].usage;
                }
                break;
            }
        }
        fclose(file);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_thread, NULL);

    while (1) {
        printf("Enter process name to monitor (or 'q' to quit): ");
        scanf("%s", samples[num_samples].name);
        if (strcmp(samples[num_samples].name, "q") == 0) {
            break;
        }
        num_samples++;
        if (num_samples == MAX_SAMPLES) {
            printf("Maximum number of samples reached.\n");
            break;
        }
    }

    pthread_join(thread_id, NULL);
    return 0;
}