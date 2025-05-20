//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

typedef enum {
    WEAK,
    MEDIUM,
    STRONG
} PasswordStrength;

int hasUppercase(const char *password) {
    while (*password) {
        if (isupper(*password)) return 1;
        password++;
    }
    return 0;
}

int hasLowercase(const char *password) {
    while (*password) {
        if (islower(*password)) return 1;
        password++;
    }
    return 0;
}

int hasDigit(const char *password) {
    while (*password) {
        if (isdigit(*password)) return 1;
        password++;
    }
    return 0;
}

int hasSpecialChar(const char *password) {
    const char *specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?/";
    while (*password) {
        if (strchr(specialChars, *password)) return 1;
        password++;
    }
    return 0;
}

PasswordStrength checkPasswordStrength(const char *password) {
    int length = strlen(password);
    
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Password must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        return WEAK;
    }
    
    int hasUpper = hasUppercase(password);
    int hasLower = hasLowercase(password);
    int hasNum = hasDigit(password);
    int hasSpecial = hasSpecialChar(password);
    
    if (hasUpper + hasLower + hasNum + hasSpecial == 4) {
        return STRONG;
    }
    if ((hasUpper + hasLower + hasNum + hasSpecial == 3) || 
        (length >= 12 && (hasUpper || hasLower || hasNum || hasSpecial))) {
        return MEDIUM;
    }
    return WEAK;
}

void printStrength(PasswordStrength strength) {
    switch (strength) {
        case WEAK:
            printf("Password Strength: WEAK\n");
            break;
        case MEDIUM:
            printf("Password Strength: MEDIUM\n");
            break;
        case STRONG:
            printf("Password Strength: STRONG\n");
            break;
        default:
            printf("Password Strength: UNKNOWN\n");
            break;
    }
}

void getPasswordAndCheckStrength() {
    char password[100];
    
    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    
    // Remove newline character if present
    password[strcspn(password, "\n")] = '\0';

    PasswordStrength strength = checkPasswordStrength(password);
    printStrength(strength);
}

int main() {
    printf("Welcome to the Password Strength Checker!\n");
    
    while (1) {
        getPasswordAndCheckStrength();
        char choice;

        printf("Do you want to check another password? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); // Clear the input buffer

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    printf("Thank you for using the Password Strength Checker. Goodbye!\n");
    return 0;
}