//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

int hasUppercase(const char *password) {
    while (*password) {
        if (isupper((unsigned char)*password)) {
            return 1; // True
        }
        password++;
    }
    return 0; // False
}

int hasLowercase(const char *password) {
    while (*password) {
        if (islower((unsigned char)*password)) {
            return 1; // True
        }
        password++;
    }
    return 0; // False
}

int hasDigit(const char *password) {
    while (*password) {
        if (isdigit((unsigned char)*password)) {
            return 1; // True
        }
        password++;
    }
    return 0; // False
}

int hasSpecialChar(const char *password) {
    char specialChars[] = "!@#$%^&*()-_=+[]{};:'\",.<>?/`~";
    while (*password) {
        if (strchr(specialChars, *password)) {
            return 1; // True
        }
        password++;
    }
    return 0; // False
}

int isLengthValid(const char *password) {
    int len = strlen(password);
    return (len >= MIN_LENGTH && len <= MAX_LENGTH);
}

const char* checkPasswordStrength(const char *password) {
    if (!isLengthValid(password)) {
        return "Password must be between 8 and 20 characters.";
    }
    if (!hasUppercase(password)) {
        return "Password must contain at least one uppercase letter.";
    }
    if (!hasLowercase(password)) {
        return "Password must contain at least one lowercase letter.";
    }
    if (!hasDigit(password)) {
        return "Password must contain at least one digit.";
    }
    if (!hasSpecialChar(password)) {
        return "Password must contain at least one special character.";
    }
    return "Password is strong!";
}

void promptPassword() {
    char password[1024];
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    
    // Remove newline character from password
    password[strcspn(password, "\n")] = 0;

    const char* result = checkPasswordStrength(password);
    printf("%s\n", result);
}

int main() {
    printf("Welcome to the Password Strength Checker!\n");
    char continueChecking = 'y';
    
    while (continueChecking == 'y' || continueChecking == 'Y') {
        promptPassword();
        printf("Would you like to check another password? (y/n): ");
        scanf(" %c", &continueChecking);
        // Clear the newline character from the buffer
        while(getchar() != '\n');
    }
    
    printf("Thank you for using the Password Strength Checker. Goodbye!\n");
    return 0;
}