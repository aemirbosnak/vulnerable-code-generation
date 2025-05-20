//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128

// Function to check if the character is a special character
int isSpecialChar(char c) {
    return (c >= 33 && c <= 47) || (c >= 58 && c <= 64) ||
           (c >= 91 && c <= 96) || (c >= 123 && c <= 126);
}

// Function to generate a random password
void generatePassword(int length, int includeSpecialChars, char *password) {
    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*()-_=+[]{};:,.<>?";

    char *charset = lower;
    int totalChars = strlen(lower) + strlen(upper) + strlen(digits);
    
    // Add upper case, digits, and special characters to the character set based on user input
    if (length > 0) {
        totalChars += strlen(upper) + strlen(digits);
    }
    if (includeSpecialChars) {
        totalChars += strlen(special);
    }

    for (int i = 0; i < length; ++i) {
        // Randomly choose a character from the combined set
        int charChoice = rand() % (totalChars);
        
        if (charChoice < strlen(lower)) {
            password[i] = lower[charChoice];
        } else if (charChoice < strlen(lower) + strlen(upper)) {
            password[i] = upper[charChoice - strlen(lower)];
        } else if (charChoice < strlen(lower) + strlen(upper) + strlen(digits)) {
            password[i] = digits[charChoice - strlen(lower) - strlen(upper)];
        } else if (includeSpecialChars) {
            password[i] = special[charChoice - strlen(lower) - strlen(upper) - strlen(digits)];
        }
    }
    password[length] = '\0'; // Null-terminate the string
}

// Function to get user inputs
void getUserInput(int *length, int *includeSpecialChars) {
    printf("Enter the desired password length (1 to %d): ", MAX_LENGTH);
    scanf("%d", length);
    if (*length < 1 || *length > MAX_LENGTH) {
        printf("Length must be between 1 and %d. Using default length of 12.\n", MAX_LENGTH);
        *length = 12;
    }

    char choice;
    printf("Include special characters? (y/n): ");
    scanf(" %c", &choice);
    *includeSpecialChars = (choice == 'y' || choice == 'Y');
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int length = 12;
    int includeSpecialChars = 0;

    // Get user inputs for password generation
    getUserInput(&length, &includeSpecialChars);

    char password[MAX_LENGTH + 1];

    // Generate the password
    generatePassword(length, includeSpecialChars, password);

    // Print the generated password
    printf("Generated Password: %s\n", password);

    return 0;
}