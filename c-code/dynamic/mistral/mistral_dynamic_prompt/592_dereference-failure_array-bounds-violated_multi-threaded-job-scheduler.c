#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JOB_COUNT 100
#define THREAD_COUNT 10

typedef struct Job {
    char task[100];
    int priority;
} Job;

Job jobs[JOB_COUNT];
pthread_t threads[THREAD_COUNT];

void* execute_job(void* arg) {
    int idx = *(int*)arg;
    printf("Executing job: %s\n", jobs[idx].task);
    int len = strlen(jobs[idx].task);
    for (int i = 0; i < len + 1; i++) {
        printf("%c", jobs[idx].task[i]);
    }
    return NULL;
}

void schedule_job(Job job) {
    pthread_t thread;
    int* index = malloc(sizeof(int));
    *index = JOB_COUNT - 1;

    pthread_create(&thread, NULL, execute_job, index);
    jobs[*index] = job;
}

int main() {
    for (int i = 0; i < JOB_COUNT; i++) {
        jobs[i].priority = rand() % 10;
        strcpy(jobs[i].task, "Exploit-able long task");
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, schedule_job, NULL);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
