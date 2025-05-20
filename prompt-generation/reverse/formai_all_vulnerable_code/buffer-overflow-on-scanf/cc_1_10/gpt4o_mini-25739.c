//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

// Function to calculate checksum by summing ASCII values of characters
unsigned long calculate_checksum(const char *input) {
    unsigned long checksum = 0;
    
    for (size_t i = 0; i < strlen(input); i++) {
        checksum += (unsigned char)input[i];
    }
    
    return checksum;
}

// Function to display the menu
void display_menu() {
    printf("===================================\n");
    printf("      CHECKSUM CALCULATOR         \n");
    printf("===================================\n");
    printf("  1. Calculate checksum\n");
    printf("  2. Exit\n");
    printf("===================================\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    unsigned long checksum;
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n'); 
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter the string to calculate checksum: ");
                while (getchar() != '\n'); // Clear the newline character
                if (fgets(input, sizeof(input), stdin) != NULL) {
                    input[strcspn(input, "\n")] = 0; // Remove newline character
                    checksum = calculate_checksum(input);
                    printf("Checksum for '%s' is: %lu\n", input, checksum);
                } else {
                    fprintf(stderr, "Error reading input.\n");
                }
                break;

            case 2:
                printf("Exiting the checksum calculator. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}