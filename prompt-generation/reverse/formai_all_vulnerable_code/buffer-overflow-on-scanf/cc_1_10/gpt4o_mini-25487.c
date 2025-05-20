//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

// Function to calculate the checksum
unsigned int calculate_checksum(int numbers[], int count) {
    unsigned int checksum = 0;

    // Iterating through the numbers to compute the checksum
    for (int i = 0; i < count; i++) {
        checksum += numbers[i];
        checksum ^= (checksum << 13);  // Left shift and XOR operation
        checksum ^= (checksum >> 17);   // Right shift and XOR operation
        checksum += (checksum << 5);    // Left shift and add
    }

    return checksum;
}

// Function to display the current numbers in the array
void display_numbers(int numbers[], int count) {
    printf("Current numbers in the array:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

// Function to clear the input buffer
void clear_buffer() {
    while (getchar() != '\n');
}

int main() {
    int numbers[MAX_NUMBERS];
    int count = 0;
    char choice;

    // Entrance of the program
    printf("Welcome to the Checksum Calculator!\n");
    printf("This program computes a checksum based on your input.\n");

    // Loop for user input
    do {
        // Requesting user input
        printf("Enter a number (or type 'q' to quit): ");
        if (count >= MAX_NUMBERS) {
            printf("Reached maximum limit of numbers (%d). No more inputs can be added.\n", MAX_NUMBERS);
            break;
        }

        // Handling numerical input
        if (scanf("%d", &numbers[count]) == 1) {
            count++;
        } else {
            clear_buffer();  // Clear the buffer for non-numeric input
            printf("Invalid input! Please enter a numeric value.\n");
            continue;
        }

        // Display the current numbers
        display_numbers(numbers, count);

        // Check if the user wants to calculate the checksum
        printf("Would you like to calculate the checksum? (y/n): ");
        scanf(" %c", &choice);
        clear_buffer();

        if (choice == 'y' || choice == 'Y') {
            unsigned int checksum = calculate_checksum(numbers, count);
            printf("The calculated checksum is: %u\n", checksum);
        }

        // Ask whether to continue
        printf("Would you like to enter another number? (y/n): ");
        scanf(" %c", &choice);
        clear_buffer();

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Checksum Calculator! Goodbye!\n");
    return 0;
}