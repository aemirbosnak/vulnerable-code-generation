//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_FIB 50
#define NUM_THREADS 2

pthread_mutex_t lock;
int fib[MAX_FIB];
int fib_index = 2;  // Start from the third Fibonacci number
int exit_flag = 0;  // Flag to signal exit

void* calculate_fibonacci(void* arg) {
    while (1) {
        // Locking to safely access shared resources
        pthread_mutex_lock(&lock);
        if (fib_index < MAX_FIB) {
            fib[fib_index] = fib[fib_index - 1] + fib[fib_index - 2];
            fib_index++;
            printf("Fibonacci calculated: %d\n", fib[fib_index - 1]);
        } else {
            exit_flag = 1; // Signal exit when maximum reaches
        }
        pthread_mutex_unlock(&lock);
        sleep(1); // Simulate some delay in calculation
    }
    return NULL;
}

void* visualize_fibonacci(void* arg) {
    while (1) {
        // Locking to safely access shared resources
        pthread_mutex_lock(&lock);
        if (exit_flag) {
            pthread_mutex_unlock(&lock);
            break; // Exit if calculation is done
        }
        system("clear"); // Clear the console
        printf("Fibonacci Sequence Visualizer:\n\n");
        for (int i = 0; i < fib_index; i++) {
            printf("%d ", fib[i]);
        }
        printf("\n");
        pthread_mutex_unlock(&lock);
        sleep(2); // Delay for visualization
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);
    
    // Initialize first two Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    // Create threads for calculation and visualization
    if (pthread_create(&threads[0], NULL, calculate_fibonacci, NULL) != 0) {
        perror("Failed to create calculation thread");
        return EXIT_FAILURE;
    }

    if (pthread_create(&threads[1], NULL, visualize_fibonacci, NULL) != 0) {
        perror("Failed to create visualization thread");
        return EXIT_FAILURE;
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("Fibonacci sequence generation finished.\n");
    return EXIT_SUCCESS;
}