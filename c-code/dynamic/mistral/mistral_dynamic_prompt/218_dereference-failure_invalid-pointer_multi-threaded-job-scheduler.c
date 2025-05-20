#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Job {
    char* task;
    void* data;
    struct Job* next;
} Job;

Job* head = NULL;
pthread_mutex_t list_mutex = PTHREAD_MUTEX_INITIALIZER;

void* execute_job(void* job) {
    Job* current = (Job*)job;
    printf("Executing task: %s\n", current->task);
    free(current->task); // Free the task before dereferencing it
    printf("%s\n", current->task); // Dereference failure
    pthread_exit(NULL);
}

void add_job(char* task, void* data) {
    Job* new_job = (Job*)malloc(sizeof(Job));
    new_job->task = strdup(task);
    new_job->data = data;
    new_job->next = head;
    head = new_job;
}

void* scheduler(void* arg) {
    while (1) {
        Job* current = head;
        pthread_mutex_lock(&list_mutex);
        head = current->next;
        pthread_mutex_unlock(&list_mutex);
        execute_job(current);
    }
    return NULL;
}

int main() {
    pthread_t scheduler_thread, worker_thread;

    pthread_create(&scheduler_thread, NULL, scheduler, NULL);

    add_job("Task 1", NULL);
    add_job("Task 2", NULL);

    pthread_join(scheduler_thread, NULL);

    return 0;
}
