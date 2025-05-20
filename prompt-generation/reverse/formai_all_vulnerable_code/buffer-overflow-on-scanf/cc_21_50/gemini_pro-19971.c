//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

int main() {
    // Sherlock Holmes greets the user
    printf("My dear Watson, welcome to my Password Strength Checker.\n");
    printf("Let us investigate the strength of your password.\n");

    // Get the user's password
    char password[101];
    printf("Enter your password, Watson: ");
    scanf("%s", password);

    // Check the length of the password
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Elementary, my dear Watson. Your password is too short. It must be at least %d characters long.\n", MIN_LENGTH);
        return EXIT_FAILURE;
    }

    // Check for uppercase letters
    int hasUppercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }
    if (!hasUppercase) {
        printf("It appears your password lacks any uppercase letters, Watson. Consider adding some for increased security.\n");
    }

    // Check for lowercase letters
    int hasLowercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }
    if (!hasLowercase) {
        printf("Curious, Watson. Your password seems to be missing lowercase letters. Including them would enhance its strength.\n");
    }

    // Check for digits
    int hasDigit = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }
    if (!hasDigit) {
        printf("Remarkable, Watson. Your password lacks any digits. Adding a few would make it more robust.\n");
    }

    // Check for special characters
    int hasSpecial = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] < 'A' || password[i] > 'z' || (password[i] >= 'a' && password[i] <= 'z')) {
            hasSpecial = 1;
            break;
        }
    }
    if (!hasSpecial) {
        printf("Fascinating, Watson. Your password contains no special characters. Consider using some, such as !@#$%^&*()-=+[]{}|\\;:\"<>,./?~.\n");
    }

    // Calculate the password strength
    int strength = 0;
    if (length >= MIN_LENGTH) {
        strength++;
    }
    if (hasUppercase) {
        strength++;
    }
    if (hasLowercase) {
        strength++;
    }
    if (hasDigit) {
        strength++;
    }
    if (hasSpecial) {
        strength++;
    }

    // Print the password strength
    switch (strength) {
        case 1:
            printf("Your password is very weak, my dear Watson. I suggest you strengthen it immediately.\n");
            break;
        case 2:
            printf("Your password is weak, Watson. It could be easily cracked by a determined attacker.\n");
            break;
        case 3:
            printf("Your password is fairly strong, Watson. However, it could still be improved.\n");
            break;
        case 4:
            printf("Your password is strong, Watson. It would be difficult for an attacker to crack it.\n");
            break;
        case 5:
            printf("Your password is excellent, Watson. It is highly unlikely that an attacker would be able to crack it.\n");
            break;
    }

    // Bid farewell to the user
    printf("Thank you for using my Password Strength Checker, Watson. May your passwords always be strong and secure.\n");

    return EXIT_SUCCESS;
}