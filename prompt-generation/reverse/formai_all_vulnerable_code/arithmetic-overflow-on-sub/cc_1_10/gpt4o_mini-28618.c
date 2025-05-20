//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n < 0) {
        fprintf(stderr, "Error: Factorial of a negative number is not defined.\n");
        exit(EXIT_FAILURE);
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void calculate_factorials(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Factorial of %d is %d\n", arr[i], factorial(arr[i]));
    }
}

void print_usage() {
    printf("Usage: ./factorial_calculator [num1 num2 ... numN]\n");
    printf("Calculate factorials of the given non-negative integers.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    int *numbers = (int *)malloc((argc - 1) * sizeof(int));
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; ++i) {
        char *endptr;
        long num = strtol(argv[i], &endptr, 10);
        
        if (*endptr != '\0' || num < 0) {
            fprintf(stderr, "Error: '%s' is not a valid non-negative integer.\n", argv[i]);
            free(numbers);
            return EXIT_FAILURE;
        }

        numbers[i - 1] = (int)num;  // Cast to int since we are using factorial for small numbers
    }

    calculate_factorials(numbers, argc - 1);

    free(numbers);
    return EXIT_SUCCESS;
}