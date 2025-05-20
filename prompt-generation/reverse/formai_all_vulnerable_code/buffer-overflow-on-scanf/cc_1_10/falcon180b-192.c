//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to check if a string contains only alphanumeric characters
int isAlphanumeric(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isalnum(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a string contains at least one uppercase letter
int hasUppercase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isupper(str[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string contains at least one lowercase letter
int hasLowercase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (islower(str[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string contains at least one digit
int hasDigit(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check the strength of a password
int checkPasswordStrength(char* password) {
    int len = strlen(password);
    if (len < 8) {
        return 0;
    }
    if (!isAlphanumeric(password)) {
        return 0;
    }
    if (!hasUppercase(password)) {
        return 0;
    }
    if (!hasLowercase(password)) {
        return 0;
    }
    if (!hasDigit(password)) {
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    if (checkPasswordStrength(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
    return 0;
}