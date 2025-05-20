//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_UPPERCASE_CHARACTERS 1
#define MIN_LOWERCASE_CHARACTERS 1
#define MIN_NUMERICAL_CHARACTERS 1
#define MIN_SPECIAL_CHARACTERS 1

int main() {
    char password[MAX_PASSWORD_LENGTH];
    char input[MAX_PASSWORD_LENGTH];
    int password_length, i;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_numerical = 0;
    int has_special = 0;

    printf("Enter the password: ");
    scanf("%s", input);

    password_length = strlen(input);

    if (password_length < MIN_PASSWORD_LENGTH) {
        printf("Password length should be at least %d characters.\n", MIN_PASSWORD_LENGTH);
        return 1;
    }

    if (password_length > MAX_PASSWORD_LENGTH) {
        printf("Password length should be at most %d characters.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    for (i = 0; i < password_length; i++) {
        if (isupper(input[i])) {
            has_uppercase = 1;
        } else if (islower(input[i])) {
            has_lowercase = 1;
        } else if (isdigit(input[i])) {
            has_numerical = 1;
        } else if (!isalnum(input[i])) {
            has_special = 1;
        }
    }

    if (!has_uppercase) {
        printf("Password should contain at least one uppercase character.\n");
        return 1;
    }

    if (!has_lowercase) {
        printf("Password should contain at least one lowercase character.\n");
        return 1;
    }

    if (!has_numerical) {
        printf("Password should contain at least one numerical character.\n");
        return 1;
    }

    if (!has_special) {
        printf("Password should contain at least one special character.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}