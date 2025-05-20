//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

int is_password_strong(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    if (is_password_strong(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

int is_password_strong(char *password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            has_lowercase = 1;
        } else if (isdigit(c)) {
            has_number = 1;
        } else if (!isalnum(c)) {
            has_special_character = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_number && has_special_character) {
        return 1;
    } else {
        return 0;
    }
}