//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[101];
    int strength;
    int length;
    int upper;
    int lower;
    int digit;
    int special;
    int i;

    // Obtain the password from the user.
    printf("My dear Watson, enter the password you wish to scrutinize: ");
    scanf("%s", password);

    // Calculate the length of the password.
    length = strlen(password);

    // Initialize the strength of the password to 0.
    strength = 0;

    // Check if the password is at least 8 characters long.
    if (length >= 8) {
        strength += 1;
    }

    // Check if the password contains at least one uppercase letter.
    upper = 0;
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
            break;
        }
    }
    if (upper) {
        strength += 1;
    }

    // Check if the password contains at least one lowercase letter.
    lower = 0;
    for (i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
            break;
        }
    }
    if (lower) {
        strength += 1;
    }

    // Check if the password contains at least one digit.
    digit = 0;
    for (i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digit = 1;
            break;
        }
    }
    if (digit) {
        strength += 1;
    }

    // Check if the password contains at least one special character.
    special = 0;
    for (i = 0; i < length; i++) {
        if (!(password[i] >= 'a' && password[i] <= 'z') && !(password[i] >= 'A' && password[i] <= 'Z') && !(password[i] >= '0' && password[i] <= '9')) {
            special = 1;
            break;
        }
    }
    if (special) {
        strength += 1;
    }

    // Print the strength of the password.
    printf("The strength of your password is %d\n", strength);

    // Provide feedback to the user based on the strength of the password.
    if (strength == 0) {
        printf("Elementary, my dear Watson! This password is weak. You must strengthen it immediately.\n");
    } else if (strength == 1 || strength == 2) {
        printf("Mediocre, my dear Watson. This password is not strong enough. You should consider making it more complex.\n");
    } else if (strength == 3) {
        printf("Acceptable, my dear Watson. This password is fairly strong, but it could still be improved.\n");
    } else if (strength == 4) {
        printf("Impressive, my dear Watson! This password is strong. It will be difficult for an attacker to crack.\n");
    } else if (strength == 5) {
        printf("Magnificent, my dear Watson! This password is exceptionally strong. It is unlikely that an attacker will be able to crack it.\n");
    }

    return 0;
}