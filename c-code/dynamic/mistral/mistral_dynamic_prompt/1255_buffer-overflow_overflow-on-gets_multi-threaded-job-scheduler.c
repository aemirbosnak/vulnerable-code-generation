#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_TITLE_LENGTH 100
#define MAX_JOB_LENGTH 1024

typedef struct Job {
    char title[MAX_TITLE_LENGTH];
    char job[MAX_JOB_LENGTH];
} Job;

Job jobs[256];
pthread_mutex_t jobs_mutex = PTHREAD_MUTEX_INITIALIZER;
int current_job = 0;

void* execute_job(void* arg) {
    printf("Executing job: %s\n", ((Job*)arg)->job);
    sleep(5);
    return NULL;
}

void add_job(const char* title, const char* job) {
    pthread_mutex_lock(&jobs_mutex);
    strcpy(jobs[current_job].title, title);
    strcpy(jobs[current_job].job, job);
    current_job = (current_job + 1) % 256;
    pthread_mutex_unlock(&jobs_mutex);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, execute_job, &jobs[current_job - 1]);
}

int main() {
    char input[MAX_JOB_LENGTH];
    while (1) {
        printf("Enter job title (or type 'exit' to quit): ");
        gets(input);

        if (strstr(input, "exit")) {
            break;
        }

        add_job(input, input);
    }

    return 0;
}
