//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
// Paranoid Password Strength Checker
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int uppercase = 0, lowercase = 0, digits = 0, special = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            uppercase++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isdigit(password[i])) {
            digits++;
        } else {
            special++;
        }
    }

    if (strlen(password) < 8) {
        printf("Password must be at least 8 characters long.\n");
    }

    if (uppercase == 0) {
        printf("Password must contain at least 1 uppercase letter.\n");
    }

    if (lowercase == 0) {
        printf("Password must contain at least 1 lowercase letter.\n");
    }

    if (digits == 0) {
        printf("Password must contain at least 1 digit.\n");
    }

    if (special == 0) {
        printf("Password must contain at least 1 special character.\n");
    }

    if (strlen(password) >= 8 && uppercase > 0 && lowercase > 0 && digits > 0 && special > 0) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}