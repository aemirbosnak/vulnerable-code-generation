//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define N 10000
#define START_VAL 0
#define END_VAL 100

static volatile int running = 1;

void sighandler(int signo) {
    printf("Caught signal %d, exiting program.\n", signo);
    running = 0;
}

int main(void) {
    // Set up signal handler
    signal(SIGINT, sighandler);

    // Initialize random number generator
    srand(time(NULL));

    // Generate random array
    int arr[N];
    for (int i = 0; i < N; i++) {
        arr[i] = (int) (rand() * (END_VAL - START_VAL) / (RAND_MAX + 1.0)) + START_VAL;
    }

    // Create buckets
    int buckets[END_VAL - START_VAL + 1];
    for (int i = 0; i < END_VAL - START_VAL + 1; i++) {
        buckets[i] = 0;
    }

    // Sort into buckets
    for (int i = 0; i < N; i++) {
        buckets[arr[i] - START_VAL]++;
    }

    // Print buckets
    for (int i = 0; i < END_VAL - START_VAL + 1; i++) {
        printf("%d: %d\n", i + START_VAL, buckets[i]);
    }

    // Main loop
    int i = 0;
    while (running) {
        // Increment counter
        i++;

        // Randomly swap elements in array
        int r1 = rand() % N;
        int r2 = rand() % N;
        int temp = arr[r1];
        arr[r1] = arr[r2];
        arr[r2] = temp;

        // Resort into buckets
        for (int j = 0; j < END_VAL - START_VAL + 1; j++) {
            buckets[j] = 0;
        }
        for (int j = 0; j < N; j++) {
            buckets[arr[j] - START_VAL]++;
        }

        // Print buckets
        for (int j = 0; j < END_VAL - START_VAL + 1; j++) {
            printf("%d: %d\n", j + START_VAL, buckets[j]);
        }

        // Check if array is sorted
        int sorted = 1;
        for (int j = 0; j < N - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                sorted = 0;
                break;
            }
        }

        // Print if sorted
        if (sorted) {
            printf("Array is sorted after %d iterations.\n", i);
            break;
        }
    }

    return 0;
}