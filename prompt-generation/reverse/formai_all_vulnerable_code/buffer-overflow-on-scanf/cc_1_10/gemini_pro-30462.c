//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character set for the password
const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+=-`~";

// Get a random number between min and max
int random_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Generate a random password of a given length
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        int index = random_range(0, strlen(charset) - 1);
        password[i] = charset[index];
    }

    // Terminate the password string
    password[length] = '\0';

    // Return the password
    return password;
}

// Prompt the user for the desired password length
int get_password_length() {
    int length;

    // Get the password length from the user
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Make sure the password length is valid
    while (length < 8 || length > 64) {
        printf("Password length must be between 8 and 64 characters. Try again: ");
        scanf("%d", &length);
    }

    // Return the password length
    return length;
}

// Generate and print a random password
void generate_and_print_password() {
    // Get the password length from the user
    int length = get_password_length();

    // Generate a random password
    char *password = generate_password(length);

    // Print the password
    printf("Your new password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate and print a random password
    generate_and_print_password();

    // Return 0 to indicate successful execution
    return 0;
}