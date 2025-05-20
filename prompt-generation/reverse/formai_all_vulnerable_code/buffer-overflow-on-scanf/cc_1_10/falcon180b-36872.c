//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isPasswordValid(char* password) {
    int length = strlen(password);
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return false;
    }
    int hasUppercase = false;
    int hasLowercase = false;
    int hasNumber = false;
    int hasSpecialChar = false;
    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            hasUppercase = hasUppercase || isupper(c);
            hasLowercase = hasLowercase || islower(c);
        } else if (isdigit(c)) {
            hasNumber = true;
        } else if (!isalpha(c) &&!isdigit(c)) {
            hasSpecialChar = true;
        }
    }
    if (!hasUppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return false;
    }
    if (!hasLowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return false;
    }
    if (!hasNumber) {
        printf("Password must contain at least one number.\n");
        return false;
    }
    if (!hasSpecialChar) {
        printf("Password must contain at least one special character.\n");
        return false;
    }
    return true;
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    if (isPasswordValid(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
    return 0;
}