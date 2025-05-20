//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: complex
// PasswordStrengthChecker.c

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    bool is_valid;
    int password_strength;
} Password;

void password_length_check(Password* password) {
    if (password->password_length < 8) {
        password->is_valid = false;
    }
}

void password_uppercase_check(Password* password) {
    for (int i = 0; i < password->password_length; i++) {
        if (password->password[i] >= 'A' && password->password[i] <= 'Z') {
            password->password_strength++;
        }
    }
}

void password_lowercase_check(Password* password) {
    for (int i = 0; i < password->password_length; i++) {
        if (password->password[i] >= 'a' && password->password[i] <= 'z') {
            password->password_strength++;
        }
    }
}

void password_number_check(Password* password) {
    for (int i = 0; i < password->password_length; i++) {
        if (password->password[i] >= '0' && password->password[i] <= '9') {
            password->password_strength++;
        }
    }
}

void password_special_char_check(Password* password) {
    for (int i = 0; i < password->password_length; i++) {
        if (password->password[i] == '!' || password->password[i] == '@' || password->password[i] == '#' || password->password[i] == '$' || password->password[i] == '%' || password->password[i] == '^' || password->password[i] == '&' || password->password[i] == '*' || password->password[i] == '(' || password->password[i] == ')') {
            password->password_strength++;
        }
    }
}

void password_check(Password* password) {
    password_length_check(password);
    password_uppercase_check(password);
    password_lowercase_check(password);
    password_number_check(password);
    password_special_char_check(password);
}

int main() {
    Password password;
    printf("Enter a password: ");
    fgets(password.password, MAX_PASSWORD_LENGTH, stdin);
    password.password_length = strlen(password.password);
    password_check(&password);
    if (password.is_valid) {
        printf("The password is valid.\n");
    } else {
        printf("The password is not valid.\n");
    }
    printf("The password strength is: %d\n", password.password_strength);
    return 0;
}