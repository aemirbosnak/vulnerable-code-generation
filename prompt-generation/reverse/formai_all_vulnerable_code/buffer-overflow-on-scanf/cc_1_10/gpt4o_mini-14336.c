//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declarations */
void benchmark_operation(const char *operation, int a, int b);
void addition(int a, int b);
void subtraction(int a, int b);
void multiplication(int a, int b);
void division(int a, int b);

int main() {
    int a, b;
    char operation[10];

    // Setup random seed for reproducibility
    srand(time(NULL));

    printf("Welcome to the Shape-Shifting Benchmarking Program!\n");
    printf("Enter two integers for the operation: ");
    scanf("%d %d", &a, &b);

    while (1) {
        printf("Choose an operation (add, sub, mul, div) or type 'exit' to quit: ");
        scanf("%s", operation);

        if (strcmp(operation, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Call the benchmarking function with the chosen operation
        benchmark_operation(operation, a, b);
    }

    return 0;
}

void benchmark_operation(const char *operation, int a, int b) {
    clock_t start_time, end_time;
    
    if (strcmp(operation, "add") == 0) {
        start_time = clock();
        addition(a, b);
        end_time = clock();
    } else if (strcmp(operation, "sub") == 0) {
        start_time = clock();
        subtraction(a, b);
        end_time = clock();
    } else if (strcmp(operation, "mul") == 0) {
        start_time = clock();
        multiplication(a, b);
        end_time = clock();
    } else if (strcmp(operation, "div") == 0) {
        start_time = clock();
        division(a, b);
        end_time = clock();
    } else {
        printf("Invalid operation. Please try again.\n");
        return;
    }

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken for %s: %f seconds\n", operation, time_taken);
}

void addition(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}

void subtraction(int a, int b) {
    printf("%d - %d = %d\n", a, b, a - b);
}

void multiplication(int a, int b) {
    printf("%d * %d = %d\n", a, b, a * b);
}

void division(int a, int b) {
    if (b == 0) {
        printf("Division by zero error!\n");
    } else {
        printf("%d / %d = %.2f\n", a, b, (double)a / b);
    }
}