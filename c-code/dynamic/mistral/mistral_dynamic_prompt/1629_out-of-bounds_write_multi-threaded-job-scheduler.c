#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 100
#define JOB_SIZE 256
#define BUFFER_SIZE (MAX_JOBS * JOB_SIZE)

char buffer[BUFFER_SIZE];
int job_count = 0;
pthread_mutex_t jobs_mutex = PTHREAD_MUTEX_INITIALIZER;

void* job_function(void* arg) {
    char* job = (char*)arg;
    snprintf(buffer + job_count * JOB_SIZE, JOB_SIZE, "%s\n", job);
    job_count++;
    return NULL;
}

int main() {
    pthread_t threads[10];
    int i;

    char jobs[10][JOB_SIZE] = {
        "Job 1: Unsafe code execution",
        "Job 2: Memory leak with malloc",
        "Job 3: Format string vulnerability",
        "Job 4: Race condition exploitation",
        "Job 5: Buffer overflow - write",
        "Job 6: SQL injection attack",
        "Job 7: Cross-site scripting attack",
        "Job 8: Command injection vulnerability",
        "Job 9: Integer overflow",
        "Job 10: Insufficient input validation"
    };

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, job_function, jobs[i]);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    char vulnerable_output[BUFFER_SIZE];
    memcpy(vulnerable_output, buffer, BUFFER_SIZE);

    // Print vulnerable output with potential out of bounds write issue
    printf("%s", vulnerable_output);

    return 0;
}
