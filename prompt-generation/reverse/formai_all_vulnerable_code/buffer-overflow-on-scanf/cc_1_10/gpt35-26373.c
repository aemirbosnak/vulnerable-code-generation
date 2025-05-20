//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scientific
/*
 * C Threading Library Implementation Example Program
 * 
 * This program demonstrates the use of the C Threading Library implementation. 
 * It utilizes two threads to perform a simple mathematical calculation. 
 * The first thread calculates the sum of all numbers from 1 to a given input number, 
 * while the second thread calculates the factorial of the same input number.
 * The final output displays the calculated sum and factorial values.
 * 
 * To compile and run:
 * gcc threading_example.c -o threading_example -lpthread
 * ./threading_example
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to calculate sum of input number
void *sum_calculation(void *param) {
    int num = *((int*) param);
    int i, sum = 0;
    
    for (i=1; i<=num; i++) {
        sum += i;
    }
    
    return (void*) sum;
}

// Function to calculate factorial of input number
void *factorial_calculation(void *param) {
    int num = *((int*) param);
    int i, factorial = 1;
    
    for (i=1; i<=num; i++) {
        factorial *= i;
    }
    
    return (void*) factorial;
}

int main() {
    int num, sum, factorial;
    printf("Enter a number to calculate sum and factorial: ");
    scanf("%d", &num);
    
    // Thread variables
    pthread_t sum_thread, factorial_thread;
    void *sum_result, *factorial_result;
    
    // Create threads
    pthread_create(&sum_thread, NULL, sum_calculation, &num);
    pthread_create(&factorial_thread, NULL, factorial_calculation, &num);
    
    // Wait for threads to finish and get return values
    pthread_join(sum_thread, &sum_result);
    pthread_join(factorial_thread, &factorial_result);
    
    // Cast void pointers to int values
    sum = *((int*) sum_result);
    factorial = *((int*) factorial_result);
    
    // Display results
    printf("Sum of numbers from 1 to %d: %d\n", num, sum);
    printf("Factorial of %d: %d\n", num, factorial);
    
    return 0;
}