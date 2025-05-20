//FormAI DATASET v1.0 Category: Calculator ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// Struct for passing parameters to the threads
struct calc_params {
    int num1;
    int num2;
    char operator;
    int result;
};

// Function for addition operation
void *add(void *params) {
    struct calc_params *p = (struct calc_params *) params;
    p->result = p->num1 + p->num2;
    return NULL;
}

// Function for subtraction operation
void *subtract(void *params) {
    struct calc_params *p = (struct calc_params *) params;
    p->result = p->num1 - p->num2;
    return NULL;
}

// Function for multiplication operation
void *multiply(void *params) {
    struct calc_params *p = (struct calc_params *) params;
    p->result = p->num1 * p->num2;
    return NULL;
}

// Function for division operation
void *divide(void *params) {
    struct calc_params *p = (struct calc_params *) params;
    p->result = p->num1 / p->num2;
    return NULL;
}

int main() {
    int num1, num2;
    char operator;

    // Read input from the user
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Enter an operator (+,-,*,/): ");
    scanf(" %c", &operator);

    // Initialize the parameters to be passed to the threads
    struct calc_params params;
    params.num1 = num1;
    params.num2 = num2;
    params.operator = operator;

    // Declare the thread variables
    pthread_t t1, t2, t3, t4;

    // Create four threads, one for each operation
    pthread_create(&t1, NULL, add, (void *) &params);
    pthread_create(&t2, NULL, subtract, (void *) &params);
    pthread_create(&t3, NULL, multiply, (void *) &params);
    pthread_create(&t4, NULL, divide, (void *) &params);

    // Wait for all threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    // Print the result of each operation
    printf("Result of addition: %d\n", params.result);
    printf("Result of subtraction: %d\n", params.result);
    printf("Result of multiplication: %d\n", params.result);
    printf("Result of division: %d\n", params.result);

    return 0;
}