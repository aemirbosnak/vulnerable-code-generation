//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 128

// Function to print an error message and exit
void printError(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(EXIT_FAILURE);
}

// Function to generate a random character based on the specified type
char getRandomCharacter(int includeLower, int includeUpper, int includeDigits, int includeSpecial) {
    int totalTypes = includeLower + includeUpper + includeDigits + includeSpecial;
    if (totalTypes == 0) {
        printError("Must include at least one character type.");
    }

    int type = rand() % totalTypes;
    if (type < includeLower) {
        return 'a' + rand() % 26;  // Lowercase letters
    } else if (type < includeLower + includeUpper) {
        return 'A' + rand() % 26;  // Uppercase letters
    } else if (type < includeLower + includeUpper + includeDigits) {
        return '0' + rand() % 10;   // Digits
    } else {
        const char *specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";
        return specialChars[rand() % strlen(specialChars)]; // Special characters
    }
}

// Function to generate a secure password
void generatePassword(char *password, int length, int includeLower, int includeUpper, int includeDigits, int includeSpecial) {
    for (int i = 0; i < length; i++) {
        password[i] = getRandomCharacter(includeLower, includeUpper, includeDigits, includeSpecial);
    }
    password[length] = '\0';  // Null-terminate the password string
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator

    int length;
    char password[MAX_PASSWORD_LENGTH + 1];

    // User inputs for password length and character types
    printf("Welcome to Secure Password Generator!\n");
    printf("Enter the desired length for the password (1-%d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
    if (length < 1 || length > MAX_PASSWORD_LENGTH) {
        printError("Invalid length! Must be between 1 and 128.");
    }

    int includeLower, includeUpper, includeDigits, includeSpecial;
    
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &includeLower);
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &includeUpper);
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &includeDigits);
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &includeSpecial);

    generatePassword(password, length, includeLower, includeUpper, includeDigits, includeSpecial);

    printf("Generated Password: %s\n", password);

    return 0;
}