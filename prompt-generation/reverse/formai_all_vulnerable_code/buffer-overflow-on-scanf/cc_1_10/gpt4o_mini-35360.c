//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

// Function to calculate checksum
unsigned long calculate_checksum(const char *input) {
    unsigned long checksum = 0;

    // Iterate through each character in the string
    for (int i = 0; input[i] != '\0'; i++) {
        checksum += (unsigned char)input[i];
    }

    return checksum;
}

// Function to print the menu
void print_menu() {
    printf("\n=============================\n");
    printf("   C Checksum Calculator\n");
    printf("=============================\n");
    printf("1. Calculate Checksum\n");
    printf("2. Exit\n");
    printf("=============================\n");
}

// Main function
int main() {
    char input[MAX_INPUT_SIZE];
    int choice;

    // Create a welcoming message
    printf("Welcome to the C Checksum Calculator!\n");
    printf("This fun program will help you compute the checksum of any string.\n");

    do {
        print_menu();
        printf("Please enter your choice (1 or 2): ");
        scanf("%d", &choice);
        getchar(); // Consume any leftover newline character

        switch (choice) {
            case 1:
                // Input the string for checksum calculation
                printf("Enter the string you want to calculate checksum for: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                // Remove the newline character from the input if present
                input[strcspn(input, "\n")] = 0;

                // Calculate checksum
                unsigned long checksum = calculate_checksum(input);
                printf("The checksum for the input string \"%s\" is: %lu\n", input, checksum);
                break;

            case 2:
                printf("Thank you for using the C Checksum Calculator! Goodbye!\n");
                break;

            default:
                printf("Oops! That choice is not valid. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}