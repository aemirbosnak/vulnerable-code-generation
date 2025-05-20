//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: lively
#include<stdio.h>
#include<string.h>

// Function to check if character is digit
int isDigit(char c) {
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

// Function to check if character is alphabet
int isAlphabet(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

// Function to check password strength
int checkPasswordStrength(char password[]) {
    int len = strlen(password), digit_count = 0, alphabet_count = 0;
    for(int i = 0; i < len; i++) {
        if(isDigit(password[i]))
            digit_count++;
        if(isAlphabet(password[i]))
            alphabet_count++;
    }
    if(len < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    else if(digit_count < 2) {
        printf("Password must contain at least 2 digits.\n");
        return 0;
    }
    else if(alphabet_count < 4) {
        printf("Password must contain at least 4 alphabets.\n");
        return 0;
    }
    else {
        printf("Password is strong.\n");
        return 1;
    }
}

int main() {
    char password[50];
    printf("Enter password: ");
    scanf("%s", password);
    if(checkPasswordStrength(password))
        printf("Password is valid.\n");
    else
        printf("Password is invalid.\n");
    return 0;
}