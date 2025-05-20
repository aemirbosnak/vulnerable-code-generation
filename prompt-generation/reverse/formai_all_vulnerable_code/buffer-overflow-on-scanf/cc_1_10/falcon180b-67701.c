//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define MIN_LOWERCASE_COUNT 1
#define MIN_UPPERCASE_COUNT 1
#define MIN_NUMBER_COUNT 1
#define MIN_SPECIAL_CHARACTER_COUNT 1

bool isPasswordValid(char* password);

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}

bool isPasswordValid(char* password) {
    int passwordLength = strlen(password);

    if (passwordLength < MIN_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH) {
        return false;
    }

    int lowercaseCount = 0;
    int uppercaseCount = 0;
    int numberCount = 0;
    int specialCharacterCount = 0;

    for (int i = 0; i < passwordLength; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                lowercaseCount++;
            } else if (isupper(password[i])) {
                uppercaseCount++;
            }
        } else if (isdigit(password[i])) {
            numberCount++;
        } else {
            specialCharacterCount++;
        }
    }

    if (lowercaseCount < MIN_LOWERCASE_COUNT || uppercaseCount < MIN_UPPERCASE_COUNT || numberCount < MIN_NUMBER_COUNT || specialCharacterCount < MIN_SPECIAL_CHARACTER_COUNT) {
        return false;
    }

    return true;
}