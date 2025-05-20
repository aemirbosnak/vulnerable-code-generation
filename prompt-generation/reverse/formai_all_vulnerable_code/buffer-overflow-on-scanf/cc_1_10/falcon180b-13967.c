//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

int is_password_valid(char *password) {
    int length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Password must be between %d and %d characters long.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 0;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else {
            has_special_char = 1;
        }
    }

    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    if (!has_special_char) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (is_password_valid(password)) {
        printf("Your password is strong!\n");
    }

    return 0;
}