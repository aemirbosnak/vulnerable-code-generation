//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 8 // Minimum length of password
#define UPPER 1 // Check for uppercase letter
#define LOWER 2 // Check for lowercase letter
#define NUMBER 4 // Check for number
#define SPECIAL 8 // Check for special character

int isUpper(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

int isLower(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}

int isNumber(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int isSpecial(char c) {
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*') {
        return 1;
    }
    return 0;
}

int checkPassword(char *password) {
    int length = strlen(password);
    int hasUpper = 0;
    int hasLower = 0;
    int hasNumber = 0;
    int hasSpecial = 0;

    if (length < LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isUpper(password[i])) {
            hasUpper = 1;
        }
        if (isLower(password[i])) {
            hasLower = 1;
        }
        if (isNumber(password[i])) {
            hasNumber = 1;
        }
        if (isSpecial(password[i])) {
            hasSpecial = 1;
        }
    }

    if (!hasUpper) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    if (!hasLower) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    if (!hasNumber) {
        printf("Password must contain at least one number.\n");
        return 0;
    }
    if (!hasSpecial) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    printf("Password is strong!\n");
    return 1;
}

int main() {
    char password[LENGTH + 1];

    printf("Enter password: ");
    scanf("%s", password);

    int result = checkPassword(password);

    return 0;
}