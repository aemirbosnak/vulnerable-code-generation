//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex to protect shared data
pthread_mutex_t mutex;

// Condition variable to signal when data is ready
pthread_cond_t data_ready;

// Shared data
float total_expenses;

// Thread function to read expenses
void *read_expenses(void *args) {
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Wait for data to be ready
    pthread_cond_wait(&data_ready, &mutex);

    // Read the expenses from a file or stream
    float expenses;
    while (scanf("%f", &expenses) != EOF) {
        // Add the expenses to the total
        total_expenses += expenses;
    }

    // Signal that data is ready
    pthread_cond_signal(&data_ready);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Thread function to print expenses
void *print_expenses(void *args) {
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Wait for data to be ready
    pthread_cond_wait(&data_ready, &mutex);

    // Print the total expenses
    printf("Total expenses: %.2f\n", total_expenses);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    // Initialize the mutex and condition variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&data_ready, NULL);

    // Create the threads
    pthread_t read_thread, print_thread;
    pthread_create(&read_thread, NULL, read_expenses, NULL);
    pthread_create(&print_thread, NULL, print_expenses, NULL);

    // Join the threads
    pthread_join(read_thread, NULL);
    pthread_join(print_thread, NULL);

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&data_ready);

    return 0;
}