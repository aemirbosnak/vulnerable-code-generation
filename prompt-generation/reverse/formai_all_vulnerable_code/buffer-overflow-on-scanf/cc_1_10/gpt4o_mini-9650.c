//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

// Function to calculate the checksum of the input string
unsigned char calculate_checksum(const char *input) {
    unsigned char checksum = 0;
    while (*input) {
        checksum ^= *input++; // XOR operation for checksum
    }
    return checksum;
}

// Function to display the menu
void display_menu() {
    printf("\n==== Magical Checksum Calculator ====\n");
    printf("1. Calculate Checksum\n");
    printf("2. Exit\n");
    printf("=====================================\n");
}

// Function to handle user interactions
void handle_user_interaction() {
    char input[MAX_INPUT_SIZE];
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the input string to calculate checksum: ");
                getchar(); // To consume newline character left by scanf
                fgets(input, MAX_INPUT_SIZE, stdin);
                
                // Remove newline character
                input[strcspn(input, "\n")] = 0;
                
                unsigned char checksum = calculate_checksum(input);
                
                printf("The checksum of '%s' is: 0x%02X\n", input, checksum);
                break;
                
            case 2:
                printf("Exiting the magical realm of checksums. Farewell!\n");
                exit(0);
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

// Entry point of the program
int main() {
    printf("Welcome to the Magical Checksum Calculator!\n");
    printf("Prepare to embark on a journey to uncover the secrets of your strings...\n\n");
    
    handle_user_interaction();
    
    return 0;
}