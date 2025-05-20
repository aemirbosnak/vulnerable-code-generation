//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to calculate the strength of a password
int passwordStrength(char *password) {
    int strength = 0;
    int length = strlen(password);

    // Check for minimum length
    if (length < 8) {
        return strength;
    } else {
        strength += 1;
    }

    // Check for uppercase characters
    int upperCount = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upperCount++;
        }
    }
    if (upperCount > 0) {
        strength += 1;
    }

    // Check for lowercase characters
    int lowerCount = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowerCount++;
        }
    }
    if (lowerCount > 0) {
        strength += 1;
    }

    // Check for digits
    int digitCount = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digitCount++;
        }
    }
    if (digitCount > 0) {
        strength += 1;
    }

    // Check for special characters
    int specialCount = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            specialCount++;
        }
    }
    if (specialCount > 0) {
        strength += 1;
    }

    // Check for repeated characters
    int repeatedCount = 0;
    for (int i = 0; i < length - 1; i++) {
        if (password[i] == password[i + 1]) {
            repeatedCount++;
        }
    }
    if (repeatedCount > 0) {
        strength -= 1;
    }

    // Check for common passwords
    char *commonPasswords[] = {"password", "123456", "12345678", "qwerty", "abc123", "iloveyou", "princess", "rockyou", "starwars", "123123", "monkey", "dragon", "superman", "batman", "tigger", "poohbear", "winnie", "tiggertoo", "loveyou", "sweet", "iloveu", "kitty", "puppy", "flower", "buttercup", "sweetie", "honey", "binky", "lucky", "dolly", "angel", "baby", "ilove", "ginger", "johnson", "william", "smith", "brown", "jones", "davis", "martin", "anderson", "taylor", "thomas", "jackson", "white", "harris", "walker", "scott", "green", "adams", "baker"};
    int commonCount = 0;
    for (int i = 0; i < sizeof(commonPasswords) / sizeof(char *); i++) {
        if (strcmp(password, commonPasswords[i]) == 0) {
            commonCount++;
        }
    }
    if (commonCount > 0) {
        strength -= 1;
    }

    return strength;
}

// Main function
int main() {
    char password[100];

    // Get the password from the user
    printf("Enter your password: ");
    gets(password);

    // Calculate the strength of the password
    int strength = passwordStrength(password);

    // Print the strength of the password
    switch (strength) {
        case 0:
            printf("Your password is very weak. Please choose a stronger password.\n");
            break;
        case 1:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
        case 2:
            printf("Your password is moderately strong. Please consider making it stronger.\n");
            break;
        case 3:
            printf("Your password is strong. Good job!\n");
            break;
        case 4:
            printf("Your password is very strong. Excellent job!\n");
            break;
        case 5:
            printf("Your password is extremely strong. Congratulations!\n");
            break;
        default:
            printf("Invalid password strength.\n");
    }

    return 0;
}