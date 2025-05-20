//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

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
        } else {
            has_special = 1;
        }
    }

    int strength = 0;

    if (length >= 8) {
        strength++;
    }

    if (has_uppercase && has_lowercase) {
        strength++;
    } else if (has_uppercase || has_lowercase) {
        strength++;
    }

    if (has_digit) {
        strength++;
    }

    if (has_special) {
        strength++;
    }

    printf("Password strength: %d\n", strength);

    return 0;
}