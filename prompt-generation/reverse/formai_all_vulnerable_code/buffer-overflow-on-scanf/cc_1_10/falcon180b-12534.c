//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8
#define MIN_LOWER_CASE 1
#define MIN_UPPER_CASE 1
#define MIN_NUMERICAL 1
#define MIN_SPECIAL_CHARACTER 1

// Function to check if the password contains at least one lowercase character
int contains_lower_case(char *password) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one uppercase character
int contains_upper_case(char *password) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one numerical character
int contains_numerical(char *password) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains at least one special character
int contains_special_character(char *password) {
    int i;
    for(i=0; i<strlen(password); i++) {
        if(!isalnum(password[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to check the strength of the password
int check_password_strength(char *password) {
    int lower_case = contains_lower_case(password);
    int upper_case = contains_upper_case(password);
    int numerical = contains_numerical(password);
    int special_character = contains_special_character(password);
    int score = 0;
    if(lower_case) {
        score++;
    }
    if(upper_case) {
        score++;
    }
    if(numerical) {
        score++;
    }
    if(special_character) {
        score++;
    }
    if(score >= 3) {
        return 1; // Strong password
    } else {
        return 0; // Weak password
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int i;

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the length of the password
    password_length = strlen(password);
    if(password_length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check the strength of the password
    if(check_password_strength(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}