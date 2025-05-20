//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

// Function prototypes
void display_menu();
void input_numbers(int *numbers, int *count);
void perform_arithmetic_operations(int *numbers, int count);
void print_results(double sum, double avg, double min, double max);
void clean_up(int *numbers);

int main() {
    // Array to hold user-input numbers
    int numbers[MAX_NUMBERS];
    int count = 0;

    printf("Welcome to the Arithmetic Calculator!\n");

    while(1) {
        display_menu();
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                input_numbers(numbers, &count);
                break;
            case 2:
                if (count > 0) {
                    perform_arithmetic_operations(numbers, count);
                } else {
                    printf("Please input numbers first!\n");
                }
                break;
            case 3:
                printf("Exiting the program...\n");
                clean_up(numbers);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\nMain Menu:\n");
    printf("1. Input Numbers\n");
    printf("2. Perform Arithmetic Operations\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void input_numbers(int *numbers, int *count) {
    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", count);

    if (*count > MAX_NUMBERS) {
        printf("Exceeded maximum limit of %d numbers. Setting count to %d.\n", MAX_NUMBERS, MAX_NUMBERS);
        *count = MAX_NUMBERS;
    }
    if (*count < 1) {
        printf("Count must be at least 1.\n");
        *count = 0;
        return;
    }

    printf("Enter %d numbers:\n", *count);
    for (int i = 0; i < *count; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
}

void perform_arithmetic_operations(int *numbers, int count) {
    double sum = 0;
    double min = numbers[0];
    double max = numbers[0];

    for (int i = 0; i < count; i++) {
        sum += numbers[i];
        if (numbers[i] < min) {
            min = numbers[i];
        }
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    double avg = sum / count;

    print_results(sum, avg, min, max);
}

void print_results(double sum, double avg, double min, double max) {
    printf("\n--- Arithmetic Operation Results ---\n");
    printf("Sum: %.2f\n", sum);
    printf("Average: %.2f\n", avg);
    printf("Minimum: %.2f\n", min);
    printf("Maximum: %.2f\n", max);
    printf("------------------------------------\n");
}

void clean_up(int *numbers) {
    // Freeing memory if allocated dynamically (not applicable in this case)
    // However, this function can be useful if you decide to use dynamic memory in future versions.
    // For static arrays, nothing needs to be done here.
    printf("Clean up complete.\n");
}