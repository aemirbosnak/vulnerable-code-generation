//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate checksum
unsigned int calculate_checksum(const char *input) {
    unsigned int checksum = 0;
    for (size_t i = 0; i < strlen(input); i++) {
        checksum += (unsigned char)input[i]; // Adding ASCII value of each character
    }
    return checksum; // Return the checksum value
}

// Function to display a friendly menu
void display_menu() {
    printf("Welcome to the Checksum Calculator!\n");
    printf("You can calculate the checksum of any string.\n");
    printf("Please choose an option:\n");
    printf("1. Calculate Checksum\n");
    printf("2. Exit\n");
}

// Function to get user input safely
void get_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0'; // Remove the newline character
        }
    }
}

int main() {
    char input[256]; // Buffer to store user input
    int choice; // Variable to store user's menu choice

    while (1) {
        display_menu(); // Display the menu to the user
        printf("Enter your choice: ");
        scanf("%d", &choice); // Get user choice
        // Clearing the input buffer after reading integer
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                printf("Enter the string to calculate its checksum: ");
                get_input(input, sizeof(input)); // Get the input string
                unsigned int checksum = calculate_checksum(input); // Calculate checksum
                printf("The checksum of the string \"%s\" is: %u\n", input, checksum);
                break;
            case 2:
                printf("Thank you for using the Checksum Calculator! Goodbye!\n");
                return 0; // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0; // Return success
}