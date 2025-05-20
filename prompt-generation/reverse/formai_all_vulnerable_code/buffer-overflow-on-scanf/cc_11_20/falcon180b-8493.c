//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int i, j, length, uppercase, lowercase, number, special;
    char *uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
    char *number_chars = "0123456789";
    char *special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>?/~";

    // Get user input for password
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // Initialize variables
    uppercase = lowercase = number = special = 0;

    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            number = 1;
            break;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        for (j = 0; j < strlen(special_chars); j++) {
            if (password[i] == special_chars[j]) {
                special = 1;
                break;
            }
        }
        if (special) break;
    }

    // Calculate password strength
    int strength = 0;
    if (uppercase) strength++;
    if (lowercase) strength++;
    if (number) strength++;
    if (special) strength++;

    // Print password strength
    if (strength == 0) {
        printf("Password is very weak.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else if (strength == 2) {
        printf("Password is moderate.\n");
    } else if (strength == 3) {
        printf("Password is strong.\n");
    } else {
        printf("Password is very strong.\n");
    }

    return 0;
}