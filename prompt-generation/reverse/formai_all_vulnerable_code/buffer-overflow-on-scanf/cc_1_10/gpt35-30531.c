//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* addition(void* arg);
void* subtraction(void* arg);
void* multiplication(void* arg);
void* division(void* arg);

int main() {
    pthread_t add_thread, sub_thread, mul_thread, div_thread;
    double num1, num2;

    printf("Enter two numbers:\n");
    scanf("%lf %lf", &num1, &num2);

    int* num_ptr1 = (int*) malloc(sizeof(int));
    int* num_ptr2 = (int*) malloc(sizeof(int));
    *num_ptr1 = num1;
    *num_ptr2 = num2;

    pthread_create(&add_thread, NULL, addition, num_ptr1);
    pthread_create(&sub_thread, NULL, subtraction, num_ptr1);
    pthread_create(&mul_thread, NULL, multiplication, num_ptr2);
    pthread_create(&div_thread, NULL, division, num_ptr2);

    double sum = 0, difference = 0, product = 0, quotient = 1;
    pthread_join(add_thread, &sum);
    pthread_join(sub_thread, &difference);
    pthread_join(mul_thread, &product);
    pthread_join(div_thread, &quotient);

    printf("Sum: %.2f\nDifference: %.2f\nProduct: %.2f\nQuotient: %.2f\n", sum, difference, product, quotient);

    free(num_ptr1);
    free(num_ptr2);
    return 0;
}

void* addition(void* arg) {
    double num1 = *((double*) arg);
    double num2 = *((double*) arg);
    double* sum = (double*) malloc(sizeof(double));
    *sum = num1 + num2;
    return (void*) (sum);
}

void* subtraction(void* arg) {
    double num1 = *((double*) arg);
    double num2 = *((double*) arg);
    double* difference = (double*) malloc(sizeof(double));
    *difference = num1 - num2;
    return (void*) (difference);
}

void* multiplication(void* arg) {
    double num1 = *((double*) arg);
    double num2 = *((double*) arg);
    double* product = (double*) malloc(sizeof(double));
    *product = num1 * num2;
    return (void*) (product);
}

void* division(void* arg) {
    double num1 = *((double*) arg);
    double num2 = *((double*) arg);
    double* quotient = (double*) malloc(sizeof(double));
    *quotient = num1 / num2;
    return (void*) (quotient);
}