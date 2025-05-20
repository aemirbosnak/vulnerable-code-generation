//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* This structure will be used to pass data between threads */
struct v {
    int *a; /* pointer to an integer array */
    int n;   /* size of the array */
};

/* Function to be executed by each thread */
void *sum_array(void *arg) {
    struct v *data = (struct v *) arg;
    int i, sum = 0;

    /* Sum up all elements in the array */
    for(i=0; i<data->n; i++)
        sum += data->a[i];

    /* Print the result and exit */
    printf("Thread %d computed sum: %d\n", (int)pthread_self(), sum);
    pthread_exit(0);
}

int main() {
    pthread_t threads[10];
    int i, sum=0, n=10, status;
    int *a = (int *)malloc(n*sizeof(int));

    /* Initialize the array with random numbers */
    for(i=0; i<n; i++)
        a[i] = rand() % 100;

    /* Create 10 threads, each computing the sum of a portion of the array */
    for(i=0; i<n; i+=n/10) {
        struct v *data = (struct v *)malloc(sizeof(struct v));
        data->a = a;
        data->n = n;

        /* Pass the data structure as argument to each thread */
        status = pthread_create(&threads[i], NULL, sum_array, (void *)data);
        if(status) {
            printf("Error: unable to create thread, %d\n", status);
            exit(-1);
        }
    }

    /* Join with each thread and print its result */
    for(i=0; i<n; i+=n/10) {
        status = pthread_join(threads[i], NULL);
        if(status) {
            printf("Error: unable to join with thread, %d\n", status);
            exit(-1);
        }
    }

    return 0;
}