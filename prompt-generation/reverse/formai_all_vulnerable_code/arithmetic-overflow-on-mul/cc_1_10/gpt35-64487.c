//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Declare variables
int sum = 0;
int product = 1;
int n = 10;
int random_numbers[10];

void *sum_thread(void *arg) {
    for (int i = 0; i < n; i++) {
        sum += random_numbers[i];
    }

    pthread_exit(NULL);
}

void *product_thread(void *arg) {
    for (int i = 0; i < n; i++) {
        product *= random_numbers[i];
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    // Generate random numbers and print them
    for (int i = 0; i < n; i++) {
        random_numbers[i] = rand() % 10 + 1;
        printf("%d ", random_numbers[i]);
    }

    // Create threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, sum_thread, NULL);
    pthread_create(&thread2, NULL, product_thread, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print results
    printf("\nSum = %d\nProduct = %d\n", sum, product);

    return 0;
}