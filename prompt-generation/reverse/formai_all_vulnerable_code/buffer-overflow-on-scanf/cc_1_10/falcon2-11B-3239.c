//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    char *ptr = password;
    int i;
    int numUpper = 0;
    int numLower = 0;
    int numDigits = 0;
    int numSpecial = 0;
    int numLength = 0;
    int totalStrength = 0;

    // Prompt user for password
    printf("Enter your password: ");
    scanf("%s", password);

    // Check length of password
    if (strlen(password) < 8) {
        printf("Password length must be at least 8 characters.\n");
        return 0;
    }

    // Check for uppercase letters
    for (i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            numUpper++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            numLower++;
        }
    }

    // Check for digits
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            numDigits++;
        }
    }

    // Check for special characters
    for (i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            numSpecial++;
        }
    }

    // Calculate total strength
    numLength = strlen(password);
    totalStrength = numUpper * 2 + numLower * 1 + numDigits * 1 + numSpecial * 1 + numLength * 1;

    // Display strength
    printf("Password strength: %d\n", totalStrength);

    return 0;
}