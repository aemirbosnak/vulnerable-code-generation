//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000

// Structure for passing data to threads
struct v {
    int start;
    int end;
};

// Function to be executed by each thread
void *runner(void *param) {
    struct v *data = (struct v *) param;
    int i, j, target = data->end;

    for (i = data->start; i <= target; i++) {
        if (i == target) {
            printf("Element found at index %d\n", i);
            pthread_exit(0);
        }
    }

    printf("Element not found\n");
    pthread_exit(0);
}

// Main function
int main() {
    pthread_t threads[MAX];
    int i, target, num_threads = 0;
    struct v data[MAX];

    // Get user input for target value and number of threads
    printf("Enter the target value: ");
    scanf("%d", &target);
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Divide the search range among threads
    int range = MAX / num_threads;
    for (i = 0; i < num_threads; i++) {
        data[i].start = i * range;
        data[i].end = (i == num_threads - 1)? MAX - 1 : (i + 1) * range - 1;

        // Create thread for each search range
        pthread_create(&threads[i], NULL, runner, &data[i]);
    }

    // Join all threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}