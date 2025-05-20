//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32

#define PASSWORD_WEAK 1
#define PASSWORD_MEDIUM 2
#define PASSWORD_STRONG 3
#define PASSWORD_VERY_STRONG 4

int is_valid_password(char *password) {
    int password_length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    if (password_length < PASSWORD_MIN_LENGTH || password_length > PASSWORD_MAX_LENGTH) {
        return PASSWORD_WEAK;
    }

    for (int i = 0; i < password_length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    if (!has_uppercase ||!has_lowercase ||!has_digit ||!has_special) {
        return PASSWORD_WEAK;
    }

    if (has_uppercase && has_lowercase && has_digit && has_special) {
        return PASSWORD_VERY_STRONG;
    } else if (has_uppercase && has_lowercase && has_digit) {
        return PASSWORD_STRONG;
    } else if (has_uppercase && has_lowercase) {
        return PASSWORD_MEDIUM;
    } else {
        return PASSWORD_WEAK;
    }
}

int main() {
    char password[PASSWORD_MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int password_strength = is_valid_password(password);

    switch (password_strength) {
        case PASSWORD_WEAK:
            printf("Password is weak\n");
            break;
        case PASSWORD_MEDIUM:
            printf("Password is medium\n");
            break;
        case PASSWORD_STRONG:
            printf("Password is strong\n");
            break;
        case PASSWORD_VERY_STRONG:
            printf("Password is very strong\n");
            break;
    }

    return 0;
}