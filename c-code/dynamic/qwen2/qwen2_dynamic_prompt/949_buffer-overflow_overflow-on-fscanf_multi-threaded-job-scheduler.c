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
    char data[256];
} Job;

Job jobs[MAX_JOBS];

void* worker(void* arg) {
    int index = *(int*)arg;
    FILE* file = fopen("input.txt", "r");
    if (!file) return NULL;

    fscanf(file, "%s", jobs[index].data);
    fclose(file);

    printf("Job %d processed: %s\n", jobs[index].id, jobs[index].data);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int indices[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i;
        indices[i] = i;
        pthread_create(&threads[i], NULL, worker, &indices[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
