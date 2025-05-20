//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: multiplayer
#include <stdio.h>
#include <string.h>

// Function to check if a given character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a given character is a letter
int isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a given character is a symbol
int isSymbol(char c) {
    return (!(isDigit(c)) && !(isLetter(c)));
}

// Function to calculate the strength of a password
int calculateStrength(char password[]) {
    int length = strlen(password);
    int strength = 0;
    
    // Check the length of the password
    if (length < 8) {
        strength -= 5;
    }
    else if (length >= 8 && length < 10) {
        strength += 5;
    }
    else {
        strength += 10;
    }
    
    // Check if the password contains at least one uppercase letter
    int hasUppercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }
    if (hasUppercase) {
        strength += 5;
    }
    else {
        strength -= 5;
    }
    
    // Check if the password contains at least one lowercase letter
    int hasLowercase = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }
    if (hasLowercase) {
        strength += 5;
    }
    else {
        strength -= 5;
    }
    
    // Check if the password contains at least one digit
    int hasDigit = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }
    if (hasDigit) {
        strength += 5;
    }
    else {
        strength -= 5;
    }
    
    // Check if the password contains at least one symbol
    int hasSymbol = 0;
    for (int i = 0; i < length; i++) {
        if (!(isDigit(password[i])) && !(isLetter(password[i]))) {
            hasSymbol = 1;
            break;
        }
    }
    if (hasSymbol) {
        strength += 5;
    }
    else {
        strength -= 5;
    }
    
    return strength;
}

/* Main function */
int main() {
    char password[50];
    int strength;
    
    while (1) {
        // Get the password from the user
        printf("\nEnter password: ");
        scanf("%s", password);
        
        // Calculate the strength of the password
        strength = calculateStrength(password);
        
        // Display the strength of the password
        if (strength < 0) {
            printf("\nPassword strength: WEAK\n");
        }
        else if (strength >=0 && strength < 15) {
            printf("\nPassword strength: MEDIUM\n");
        }
        else {
            printf("\nPassword strength: STRONG\n");
        }
    }
    return 0;
}