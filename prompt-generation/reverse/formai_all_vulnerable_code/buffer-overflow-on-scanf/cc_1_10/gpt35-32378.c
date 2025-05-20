//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>

// Function prototypes
int countDigits(char password[], int n);
int countUppercase(char password[], int n);
int countLowercase(char password[], int n);
int countSpecial(char password[], int n);

int main() {
    // Configurable parameters
    int minLen = 6;
    int minDigits = 1;
    int minUppercase = 1;
    int minLowercase = 1;
    int minSpecial = 1;
    
    // User input
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);
    int n = strlen(password);
    
    // Check password length
    if (n < minLen) {
        printf("Your password is too short\n");
        printf("Password should be at least %d characters long\n", minLen);
        return 1;
    }
    
    // Check number of digits
    if (countDigits(password, n) < minDigits) {
        printf("Your password is too weak\n");
        printf("Password should contain at least %d digit(s)\n", minDigits);
        return 1;
    }
    
    // Check number of uppercase letters
    if (countUppercase(password, n) < minUppercase) {
        printf("Your password is too weak\n");
        printf("Password should contain at least %d uppercase letter(s)\n", minUppercase);
        return 1;
    }
    
    // Check number of lowercase letters
    if (countLowercase(password, n) < minLowercase) {
        printf("Your password is too weak\n");
        printf("Password should contain at least %d lowercase letter(s)\n", minLowercase);
        return 1;
    }
    
    // Check number of special characters
    if (countSpecial(password, n) < minSpecial) {
        printf("Your password is too weak\n");
        printf("Password should contain at least %d special character(s)\n", minSpecial);
        return 1;
    }
    
    // Password is strong
    printf("Your password is strong\n");
    return 0;
}

// Counts the number of digits in a string
int countDigits(char password[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            count++;
        }
    }
    return count;
}

// Counts the number of uppercase letters in a string
int countUppercase(char password[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            count++;
        }
    }
    return count;
}

// Counts the number of lowercase letters in a string
int countLowercase(char password[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            count++;
        }
    }
    return count;
}

// Counts the number of special characters in a string
int countSpecial(char password[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!(password[i] >= '0' && password[i] <= '9') &&
            !(password[i] >= 'A' && password[i] <= 'Z') &&
            !(password[i] >= 'a' && password[i] <= 'z')) {
            count++;
        }
    }
    return count;
}