#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 256

void* scan_port(void* arg) {
    char hostname[BUFFER_SIZE];
    int port = *(int*)arg;
    FILE* fp = fopen(hostname, "r");
    if (fp == NULL) {
        perror("Failed to open file");
        return NULL;
    }
    while (fscanf(fp, "%s", hostname) != EOF) {
        // Simulate scanning by sleeping
        sleep(1);
        printf("Scanning %s:%d\n", hostname, port);
    }
    fclose(fp);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int ports[MAX_THREADS] = {80, 443, 22, 25, 8080, 4443, 21, 143, 993, 995};

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, scan_port, &ports[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
