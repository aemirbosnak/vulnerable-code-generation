//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define LOWERCASE_LETTER 'a'
#define UPPERCASE_LETTER 'A'
#define NUMBER '0'
#define SPECIAL_CHARACTER '!'

int is_password_valid(char* password);

int main() {
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (is_password_valid(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

int is_password_valid(char* password) {
    int length = strlen(password);
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return 0;
    }

    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_number = 0;
    int has_special_character = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (c >= LOWERCASE_LETTER && c <= 'z') {
            has_lowercase = 1;
        } else if (c >= UPPERCASE_LETTER && c <= 'Z') {
            has_uppercase = 1;
        } else if (c >= NUMBER && c <= '9') {
            has_number = 1;
        } else if (c == SPECIAL_CHARACTER) {
            has_special_character = 1;
        }
    }

    return has_lowercase && has_uppercase && has_number && has_special_character;
}