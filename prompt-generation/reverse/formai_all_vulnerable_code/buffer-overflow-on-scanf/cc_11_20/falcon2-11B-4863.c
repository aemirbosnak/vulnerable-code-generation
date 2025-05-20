//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_UPPERCASE_LETTER_COUNT 1
#define MIN_LOWERCASE_LETTER_COUNT 1
#define MIN_NUMBER_COUNT 1
#define MIN_SPECIAL_CHARACTER_COUNT 1

int checkPasswordStrength(char* password) {
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int numberCount = 0;
    int specialCharacterCount = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            uppercaseCount++;
        } else if (islower(password[i])) {
            lowercaseCount++;
        } else if (isdigit(password[i])) {
            numberCount++;
        } else if (password[i] == '_' || password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '=' || password[i] == '+' || password[i] == ';' || password[i] == ':') {
            specialCharacterCount++;
        }
    }

    if (strlen(password) >= MIN_PASSWORD_LENGTH) {
        if (uppercaseCount >= MIN_UPPERCASE_LETTER_COUNT && lowercaseCount >= MIN_LOWERCASE_LETTER_COUNT && numberCount >= MIN_NUMBER_COUNT && specialCharacterCount >= MIN_SPECIAL_CHARACTER_COUNT) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (checkPasswordStrength(password) == 1) {
        printf("Strong password\n");
    } else {
        printf("Weak password\n");
    }

    return 0;
}