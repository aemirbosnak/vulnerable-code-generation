//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: synchronous
#include<stdio.h>
#include<string.h>

// Function to check the password strength
void passwordStrengthChecker(char password[]) {
    int len = strlen(password);
    int i = 0;
    int upperCount = 0, lowerCount = 0, digitCount = 0, specialCount = 0;

    // Checking conditions
    while(password[i]) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            upperCount++;
        } else if(password[i] >= 'a' && password[i] <= 'z') {
            lowerCount++;
        } else if(password[i] >= '0' && password[i] <= '9') {
            digitCount++;
        } else {
            specialCount++;
        }
        i++;
    }

    // Calculating and printing password strength score
    int strengthScore = 0;
    if(len <= 5) {
        strengthScore += 5;
    } else if(len <= 10) {
        strengthScore += 10;     
    } else {
        strengthScore += 15;
    }
    if(upperCount >= 1) {
        strengthScore += 5;
    }
    if(lowerCount >= 1) {
        strengthScore += 5;
    }
    if(digitCount >= 1) {
        strengthScore += 5;
    }
    if(specialCount >= 1) {
        strengthScore += 5;
    }

    // Final password strength checking
    if(strengthScore <= 25) {
        printf("Password strength: Weak");
    } else if(strengthScore <= 50) {
        printf("Password strength: Medium");
    } else if(strengthScore <= 75) {
        printf("Password strength: Strong");
    } else {
        printf("Password strength: Excellent");
    }
}

int main() {
    // Reading password from user
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);

    // Calling password strength function
    passwordStrengthChecker(password);

    return 0;
}