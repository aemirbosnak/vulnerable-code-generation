//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold data passed to each thread
typedef struct {
    long long start;
    long long end;
    long long result;
} ThreadData;

// Function to compute the product of a range of numbers
void* calculate_factorial_part(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    data->result = 1;
    for (long long i = data->start; i <= data->end; i++) {
        data->result *= i;
    }
    pthread_exit(NULL);
}

// Function to calculate the factorial of a number using threads
long long factorial(int n) {
    if (n < 0) {
        fprintf(stderr, "Factorial of a negative number doesn't exist.\n");
        return -1; // Error condition
    }
    
    if (n == 0 || n == 1) {
        return 1;
    }

    int num_threads = 4; // Number of threads to use
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];
    long long range_size = n / num_threads;

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start = (i * range_size) + 1;
        thread_data[i].end = (i == num_threads - 1) ? n : ((i + 1) * range_size);
        pthread_create(&threads[i], NULL, calculate_factorial_part, (void*)&thread_data[i]);
    }

    // Wait for all threads to finish
    long long total_result = 1;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        total_result *= thread_data[i].result; // Combine results
    }

    return total_result;
}

int main() {
    int number;
    printf("Enter a non-negative integer to calculate its factorial: ");
    scanf("%d", &number);

    long long result = factorial(number);
    
    if (result != -1) {
        printf("Factorial of %d is %lld\n", number, result);
    }

    return 0;
}