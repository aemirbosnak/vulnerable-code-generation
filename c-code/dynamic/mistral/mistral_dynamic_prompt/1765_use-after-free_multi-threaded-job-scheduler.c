#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

typedef struct Job {
    void (*func)(void* arg);
    void* arg;
    struct Job* next;
} Job;

Job* head = NULL;
pthread_mutex_t jobs_mutex = PTHREAD_MUTEX_INITIALIZER;

void free_job(Job* job) {
    free(job->arg);
    free(job);
}

void job_thread(void* arg) {
    Job* current = head;
    while (current) {
        head = current->next;
        current->next = NULL;
        current->func(current->arg);
        free_job(current);
        current = head;
    }
    pthread_detach(pthread_self());
}

void create_job(void (*func)(void*), void* arg) {
    Job* new_job = (Job*)malloc(sizeof(Job));
    new_job->func = func;
    new_job->arg = arg;
    new_job->next = head;
    head = new_job;
}

void example_func(void* arg) {
    char* str = (char*)arg;
    free(str);
}

int main() {
    pthread_t thread;
    char* str = (char*)malloc(100);
    strcpy(str, "Example String");
    create_job(example_func, str);
    pthread_create(&thread, NULL, &job_thread, NULL);

    while (1);
    return 0;
}
