//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate secure password
void generatePassword(int len) {
    char pass[len];
    int i, r;
    srand(time(NULL));  // Initialize random number generator

    // Generate password randomly
    for(i = 0; i < len; i++) {
        r = rand() % 94 + 33; // ASCII characters from 33 (!) to 126 (~)
        pass[i] = (char)r;
    }

    // Print generated password
    printf("\nYour secure password: ");
    for(i = 0; i < len; i++) {
        printf("%c", pass[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int len;
    char choice;

    // Display welcome message
    printf("**********************************\n");
    printf("*** Retro Style Password Gen ****\n");
    printf("**********************************\n\n");

    // Prompt user for password length
    printf("Enter password length (6-16): ");
    scanf("%d", &len);

    // Validate password length
    if(len < 6 || len > 16) {
        printf("Invalid password length! Please try again.\n");
        printf("Enter password length (6-16): ");
        scanf("%d", &len);
    }

    // Generate secure password
    generatePassword(len);

    // Prompt user if they want to generate another password
    printf("Do you want to generate another password? (Y/N): ");
    scanf(" %c", &choice);

    // Loop until user chooses to quit
    while(choice == 'Y' || choice == 'y') {
        // Prompt user for password length
        printf("Enter password length (6-16): ");
        scanf("%d", &len);

        // Validate password length
        if(len < 6 || len > 16) {
            printf("Invalid password length! Please try again.\n");
            printf("Enter password length (6-16): ");
            scanf("%d", &len);
        }

        // Generate secure password
        generatePassword(len);

        // Prompt user if they want to generate another password
        printf("Do you want to generate another password? (Y/N): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using Retro Style Password Gen!\n");
    return 0;
}