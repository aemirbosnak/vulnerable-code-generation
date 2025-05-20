//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 128

// Define the character classes
#define CHAR_CLASS_LOWERCASE 0
#define CHAR_CLASS_UPPERCASE 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SPECIAL 3

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password strength messages
const char *PASSWORD_STRENGTH_MESSAGES[] = {
    "Weak",
    "Medium",
    "Strong"
};

// Function to check if a character is lowercase
int is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is uppercase
int is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int is_special(char c) {
    return !is_lowercase(c) && !is_uppercase(c) && !is_digit(c);
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int length = strlen(password);
    
    // Check if the password is long enough
    if (length < MIN_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }
    
    // Check if the password is too long
    if (length > MAX_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }
    
    // Check if the password contains at least one lowercase character
    int has_lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (is_lowercase(password[i])) {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        return PASSWORD_STRENGTH_WEAK;
    }
    
    // Check if the password contains at least one uppercase character
    int has_uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (is_uppercase(password[i])) {
            has_uppercase = 1;
            break;
        }
}
if (!has_uppercase) {
return PASSWORD_STRENGTH_WEAK;
}
int has_digit = 0;
for (int i = 0; i < length; i++) {
if (is_digit(password[i])) {
has_digit = 1;
break;
}
}
if (!has_digit) {
return PASSWORD_STRENGTH_WEAK;
}

int has_special = 0;
for (int i = 0; i < length; i++) {
if (is_special(password[i])) {
has_special = 1;
break;
}
}
if (!has_special) {
return PASSWORD_STRENGTH_WEAK;
}

return PASSWORD_STRENGTH_STRONG;
}

int main() {
char password[MAX_PASSWORD_LENGTH + 1];

printf("Enter a password: ");
gets(password);

int strength = check_password_strength(password);
printf("Password strength: %s\n", PASSWORD_STRENGTH_MESSAGES[strength]);

return 0;
}