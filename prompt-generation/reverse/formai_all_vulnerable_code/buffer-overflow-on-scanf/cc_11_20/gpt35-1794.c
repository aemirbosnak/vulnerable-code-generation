//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to check if the password is strong
int passwordStrength(char *password) {
    int passwordLength = strlen(password);
    int score = 0;
    // check if password length is greater than 8
    if (passwordLength > 8) {
        score++;
    }
    // check if password contains digits
    int hasDigits = 0;
    for (int i=0; i<passwordLength; i++) {
        if (isdigit(password[i])) {
            hasDigits = 1;
            break;
        }
    }
    if (hasDigits) {
        score++;
    }
    // check if password contains lowercase letters
    int hasLowercase = 0;
    for (int i=0; i<passwordLength; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
            break;
        }
    }
    if (hasLowercase) {
        score++;
    }
    // check if password contains uppercase letters
    int hasUppercase = 0;
    for (int i=0; i<passwordLength; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
            break;
        }
    }
    if (hasUppercase) {
        score++;
    }
    // check if password contains special characters
    int hasSpecial = 0;
    for (int i=0; i<passwordLength; i++) {
        if (!isalnum(password[i])) {
            hasSpecial = 1;
            break;
        }
    }
    if (hasSpecial) {
        score++;
    }
    // determine password strength based on score
    int passwordStrength = 0;
    switch(score) {
        case 0:
        case 1:
            passwordStrength = 1;
            break;
        case 2:
            passwordStrength = 2;
            break;
        case 3:
            passwordStrength = 3;
            break;
        case 4:
            passwordStrength = 4;
            break;
        case 5:
            passwordStrength = 5;
            break;
    }
    return passwordStrength;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = passwordStrength(password);
    printf("Your password is ");
    switch (strength) {
        case 1:
            printf("very weak.\n");
            break;
        case 2:
            printf("weak.\n");
            break;
        case 3:
            printf("moderate.\n");
            break;
        case 4:
            printf("strong.\n");
            break;
        case 5:
            printf("very strong.\n");
            break;
    }
    return 0;
}