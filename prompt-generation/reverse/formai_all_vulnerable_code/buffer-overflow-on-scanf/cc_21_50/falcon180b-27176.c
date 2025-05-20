//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int length, uppercase, lowercase, digit, special_char;

    printf("Enter a password to check its strength: ");
    scanf("%s", password);

    // check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // check for uppercase letters
    uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // check for lowercase letters
    lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // check for digits
    digit = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    // check for special characters
    special_char = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special_char = 1;
            break;
        }
    }

    // determine password strength
    int strength = 0;
    if (length >= 8 && uppercase && lowercase && digit && special_char) {
        strength = 5;
    } else if (length >= 8 && (uppercase || lowercase) && digit && special_char) {
        strength = 4;
    } else if (length >= 8 && (uppercase || lowercase) && digit) {
        strength = 3;
    } else if (length >= 8 && (uppercase || lowercase) && special_char) {
        strength = 2;
    } else if (length >= 8 && digit && special_char) {
        strength = 1;
    } else {
        strength = 0;
    }

    // display password strength
    switch (strength) {
        case 5:
            printf("Password is very strong.\n");
            break;
        case 4:
            printf("Password is strong.\n");
            break;
        case 3:
            printf("Password is medium.\n");
            break;
        case 2:
            printf("Password is weak.\n");
            break;
        case 1:
            printf("Password is very weak.\n");
            break;
        default:
            printf("Password is invalid.\n");
            break;
    }

    return 0;
}