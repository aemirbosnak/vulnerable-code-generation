//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int isPasswordValid(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak!\n");
    }

    return 0;
}

int isPasswordValid(char *password) {
    int length = strlen(password);
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    // Check for length
    if (length < 8) {
        return 0;
    }

    // Check for uppercase letter
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpperCase = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            hasLowerCase = 1;
            break;
        }
    }

    // Check for number
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            hasNumber = 1;
            break;
        }
    }

    // Check for special character
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            hasSpecialChar = 1;
            break;
        }
    }

    // Check if all conditions are met
    if (hasUpperCase && hasLowerCase && hasNumber && hasSpecialChar) {
        return 1;
    }

    return 0;
}