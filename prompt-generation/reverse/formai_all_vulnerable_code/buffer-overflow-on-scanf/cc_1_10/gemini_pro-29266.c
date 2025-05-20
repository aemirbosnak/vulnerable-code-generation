//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char generate_random_char() {
    int random_number = rand() % 94 + 33;
    return (char)random_number;
}

// Function to generate a random digit
char generate_random_digit() {
    int random_number = rand() % 10 + 48;
    return (char)random_number;
}

// Function to generate a random symbol
char generate_random_symbol() {
    int random_number = rand() % 15 + 33;
    return (char)random_number;
}

// Function to generate a random password
char *generate_random_password(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int random_type = rand() % 3;
        switch (random_type) {
            case 0:
                password[i] = generate_random_char();
                break;
            case 1:
                password[i] = generate_random_digit();
                break;
            case 2:
                password[i] = generate_random_symbol();
                break;
        }
    }
    password[length] = '\0';
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int length;
    printf("Enter the length of the password you want to generate: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generate_random_password(length);

    // Print the generated password
    printf("Your generated password is: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}