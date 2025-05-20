//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LENGTH 8 // Minimum password length
#define UPPER 1 // At least one uppercase letter
#define LOWER 2 // At least one lowercase letter
#define NUMBER 4 // At least one number
#define SPECIAL 8 // At least one special character

int check_password_strength(char *password);

int main() {
    char password[LENGTH + 1];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    switch(strength) {
        case 0:
            printf("Weak password. Please choose a stronger one.\n");
            break;
        case 1:
            printf("Fair password. It could be stronger.\n");
            break;
        case 2:
            printf("Good password. Keep it up!\n");
            break;
        case 3:
            printf("Excellent password. Well done!\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password) {
    int strength = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    // Check for minimum length
    if(strlen(password) < LENGTH) {
        printf("Password must be at least %d characters long.\n", LENGTH);
        return 0;
    }

    // Check for uppercase letter
    for(int i=0; i<strlen(password); i++) {
        if(isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }
    if(!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Check for lowercase letter
    for(int i=0; i<strlen(password); i++) {
        if(islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }
    if(!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check for number
    for(int i=0; i<strlen(password); i++) {
        if(isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }
    if(!has_number) {
        printf("Password must contain at least one number.\n");
        return 0;
    }

    // Check for special character
    for(int i=0; i<strlen(password); i++) {
        if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*') {
            has_special = 1;
            break;
        }
    }
    if(!has_special) {
        printf("Password must contain at least one special character (!@#$%&*).\n");
        return 0;
    }

    // Calculate password strength
    if(has_uppercase && has_lowercase && has_number && has_special) {
        strength = 3; // Excellent
    } else if(has_uppercase && has_lowercase && has_number) {
        strength = 2; // Good
    } else if(has_uppercase && has_lowercase) {
        strength = 1; // Fair
    } else {
        strength = 0; // Weak
    }

    return strength;
}