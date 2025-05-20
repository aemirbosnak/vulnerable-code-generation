//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Get password input from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check for uppercase letters
    if (!isupper(password[0])) {
        printf("Password must start with an uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letters
    if (!islower(password[length - 1])) {
        printf("Password must end with a lowercase letter.\n");
        return 0;
    }

    // Check for special characters
    if (!strpbrk(password, "!@#$%^&*()_+")) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    // Check for numbers
    if (!isdigit(password[length / 2])) {
        printf("Password must contain at least one number.\n");
        return 0;
    }

    // Check for repeated characters
    for (int i = 0; i < length - 1; i++) {
        if (password[i] == password[i + 1]) {
            printf("Password must not contain repeated characters.\n");
            return 0;
        }
    }

    // Password is strong
    printf("Password is strong.\n");
    return 0;
}