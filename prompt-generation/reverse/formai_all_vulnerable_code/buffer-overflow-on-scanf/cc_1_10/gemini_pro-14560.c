//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 32

int check_length(char *password) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Password too short. Minimum length is %d characters.\n", MIN_LENGTH);
        return 0;
    } else if (length > MAX_LENGTH) {
        printf("Password too long. Maximum length is %d characters.\n", MAX_LENGTH);
        return 0;
    }
    return 1;
}

int check_uppercase(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            count++;
        }
    }
    if (count == 0) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    return 1;
}

int check_lowercase(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            count++;
        }
    }
    if (count == 0) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    return 1;
}

int check_digits(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            count++;
        }
    }
    if (count == 0) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    return 1;
}

int check_special_characters(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            count++;
        }
    }
    if (count == 0) {
        printf("Password must contain at least one special character (!, @, #, $, %%).\n");
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    if (!check_length(password)) {
        return 1;
    }
    if (!check_uppercase(password)) {
        return 1;
    }
    if (!check_lowercase(password)) {
        return 1;
    }
    if (!check_digits(password)) {
        return 1;
    }
    if (!check_special_characters(password)) {
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}