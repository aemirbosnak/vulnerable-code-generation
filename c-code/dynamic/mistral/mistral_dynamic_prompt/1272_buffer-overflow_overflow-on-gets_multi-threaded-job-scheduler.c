#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 16

pthread_t workers[MAX_THREADS];
char job_queue[MAX_THREADS][BUFFER_SIZE];

void *worker(void *arg) {
    int index = (int)arg;
    printf("Worker %d started\n", index);
    gets(job_queue[index]); // Vulnerable to buffer overflow on gets
    printf("Worker %d ended\n", index);
    pthread_exit(NULL);
}

int main() {
    int i, num_jobs;
    printf("Enter the number of jobs: ");
    scanf("%d", &num_jobs);

    for (i = 0; i < num_jobs; i++) {
        pthread_create(&workers[i], NULL, &worker, (void *)i);
    }

    for (i = 0; i < num_jobs; i++) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}
