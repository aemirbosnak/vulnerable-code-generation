//Code Llama-13B DATASET v1.0 Category: Secure Password Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define PASSWORD_UPPERCASE 4
#define PASSWORD_LOWERCASE 4
#define PASSWORD_DIGITS 4
#define PASSWORD_SPECIAL 4

// Function to generate a random character
char random_char(char *chars, int length) {
    return chars[rand() % length];
}

// Function to generate a random uppercase letter
char random_uppercase() {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return random_char(chars, sizeof(chars) - 1);
}

// Function to generate a random lowercase letter
char random_lowercase() {
    char chars[] = "abcdefghijklmnopqrstuvwxyz";
    return random_char(chars, sizeof(chars) - 1);
}

// Function to generate a random digit
char random_digit() {
    char chars[] = "0123456789";
    return random_char(chars, sizeof(chars) - 1);
}

// Function to generate a random special character
char random_special() {
    char chars[] = "!@#$%^&*()_+-=[]{}|;:,./<>?";
    return random_char(chars, sizeof(chars) - 1);
}

// Function to generate a random password
char *generate_password() {
    char password[PASSWORD_LENGTH + 1];
    int uppercase = PASSWORD_UPPERCASE;
    int lowercase = PASSWORD_LOWERCASE;
    int digits = PASSWORD_DIGITS;
    int special = PASSWORD_SPECIAL;
    int length = PASSWORD_LENGTH;

    // Add uppercase letters
    for (int i = 0; i < uppercase; i++) {
        password[i] = random_uppercase();
    }

    // Add lowercase letters
    for (int i = uppercase; i < uppercase + lowercase; i++) {
        password[i] = random_lowercase();
    }

    // Add digits
    for (int i = uppercase + lowercase; i < uppercase + lowercase + digits; i++) {
        password[i] = random_digit();
    }

    // Add special characters
    for (int i = uppercase + lowercase + digits; i < uppercase + lowercase + digits + special; i++) {
        password[i] = random_special();
    }

    // Add null terminator
    password[length] = '\0';

    return password;
}

int main() {
    srand(time(NULL));

    // Generate and print password
    char *password = generate_password();
    printf("Your password is: %s\n", password);

    return 0;
}