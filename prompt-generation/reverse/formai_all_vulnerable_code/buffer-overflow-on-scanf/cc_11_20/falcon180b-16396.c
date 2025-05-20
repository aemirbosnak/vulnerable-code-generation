//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char password[50];
    int length, i, upperCase = 0, lowerCase = 0, digit = 0, specialChar = 0;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for minimum length
    if (length < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letter
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCase = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowerCase = 1;
            break;
        }
    }

    // Check for digit
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    // Check for special character
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            specialChar = 1;
            break;
        }
    }

    // Check password strength
    if (upperCase && lowerCase && digit && specialChar) {
        printf("Password is strong.\n");
    } else if (upperCase && lowerCase && digit) {
        printf("Password is good.\n");
    } else if (upperCase && lowerCase) {
        printf("Password is fair.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}