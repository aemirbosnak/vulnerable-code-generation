//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Struct to pass data between threads
struct v {
    int *a;
    int n;
};

// Function to be executed by each thread
void *runner(void *param) {
    struct v *data = param;
    int sum = 0;

    // Loop through array and calculate sum
    for (int i = 0; i < data->n; i++) {
        sum += *(data->a + i);
    }

    // Print result and exit
    printf("Thread %d calculated sum: %d\n", *(int*)param, sum);
    pthread_exit(0);
}

// Main function
int main() {
    pthread_t threads[4];
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int i, rc;

    // Create threads
    for (i = 0; i < 4; i++) {
        struct v *data = malloc(sizeof(struct v));
        data->a = a;
        data->n = n / 4;
        rc = pthread_create(&threads[i], NULL, runner, (void*)i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join threads
    for (i = 0; i < 4; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    return 0;
}