//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int isAlphabet(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
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

int isSpecialChar(char c) {
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?') {
        return 1;
    }
    return 0;
}

int main() {
    char password[MAX_LENGTH];
    int length = 0;

    printf("Enter the password: ");
    scanf("%s", password);

    while (password[length]!= '\0') {
        length++;
    }

    int hasAlphabet = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        if (isAlphabet(password[i])) {
            hasAlphabet = 1;
        } else if (isNumber(password[i])) {
            hasNumber = 1;
        } else if (isSpecialChar(password[i])) {
            hasSpecialChar = 1;
        }
    }

    int strength = 0;

    if (length >= 8) {
        strength++;
    }

    if (hasAlphabet) {
        strength++;
    }

    if (hasNumber) {
        strength++;
    }

    if (hasSpecialChar) {
        strength++;
    }

    printf("Password strength: %d\n", strength);

    return 0;
}