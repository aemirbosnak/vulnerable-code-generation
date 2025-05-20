//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Alan Touring
//Welcome to the C Password Strength Checker program!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

//Function to check if the password contains at least one uppercase letter
bool hasUppercase(char password[]) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

//Function to check if the password contains at least one lowercase letter
bool hasLowercase(char password[]) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

//Function to check if the password contains at least one digit
bool hasDigit(char password[]) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

//Function to check if the password contains at least one special character
bool hasSpecial(char password[]) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (ispunct(password[i])) {
            return true;
        }
    }
    return false;
}

//Main function
int main() {
    char password[50];
    int length, strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    //Check length
    if (length >= 8) {
        strength++;
    }

    //Check uppercase letters
    if (hasUppercase(password)) {
        strength++;
    }

    //Check lowercase letters
    if (hasLowercase(password)) {
        strength++;
    }

    //Check digits
    if (hasDigit(password)) {
        strength++;
    }

    //Check special characters
    if (hasSpecial(password)) {
        strength++;
    }

    //Print strength of password
    if (strength == 5) {
        printf("Password strength: Very Strong");
    } else if (strength == 4) {
        printf("Password strength: Strong");
    } else if (strength == 3) {
        printf("Password strength: Moderate");
    } else if (strength == 2) {
        printf("Password strength: Weak");
    } else {
        printf("Password strength: Very Weak");
    }

    return 0;
}