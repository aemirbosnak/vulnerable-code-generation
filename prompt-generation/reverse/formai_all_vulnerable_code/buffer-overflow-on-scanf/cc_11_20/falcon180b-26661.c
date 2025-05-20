//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 8

int main() {
    char password[LENGTH + 1];
    int length, i, count = 0;
    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < LENGTH) {
        printf("Password should be at least %d characters long.\n", LENGTH);
        return 0;
    }

    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            count++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            count++;
        }
    }

    // Check for digits
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            count++;
        }
    }

    // Determine password strength
    if (count < 3) {
        printf("Weak password\n");
    } else if (count < 5) {
        printf("Moderate password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}