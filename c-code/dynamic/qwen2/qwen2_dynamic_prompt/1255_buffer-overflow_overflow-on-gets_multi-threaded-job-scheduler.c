#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 100

typedef struct {
    char *job_name;
    int priority;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* worker_thread(void* arg) {
    while (1) {
        if (job_count > 0) {
            Job current_job = jobs[0];
            for (int i = 0; i < job_count - 1; i++) {
                jobs[i] = jobs[i + 1];
            }
            job_count--;
            printf("Executing job: %s with priority: %d\n", current_job.job_name, current_job.priority);
            free(current_job.job_name);
        } else {
            pthread_exit(NULL);
        }
    }
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, worker_thread, NULL);

    while (1) {
        char job_name[256];
        int priority;
        printf("Enter job name (or 'exit' to quit): ");
        fgets(job_name, sizeof(job_name), stdin);
        job_name[strcspn(job_name, "\n")] = '\0';
        if (strcmp(job_name, "exit") == 0) {
            break;
        }

        printf("Enter job priority: ");
        scanf("%d", &priority);
        getchar(); // Consume newline character left by scanf

        if (job_count >= MAX_JOBS) {
            printf("Job queue is full!\n");
            continue;
        }

        jobs[job_count].job_name = strdup(job_name);
        jobs[job_count].priority = priority;
        job_count++;
    }

    pthread_join(thread_id, NULL);
    return 0;
}
