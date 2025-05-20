//Falcon2-11B DATASET v1.0 Category: Math exercise ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to calculate the sum of prime numbers using multi-threading
void *calculateSum(void *threadID) {
    int threadIDValue = *(int*)threadID;
    int lowerLimit = threadIDValue * 1000;
    int upperLimit = (threadIDValue + 1) * 1000;
    int sum = 0;

    for (int i = lowerLimit; i <= upperLimit; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }

    // Printing the sum of prime numbers for this thread
    printf("Sum of prime numbers for thread %d: %d\n", threadIDValue, sum);

    // Returning the sum to the main function
    return (void*)sum;
}

// Function to calculate the sum of prime numbers using multi-threading
int calculateSumOfPrimes() {
    int numThreads = 10;
    int threads[numThreads];

    // Creating threads and calculating the sum of prime numbers
    for (int i = 0; i < numThreads; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, calculateSum, &(threads[i]));
    }

    for (int i = 0; i < numThreads; i++) {
        int sum = *(int*)pthread_getspecific(threads[i]);
        pthread_setspecific(threads[i], NULL);
    }

    // Printing the total sum of prime numbers
    int totalSum = 0;
    for (int i = 0; i < numThreads; i++) {
        totalSum += *(int*)pthread_getspecific(threads[i]);
    }
    printf("Total sum of prime numbers: %d\n", totalSum);

    return totalSum;
}

int main() {
    int totalSum = calculateSumOfPrimes();
    printf("Total sum of prime numbers: %d\n", totalSum);
    return 0;
}