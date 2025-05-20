//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define LOWERCASE 'a'
#define UPPERCASE 'A'
#define NUMBERS '0'
#define SPECIAL '!'
#define MIN_LENGTH 8

int main() {
    char password[100];
    int length, i;
    char lowercase = 0, uppercase = 0, numbers = 0, special = 0;
    srand(time(NULL));

    // Prompt user to enter password
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Password is too short. Minimum length is %d.\n", MIN_LENGTH);
        return 0;
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for numbers
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numbers = 1;
            break;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = 1;
            break;
        }
    }

    // Check if password meets all criteria
    if (lowercase && uppercase && numbers && special) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}