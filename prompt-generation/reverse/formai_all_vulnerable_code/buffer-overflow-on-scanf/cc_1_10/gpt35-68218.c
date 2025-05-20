//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

double result = 0.0;

void* addition(void* arg) {
    double* array = (double*) arg;
    result = array[0] + array[1];
    pthread_exit(NULL);
}

void* subtraction(void* arg) {
    double* array = (double*) arg;
    result = array[0] - array[1];
    pthread_exit(NULL);
}

void* multiplication(void* arg) {
    double* array = (double*) arg;
    result = array[0] * array[1];
    pthread_exit(NULL);
}

void* division(void* arg) {
    double* array = (double*) arg;
    if (array[1] == 0) {
        printf("Error: Division by zero");
        pthread_exit(NULL);
    }
    result = array[0] / array[1];
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    double numbers[2];

    // Taking the input from the user
    printf("Enter the first number: ");
    scanf("%lf", &numbers[0]);
    printf("Enter the second number: ");
    scanf("%lf", &numbers[1]);

    // Creating threads for each arithmetic operation
    if (pthread_create(&threads[0], NULL, addition, numbers) != 0) {
        printf("Error: Thread creation failed\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&threads[1], NULL, subtraction, numbers) != 0) {
        printf("Error: Thread creation failed\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&threads[2], NULL, multiplication, numbers) != 0) {
        printf("Error: Thread creation failed\n");
        exit(EXIT_FAILURE);
    }

    if (pthread_create(&threads[3], NULL, division, numbers) != 0) {
        printf("Error: Thread creation failed\n");
        exit(EXIT_FAILURE);
    }

    // Joining the threads after each arithmetic operation is complete
    if (pthread_join(threads[0], NULL) != 0) {
        printf("Error: Thread joining failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Addition Result: %lf\n", result);

    if (pthread_join(threads[1], NULL) != 0) {
        printf("Error: Thread joining failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Subtraction Result: %lf\n", result);

    if (pthread_join(threads[2], NULL) != 0) {
        printf("Error: Thread joining failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Multiplication Result: %lf\n", result);

    if (pthread_join(threads[3], NULL) != 0) {
        printf("Error: Thread joining failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Division Result: %lf\n", result);

    return 0;
}