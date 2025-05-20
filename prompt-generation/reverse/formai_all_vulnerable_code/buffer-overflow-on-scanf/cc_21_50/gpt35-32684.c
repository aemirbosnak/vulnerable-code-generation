//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Alan Touring
// C Password Strength Checker
// By AI Chatbot in the style of Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    printf("\nWelcome to the Password Strength Checker!");

    char password[100];
    int length, upper, lower, digit, special;
    int i, strength = 0;

    // Get password from user
    printf("\nEnter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check password length
    if(length < 8) {
        printf("\nPassword too short! Strength score = %d", strength);
        return 0;
    } else {
        strength += length * 4;
    }

    // Check for upper case letters
    for(i = 0; i < length; i++) {
        if(isupper(password[i])) {
            upper = 1;
            break;
        }
    }
    if(upper == 1) {
        strength += 5;
    } else {
        printf("\nPassword must contain at least one upper case letter! Strength score = %d", strength);
        return 0;
    }

    // Check for lower case letters
    for(i = 0; i < length; i++) {
        if(islower(password[i])) {
            lower = 1;
            break;
        }
    }
    if(lower == 1) {
        strength += 5;
    } else {
        printf("\nPassword must contain at least one lower case letter! Strength score = %d", strength);
        return 0;
    }

    // Check for digits
    for(i = 0; i < length; i++) {
        if(isdigit(password[i])) {
            digit = 1;
            break;
        }
    }
    if(digit == 1) {
        strength += 5;
    } else {
        printf("\nPassword must contain at least one digit! Strength score = %d", strength);
        return 0;
    }

    // Check for special characters
    for(i = 0; i < length; i++) {
        if(!isalnum(password[i])) {
            special = 1;
            break;
        }
    }
    if(special == 1) {
        strength += 5;
    } else {
        printf("\nPassword must contain at least one special character! Strength score = %d", strength);
        return 0;
    }

    // Check for consecutive upper case letters
    for(i = 0; i < length - 1; i++) {
        if(isupper(password[i]) && isupper(password[i+1])) {
            strength -= 10;
            break;
        }
    }

    // Check for consecutive lower case letters
    for(i = 0; i < length - 1; i++) {
        if(islower(password[i]) && islower(password[i+1])) {
            strength -= 10;
            break;
        }
    }

    // Check for consecutive digits
    for(i = 0; i < length - 1; i++) {
        if(isdigit(password[i]) && isdigit(password[i+1])) {
            strength -= 10;
            break;
        }
    }

    // Print strength score
    if(strength < 20) {
        printf("\nWeak password! Strength score = %d", strength);
    } else if(strength >= 20 && strength < 40) {
        printf("\nModerate password! Strength score = %d", strength);
    } else if(strength >= 40 && strength < 60) {
        printf("\nStrong password! Strength score = %d", strength);
    } else if(strength >= 60) {
        printf("\nVery strong password! Strength score = %d", strength);
    }

    return 0;
}