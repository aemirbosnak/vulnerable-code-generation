//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_RETRIES 3

// Function to perform a safe memory allocation
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        return NULL;
    }
    return ptr;
}

// Recursive function to read an integer from user input, with error handling
int read_integer(int attempt) {
    if (attempt >= MAX_RETRIES) {
        fprintf(stderr, "Maximum retries reached. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    int num;
    printf("Enter an integer: ");
    int res = scanf("%d", &num);
    
    if (res == EOF) {
        fprintf(stderr, "Input error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else if (res != 1) {
        fprintf(stderr, "Invalid input. Please enter a valid integer.\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return read_integer(attempt + 1);
    }

    return num;
}

// Recursive function to perform division and handle division by zero
double safe_divide(double numerator, double denominator, int attempt) {
    if (attempt >= MAX_RETRIES) {
        fprintf(stderr, "Maximum retries reached for division. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    if (denominator == 0) {
        fprintf(stderr, "Division by zero is not allowed. Please enter a non-zero denominator.\n");
        printf("Enter the denominator: ");
        int res = scanf("%lf", &denominator);
        
        if (res == EOF) {
            fprintf(stderr, "Input error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        } else if (res != 1 || denominator == 0) {
            // Clear the input buffer
            while (getchar() != '\n');
            return safe_divide(numerator, 0, attempt + 1);
        }
    }

    return numerator / denominator;
}

// Recursive function to perform the calculation
void perform_calculation(int attempt) {
    if (attempt >= MAX_RETRIES) {
        fprintf(stderr, "Maximum retries reached for calculation. Exiting...\n");
        exit(EXIT_FAILURE);
    }

    printf("\n--- Calculation ---\n");
    int a = read_integer(0);
    int b = read_integer(0);
    double result = safe_divide((double)a, (double)b, 0);
    printf("Result of %d / %d = %lf\n", a, b, result);
}

int main() {
    printf("Welcome to the Recursive Error Handling Example Program!\n");

    while (1) {
        perform_calculation(0);
        printf("Do you want to perform another calculation? (y/n): ");
        char choice;
        int res = scanf(" %c", &choice);

        if (res == EOF || (choice != 'y' && choice != 'n')) {
            fprintf(stderr, "Input error or invalid choice. Exiting...\n");
            exit(EXIT_FAILURE);
        }

        if (choice == 'n') {
            break;
        }
    }

    printf("Thank you for using the program!\n");
    return 0;
}