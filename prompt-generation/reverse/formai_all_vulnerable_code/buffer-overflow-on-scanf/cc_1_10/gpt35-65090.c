//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isUppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLowercase(char c) {
    return c >= 'a' && c <= 'z';
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isSpecialChar(char c) {
    return !isUppercase(c) && !isLowercase(c) && !isDigit(c);
}

int countUppercase(char* str) {
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isUppercase(str[i])) {
            cnt++;
        }
    }
    return cnt;
}

int countLowercase(char* str) {
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isLowercase(str[i])) {
            cnt++;
        }
    }
    return cnt;
}

int countDigits(char* str) {
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isDigit(str[i])) {
            cnt++;
        }
    }
    return cnt;
}

int countSpecialChars(char* str) {
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isSpecialChar(str[i])) {
            cnt++;
        }
    }
    return cnt;
}

bool isPasswordStrong(char* str) {
    int len = strlen(str);
    if (len < 8) {
        return false;
    }
    if (countUppercase(str) < 1) {
        return false;
    }
    if (countLowercase(str) < 1) {
        return false;
    }
    if (countDigits(str) < 1) {
        return false;
    }
    if (countSpecialChars(str) < 1) {
        return false;
    }
    return true;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);
    if (isPasswordStrong(password)) {
        printf("Password is strong\n");
    } else {
        printf("Password is weak\n");
    }
    return 0;
}