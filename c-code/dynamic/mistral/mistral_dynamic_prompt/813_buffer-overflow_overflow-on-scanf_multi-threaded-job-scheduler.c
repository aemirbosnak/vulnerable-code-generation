#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_TITLE 50
#define MAX_DESC 100
#define MAX_WORKERS 10

typedef struct {
    char title[MAX_TITLE];
    char description[MAX_DESC];
} Job;

Job jobs[MAX_WORKERS];
pthread_t workers[MAX_WORKERS];

void* worker(void* arg) {
    Job* job = (Job*) arg;
    printf("Starting job: %s\n", job->title);
    sleep(1); // Simulate work
    printf("Finished job: %s\n", job->title);
    return NULL;
}

int main() {
    int i;
    for (i = 0; i < MAX_WORKERS; i++) {
        printf("Enter job title and description (or 'quit' to exit):\n");
        scanf("%s%*[^\n]%*c%[^\n]%*c", jobs[i].title, jobs[i].description);

        if (strcmp(jobs[i].title, "quit") == 0)
            break;

        pthread_create(&workers[i], NULL, &worker, &jobs[i]);
    }

    for (i = 0; i < MAX_WORKERS; i++) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}
