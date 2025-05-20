//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: real-life
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int checkPassword(char *password) {
    int minLength = 8;
    int maxLength = 16;
    int lowercaseCount = 0;
    int uppercaseCount = 0;
    int numberCount = 0;
    int specialCharacterCount = 0;

    for (int i = 0; password[i]!= '\0'; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                lowercaseCount++;
            } else {
                uppercaseCount++;
            }
        } else if (isdigit(password[i])) {
            numberCount++;
        } else {
            specialCharacterCount++;
        }
    }

    if (strlen(password) < minLength || strlen(password) > maxLength) {
        return 0;
    }

    if (lowercaseCount < 1 || uppercaseCount < 1 || numberCount < 1 || specialCharacterCount < 1) {
        return 0;
    }

    return 1;
}

int main() {
    char password[16];

    printf("Enter your password: ");
    scanf("%s", password);

    if (checkPassword(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak!\n");
    }

    return 0;
}