//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 8
#define MIN_LOWER_CASE 1
#define MIN_UPPER_CASE 1
#define MIN_NUMBERS 1
#define MIN_SPECIAL_CHARS 1

int checkPasswordStrength(char* password) {
    int length = strlen(password);
    if (length < PASSWORD_LENGTH) {
        printf("Password should be at least %d characters long.\n", PASSWORD_LENGTH);
        return 0;
    }
    int lowerCaseCount = 0;
    int upperCaseCount = 0;
    int numberCount = 0;
    int specialCharCount = 0;
    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (c >= 'a' && c <= 'z') {
                lowerCaseCount++;
            } else if (c >= 'A' && c <= 'Z') {
                upperCaseCount++;
            }
        } else if (isdigit(c)) {
            numberCount++;
        } else {
            specialCharCount++;
        }
    }
    if (lowerCaseCount < MIN_LOWER_CASE || upperCaseCount < MIN_UPPER_CASE || numberCount < MIN_NUMBERS || specialCharCount < MIN_SPECIAL_CHARS) {
        printf("Password should contain at least %d lowercase letters, %d uppercase letters, %d numbers, and %d special characters.\n", MIN_LOWER_CASE, MIN_UPPER_CASE, MIN_NUMBERS, MIN_SPECIAL_CHARS);
        return 0;
    }
    printf("Password is strong.\n");
    return 1;
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    int result = checkPasswordStrength(password);
    if (result == 1) {
        printf("Password accepted.\n");
    }
    return 0;
}