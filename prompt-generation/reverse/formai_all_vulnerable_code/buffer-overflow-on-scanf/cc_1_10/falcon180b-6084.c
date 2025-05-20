//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define PASSWORD_MAX_LENGTH 64
#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_NUM_DIGITS 4
#define PASSWORD_MAX_NUM_SPECIAL_CHARS 4

int check_password_strength(char *password) {
    int length = strlen(password);
    int num_digits = 0;
    int num_special_chars = 0;
    int num_lowercase_letters = 0;
    int num_uppercase_letters = 0;

    if (length < PASSWORD_MIN_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }

    if (length > PASSWORD_MAX_LENGTH) {
        printf("Password is too long.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            num_digits++;
        } else if (isupper(password[i]) || islower(password[i])) {
            if (isupper(password[i])) {
                num_uppercase_letters++;
            } else {
                num_lowercase_letters++;
            }
        } else if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?\\", password[i])!= NULL) {
            num_special_chars++;
        }
    }

    if (num_digits > PASSWORD_MAX_NUM_DIGITS) {
        printf("Password contains too many digits.\n");
        return 0;
    }

    if (num_special_chars > PASSWORD_MAX_NUM_SPECIAL_CHARS) {
        printf("Password contains too many special characters.\n");
        return 0;
    }

    if (num_lowercase_letters == 0 || num_uppercase_letters == 0) {
        printf("Password must contain both lowercase and uppercase letters.\n");
        return 0;
    }

    if (num_digits == 0 && num_special_chars == 0) {
        printf("Password must contain at least one digit or special character.\n");
        return 0;
    }

    printf("Password is strong.\n");
    return 1;
}

int main() {
    char password[PASSWORD_MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    int result = check_password_strength(password);

    if (result == 1) {
        printf("Congratulations, your password is strong.\n");
    } else {
        printf("Sorry, your password is weak.\n");
    }

    return 0;
}