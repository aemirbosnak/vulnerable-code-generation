//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_func(void *arg) {
    int id = *((int *) arg);
    char thread_name[10];
    sprintf(thread_name, "Thread %d", id);
    pthread_setname_np(pthread_self(), thread_name);

    while (1) {
        struct timeval start, end;
        gettimeofday(&start, NULL);
        sleep(1);
        gettimeofday(&end, NULL);

        double diff = ((end.tv_sec - start.tv_sec) * 1000000 +
                      (end.tv_usec - start.tv_usec)) / 1000000;
        printf("Thread %d CPU usage: %.2f%%\n", id, (100 - (diff * 100)) / (double) NUM_THREADS);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    while (1) {
        sleep(5);
        system("clear");
        printf("CPU usage:\n");
        for (i = 0; i < NUM_THREADS; i++) {
            printf("Thread %d: ", i + 1);
            for (int j = 0; j < 50; j++) {
                if (j * 2 <= (100 - ((double) i / (double) NUM_THREADS) * 50)) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}