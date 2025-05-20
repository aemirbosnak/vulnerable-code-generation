//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if a character is a letter
bool is_letter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    } else {
        return false;
    }
}

// Function to check if a character is a number
bool is_number(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    } else {
        return false;
    }
}

// Function to check if a character is a special character
bool is_special_char(char c) {
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '-' || c == '+' || c == '=' || c == '^' || c == '_' || c == '~' || c == '|' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ':' || c == '"' || c == '\'' || c == '\\' || c == ',') {
        return true;
    } else {
        return false;
    }
}

// Function to check password strength
void check_password_strength(char* password) {
    int length = strlen(password);
    int num_letters = 0;
    int num_numbers = 0;
    int num_special_chars = 0;

    // Count the number of letters, numbers, and special characters
    for (int i = 0; i < length; i++) {
        if (is_letter(password[i])) {
            num_letters++;
        } else if (is_number(password[i])) {
            num_numbers++;
        } else if (is_special_char(password[i])) {
            num_special_chars++;
        }
    }

    // Print the password strength
    if (num_letters > 0 && num_numbers > 0 && num_special_chars > 0) {
        printf("Password is strong\n");
    } else if (num_letters > 0 && num_numbers > 0) {
        printf("Password is medium\n");
    } else if (num_letters > 0) {
        printf("Password is weak\n");
    } else {
        printf("Password is very weak\n");
    }
}

// Main function
int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    check_password_strength(password);

    return 0;
}