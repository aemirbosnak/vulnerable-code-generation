//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate random integers
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate random uppercase letters
char rand_uppercase() {
    return rand_int(65, 90);
}

// Function to generate random lowercase letters
char rand_lowercase() {
    return rand_int(97, 122);
}

// Function to generate random digits
char rand_digit() {
    return rand_int(48, 57);
}

// Function to generate random symbols
char rand_symbol() {
    char symbols[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?";
    return symbols[rand_int(0, strlen(symbols) - 1)];
}

// Function to generate a secure password with given length
void generate_password(int length) {
    char password[length + 1]; // Leave room for the terminating null character
    password[length] = '\0'; // Set the last character to null

    // Generate random characters for the password
    for (int i = 0; i < length; i++) {
        // Randomly select a character type
        int type = rand_int(0, 3);

        // Generate a random character of the selected type
        if (type == 0) {
            password[i] = rand_uppercase();
        } else if (type == 1) {
            password[i] = rand_lowercase();
        } else if (type == 2) {
            password[i] = rand_digit();
        } else if (type == 3) {
            password[i] = rand_symbol();
        }
    }

    // Print the generated password
    printf("Your secure password is: %s\n", password);
}

int main() {
    // Set the seed for the random number generator
    srand(time(0));

    // Ask the user for the desired length of the password
    printf("How many characters should your password have? ");
    int length;
    scanf("%d", &length);

    // Generate the password
    generate_password(length);

    return 0;
}