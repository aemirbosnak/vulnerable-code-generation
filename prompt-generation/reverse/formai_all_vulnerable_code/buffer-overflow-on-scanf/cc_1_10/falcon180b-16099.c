//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isValidPassword(char *password) {
    // Check password length
    if (strlen(password) < 8) {
        printf("Password must be at least 8 characters long.\n");
        return false;
    }
    
    // Check for uppercase letter
    if (!isupper(password[0])) {
        printf("Password must contain at least one uppercase letter.\n");
        return false;
    }
    
    // Check for lowercase letter
    if (!islower(password[0])) {
        printf("Password must contain at least one lowercase letter.\n");
        return false;
    }
    
    // Check for digit
    if (!isdigit(password[0])) {
        printf("Password must contain at least one digit.\n");
        return false;
    }
    
    // Check for special character
    if (!strchr("!@#$%^&*()_+-=[]{}|;:,.<>?", password)) {
        printf("Password must contain at least one special character.\n");
        return false;
    }
    
    return true;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);
    
    if (isValidPassword(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
    
    return 0;
}