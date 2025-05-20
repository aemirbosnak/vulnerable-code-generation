//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length, upper = 0, lower = 0, digit = 0, special = 0;

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lower = 1;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = 1;
            break;
        }
    }

    // Check password strength
    if (length >= 8 && upper && lower && digit && special) {
        printf("Strong password\n");
    } else if (length >= 8 && (upper || lower || digit || special)) {
        printf("Moderate password\n");
    } else {
        printf("Weak password\n");
    }

    return 0;
}