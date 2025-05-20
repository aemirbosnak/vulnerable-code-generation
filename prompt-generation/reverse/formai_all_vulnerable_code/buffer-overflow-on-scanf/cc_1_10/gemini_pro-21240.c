//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong enough
int check_password_strength(char *password) {
    int strength = 0;

    // Check the length of the password
    if (strlen(password) < 8) {
        strength++;
    }

    // Check if the password contains at least one uppercase letter
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one digit
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one special character
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            strength++;
            break;
        }
    }

    return strength;
}

// Function to generate a random password
char *generate_random_password() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a buffer to store the password
    char *password = malloc(10);

    // Generate a random password
    for (int i = 0; i < 10; i++) {
        password[i] = rand() % 94 + 32;
    }

    // Return the password
    return password;
}

int main() {
    // Get the password from the user
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = check_password_strength(password);

    // Print the strength of the password
    printf("The strength of the password is: %d\n", strength);

    // Generate a random password
    char *random_password = generate_random_password();

    // Print the random password
    printf("A random password is: %s\n", random_password);

    return 0;
}