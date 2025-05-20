//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32
#define PASSWORD_LOWER_CASE 1
#define PASSWORD_UPPER_CASE 2
#define PASSWORD_NUMBER 4
#define PASSWORD_SPECIAL 8

// Function to check if a character is a lowercase letter
bool isLowerCase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is an uppercase letter
bool isUpperCase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a number
bool isNumber(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a special character
bool isSpecial(char c) {
    return (!isLowerCase(c) &&!isUpperCase(c) &&!isNumber(c));
}

// Function to check if a password meets the required criteria
bool checkPassword(char* password) {
    int length = strlen(password);
    if (length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH) {
        return false;
    }
    int lowerCaseCount = 0;
    int upperCaseCount = 0;
    int numberCount = 0;
    int specialCount = 0;
    for (int i = 0; i < length; i++) {
        if (isLowerCase(password[i])) {
            lowerCaseCount++;
        } else if (isUpperCase(password[i])) {
            upperCaseCount++;
        } else if (isNumber(password[i])) {
            numberCount++;
        } else if (isSpecial(password[i])) {
            specialCount++;
        }
    }
    if (lowerCaseCount == 0 || upperCaseCount == 0 || numberCount == 0 || specialCount == 0) {
        return false;
    }
    return true;
}

int main() {
    char password[PASSWORD_MAX_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    if (checkPassword(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
    return 0;
}