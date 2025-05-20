//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

int is_password_valid(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_digit = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?') {
            has_special_char = 1;
        }
    }

    if (length < 8) {
        return 0;
    } else if (length >= 8 && length < 12 && has_uppercase && has_lowercase) {
        return 1;
    } else if (length >= 12 && has_uppercase && has_lowercase && has_digit && has_special_char) {
        return 2;
    }

    return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = is_password_valid(password);

    switch (strength) {
        case 0:
            printf("Weak password\n");
            break;
        case 1:
            printf("Moderate password\n");
            break;
        case 2:
            printf("Strong password\n");
            break;
        default:
            printf("Invalid password\n");
            break;
    }

    return 0;
}