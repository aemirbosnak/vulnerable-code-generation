//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length;
    int lowercase = 0;
    int uppercase = 0;
    int digits = 0;
    int special = 0;

    // Prompt user for password
    printf("Please enter your password: ");
    fgets(password, MAX_LENGTH, stdin);

    // Remove newline character
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        length--;
    }

    // Check password strength
    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                uppercase = 1;
            } else if (islower(password[i])) {
                lowercase = 1;
            }
        } else if (isdigit(password[i])) {
            digits = 1;
        } else if (!isalnum(password[i])) {
            special = 1;
        }
    }

    // Print password strength
    if (length >= 8 && uppercase && lowercase && digits && special) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}