//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 128
#define MIN_PASSWORD_LENGTH 8

// Function Prototypes
void generatePassword(char *password, int length, int useUpper, int useLower, int useDigits, int useSpecial);
void shuffleString(char *str, int length);
int randomInRange(int min, int max);
int isValidCharacter(char c, int useUpper, int useLower, int useDigits, int useSpecial);

// Main Program
int main() {
    int length = 0;
    int useUpper = 0, useLower = 0, useDigits = 0, useSpecial = 0;
    char password[MAX_PASSWORD_LENGTH + 1];

    // Seed the random number generator
    srand(time(NULL));

    // User Input
    printf("Welcome to the Shape-Shifting Password Generator!\n");
    
    // Specify password length
    do {
        printf("Enter desired password length (8 to 128): ");
        scanf("%d", &length);
    } while (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH);

    // Character type choices
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useUpper);
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useLower);
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &useDigits);
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &useSpecial);

    // Validate at least one character type is selected
    if (!useUpper && !useLower && !useDigits && !useSpecial) {
        printf("At least one character type must be selected!\n");
        return 1;
    }

    // Generate password
    generatePassword(password, length, useUpper, useLower, useDigits, useSpecial);

    // Output the generated password
    printf("Your secure password is: %s\n", password);
    
    return 0;
}

// Password Generation
void generatePassword(char *password, int length, int useUpper, int useLower, int useDigits, int useSpecial) {
    const char *upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lowerChars = "abcdefghijklmnopqrstuvwxyz";
    const char *digitChars = "0123456789";
    const char *specialChars = "!@#$%^&*()-_=+[]{};:,.<>?";

    int index = 0;

    // At least one character from each selected type
    if (useUpper) {
        password[index++] = upperChars[randomInRange(0, strlen(upperChars) - 1)];
    }
    if (useLower) {
        password[index++] = lowerChars[randomInRange(0, strlen(lowerChars) - 1)];
    }
    if (useDigits) {
        password[index++] = digitChars[randomInRange(0, strlen(digitChars) - 1)];
    }
    if (useSpecial) {
        password[index++] = specialChars[randomInRange(0, strlen(specialChars) - 1)];
    }

    // Fill remaining characters
    for ( ; index < length; index++) {
        char selectedChar;
        int charType = randomInRange(1, 4);
        switch (charType) {
            case 1:
                if (useUpper) {
                    selectedChar = upperChars[randomInRange(0, strlen(upperChars) - 1)];
                } else {
                    index--;
                    continue;
                }
                break;
            case 2:
                if (useLower) {
                    selectedChar = lowerChars[randomInRange(0, strlen(lowerChars) - 1)];
                } else {
                    index--;
                    continue;
                }
                break;
            case 3:
                if (useDigits) {
                    selectedChar = digitChars[randomInRange(0, strlen(digitChars) - 1)];
                } else {
                    index--;
                    continue;
                }
                break;
            case 4:
                if (useSpecial) {
                    selectedChar = specialChars[randomInRange(0, strlen(specialChars) - 1)];
                } else {
                    index--;
                    continue;
                }
                break;
            default:
                selectedChar = ' ';
                break;
        }
        password[index] = selectedChar;
    }

    password[length] = '\0'; // Null-terminate the string
    shuffleString(password, length); // Shuffle to increase randomness
}

// Shuffle the password
void shuffleString(char *str, int length) {
    for (int i = 0; i < length; i++) {
        int j = randomInRange(0, length - 1);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Random number generator in a given range
int randomInRange(int min, int max) {
    return min + rand() % (max - min + 1);
}