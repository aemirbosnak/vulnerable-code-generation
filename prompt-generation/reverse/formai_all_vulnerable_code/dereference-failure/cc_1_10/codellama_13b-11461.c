//Code Llama-13B DATASET v1.0 Category: Secure Password Generator ; Style: modular
/*
 * A modular C Secure Password Generator example program
 * Generates a random password with a given length
 * and includes basic security features
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Function prototypes
void generate_password(int length, char *password);
bool validate_password(char *password);

int main() {
    // Generate a password with a length of 16 characters
    char password[16];
    generate_password(16, password);

    // Validate the password
    if (validate_password(password)) {
        printf("Generated password: %s\n", password);
    } else {
        printf("Generated password is invalid.\n");
    }

    return 0;
}

// Generate a random password with a given length
void generate_password(int length, char *password) {
    // Initialize the random number generator
    srand((unsigned)time(NULL));

    // Generate random characters for the password
    for (int i = 0; i < length; i++) {
        int random_char = rand() % 95 + 33;
        password[i] = (char)random_char;
    }

    // Add a null terminator at the end of the password
    password[length] = '\0';
}

// Validate the password by checking if it is printable and does not contain any whitespace
bool validate_password(char *password) {
    // Check if the password is printable
    if (!isprint(password)) {
        return false;
    }

    // Check if the password contains any whitespace
    if (strchr(password, ' ') != NULL) {
        return false;
    }

    return true;
}