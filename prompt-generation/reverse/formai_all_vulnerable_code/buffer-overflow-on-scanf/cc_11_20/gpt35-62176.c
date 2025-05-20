//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Declare variables
    char password[50];
    int i;
    int length;
    int hasCapital = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecial = 0;

    // Get user input
    printf("Please enter a password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check password characters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasCapital = 1;
        }
        else if (islower(password[i])) {
            hasLowercase = 1;
        }
        else if (isdigit(password[i])) {
            hasNumber = 1;
        }
        else {
            hasSpecial = 1;
        }
    }

    // Check password strength
    if (hasCapital && hasLowercase && hasNumber && hasSpecial) {
        printf("Strong password!\n");
    }
    else if (hasCapital && hasLowercase && hasNumber) {
        printf("Medium password.\n");
    }
    else {
        printf("Weak password.\n");
    }

    return 0;
}