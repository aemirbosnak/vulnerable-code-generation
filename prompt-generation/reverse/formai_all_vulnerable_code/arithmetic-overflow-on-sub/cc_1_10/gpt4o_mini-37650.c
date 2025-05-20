//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addition(int n) {
    volatile long sum = 0; // Using volatile to prevent compiler optimization
    for (int i = 0; i < n; i++) {
        sum += i;
    }
}

void subtraction(int n) {
    volatile long difference = 0;
    for (int i = 0; i < n; i++) {
        difference -= i;
    }
}

void multiplication(int n) {
    volatile long product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }
}

void division(int n) {
    volatile double quotient = 1.0;
    for (int i = 1; i <= n; i++) {
        if (i != 0) {
            quotient /= i;
        }
    }
}

void benchmark(void (*operation)(int), const char* operation_name, int n) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    operation(n);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for %s with n = %d: %f seconds\n", operation_name, n, cpu_time_used);
}

void display_menu() {
    printf("\nBenchmarking Mathematical Operations\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
    printf("Choose an operation to benchmark (1-5): ");
}

int main() {
    int choice, n;

    printf("Welcome to the Introspective Benchmarking Program!\n");
    printf("Please enter the number of iterations to benchmark (e.g., 1000000): ");
    scanf("%d", &n);

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                benchmark(addition, "Addition", n);
                break;
            case 2:
                benchmark(subtraction, "Subtraction", n);
                break;
            case 3:
                benchmark(multiplication, "Multiplication", n);
                break;
            case 4:
                benchmark(division, "Division", n);
                break;
            case 5:
                printf("Exiting the benchmarking program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}