//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, i;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for minimum length
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letter
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            printf("Password contains an uppercase letter.\n");
            return 0;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            printf("Password contains a lowercase letter.\n");
            return 0;
        }
    }

    // Check for digit
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            printf("Password contains a digit.\n");
            return 0;
        }
    }

    // Check for special character
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            printf("Password contains a special character.\n");
            return 0;
        }
    }

    // Password strength is strong
    printf("Password is strong.\n");
    return 0;
}