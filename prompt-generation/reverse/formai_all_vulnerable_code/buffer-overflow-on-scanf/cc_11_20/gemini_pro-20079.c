//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

// Function to check if the password is strong
int check_password_strength(char *password)
{
    int strength = 0;

    // Check the length of the password
    if (strlen(password) >= MIN_LENGTH) {
        strength++;
    }

    // Check if the password contains at least one uppercase letter
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }
    if (has_uppercase) {
        strength++;
    }

    // Check if the password contains at least one lowercase letter
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }
    if (has_lowercase) {
        strength++;
    }

    // Check if the password contains at least one digit
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
            break;
        }
    }
    if (has_digit) {
        strength++;
    }

    // Check if the password contains at least one special character
    int has_special_character = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            has_special_character = 1;
            break;
        }
    }
    if (has_special_character) {
        strength++;
    }

    // Return the strength of the password
    return strength;
}

// Main function
int main()
{
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the strength of the password
    printf("The strength of your password is: %d\n", strength);

    return 0;
}