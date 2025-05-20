//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8) {
        printf("Password is too short.\n");
        return 1;
    }

    if (length > MAX_PASSWORD_LENGTH) {
        printf("Password is too long.\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (isupper(c)) {
            has_uppercase = 1;
        } else if (islower(c)) {
            has_lowercase = 1;
        } else if (isdigit(c)) {
            has_digit = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '^' || c == '~') {
            has_special_char = 1;
        }
    }

    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    if (!has_special_char) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}