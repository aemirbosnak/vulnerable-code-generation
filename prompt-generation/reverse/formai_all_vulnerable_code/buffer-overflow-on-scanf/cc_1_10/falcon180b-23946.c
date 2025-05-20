//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMERIC_CHARS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-=[]{}|;:,.<>?/\\"

int is_valid_password(char *password) {
    int length = strlen(password);
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_numeric = 0;
    int has_special = 0;
    int consecutive_chars = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (strchr(LOWERCASE_CHARS, c)!= NULL) {
            has_lowercase = 1;
        } else if (strchr(UPPERCASE_CHARS, c)!= NULL) {
            has_uppercase = 1;
        } else if (strchr(NUMERIC_CHARS, c)!= NULL) {
            has_numeric = 1;
        } else if (strchr(SPECIAL_CHARS, c)!= NULL) {
            has_special = 1;
        } else {
            consecutive_chars++;
        }

        if (consecutive_chars > 3) {
            return 0;
        }
    }

    if (length < 8) {
        return 0;
    }

    if (!has_lowercase ||!has_uppercase ||!has_numeric ||!has_special) {
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}