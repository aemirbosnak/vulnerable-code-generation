//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Welcome message
    printf("Hello there, password master! 🧙‍♂️✨\n\n");
    printf("Let's check how strong your password is. 💪\n");

    // Get the password from the user
    char password[100];
    printf("Enter your password, brave adventurer: ");
    scanf("%s", password);

    // Calculate the password strength
    int strength = 0;

    // Check for length
    if (strlen(password) >= 8) {
        strength += 20;
    }

    // Check for uppercase letters
    int hasUppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }
    if (hasUppercase) {
        strength += 20;
    }

    // Check for lowercase letters
    int hasLowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }
    if (hasLowercase) {
        strength += 20;
    }

    // Check for numbers
    int hasNumbers = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasNumbers = 1;
            break;
        }
    }
    if (hasNumbers) {
        strength += 20;
    }

    // Check for symbols
    int hasSymbols = 0;
    for (int i = 0; i < strlen(password); i++) {
        if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~')) {
            hasSymbols = 1;
            break;
        }
    }
    if (hasSymbols) {
        strength += 20;
    }

    // Check for repeated characters
    int hasRepeated = 0;
    for (int i = 0; i < strlen(password); i++) {
        for (int j = i + 1; j < strlen(password); j++) {
            if (password[i] == password[j]) {
                hasRepeated = 1;
                break;
            }
        }
        if (hasRepeated) {
            break;
        }
    }
    if (!hasRepeated) {
        strength += 10;
    }

    // Check for common passwords
    char *commonPasswords[] = {"password", "123456", "12345678", "qwerty", "abc123", "monkey", "iloveyou", "dragon", "princess", "sunshine"};
    int isCommon = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(password, commonPasswords[i]) == 0) {
            isCommon = 1;
            break;
        }
    }
    if (!isCommon) {
        strength += 10;
    }

    // Print the password strength
    printf("\nYour password strength is: %d%% 💪\n", strength);

    // Give feedback based on the password strength
    if (strength < 50) {
        printf("Oh dear, your password is a bit weak. Let's make it stronger together! 🦸‍♂️🦸‍♀️\n");
    } else if (strength >= 50 && strength < 75) {
        printf("Not bad! Your password is getting there, but it could still be stronger. Let's keep improving! 🧙‍♂️🧙‍♀️\n");
    } else if (strength >= 75 && strength < 90) {
        printf("Impressive! Your password is strong, but there's always room for improvement. Keep up the good work! 💪💪\n");
    } else {
        printf("Wow! Your password is incredibly strong! 🏆🏆\n");
    }

    // Farewell message
    printf("\nStay safe and keep your passwords strong, my friend! ✨🏰✨\n");

    return 0;
}