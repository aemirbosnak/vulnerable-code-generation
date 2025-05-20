//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8
#define UPPER_CASE 0
#define LOWER_CASE 1
#define NUMBER 2
#define SPECIAL_CHAR 3

int main() {
    char password[MAX_LENGTH];
    int length, i, strength = 0;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for minimum length
    if (length < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            strength |= UPPER_CASE;
            break;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            strength |= LOWER_CASE;
            break;
        }
    }

    // Check for numbers
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            strength |= NUMBER;
            break;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            strength |= SPECIAL_CHAR;
            break;
        }
    }

    // Print password strength
    if (strength == 0) {
        printf("Password is very weak.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else if (strength == 2) {
        printf("Password is average.\n");
    } else if (strength == 3) {
        printf("Password is strong.\n");
    } else if (strength == 4) {
        printf("Password is very strong.\n");
    }

    return 0;
}