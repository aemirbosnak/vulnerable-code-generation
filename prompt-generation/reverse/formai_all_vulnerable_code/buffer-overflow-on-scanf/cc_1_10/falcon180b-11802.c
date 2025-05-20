//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i])!= tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to check password strength
int checkPasswordStrength(char *password) {
    int len = strlen(password);
    int hasDigit = 0;
    int hasUpper = 0;
    int hasLower = 0;
    int hasSpecial = 0;

    // Check for digit
    for (int i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }

    // Check for uppercase letter
    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < len; i++) {
        if (islower(password[i])) {
            hasLower = 1;
            break;
        }
    }

    // Check for special character
    for (int i = 0; i < len; i++) {
        if (!isalnum(password[i])) {
            hasSpecial = 1;
            break;
        }
    }

    // Check if password is a palindrome
    if (isPalindrome(password)) {
        printf("Password is a palindrome.\n");
    }

    // Check password strength
    int strength = 0;
    if (len >= 8) {
        strength++;
    }
    if (hasDigit) {
        strength++;
    }
    if (hasUpper) {
        strength++;
    }
    if (hasLower) {
        strength++;
    }
    if (hasSpecial) {
        strength++;
    }

    switch (strength) {
        case 0:
            printf("Very Weak\n");
            break;
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Moderate\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very Strong\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    return strength;
}

int main() {
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    int strength = checkPasswordStrength(password);
    return 0;
}