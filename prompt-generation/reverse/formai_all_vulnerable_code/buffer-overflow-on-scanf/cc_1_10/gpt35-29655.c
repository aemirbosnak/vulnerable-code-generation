//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 16 // Maximum length of password
#define MIN_LENGTH 8  // Minimum length of password
#define NUM_SPECIAL_CHARS 4 // Number of special characters to include

char generate_random_char() {
    // Generate a random character from ASCII values 32-126 (printable characters)
    return rand() % 95 + 32;
}

void generate_password(int length, char* password) {
    int i;
    int num_special_chars = 0;

    // Initialize password to all zeroes
    for (i = 0; i < length; i++) {
        password[i] = 0;
    }

    // Add random letters and digits
    for (i = 0; i < length - NUM_SPECIAL_CHARS; i++) {
        password[i] = generate_random_char();
    }

    // Add random special characters
    while (num_special_chars < NUM_SPECIAL_CHARS) {
        // Generate a random index between 0 and length-1
        int index = rand() % length;
        // Check if the character at the index is already a special character
        if (!isdigit(password[index]) && !isalpha(password[index])) {
            password[index] = generate_random_char();
            num_special_chars++;
        }
    }
}

int main() {
    printf("C Secure Password Generator\n");
    printf("Enter desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);

    int length;
    scanf("%d", &length);

    // Check if password length is within acceptable range
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid password length!\n");
        return 1;
    }

    // Seed random number generator
    srand(time(NULL));

    // Allocate memory for password
    char* password = (char*) malloc(length * sizeof(char));

    // Generate random password
    generate_password(length, password);

    // Print password
    printf("Your secure password is: %s\n", password);

    // Free memory
    free(password);

    return 0;
}