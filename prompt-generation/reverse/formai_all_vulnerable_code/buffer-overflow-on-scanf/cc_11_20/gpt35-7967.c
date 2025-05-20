//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Alan Touring
// Alan Touring-style C Password Strength Checker

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char password[1024];
    bool isValid = false;
    int length, upperCount = 0, lowerCount = 0, digitCount = 0, specialCount = 0;

    printf("Please enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        isValid = false;
    } else {
        isValid = true;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCount++;
        } else if (islower(password[i])) {
            lowerCount++;
        } else if (isdigit(password[i])) {
            digitCount++;
        } else {
            specialCount++;
        }
    }

    if (upperCount < 1) {
        printf("Password must contain at least one uppercase letter.\n");
        isValid = false;
    }

    if (lowerCount < 1) {
        printf("Password must contain at least one lowercase letter.\n");
        isValid = false;
    }

    if (digitCount < 1) {
        printf("Password must contain at least one digit.\n");
        isValid = false;
    }

    if (specialCount < 1) {
        printf("Password must contain at least one special character.\n");
        isValid = false;
    }

    if (isValid) {
        printf("Password is strong and meets all requirements.\n");
    } else {
        printf("Password is weak and does not meet all requirements.\n");
    }

    return 0;
}