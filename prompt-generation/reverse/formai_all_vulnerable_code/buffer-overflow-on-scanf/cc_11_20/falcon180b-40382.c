//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, i, score = 0;
    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for length
    if (length < 8) {
        printf("Weak\n");
        exit(0);
    }

    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            score++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            score++;
        }
    }

    // Check for numbers
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            score++;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*') {
            score++;
        }
    }

    // Determine password strength
    if (score < 3) {
        printf("Weak\n");
    } else if (score < 6) {
        printf("Moderate\n");
    } else {
        printf("Strong\n");
    }

    return 0;
}