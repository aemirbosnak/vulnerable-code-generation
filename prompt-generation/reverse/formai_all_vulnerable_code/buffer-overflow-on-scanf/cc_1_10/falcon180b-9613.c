//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64
#define MIN_LOWER_CASE_COUNT 1
#define MIN_UPPER_CASE_COUNT 1
#define MIN_NUMERIC_COUNT 1
#define MIN_SPECIAL_COUNT 1

bool isPasswordValid(char* password);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid.\n");
    }

    return 0;
}

bool isPasswordValid(char* password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return false;
    }

    int lowerCaseCount = 0;
    int upperCaseCount = 0;
    int numericCount = 0;
    int specialCount = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                upperCaseCount++;
            } else {
                lowerCaseCount++;
            }
        } else if (isdigit(c)) {
            numericCount++;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*') {
            specialCount++;
        }
    }

    if (lowerCaseCount < MIN_LOWER_CASE_COUNT || upperCaseCount < MIN_UPPER_CASE_COUNT || numericCount < MIN_NUMERIC_COUNT || specialCount < MIN_SPECIAL_COUNT) {
        return false;
    }

    return true;
}