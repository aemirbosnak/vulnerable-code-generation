//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function declarations
void *add(void *arg);
void *subtract(void *arg);
void *multiply(void *arg);
void *divide(void *arg);

// Global variables
double result = 0;
pthread_mutex_t mutex;

int main() {
    pthread_t tid[4];
    pthread_mutex_init(&mutex, NULL); // Initialize mutex
    
    // Get input from user
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    // Create threads for each operation
    pthread_create(&tid[0], NULL, add, (void *)&num1);
    pthread_create(&tid[1], NULL, subtract, (void *)&num1);
    pthread_create(&tid[2], NULL, multiply, (void *)&num2);
    pthread_create(&tid[3], NULL, divide, (void *)&num2);
    
    // Join threads to wait for operations to complete
    for (int i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
    }
    
    // Print result
    printf("The result is: %lf\n", result);
    
    pthread_mutex_destroy(&mutex); // Destroy mutex
    
    return 0;
}

void *add(void *arg) {
    double num1 = *(double *)arg;
    pthread_mutex_lock(&mutex); // Lock mutex to prevent race condition
    result += num1;
    pthread_mutex_unlock(&mutex); // Unlock mutex
    pthread_exit(NULL);
}

void *subtract(void *arg) {
    double num1 = *(double *)arg;
    pthread_mutex_lock(&mutex); // Lock mutex to prevent race condition
    result -= num1;
    pthread_mutex_unlock(&mutex); // Unlock mutex
    pthread_exit(NULL);
}

void *multiply(void *arg) {
    double num2 = *(double *)arg;
    pthread_mutex_lock(&mutex); // Lock mutex to prevent race condition
    result *= num2;
    pthread_mutex_unlock(&mutex); // Unlock mutex
    pthread_exit(NULL);
}

void *divide(void *arg) {
    double num2 = *(double *)arg;
    pthread_mutex_lock(&mutex); // Lock mutex to prevent race condition
    if (num2 != 0) {
        result /= num2;
    } else {
        printf("Error: division by zero\n");
    }
    pthread_mutex_unlock(&mutex); // Unlock mutex
    pthread_exit(NULL);
}