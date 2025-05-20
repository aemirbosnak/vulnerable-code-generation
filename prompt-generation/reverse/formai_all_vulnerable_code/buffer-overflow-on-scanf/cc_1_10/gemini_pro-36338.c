//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to store the password details
typedef struct {
    char *password;
    int strength;
} Password;

// Function to check if the password is strong
int isStrongPassword(const char *password) {
    int i, len, score = 0;

    // Check the length of the password
    len = strlen(password);
    if (len < 8) {
        return 0;
    }

    // Check if the password contains at least one uppercase letter
    for (i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            score++;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter
    for (i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            score++;
            break;
        }
    }

    // Check if the password contains at least one digit
    for (i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            score++;
            break;
        }
    }

    // Check if the password contains at least one special character
    for (i = 0; i < len; i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            score++;
            break;
        }
    }

    // Check if the password does not contain any common words
    char *commonWords[] = {"password", "123456", "admin", "root", "test", "hello", "world", "love", "you"};
    for (i = 0; i < 10; i++) {
        if (strcmp(password, commonWords[i]) == 0) {
            score--;
            break;
        }
    }

    // Return the strength of the password
    if (score >= 4) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check the strength of the password and display the result
void checkPasswordStrength(const char *password) {
    int strength = isStrongPassword(password);

    if (strength) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak!\n");
    }
}

// Main function
int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    checkPasswordStrength(password);

    return 0;
}