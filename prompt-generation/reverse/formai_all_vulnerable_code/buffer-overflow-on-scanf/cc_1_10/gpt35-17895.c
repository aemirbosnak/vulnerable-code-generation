//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: active
#include <stdio.h>
#include <string.h>

int checkLength(char* password) {
    int len = strlen(password);
    if(len >= 8 && len <= 16) {
        return 1;
    }
    return 0;
}

int checkUpper(char* password) {
    int len = strlen(password);
    for(int i = 0; i < len; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            return 1;
        }
    }
    return 0;
}

int checkLower(char* password) {
    int len = strlen(password);
    for(int i = 0; i < len; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            return 1;
        }
    }
    return 0;
}

int checkDigit(char* password) {
    int len = strlen(password);
    for(int i = 0; i < len; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            return 1;
        }
    }
    return 0;
}

int checkSpecial(char* password) {
    int len = strlen(password);
    for(int i = 0; i < len; i++) {
        if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            return 1;
        }
    }
    return 0;
}

int main() {
    char password[20];
    printf("Enter password: ");
    scanf("%s", password);
    int length = checkLength(password);
    int upper = checkUpper(password);
    int lower = checkLower(password);
    int digit = checkDigit(password);
    int special = checkSpecial(password);
    if(!length) {
        printf("Password must be between 8 and 16 characters.\n");
    }
    if(!upper) {
        printf("Password must contain at least one uppercase letter.\n");
    }
    if(!lower) {
        printf("Password must contain at least one lowercase letter.\n");
    }
    if(!digit) {
        printf("Password must contain at least one digit.\n");
    }
    if(!special) {
        printf("Password must contain at least one special character (!@#$%%^&*).\n");
    }
    if(length && upper && lower && digit && special) {
        printf("Password strength is strong.\n");
    }
    return 0;
}