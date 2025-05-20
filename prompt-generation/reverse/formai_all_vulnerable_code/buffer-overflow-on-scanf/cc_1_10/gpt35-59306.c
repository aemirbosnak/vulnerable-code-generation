//FormAI DATASET v1.0 Category: Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
void division(int x, int y);

void *adder_thread(void *arg);
void *subtracter_thread(void *arg);
void *multiplier_thread(void *arg);
void *divider_thread(void *arg);

int main() {
    int x, y;
    pthread_t adder, subtracter, multiplier, divider;

    printf("Enter the first number: ");
    scanf("%d", &x);

    printf("Enter the second number: ");
    scanf("%d", &y);

    void *sum, *difference, *product;

    pthread_create(&adder, NULL, adder_thread, &x);
    pthread_create(&subtracter, NULL, subtracter_thread, &x);
    pthread_create(&multiplier, NULL, multiplier_thread, &x);

    pthread_join(adder, &sum);
    pthread_join(subtracter, &difference);
    pthread_join(multiplier, &product);

    printf("Addition: %d\n", *((int*)sum));
    printf("Subtraction: %d\n", *((int*)difference));
    printf("Multiplication: %d\n", *((int*)product));

    division(x, y);

    return 0;
}

int add(int x, int y) {
    return x + y;
}

int subtract(int x, int y) {
    return x - y;
}

int multiply(int x, int y) {
    return x * y;
}

void division(int x, int y) {
    if (y != 0) {
        printf("Division: %d\n", x / y);
    } else {
        printf("Cannot divide by zero\n");
    }
}

void *adder_thread(void *arg) {
    int x = *((int*)arg);
    int y = 5;
    int *result = malloc(sizeof(int));
    *result = add(x, y);
    pthread_exit(result);
}

void *subtracter_thread(void *arg) {
    int x = *((int*)arg);
    int y = 5;
    int *result = malloc(sizeof(int));
    *result = subtract(x, y);
    pthread_exit(result);
}

void *multiplier_thread(void *arg) {
    int x = *((int*)arg);
    int y = 5;
    int *result = malloc(sizeof(int));
    *result = multiply(x, y);
    pthread_exit(result);
}

void *divider_thread(void *arg) {
    int x = *((int*)arg);
    int y = 5;
    if (y != 0) {
        division(x, y);
    } else {
        printf("Cannot divide by zero\n");
    }
    pthread_exit(NULL);
}