//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length;
    int uppercase = 0, lowercase = 0, digit = 0, special = 0;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for uppercase letters
    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for(int i=0; i<length; i++) {
        if(islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for digits
    for(int i=0; i<length; i++) {
        if(isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    // Check for special characters
    for(int i=0; i<length; i++) {
        if(!isalnum(password[i])) {
            special = 1;
            break;
        }
    }

    // Calculate password strength
    if(length < 8) {
        strength = 1;
    }
    else if(length < 12) {
        strength = 2;
    }
    else if(length < 16) {
        strength = 3;
    }
    else {
        strength = 4;
    }

    strength += uppercase;
    strength += lowercase;
    strength += digit;
    strength += special;

    printf("Password strength: ");
    if(strength <= 2) {
        printf("Weak\n");
    }
    else if(strength <= 4) {
        printf("Medium\n");
    }
    else {
        printf("Strong\n");
    }

    return 0;
}