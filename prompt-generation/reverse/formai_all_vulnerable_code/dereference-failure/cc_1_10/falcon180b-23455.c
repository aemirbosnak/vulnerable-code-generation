//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

struct v {
    int *a;
    int *b;
    int *c;
};

void *runner(void *param) {
    struct v *data = param;
    int sum = data->a[0] + data->b[0] + data->c[0];
    printf("Thread %d calculated sum: %d\n", *(int*)param, sum);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, ret;
    struct v data;

    data.a = malloc(NUM_THREADS * sizeof(int));
    data.b = malloc(NUM_THREADS * sizeof(int));
    data.c = malloc(NUM_THREADS * sizeof(int));

    for (i = 0; i < NUM_THREADS; i++) {
        data.a[i] = i;
        data.b[i] = i*2;
        data.c[i] = i*3;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_create(&threads[i], NULL, runner, (void*)i);
        if (ret) {
            printf("Error: unable to create thread, %d\n", ret);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret) {
            printf("Error: unable to join thread, %d\n", ret);
            exit(-1);
        }
    }

    free(data.a);
    free(data.b);
    free(data.c);

    return 0;
}