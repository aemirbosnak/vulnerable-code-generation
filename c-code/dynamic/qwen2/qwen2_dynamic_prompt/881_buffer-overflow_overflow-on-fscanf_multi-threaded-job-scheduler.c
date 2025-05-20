#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 10

typedef struct {
    int id;
    char description[256];
} Job;

Job jobs[MAX_JOBS];

void* worker(void* arg) {
    int index = *(int*)arg;
    FILE* file = fopen("jobs.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    while (index < MAX_JOBS) {
        fscanf(file, "%d %[^\n]", &jobs[index].id, jobs[index].description);
        printf("Thread %d: Job ID %d - Description %s\n", pthread_self(), jobs[index].id, jobs[index].description);
        index += MAX_JOBS; // Simulate multiple threads accessing the same resource
    }
    fclose(file);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int indices[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        indices[i] = i;
        pthread_create(&threads[i], NULL, worker, &indices[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
