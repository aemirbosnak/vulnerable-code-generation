//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main(int argc, char *argv[]) {
    char password[MAX_LENGTH];
    int length, i;
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special = 0;

    // Get password from user
    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);

    // Remove newline character
    length = strlen(password);
    password[--length] = '\0';

    // Check password length
    if (length < 8 || length > 20) {
        printf("Password must be between 8 and 20 characters.\n");
        return 1;
    }

    // Check for uppercase letter
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for digit
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check for special character
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special = 1;
            break;
        }
    }

    // Calculate password strength
    int strength = 0;
    if (has_uppercase) {
        strength++;
    }
    if (has_lowercase) {
        strength++;
    }
    if (has_digit) {
        strength++;
    }
    if (has_special) {
        strength++;
    }

    // Print password strength
    printf("Password strength: ");
    switch (strength) {
        case 0:
            printf("Very Weak\n");
            break;
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very Strong\n");
            break;
    }

    return 0;
}