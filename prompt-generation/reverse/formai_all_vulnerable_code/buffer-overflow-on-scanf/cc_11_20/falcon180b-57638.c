//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length, i, score = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 6 || length > MAX_PASSWORD_LENGTH) {
        printf("Password must be between 6 and %d characters long.\n", MAX_PASSWORD_LENGTH);
        return 1;
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

    // Calculate password strength
    if (score == 0) {
        printf("Very Weak\n");
    } else if (score == 1) {
        printf("Weak\n");
    } else if (score == 2) {
        printf("Moderate\n");
    } else if (score == 3) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }

    return 0;
}