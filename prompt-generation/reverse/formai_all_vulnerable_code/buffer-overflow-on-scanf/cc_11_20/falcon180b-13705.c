//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, upperCaseCount = 0, lowerCaseCount = 0, digitCount = 0, specialCharCount = 0;
    float strength = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    // Counting uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCaseCount++;
        }
    }

    // Counting lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowerCaseCount++;
        }
    }

    // Counting digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digitCount++;
        }
    }

    // Counting special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            specialCharCount++;
        }
    }

    // Calculating password strength
    if (length < 8) {
        strength = 0;
    } else if (length >= 8 && length <= 12) {
        strength = (float) (length - 7) / 5;
    } else {
        strength = 1;
    }

    if (upperCaseCount > 0) {
        strength += 0.1;
    }

    if (lowerCaseCount > 0) {
        strength += 0.1;
    }

    if (digitCount > 0) {
        strength += 0.1;
    }

    if (specialCharCount > 0) {
        strength += 0.1;
    }

    printf("Password strength: %.2f\n", strength);

    return 0;
}