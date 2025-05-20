//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
//This C Threading Library Implementation example program creates 2 threads to calculate the sum and product of elements in an array of integers.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10

pthread_mutex_t mutex; // Declare mutex lock 

int array[ARRAY_SIZE] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}; // Declare array of integers with size ARRAY_SIZE

int sum = 0; // Declare a variable to store the sum of elements in the array
int product = 1; // Declare a variable to store the product of elements in the array

void* calculate_sum(void* arg) { // Function to calculate the sum of elements in the array
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        pthread_mutex_lock(&mutex); // Lock mutex to ensure thread safety
        sum += array[i];
        pthread_mutex_unlock(&mutex); // Unlock mutex
    }

    pthread_exit(NULL); // Terminate thread
}

void* calculate_product(void* arg) { // Function to calculate the product of elements in the array
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        pthread_mutex_lock(&mutex); // Lock mutex to ensure thread safety
        product *= array[i];
        pthread_mutex_unlock(&mutex); // Unlock mutex
    }

    pthread_exit(NULL); // Terminate thread
}

int main() {
    pthread_t thread1, thread2; // Declare 2 threads

    pthread_mutex_init(&mutex, NULL); // Initialize mutex lock 

    pthread_create(&thread1, NULL, calculate_sum, NULL); // Create thread1 to calculate the sum of elements in the array
    pthread_create(&thread2, NULL, calculate_product, NULL); // Create thread2 to calculate the product of elements in the array

    pthread_join(thread1, NULL); // Wait for thread1 to complete
    pthread_join(thread2, NULL); // Wait for thread2 to complete

    printf("The sum of elements in the array is: %d\n", sum); // Print the sum of elements in the array
    printf("The product of elements in the array is: %d\n", product); // Print the product of elements in the array

    pthread_mutex_destroy(&mutex); // Destroy mutex lock 

    return 0;
}