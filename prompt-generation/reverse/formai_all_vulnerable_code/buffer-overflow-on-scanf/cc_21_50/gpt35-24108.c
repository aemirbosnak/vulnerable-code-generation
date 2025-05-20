//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: happy
#include<stdio.h>
#include<string.h>

// Global variable declaration
char password[100];

// Function to check password strength
void checkPasswordStrength() {
    int length, lowerCase = 0, upperCase = 0, digit = 0, specialChar = 0, i;
    length = strlen(password);

    // Check for lower case letters
    for (i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowerCase = 1;
            break;
        }
    }

    // Check for upper case letters
    for (i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upperCase = 1;
            break;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~')) {
            specialChar = 1;
            break;
        }
    }

    // Check for digits
    for (i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digit = 1;
            break;
        }
    }

    // Finally, check the password strength
    if (lowerCase && upperCase && specialChar && digit && (length >= 8)) {
        printf("Congrats! Your Password '%s' is a strong password. Keep it safe!\n", password);
    } else if ((!lowerCase || !upperCase) && specialChar && digit && (length >= 8)) {
        printf("Your Password '%s' has mixed-case letters missing. Please change.\n", password);
    } else if (lowerCase && upperCase && !specialChar && digit && (length >= 8)) {
        printf("Please add at least one special character to your Password '%s'.\n", password);
    } else if (lowerCase && upperCase && specialChar && !digit && (length >= 8)) {
        printf("Please add at least one digit(0-9) to your Password '%s'.\n", password);
    } else if ((lowerCase || upperCase || specialChar || digit) && (length >= 8)) {
        printf("Your Password '%s' is near-strong. Please improve by adding more criteria like uppercase/lowercase letters, digits, and special characters.\n", password);
    } else {
        printf("Your Password '%s' is too weak. Please choose a new password containing at least 8 characters(longer passwords are better), uppercase/lowercase letters, digits, and special characters.\n", password);
    }
}

int main() {
    printf("Welcome! I am your Password Strength Checker. Let's check how secure your password is. Enter your password:\n");
    scanf("%s", password);

    // Checking the password strength
    checkPasswordStrength();

    return 0;
}