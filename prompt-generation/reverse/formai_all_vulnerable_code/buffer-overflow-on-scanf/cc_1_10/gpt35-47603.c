//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: creative
#include<stdio.h>
#include<string.h>

int checkPasswordStrength(char password[]) {
    int len = strlen(password);
    int hasLower = 0, hasUpper = 0, hasDigit = 0, specialChar = 0;
  
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
        }
        else if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        }
        else {
            specialChar = 1;
        }
    }

    if (len < 8) {
        return 0;
    }

    int strength = hasLower + hasUpper + hasDigit + specialChar;

    if (strength < 3) {
        return 1;
    }
    else if (strength == 3) {
        return 2;
    }
    else {
        return 3;
    }
}

int main() {
    char password[15];

    printf("Enter a password: ");
    scanf("%s", password);

    int result = checkPasswordStrength(password);

    if (result == 0) {
        printf("The password is too weak.\n");
    }
    else if (result == 1) {
        printf("The password is of moderate strength.\n");
    }
    else if (result == 2) {
        printf("The password is strong.\n");
    }
    else {
        printf("The password is very strong.\n");
    }

    return 0;
}