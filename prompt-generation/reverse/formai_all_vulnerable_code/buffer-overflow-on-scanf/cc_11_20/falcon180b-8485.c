//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define PASSWORD_LENGTH 8

int main() {
    char password[PASSWORD_LENGTH];
    int password_strength = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;

    printf("Enter password: ");
    scanf("%s", password);

    if (strlen(password) < PASSWORD_LENGTH) {
        printf("Password is too short.\n");
        return 1;
    }

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            has_special_character = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_number && has_special_character) {
        printf("Password is strong.\n");
        password_strength = 4;
    } else if (has_uppercase && has_lowercase && has_number) {
        printf("Password is moderate.\n");
        password_strength = 3;
    } else if (has_uppercase && has_lowercase) {
        printf("Password is weak.\n");
        password_strength = 2;
    } else if (has_number) {
        printf("Password is very weak.\n");
        password_strength = 1;
    } else {
        printf("Password is extremely weak.\n");
        password_strength = 0;
    }

    return 0;
}