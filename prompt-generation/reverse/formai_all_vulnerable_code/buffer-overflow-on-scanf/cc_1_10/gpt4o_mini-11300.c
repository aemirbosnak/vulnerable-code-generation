//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SPECIAL "?!@#$%^&*()-_=+[]{};:'\",.<>/"

void displayMenu() {
    printf("\n=== Secure Password Generator ===\n");
    printf("1. Generate Password\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int isValidPasswordLength(int length) {
    if (length < 8 || length > MAX_LENGTH) {
        printf("Error: Password length must be between 8 and %d.\n", MAX_LENGTH);
        return 0;
    }
    return 1;
}

void generatePassword(int length, int includeUpper, int includeLower, int includeDigits, int includeSpecial) {
    char password[MAX_LENGTH + 1]; // Buffer for the password
    char charset[256]; // Buffer to hold all possible characters
    int index = 0;
    srand(time(NULL)); // Seed the random number generator

    // Build the charset based on user choices
    if (includeUpper) {
        strcat(charset, UPPERCASE);
    }
    if (includeLower) {
        strcat(charset, LOWERCASE);
    }
    if (includeDigits) {
        strcat(charset, DIGITS);
    }
    if (includeSpecial) {
        strcat(charset, SPECIAL);
    }

    int charsetLength = strlen(charset);
    if (charsetLength == 0) {
        printf("Error: No character sets selected for password generation.\n");
        return;
    }

    // Generate the password
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charsetLength; // Get a random index
        password[i] = charset[randomIndex]; // Select a character from the charset
    }
    password[length] = '\0'; // Null-terminate the string

    printf("Generated Password: %s\n", password);
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 1) {
            int length;
            int includeUpper, includeLower, includeDigits, includeSpecial;
            printf("Enter desired password length (8 to %d): ", MAX_LENGTH);
            scanf("%d", &length);
            
            if (!isValidPasswordLength(length)) {
                continue; // Invalid length, go back to the menu
            }

            printf("Include uppercase letters? (1 for Yes, 0 for No): ");
            scanf("%d", &includeUpper);
            printf("Include lowercase letters? (1 for Yes, 0 for No): ");
            scanf("%d", &includeLower);
            printf("Include digits? (1 for Yes, 0 for No): ");
            scanf("%d", &includeDigits);
            printf("Include special characters? (1 for Yes, 0 for No): ");
            scanf("%d", &includeSpecial);

            generatePassword(length, includeUpper, includeLower, includeDigits, includeSpecial);
        }
    } while (choice != 2);

    printf("Goodbye!\n");
    return 0;
}