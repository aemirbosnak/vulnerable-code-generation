//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

/* Function to count the number of uppercase letters in a string */
int countUppercase(char* str) {
    int count = 0;
    for(int i=0; i<strlen(str); i++) {
        if(isupper(str[i])) {
            count++;
        }
    }
    return count;
}

/* Function to count the number of lowercase letters in a string */
int countLowercase(char* str) {
    int count = 0;
    for(int i=0; i<strlen(str); i++) {
        if(islower(str[i])) {
            count++;
        }
    }
    return count;
}

/* Function to count the number of digits in a string */
int countDigits(char* str) {
    int count = 0;
    for(int i=0; i<strlen(str); i++) {
        if(isdigit(str[i])) {
            count++;
        }
    }
    return count;
}

/* Function to count the number of special characters in a string */
int countSpecialCharacters(char* str) {
    int count = 0;
    for(int i=0; i<strlen(str); i++) {
        if(!isalnum(str[i])) {
            count++;
        }
    }
    return count;
}

/* Function to check the strength of a password */
int checkPasswordStrength(char* password) {
    int strength = 0;

    /* Check for uppercase letters */
    if(countUppercase(password) > 0) {
        strength++;
    }

    /* Check for lowercase letters */
    if(countLowercase(password) > 0) {
        strength++;
    }

    /* Check for digits */
    if(countDigits(password) > 0) {
        strength++;
    }

    /* Check for special characters */
    if(countSpecialCharacters(password) > 0) {
        strength++;
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    /* Check the strength of the password */
    int strength = checkPasswordStrength(password);

    if(strength == 0) {
        printf("Weak password\n");
    }
    else if(strength == 1) {
        printf("Moderate password\n");
    }
    else if(strength == 2) {
        printf("Strong password\n");
    }
    else {
        printf("Very strong password\n");
    }

    return 0;
}