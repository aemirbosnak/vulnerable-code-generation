//FormAI DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

// Function declaration for asynchronous calculation
void *addition(void *arg);
void *subtraction(void *arg);
void *multiplication(void *arg);
void *division(void *arg);

int main()
{
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    pthread_t thread_addition, thread_subtraction, thread_multiplication, thread_division;
    int rc;

    // Calculation using threads
    if ((rc = pthread_create(&thread_addition, NULL, addition, &num1))) {
        fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
        return EXIT_FAILURE;
    }
    if ((rc = pthread_create(&thread_subtraction, NULL, subtraction, &num2))) {
        fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
        return EXIT_FAILURE;
    }
    if ((rc = pthread_create(&thread_multiplication, NULL, multiplication, &num1))) {
        fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
        return EXIT_FAILURE;
    }
    if ((rc = pthread_create(&thread_division, NULL, division, &num2))) {
        fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
        return EXIT_FAILURE;
    }

    // Wait for threads to complete
    pthread_join(thread_addition, NULL);
    pthread_join(thread_subtraction, NULL);
    pthread_join(thread_multiplication, NULL);
    pthread_join(thread_division, NULL);

    printf("\nEnd of program\n");

    return 0;
}

// Function definition for addition
void *addition(void *arg)
{
    int num = *(int*) arg;
    int result = num + num;
    printf("\nAddition operation: %d + %d = %d\n", num, num, result);
    pthread_exit(NULL);
}

// Function definition for subtraction
void *subtraction(void *arg)
{
    int num = *(int*) arg;
    int result = num - num;
    printf("\nSubtraction operation: %d - %d = %d\n", num, num, result);
    pthread_exit(NULL);
}

// Function definition for multiplication
void *multiplication(void *arg)
{
    int num = *(int*) arg;
    int result = num * num;
    printf("\nMultiplication operation: %d * %d = %d\n", num, num, result);
    pthread_exit(NULL);
}

// Function definition for division
void *division(void *arg)
{
    int num = *(int*) arg;
    if (num == 0) {
        printf("\nDivision by 0 is not allowed\n");
        pthread_exit(NULL);
    } else {
        int result = num / num;
        printf("\nDivision operation: %d / %d = %d\n", num, num, result);
        pthread_exit(NULL);
    }
}