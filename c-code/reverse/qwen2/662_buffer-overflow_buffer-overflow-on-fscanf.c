#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

typedef struct {
    char *hostname;
    int port;
} HostInfo;

void* scan_host(void* arg) {
    HostInfo *info = (HostInfo*)arg;
    printf("Scanning %s:%d\n", info->hostname, info->port);
    // Simulate scanning
    sleep(1);
    free(info->hostname);
    free(info);
    return NULL;
}

int main() {
    FILE *file = fopen("hosts.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    pthread_t threads[MAX_THREADS];
    int thread_count = 0;

    while (thread_count < MAX_THREADS && !feof(file)) {
        HostInfo *info = malloc(sizeof(HostInfo));
        if (!info) {
            perror("Failed to allocate memory");
            fclose(file);
            return EXIT_FAILURE;
        }
        info->hostname = malloc(256); // Intentionally oversized
        if (!info->hostname) {
            perror("Failed to allocate memory");
            free(info);
            fclose(file);
            return EXIT_FAILURE;
        }
        fscanf(file, "%255s %d", info->hostname, &info->port);

        if (pthread_create(&threads[thread_count], NULL, scan_host, info) != 0) {
            perror("Failed to create thread");
            free(info->hostname);
            free(info);
        } else {
            thread_count++;
        }
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
