//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: visionary
/*
 * Performance-Critical Component
 * This program is designed to demonstrate the use of multi-threading, 
 * memory allocation, and complex calculations, to create a performant 
 * component for a larger system.
 *
 * The program calculates the first n terms of the Fibonacci sequence using 
 * multi-threading. The number of threads can be dynamically set to optimize
 * performance for different systems.
 *
 * Author: Your Name
 * Date:   August 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 16

long long fib_num[MAX_THREADS][2];

void *calculate_fibonacci(void *arg) {
    int *thread_num = (int *)arg;
    int start = fib_num[*thread_num][0];
    int end = fib_num[*thread_num][1];
    long long fib1 = 0, fib2 = 1, fib_next;

    for (int i = start; i <= end; i++) {
        if (i < 2)
            fib_next = i;
        else {
            fib_next = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib_next;
        }
    }

    pthread_exit((void *)fib_next);
}

int main() {
    int num_terms, num_threads, thread_err;
    long long result = 0;
    pthread_t threads[MAX_THREADS];

    printf("Enter the number of terms to calculate: ");
    scanf("%d", &num_terms);

    printf("Enter the number of threads to use (1-16): ");
    scanf("%d", &num_threads);

    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Invalid number of threads. Setting to 1.\n");
        num_threads = 1;
    }

    int terms_per_thread = num_terms / num_threads;
    int extra_terms = num_terms % num_threads;
    int start = 0, end;

    for (int i = 0; i < num_threads; i++) {
        fib_num[i][0] = start;
        end = start + terms_per_thread - 1;
        if (i == num_threads - 1)
            end += extra_terms;
        fib_num[i][1] = end;

        thread_err = pthread_create(&threads[i], NULL, calculate_fibonacci, (void *)&i);
        if (thread_err) {
            printf("Error creating thread %d. Exiting.\n", i);
            exit(-1);
        }

        start = end + 1;
    }

    for (int i = 0; i < num_threads; i++) {
        void *thread_result;
        thread_err = pthread_join(threads[i], &thread_result);
        if (thread_err) {
            printf("Error joining thread %d. Exiting.\n", i);
            exit(-1);
        }
        result += (long long)thread_result;
    }

    printf("The %dth term of the Fibonacci sequence is %lld.\n", num_terms, result);

    return 0;
}