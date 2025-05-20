//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// This program generates a secure password of a given length.

// Function to generate a random number between two numbers.
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character from a string.
char generate_random_character(const char *string) {
    int index = generate_random_number(0, strlen(string) - 1);
    return string[index];
}

// Function to generate a random password of a given length.
char *generate_random_password(int length) {
    // Create an array to store the password.
    char *password = malloc(length + 1);

    // Generate a random character for each position in the password.
    for (int i = 0; i < length; i++) {
        password[i] = generate_random_character("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()");
    }

    // Terminate the password with a null character.
    password[length] = '\0';

    // Return the password.
    return password;
}

// Function to print a password.
void print_password(const char *password) {
    printf("Your password is: %s\n", password);
}

// Main function.
int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Get the length of the password from the user.
    int length;
    printf("Enter the length of the password you want: ");
    scanf("%d", &length);

    // Generate a random password.
    char *password = generate_random_password(length);

    // Print the password.
    print_password(password);

    // Free the memory allocated for the password.
    free(password);

    return 0;
}