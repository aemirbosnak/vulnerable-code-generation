#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 100

char jobs[MAX_JOBS][256];
int job_count = 0;

void* schedule_job(void* arg) {
    int id = *(int*)arg;
    while (1) {
        if (job_count > 0) {
            strcpy(jobs[id], "Executing job: ");
            strcat(jobs[id], jobs[0]);
            printf("%s\n", jobs[id]);
            job_count--;
            memmove(jobs, &jobs[1], job_count * sizeof(char[256]));
        } else {
            sleep(1);
        }
    }
}

int main() {
    pthread_t threads[4];
    int thread_ids[4] = {0, 1, 2, 3};

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, schedule_job, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        sprintf(jobs[i], "%d", i);
        job_count++;
        sleep(1);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
