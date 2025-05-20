//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

int is_valid_password(char *password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        }
        else if (islower(password[i])) {
            has_lowercase = 1;
        }
        else if (isdigit(password[i])) {
            has_digit = 1;
        }
        else if (!isalnum(password[i])) {
            has_special_char = 1;
        }
    }
    if (has_uppercase && has_lowercase && has_digit && has_special_char) {
        return 1;
    }
    return 0;
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_strength = 0;
    printf("Enter a password: ");
    scanf("%s", password);
    password_strength = is_valid_password(password);
    if (password_strength == 1) {
        printf("Password is strong.\n");
    }
    else {
        printf("Password is weak.\n");
    }
    return 0;
}