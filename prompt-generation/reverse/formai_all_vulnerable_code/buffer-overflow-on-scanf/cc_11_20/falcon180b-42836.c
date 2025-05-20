//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, score = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for length
    if (length < 8) {
        printf("Your password is too short.\n");
        return 0;
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
        if (!isalnum(password[i])) {
            score++;
        }
    }

    // Calculate the final score
    if (score < 2) {
        printf("Your password is weak.\n");
    } else if (score >= 2 && score < 4) {
        printf("Your password is medium.\n");
    } else {
        printf("Your password is strong.\n");
    }

    return 0;
}