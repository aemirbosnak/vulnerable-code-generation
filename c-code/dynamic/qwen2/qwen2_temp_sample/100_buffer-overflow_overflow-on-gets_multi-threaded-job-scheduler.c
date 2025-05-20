#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_JOBS 10
#define JOB_NAME_LEN 256

typedef struct {
    char name[JOB_NAME_LEN];
    int priority;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;
pthread_mutex_t job_lock;

void* handle_job(void* arg) {
    int index = *(int*)arg;
    pthread_mutex_lock(&job_lock);
    if (index >= job_count) {
        pthread_mutex_unlock(&job_lock);
        return NULL;
    }
    printf("Handling job: %s\n", jobs[index].name);
    pthread_mutex_unlock(&job_lock);
    return NULL;
}

void add_job(const char* name, int priority) {
    pthread_mutex_lock(&job_lock);
    if (job_count < MAX_JOBS) {
        strncpy(jobs[job_count].name, name, JOB_NAME_LEN - 1);
        jobs[job_count].name[JOB_NAME_LEN - 1] = '\0';
        jobs[job_count].priority = priority;
        job_count++;
    } else {
        printf("Job queue is full!\n");
    }
    pthread_mutex_unlock(&job_lock);
}

int main() {
    pthread_t threads[MAX_JOBS];
    int thread_ids[MAX_JOBS];

    // Simulate adding jobs with user input
    while (1) {
        char name[JOB_NAME_LEN];
        int priority;
        printf("Enter job name (or 'exit' to stop): ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        if (strcmp(name, "exit") == 0) break;
        printf("Enter job priority: ");
        scanf("%d", &priority);
        getchar(); // Consume newline character left by scanf
        add_job(name, priority);
    }

    // Create threads to handle jobs
    for (int i = 0; i < job_count; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, handle_job, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < job_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
