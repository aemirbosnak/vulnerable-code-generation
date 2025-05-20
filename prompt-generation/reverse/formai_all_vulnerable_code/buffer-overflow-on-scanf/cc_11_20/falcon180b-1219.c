//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length;
    int upper, lower, digit, special;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    upper = lower = digit = special = 0;

    // Check for uppercase letters
    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            upper = 1;
            break;
        }
    }

    // Check for lowercase letters
    for(int i=0; i<length; i++) {
        if(islower(password[i])) {
            lower = 1;
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
    int strength = 0;
    if(length >= 8) {
        strength += 1;
    }
    if(upper) {
        strength += 1;
    }
    if(lower) {
        strength += 1;
    }
    if(digit) {
        strength += 1;
    }
    if(special) {
        strength += 1;
    }

    printf("Password strength: %d\n", strength);

    return 0;
}