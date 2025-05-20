//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

int is_valid_password(char *password) {
    int length = strlen(password);

    if (length < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_number = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*') {
            has_special_character = 1;
        }
    }

    if (!has_uppercase) {
        printf("Password should contain at least one uppercase letter.\n");
        return 0;
    }

    if (!has_lowercase) {
        printf("Password should contain at least one lowercase letter.\n");
        return 0;
    }

    if (!has_number) {
        printf("Password should contain at least one number.\n");
        return 0;
    }

    if (!has_special_character) {
        printf("Password should contain at least one special character.\n");
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    int result = is_valid_password(password);

    if (result) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}