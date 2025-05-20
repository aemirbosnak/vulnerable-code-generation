//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

// Function to check password strength
int checkPasswordStrength(char* password) {
    // Check for minimum length
    if (strlen(password) < 8) {
        return 0;
    }
    
    // Check for uppercase letters
    int hasUpperCase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpperCase = 1;
            break;
        }
    }
    if (!hasUpperCase) {
        return 0;
    }
    
    // Check for lowercase letters
    int hasLowerCase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowerCase = 1;
            break;
        }
    }
    if (!hasLowerCase) {
        return 0;
    }
    
    // Check for digits
    int hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }
    if (!hasDigit) {
        return 0;
    }
    
    // Check for special characters
    int hasSpecialChar = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '#' || password[i] == '@' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '+' || password[i] == '-' || password[i] == '=' || password[i] == '^' || password[i] == '{' || password[i] == '|' || password[i] == '}' || password[i] == '~') {
            hasSpecialChar = 1;
            break;
        }
    }
    if (!hasSpecialChar) {
        return 0;
    }
    
    // Return password strength
    return 1;
}

int main() {
    // Prompt user for password
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    
    // Check password strength
    int strength = checkPasswordStrength(password);
    if (strength == 0) {
        printf("Weak password\n");
    } else {
        printf("Strong password\n");
    }
    
    return 0;
}