//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct v {
    int *a;
    int n;
};

void *runner(void *param) {
    struct v *data = param;
    int i, sum = 0;

    for (i = 0; i < data->n; i++) {
        sum += data->a[i];
    }

    printf("Thread %d finished. Sum: %d\n", *(int*)param, sum);
    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc, sum = 0;
    struct v data;

    data.a = malloc(10 * sizeof(int));
    data.n = 10;

    for (i = 0; i < 10; i++) {
        data.a[i] = i;
        sum += i;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, runner, (void*)&i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total sum: %d\n", sum);

    free(data.a);
    return 0;
}