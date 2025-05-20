//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int is_password_strong(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    if (length < 8) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (isupper(c)) {
            has_uppercase = 1;
        } else if (islower(c)) {
            has_lowercase = 1;
        } else if (isdigit(c)) {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_digit && has_special) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (is_password_strong(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is not strong enough.\n");
    }

    return 0;
}