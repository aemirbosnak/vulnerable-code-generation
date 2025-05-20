//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int check_password_strength(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    if (length < 8 || length > MAX_LENGTH) {
        printf("Password must be between 8 and %d characters.\n", MAX_LENGTH);
        return 0;
    }

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else if (islower(c)) {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_digit = 1;
        } else if (!isalnum(c)) {
            has_special = 1;
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

    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    printf("Password is strong.\n");
    return 1;
}

int main() {
    char password[MAX_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    int result = check_password_strength(password);

    if (result == 1) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}