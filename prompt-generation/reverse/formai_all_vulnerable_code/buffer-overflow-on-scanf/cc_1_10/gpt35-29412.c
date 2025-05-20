//FormAI DATASET v1.0 Category: Calculator ; Style: multi-threaded
// Multi-threaded calculator program
#include <stdio.h>
#include <pthread.h>

// Function prototypes
void* add(void* argument);
void* subtract(void* argument);
void* multiply(void* argument);
void* divide(void* argument);

// Global variables
int num1, num2, result;
char operator;

int main() {
    // Get user input
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Create threads
    pthread_t thread1, thread2, thread3, thread4;
    pthread_create(&thread1, NULL, add, NULL);
    pthread_create(&thread2, NULL, subtract, NULL);
    pthread_create(&thread3, NULL, multiply, NULL);
    pthread_create(&thread4, NULL, divide, NULL);

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    // Print result
    printf("Result: %d\n", result);

    return 0;
}

void* add(void* argument) {
    if (operator == '+') {
        result = num1 + num2;
    }
    pthread_exit(0);
}

void* subtract(void* argument) {
    if (operator == '-') {
        result = num1 - num2;
    }
    pthread_exit(0);
}

void* multiply(void* argument) {
    if (operator == '*') {
        result = num1 * num2;
    }
    pthread_exit(0);
}

void* divide(void* argument) {
    if (operator == '/') {
        result = num1 / num2;
    }
    pthread_exit(0);
}