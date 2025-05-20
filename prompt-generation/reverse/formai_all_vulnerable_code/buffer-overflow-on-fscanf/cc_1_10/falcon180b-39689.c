//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX_THREADS 10

struct thread_data {
    int thread_id;
    int cpu_percent;
};

void *monitor_cpu(void *arg) {
    int thread_id = *(int *) arg;
    struct thread_data *data = (struct thread_data *) malloc(sizeof(struct thread_data));
    data->thread_id = thread_id;

    while(1) {
        FILE *fp;
        char filename[20];
        sprintf(filename, "/proc/%d/stat", getpid());
        fp = fopen(filename, "r");

        if(fp == NULL) {
            printf("Error: Cannot open file\n");
            exit(1);
        }

        fscanf(fp, "cpu %d ", &data->cpu_percent);
        fclose(fp);

        printf("Thread %d: CPU usage: %d%%\n", thread_id, data->cpu_percent);
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, ret;

    for(i = 0; i < MAX_THREADS; i++) {
        ret = pthread_create(&threads[i], NULL, monitor_cpu, (void *) &i);
        if(ret!= 0) {
            printf("Error: Unable to create thread, %d\n", ret);
            exit(1);
        }
    }

    for(i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}