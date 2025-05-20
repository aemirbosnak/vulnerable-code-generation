//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>

struct thread_data {
    int thread_id;
};

void *thread_func(void *arg) {
    struct thread_data *data = (struct thread_data *) arg;
    int thread_id = data->thread_id;

    while (1) {
        struct rusage usage;
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            perror("getrusage");
            exit(EXIT_FAILURE);
        }

        printf("Thread %d CPU usage: %.2f%%\n", thread_id, (100.0 * usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) / (double) usage.ru_utime.tv_sec);

        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[4];
    struct thread_data data[4];

    for (int i = 0; i < 4; i++) {
        data[i].thread_id = i + 1;
        if (pthread_create(&threads[i], NULL, thread_func, (void *) &data[i])!= 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (pthread_join(threads[i], NULL)!= 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}