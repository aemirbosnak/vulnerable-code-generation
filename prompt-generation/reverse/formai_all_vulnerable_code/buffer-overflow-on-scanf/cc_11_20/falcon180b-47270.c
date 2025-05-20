//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, upperCase, lowerCase, digits, specialChars;

    // Get password input from user
    printf("Enter password: ");
    scanf("%s", password);

    // Calculate password length
    length = strlen(password);

    // Initialize flags
    upperCase = lowerCase = digits = specialChars = 0;

    // Check for upper case letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCase = 1;
            break;
        }
    }

    // Check for lower case letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowerCase = 1;
            break;
        }
    }

    // Check for digits
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digits = 1;
            break;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            specialChars = 1;
            break;
        }
    }

    // Print password strength
    if (length < 8) {
        printf("Weak\n");
    } else if (length < 12) {
        if (upperCase && lowerCase && digits && specialChars) {
            printf("Strong\n");
        } else {
            printf("Moderate\n");
        }
    } else {
        if (upperCase && lowerCase && digits && specialChars) {
            printf("Very strong\n");
        } else {
            printf("Strong\n");
        }
    }

    return 0;
}