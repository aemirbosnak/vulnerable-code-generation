//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure for passing data to threads
struct v {
    int *a;
    int n;
};

// Function to be executed by each thread
void *runner(void *param) {
    struct v *data = param;
    int i, c = 0;

    // Add elements of array
    for (i = 0; i < data->n; i++) {
        c += data->a[i];
    }

    // Return the sum
    pthread_exit((void *)c);
}

int main(int argc, char **argv) {
    pthread_t threads[10];
    int i, n, c = 0;
    struct v data;

    // Get the size of array from user
    printf("Enter the size of array: ");
    scanf("%d", &n);

    // Initialize the array
    int a[n];
    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Set the data to be passed to each thread
    data.a = a;
    data.n = n;

    // Create threads
    for (i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, runner, &data);
    }

    // Join threads
    for (i = 0; i < n; i++) {
        pthread_join(threads[i], (void **)&c);
        printf("The sum of elements in thread %d is %d\n", i, c);
    }

    return 0;
}