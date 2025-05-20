//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Prompt user for password
    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character from password
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
    }

    // Check password strength
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_character = 0;
    int has_repeated_character = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_number = 1;
        } else if (!isalnum(c)) {
            has_special_character = 1;
        }
    }

    for (int i = 0; i < length - 1; i++) {
        if (password[i] == password[i + 1]) {
            has_repeated_character = 1;
            break;
        }
    }

    // Print password strength
    if (length < 8) {
        printf("Password is too short\n");
    } else if (!has_uppercase ||!has_lowercase ||!has_number ||!has_special_character) {
        printf("Password is weak\n");
    } else if (has_repeated_character) {
        printf("Password contains repeated characters\n");
    } else {
        printf("Password is strong\n");
    }

    return 0;
}