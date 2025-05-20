//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    // Set up variables
    int pwdLength = 0;
    char* password;
    char* characterSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=";

    // Input prompt for password length
    printf("How many characters would you like your password to be? (8-64)\n");
    scanf("%d", &pwdLength);

    // Check for valid input
    if (pwdLength < 8 || pwdLength > 64) {
        printf("Invalid input. Password length must be between 8 and 64 characters.\n");
        return 1;
    }

    // Allocate memory for password
    password = (char*)malloc(sizeof(char) * (pwdLength + 1));

    // Set up random number generator based on time
    srand((unsigned)time(NULL));

    // Generate password character by character
    for (int i = 0; i < pwdLength; i++) {
        int randomIndex = rand() % strlen(characterSet);
        password[i] = characterSet[randomIndex];
    }

    // Add null terminator at end of password string
    password[pwdLength] = '\0';

    // Check that password meets requirements
    int hasLowercase = 0;
    int hasUppercase = 0;
    int hasNumber = 0;
    int hasSpecial = 0;

    for (int i = 0; i < pwdLength; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (isdigit(password[i])) {
            hasNumber = 1;
        } else if (!isalnum(password[i])) {
            hasSpecial = 1;
        }
    }

    // Add missing characters to password
    if (!hasLowercase) {
        int randomIndex = rand() % 26;
        password[rand() % pwdLength] = 'a' + randomIndex;
    }
    if (!hasUppercase) {
        int randomIndex = rand() % 26;
        password[rand() % pwdLength] = 'A' + randomIndex;
    }
    if (!hasNumber) {
        int randomIndex = rand() % 10;
        password[rand() % pwdLength] = '0' + randomIndex;
    }
    if (!hasSpecial) {
        int randomIndex = rand() % 20;
        password[rand() % pwdLength] = "!@#$%^&*()_+-="[randomIndex];
    }

    // Print password to console
    printf("Your secure password is: %s\n", password);

    // Free memory allocated to password
    free(password);

    return 0;
}