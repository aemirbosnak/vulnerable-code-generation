//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Donald Knuth
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Function to count the number of characters in the password
int count_characters(char* password) {
    int count = 0;
    for(int i = 0; password[i] != '\0'; i++) {
        count++;
    }
    return count;
}

// Function to check if the password contains at least one uppercase letter
bool has_uppercase_letter(char* password) {
    for(int i = 0; password[i] != '\0'; i++) 
        if(isupper(password[i]))
            return true;
    return false;
}

// Function to check if the password contains at least one lowercase letter
bool has_lowercase_letter(char* password) {
    for(int i = 0; password[i] != '\0'; i++) 
        if(islower(password[i]))
            return true;
    return false;
}

// Function to check if the password contains at least one digit
bool has_digit(char* password) {
    for(int i = 0; password[i] != '\0'; i++) 
        if(isdigit(password[i]))
            return true;
    return false;
}

// Function to check if the password contains at least one special character
bool has_special_character(char* password) {
    for(int i = 0; password[i] != '\0'; i++) 
        if(!isalnum(password[i]))
            return true;
    return false;
}

// Function to return the password strength
int get_strength(char* password) {
    int password_length = count_characters(password);
    int strength = 0;

    if(password_length >= 8) 
        strength += 1;
    if(has_uppercase_letter(password)) 
        strength += 1;
    if(has_lowercase_letter(password)) 
        strength += 1;
    if(has_digit(password)) 
        strength += 1;
    if(has_special_character(password)) 
        strength += 1;

    return strength;
}

// Main function to test the password strength checker
int main() {
    char password[50];

    printf("Enter the password: ");
    scanf("%s", password);

    int strength = get_strength(password);

    switch(strength) {
        case 0: printf("The password is weak.\n");
                break;
        case 1: printf("The password is moderate.\n");
                break;
        case 2: printf("The password is strong.\n");
                break;
        case 3: printf("The password is very strong.\n");
                break;
        case 4: printf("The password is extremely strong.\n");
                break;
        default: printf("Invalid password.\n");
                break;
    }

    return 0;
}