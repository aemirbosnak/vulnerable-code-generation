//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if password is strong enough
int check_password_strength(char *password) {
    // Check password length
    int length = strlen(password);
    if (length < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letter
    if (!isupper(password[0])) {
        printf("Password should contain at least one uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letter
    if (!islower(password[1])) {
        printf("Password should contain at least one lowercase letter.\n");
        return 0;
    }

    // Check for digit
    if (!isdigit(password[2])) {
        printf("Password should contain at least one digit.\n");
        return 0;
    }

    // Check for special character
    if (!isalpha(password[3]) &&!isdigit(password[3])) {
        printf("Password should contain at least one special character.\n");
        return 0;
    }

    printf("Password is strong enough.\n");
    return 1;
}

int main() {
    char password[100];

    printf("Enter password: ");
    scanf("%s", password);

    int result = check_password_strength(password);

    if (result == 1) {
        printf("Password is strong enough.\n");
    } else {
        printf("Password is not strong enough.\n");
    }

    return 0;
}