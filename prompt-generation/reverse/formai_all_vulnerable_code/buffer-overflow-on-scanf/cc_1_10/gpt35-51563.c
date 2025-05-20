//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

// function prototypes
int check_length(char* str);
int check_uppercase(char* str);
int check_lowercase(char* str);
int check_digit(char* str);
int check_special(char* str);

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter password: ");
    scanf("%s", password);

    int valid_length, valid_upper, valid_lower, valid_digit, valid_special;
    valid_length = check_length(password);
    valid_upper = check_uppercase(password);
    valid_lower = check_lowercase(password);
    valid_digit = check_digit(password);
    valid_special = check_special(password);

    // check if password is valid
    if (valid_length && valid_upper && valid_lower && valid_digit && valid_special) {
        printf("Password is strong!\n");
    }
    else {
        printf("Password is not strong.\n");
        printf("Requirements:\n");
        if (!valid_length) {
            printf("- Must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        }
        if (!valid_upper) {
            printf("- Must contain at least one uppercase letter.\n");
        }
        if (!valid_lower) {
            printf("- Must contain at least one lowercase letter.\n");
        }
        if (!valid_digit) {
            printf("- Must contain at least one digit.\n");
        }
        if (!valid_special) {
            printf("- Must contain at least one special character (@, #, $, %, &, *, +, -, /, =, ?, ^, _, {, }, |, ~, .)\n");
        }
    }

    return 0;
}

// check if password length is valid
int check_length(char* str) {
    int len = strlen(str);
    if (len >= MIN_LENGTH && len <= MAX_LENGTH) {
        return 1;
    }
    return 0;
}

// check if password contains uppercase letters
int check_uppercase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            return 1;
        }
    }
    return 0;
}

// check if password contains lowercase letters
int check_lowercase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (islower(str[i])) {
            return 1;
        }
    }
    return 0;
}

// check if password contains digits
int check_digit(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            return 1;
        }
    }
    return 0;
}

// check if password contains a special character
int check_special(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '&' || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '=' || str[i] == '?' || str[i] == '^' || str[i] == '_' || str[i] == '{' || str[i] == '}' || str[i] == '|' || str[i] == '~' || str[i] == '.') {
            return 1;
        }
    }
    return 0;
}