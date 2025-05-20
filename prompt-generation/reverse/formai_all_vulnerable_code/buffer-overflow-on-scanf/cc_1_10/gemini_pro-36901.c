//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Alan Turing
/* Alan Turing's Secure Password Generator */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define MIN_LENGTH 8
#define MAX_LENGTH 25
#define NUM_CHARSETS 4
#define CHARSET_SIZE 62

// Charsets
char charsets[NUM_CHARSETS][CHARSET_SIZE] = {
    "abcdefghijklmnopqrstuvwxyz",
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "0123456789",
    "!@#$%^&*()"
};

// Function to generate a random number
int randInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to generate a random character from a charset
char randChar(char *charset) {
    return charset[randInt(0, CHARSET_SIZE - 1)];
}

// Function to generate a random password
char *generatePassword(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        password[i] = randChar(charsets[randInt(0, NUM_CHARSETS - 1)]);
    }
    password[length] = '\0';
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the desired password length from the user
    printf("Enter the desired password length (8-25): ");
    int length;
    scanf("%d", &length);

    // Validate the password length
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length. Please enter a value between 8 and 25.\n");
        return 1;
    }

    // Generate the password
    char *password = generatePassword(length);

    // Print the password to the console
    printf("Your secure password is: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}