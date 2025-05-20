//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 1024

// Function to calculate the checksum of a given string
unsigned int calculate_checksum(const char *input) {
    unsigned int checksum = 0;
    int length = strlen(input);
    
    // Iterate through each character, adding its ASCII value to the checksum
    for (int i = 0; i < length; i++) {
        checksum += (unsigned char)input[i];
    }
    
    // Return the final checksum value
    return checksum;
}

// Function to display the menu
void display_menu() {
    printf("===== Checksum Calculator =====\n");
    printf("1. Calculate checksum\n");
    printf("2. Exit\n");
    printf("==============================\n");
}

// Function to handle user input for checksum calculation
void handle_checksum_calculation() {
    char input[MAX_STRING_LENGTH];
    
    printf("Enter a string to calculate its checksum (max %d characters):\n", MAX_STRING_LENGTH - 1);
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0'; 

    // Calculate and print the checksum
    unsigned int checksum = calculate_checksum(input);
    printf("The checksum of the string '%s' is: %u\n", input, checksum);
}

int main() {
    int choice;
    
    // Main loop for user interaction
    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();  // Clear the newline character from the input buffer
        
        switch (choice) {
            case 1:
                handle_checksum_calculation();
                break;
            case 2:
                printf("Exiting the Checksum Calculator. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}