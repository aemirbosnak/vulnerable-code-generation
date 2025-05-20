//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

int is_valid_password(char* password) {
    int length = strlen(password);

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Password length is not within the allowed range.\n");
        return 0;
    }

    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special_character = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else if (!isalnum(password[i])) {
            has_special_character = 1;
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

    if (!has_special_character) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    printf("Password is strong.\n");
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Password strength: %d\n", strlen(password));
    }

    return 0;
}