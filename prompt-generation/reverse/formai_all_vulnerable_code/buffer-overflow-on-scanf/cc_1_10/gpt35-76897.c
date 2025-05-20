//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void *addition(void *arg);
void *subtraction(void *arg);
void *multiplication(void *arg);
void *division(void *arg);

int main() {
    int x, y, result;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    pthread_t thread[4];

    pthread_create(&thread[0], NULL, addition, &x);
    pthread_create(&thread[1], NULL, subtraction, &x);
    pthread_create(&thread[2], NULL, multiplication, &x);
    pthread_create(&thread[3], NULL, division, &x);

    pthread_join(thread[0], (void **)&result);
    printf("Addition: %d\n", result);

    pthread_join(thread[1], (void **)&result);
    printf("Subtraction: %d\n", result);

    pthread_join(thread[2], (void **)&result);
    printf("Multiplication: %d\n", result);

    pthread_join(thread[3], (void **)&result);
    printf("Division: %d\n", result);

    return 0;
}

void *addition(void *arg) {
    int x = *(int *)arg;
    int y = rand() % 100;
    int result = x + y;
    printf("Addition of %d and %d: %d\n", x, y, result);
    pthread_exit((void *)result);
}

void *subtraction(void *arg) {
    int x = *(int *)arg;
    int y = rand() % x;
    int result = x - y;
    printf("Subtraction of %d and %d: %d\n", x, y, result);
    pthread_exit((void *)result);
}

void *multiplication(void *arg) {
    int x = *(int *)arg;
    int y = rand() % 10;
    int result = x * y;
    printf("Multiplication of %d and %d: %d\n", x, y, result);
    pthread_exit((void *)result);
}

void *division(void *arg) {
    int x = *(int *)arg;
    int y = rand() % x + 1;
    int result = x / y;
    printf("Division of %d and %d: %d\n", x, y, result);
    pthread_exit((void *)result);
}