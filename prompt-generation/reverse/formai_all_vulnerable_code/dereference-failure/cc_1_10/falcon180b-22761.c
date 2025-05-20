//Falcon-180B DATASET v1.0 Category: Error handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE (1024 * 1024)

typedef struct {
    pthread_t thread_id;
    int status;
    void *result;
} thread_data_t;

void *thread_function(void *arg) {
    int *data = arg;
    int result = *data * 2;

    if (result == 0) {
        perror("Error: Division by zero");
        exit(1);
    }

    return (void *)result;
}

void handle_error(int error) {
    fprintf(stderr, "Error: %s\n", strerror(error));
    exit(1);
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t thread_data[MAX_THREADS];
    int i, rc;

    for (i = 0; i < MAX_THREADS; i++) {
        int data = i + 1;
        thread_data[i].status = 0;
        rc = pthread_create(&threads[i], NULL, thread_function, &data);

        if (rc!= 0) {
            handle_error(rc);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        void *result;
        rc = pthread_join(threads[i], &result);

        if (rc!= 0) {
            handle_error(rc);
        }

        printf("Thread %d returned: %d\n", i + 1, *(int *)result);
    }

    return 0;
}