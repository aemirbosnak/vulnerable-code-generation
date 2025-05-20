//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

#define INTERVAL 1 // Refresh interval in seconds

struct timeval last_update;
unsigned long long int last_ram_usage = 0;

void *monitor_ram_usage(void *arg) {
    while (1) {
        struct timeval current_time;
        gettimeofday(&current_time, NULL);

        if (current_time.tv_sec - last_update.tv_sec >= INTERVAL) {
            last_update = current_time;

            unsigned long long int current_ram_usage = 0;
            FILE *fp = fopen("/proc/self/statm", "r");
            if (fp!= NULL) {
                fscanf(fp, "%*s %*s %*s %*s %*s %*s %llu", &current_ram_usage);
                fclose(fp);
            }

            if (current_ram_usage > last_ram_usage) {
                printf("RAM usage increased by %llu bytes\n", current_ram_usage - last_ram_usage);
            } else if (current_ram_usage < last_ram_usage) {
                printf("RAM usage decreased by %llu bytes\n", last_ram_usage - current_ram_usage);
            }

            last_ram_usage = current_ram_usage;
        }

        usleep(100000); // Sleep for 100ms
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, monitor_ram_usage, NULL);

    while (1) {
        printf("Press any key to exit...\n");
        getchar();
        break;
    }

    pthread_join(thread_id, NULL);

    return 0;
}