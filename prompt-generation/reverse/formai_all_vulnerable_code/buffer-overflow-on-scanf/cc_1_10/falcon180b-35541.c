//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PASS_LEN 50

bool isPasswordValid(char *password);

int main() {
    char password[MAX_PASS_LEN];

    printf("Enter password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

bool isPasswordValid(char *password) {
    int len = strlen(password);

    // Check for length
    if (len < 8) {
        return false;
    }

    // Check for uppercase
    if (!isupper(password[0])) {
        return false;
    }

    // Check for lowercase
    if (!islower(password[1])) {
        return false;
    }

    // Check for digit
    for (int i = 2; i < len; i++) {
        if (!isdigit(password[i])) {
            return false;
        }
    }

    return true;
}