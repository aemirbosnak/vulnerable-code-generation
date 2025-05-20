//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length;
    int count_upper = 0, count_lower = 0, count_digit = 0, count_special = 0;

    // Prompt the user to enter a password
    printf("Enter a password: ");
    fgets(password, MAX_LENGTH, stdin);

    // Remove the newline character at the end of the password
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        --length;
    }

    // Check the length of the password
    if (length < 8) {
        printf("Password is too short.\n");
        return 1;
    }

    // Check if the password contains at least one uppercase letter
    if (!isupper(password[0])) {
        for (int i = 1; i < length; ++i) {
            if (isupper(password[i])) {
                count_upper = 1;
                break;
            }
        }
    }

    // Check if the password contains at least one lowercase letter
    if (!islower(password[0])) {
        for (int i = 1; i < length; ++i) {
            if (islower(password[i])) {
                count_lower = 1;
                break;
            }
        }
    }

    // Check if the password contains at least one digit
    if (!isdigit(password[0])) {
        for (int i = 1; i < length; ++i) {
            if (isdigit(password[i])) {
                count_digit = 1;
                break;
            }
        }
    }

    // Check if the password contains at least one special character
    if (!ispunct(password[0])) {
        for (int i = 1; i < length; ++i) {
            if (ispunct(password[i])) {
                count_special = 1;
                break;
            }
        }
    }

    // Check if the password meets all the strength criteria
    if (count_upper && count_lower && count_digit && count_special) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}