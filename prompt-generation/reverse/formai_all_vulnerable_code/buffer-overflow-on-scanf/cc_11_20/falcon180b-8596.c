//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32

#define PASSWORD_LOWER_CASE 1
#define PASSWORD_UPPER_CASE 2
#define PASSWORD_NUMBER 4
#define PASSWORD_SPECIAL_CHAR 8

int PasswordStrengthChecker(char *password) {
    int length = strlen(password);

    if (length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH) {
        return 0;
    }

    int hasLowerCase = 0;
    int hasUpperCase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (isalpha(c)) {
            if (c >= 'a' && c <= 'z') {
                hasLowerCase = 1;
            } else if (c >= 'A' && c <= 'Z') {
                hasUpperCase = 1;
            }
        } else if (isdigit(c)) {
            hasNumber = 1;
        } else if (!isalnum(c)) {
            hasSpecialChar = 1;
        }
    }

    int score = 0;

    if (hasLowerCase) {
        score += PASSWORD_LOWER_CASE;
    }

    if (hasUpperCase) {
        score += PASSWORD_UPPER_CASE;
    }

    if (hasNumber) {
        score += PASSWORD_NUMBER;
    }

    if (hasSpecialChar) {
        score += PASSWORD_SPECIAL_CHAR;
    }

    if (score == 0) {
        return 0;
    } else if (score == 1) {
        return 1;
    } else if (score == 2) {
        return 2;
    } else if (score == 3) {
        return 3;
    } else {
        return 4;
    }
}

int main() {
    char password[PASSWORD_MAX_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    int strength = PasswordStrengthChecker(password);

    switch (strength) {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Fair\n");
            break;
        case 2:
            printf("Good\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very Strong\n");
            break;
    }

    return 0;
}