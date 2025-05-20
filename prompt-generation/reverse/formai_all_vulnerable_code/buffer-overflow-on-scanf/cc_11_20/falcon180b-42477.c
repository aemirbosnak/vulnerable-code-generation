//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main(void) {

    char password[MAX_PASSWORD_LENGTH + 1];
    int length, uppercase = 0, lowercase = 0, digit = 0, special = 0;

    // Prompt the user to enter a password
    printf("Enter your password: ");
    scanf("%s", password);

    // Get the length of the password
    length = strlen(password);

    // Check if the password contains at least one uppercase letter
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check if the password contains at least one digit
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    // Check if the password contains at least one special character
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = 1;
            break;
        }
    }

    // Determine the strength of the password based on the above criteria
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (uppercase) {
        strength++;
    }
    if (lowercase) {
        strength++;
    }
    if (digit) {
        strength++;
    }
    if (special) {
        strength++;
    }

    // Display the strength of the password
    if (strength < 3) {
        printf("Weak\n");
    } else if (strength < 5) {
        printf("Moderate\n");
    } else {
        printf("Strong\n");
    }

    return 0;
}