//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define LENGTH_MIN 8
#define LENGTH_MAX 32
#define LOWERCASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-=[]{}|;:,.<>/?"

int main() {
    char password[LENGTH_MAX];
    int length, i, j;
    int lowercase_count = 0;
    int uppercase_count = 0;
    int number_count = 0;
    int special_count = 0;
    int total_count = 0;
    int complexity_score = 0;
    int strength = 0;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check password length
    if(length < LENGTH_MIN) {
        printf("Password is too short.\n");
        return 1;
    }
    if(length > LENGTH_MAX) {
        printf("Password is too long.\n");
        return 1;
    }

    // Check for lowercase letters
    for(i = 0; i < length; i++) {
        if(strchr(LOWERCASE_LETTERS, password[i])!= NULL) {
            lowercase_count++;
        }
    }

    // Check for uppercase letters
    for(i = 0; i < length; i++) {
        if(strchr(UPPERCASE_LETTERS, password[i])!= NULL) {
            uppercase_count++;
        }
    }

    // Check for numbers
    for(i = 0; i < length; i++) {
        if(strchr(NUMBERS, password[i])!= NULL) {
            number_count++;
        }
    }

    // Check for special characters
    for(i = 0; i < length; i++) {
        if(strchr(SPECIAL_CHARS, password[i])!= NULL) {
            special_count++;
        }
    }

    // Calculate total count of characters
    total_count = length - 1;

    // Calculate complexity score
    complexity_score = (int)sqrt(total_count * (total_count + 1) / 2);

    // Calculate password strength
    if(lowercase_count > 0 && uppercase_count > 0 && number_count > 0 && special_count > 0) {
        strength = 4;
    }
    else if(lowercase_count > 0 && uppercase_count > 0 && (number_count > 0 || special_count > 0)) {
        strength = 3;
    }
    else if(lowercase_count > 0 && uppercase_count > 0) {
        strength = 2;
    }
    else if(lowercase_count > 0 || uppercase_count > 0) {
        strength = 1;
    }
    else {
        strength = 0;
    }

    // Print password strength
    printf("Password strength: ");
    if(strength == 0) {
        printf("Very Weak\n");
    }
    else if(strength == 1) {
        printf("Weak\n");
    }
    else if(strength == 2) {
        printf("Moderate\n");
    }
    else if(strength == 3) {
        printf("Strong\n");
    }
    else if(strength == 4) {
        printf("Very Strong\n");
    }

    return 0;
}