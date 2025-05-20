//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASS_LENGTH 8
#define MAX_PASS_LENGTH 20

int check_password_strength(char *password);

int main() {
    char password[MAX_PASS_LENGTH + 1]; // Extra byte for null character
    printf("Enter a password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);
    switch (strength) {
        case 0:
            printf("Weak password.\n");
            break;
        case 1:
            printf("Moderate password.\n");
            break;
        case 2:
            printf("Strong password.\n");
            break;
        default:
            printf("Invalid password.\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password) {
    int length = strlen(password);

    // Length check
    if (length < MIN_PASS_LENGTH || length > MAX_PASS_LENGTH) {
        return -1;
    }

    int score = 0;

    // Uppercase letter check
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            score++;
            break;
        }
    }

    // Lowercase letter check
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            score++;
            break;
        }
    }

    // Digit check
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            score++;
            break;
        }
    }

    // Symbol check
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            score++;
            break;
        }
    }

    if (score < 2) {
        return 0; // Weak password
    } else if (score == 2) {
        return 1; // Moderate password
    } else {
        return 2; // Strong password
    }
}