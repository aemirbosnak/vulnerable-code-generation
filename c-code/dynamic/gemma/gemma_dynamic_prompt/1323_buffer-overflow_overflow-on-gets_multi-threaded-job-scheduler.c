#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <string.h>

void *thread_func(void *arg) {
    char *job_name = (char *)arg;
    gets(job_name);
    printf("Thread: %s, Job: %s\n", (char *)pthread_self(), job_name);
    return NULL;
}

int main() {
    pthread_t threads[10];
    char job_names[10][100];

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, thread_func, job_names[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
