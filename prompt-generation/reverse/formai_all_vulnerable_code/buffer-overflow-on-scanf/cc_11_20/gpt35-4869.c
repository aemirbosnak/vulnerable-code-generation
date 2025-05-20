//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASS_LENGTH 25

// Function to check password strength
bool passwordStrengthChecker(char *password)
{
    int length = strlen(password);
    bool hasUpperCase = false, hasLowerCase = false;
    bool hasDigit = false, hasSpecialChar = false;
    int i;

    // Length check
    if (length < 8) {
        printf("Password must have at least 8 characters\n");
        return false;
    }

    // Character check
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpperCase = true;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowerCase = true;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = true;
        }
        else {
            hasSpecialChar = true;
        }
    }

    // Strength check
    if (hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) {
        printf("Strong Password!\n");
        return true;
    }
    else if ((hasUpperCase && hasLowerCase && hasDigit) ||
             (hasUpperCase && hasLowerCase && hasSpecialChar) ||
             (hasLowerCase && hasDigit && hasSpecialChar) ||
             (hasUpperCase && hasDigit && hasSpecialChar)) {
        printf("Moderate Password\n");
        return true;
    }
    else {
        printf("Weak Password! Try another combination.\n");
        return false;
    }
}

int main()
{
    char password[MAX_PASS_LENGTH];
    int i, n;

    printf("Enter the number of players: ");
    scanf("%d", &n);

    // Loop over players and check password strength for each player
    for (i = 1; i <= n; i++) {
        printf("\nPLAYER %d\n", i);
        printf("Enter your password: ");
        scanf("%s", password);
        passwordStrengthChecker(password);
    }

    return 0;
}