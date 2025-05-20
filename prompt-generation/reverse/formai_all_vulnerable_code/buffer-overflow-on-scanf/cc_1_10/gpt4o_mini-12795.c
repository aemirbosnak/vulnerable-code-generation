//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>

#define MAX_NUMBERS 100

// Function to calculate the average of an array of numbers
double calculate_average(int numbers[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return (double)sum / count;
}

// Function to find the maximum number in an array
int find_maximum(int numbers[], int count) {
    int max = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

// Function to find the minimum number in an array
int find_minimum(int numbers[], int count) {
    int min = numbers[0];
    for (int i = 1; i < count; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

// Function to count the odd and even numbers in an array
void count_odds_evens(int numbers[], int count, int *even_count, int *odd_count) {
    *even_count = 0;
    *odd_count = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] % 2 == 0) {
            (*even_count)++;
        } else {
            (*odd_count)++;
        }
    }
}

// Main function to demonstrate the arithmetic operations
int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;
    char choice;

    printf("Welcome to the Interactive Arithmetic Operations Program!\n");

    // Read numbers from user
    do {
        printf("Enter a number (or type 'q' to finish): ");
        if (scanf("%d", &numbers[count]) != 1) {
            // Clear the input buffer and break if user wants to quit
            while (getchar() != '\n'); // Clear the buffer
            break;
        }
        count++;
        if (count >= MAX_NUMBERS) {
            printf("Maximum number of entries reached.\n");
            break;
        }
    } while (1);

    // Perform calculations if there are numbers to process
    if (count > 0) {
        double average = calculate_average(numbers, count);
        int max = find_maximum(numbers, count);
        int min = find_minimum(numbers, count);
        int odd_count, even_count;

        count_odds_evens(numbers, count, &even_count, &odd_count);

        // Display results
        printf("\nResults:\n");
        printf("Total numbers entered: %d\n", count);
        printf("Average: %.2f\n", average);
        printf("Maximum: %d\n", max);
        printf("Minimum: %d\n", min);
        printf("Even numbers: %d\n", even_count);
        printf("Odd numbers: %d\n", odd_count);

        // Provide options for further calculations
        do {
            printf("\nWould you like to perform another calculation (y/n)? ");
            scanf(" %c", &choice);
            choice = tolower(choice);

            if (choice == 'y') {
                printf("\nYou can either:\n");
                printf("1. Add a new number\n");
                printf("2. Analyze existing numbers\n");
                printf("Choose an option (1 or 2): ");
                int option;
                scanf("%d", &option);

                if (option == 1) {
                    if (count < MAX_NUMBERS) {
                        printf("Enter a new number: ");
                        scanf("%d", &numbers[count]);
                        count++;
                    } else {
                        printf("Maximum number of entries reached.\n");
                    }
                } else if (option == 2) {
                    average = calculate_average(numbers, count);
                    max = find_maximum(numbers, count);
                    min = find_minimum(numbers, count);
                    count_odds_evens(numbers, count, &even_count, &odd_count);

                    // Display results
                    printf("\nUpdated Results:\n");
                    printf("Total numbers entered: %d\n", count);
                    printf("Average: %.2f\n", average);
                    printf("Maximum: %d\n", max);
                    printf("Minimum: %d\n", min);
                    printf("Even numbers: %d\n", even_count);
                    printf("Odd numbers: %d\n", odd_count);
                } else {
                    printf("Invalid option selected.\n");
                }
            }

        } while (choice == 'y');
    } else {
        printf("No numbers entered. Exiting the program.\n");
    }

    printf("Thank you for using the program. Goodbye!\n");
    return 0;
}