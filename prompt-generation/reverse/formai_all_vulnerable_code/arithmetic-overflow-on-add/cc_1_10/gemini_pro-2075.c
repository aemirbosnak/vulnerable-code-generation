//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()_+=-`~?/<>";

// Function to generate a random number between min and max
int random_int(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate a random character from a given string
char random_char(char *str) {
    return str[random_int(0, strlen(str) - 1)];
}

// Function to generate a random password of a given length
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate a random character from each character set
    password[0] = random_char(lowercase);
    password[1] = random_char(uppercase);
    password[2] = random_char(numbers);
    password[3] = random_char(symbols);

    // Generate the remaining characters randomly
    for (int i = 4; i < length; i++) {
        password[i] = random_char(lowercase);
        password[i + 1] = random_char(uppercase);
        password[i + 2] = random_char(numbers);
        password[i + 3] = random_char(symbols);
        i += 3;
    }

    // Terminate the string
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Generate the password
    char *password = generate_password(length);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}