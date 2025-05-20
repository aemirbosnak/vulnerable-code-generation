//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Ada Lovelace
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Ada Lovelace style threading library implementation example program

typedef struct {
    pthread_t thread_id;
    void *(*start_routine)(void *);
    void *arg;
} thread_t;

int thread_create(thread_t *thread, void *(*start_routine)(void *), void *arg) {
    int ret;
    ret = pthread_create(&thread->thread_id, NULL, start_routine, arg);
    if (ret!= 0) {
        printf("Error: unable to create thread, %d\n", ret);
        exit(ret);
    }
    return 0;
}

int thread_join(thread_t *thread, void **value_ptr) {
    int ret;
    ret = pthread_join(thread->thread_id, value_ptr);
    if (ret!= 0) {
        printf("Error: unable to join thread, %d\n", ret);
        exit(ret);
    }
    return 0;
}

void *sum_of_squares(void *arg) {
    int i, n = *((int *) arg);
    int sum = 0;
    for (i = 1; i <= n; i++) {
        sum += i * i;
    }
    return (void *) sum;
}

int main() {
    int n, i;
    int *result;
    thread_t thread;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    thread_create(&thread, sum_of_squares, &n);
    thread_join(&thread, &result);

    printf("Sum of squares of first %d natural numbers: %d\n", n, *result);

    return 0;
}