//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH_MIN 8
#define PASSWORD_LENGTH_MAX 32

int main() {
    char password[PASSWORD_LENGTH_MAX];
    int length;

    // Prompt user for password
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if password length is within acceptable range
    length = strlen(password);
    if (length < PASSWORD_LENGTH_MIN || length > PASSWORD_LENGTH_MAX) {
        printf("Password length must be between %d and %d characters.\n", PASSWORD_LENGTH_MIN, PASSWORD_LENGTH_MAX);
        return 1;
    }

    // Check if password contains at least one uppercase letter
    if (!isupper(password[0])) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    // Check if password contains at least one lowercase letter
    if (!islower(password[0])) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    // Check if password contains at least one digit
    if (!isdigit(password[0])) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    // Check if password contains at least one special character
    if (!strpbrk(password, "!@#$%^&*()_+-=[]{}|;:,.<>/?~`")) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    // If all checks passed, password is strong
    printf("Password is strong.\n");
    return 0;
}