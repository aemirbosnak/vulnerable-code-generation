//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
char* generatePassword(int length) {
    char* password = (char*)malloc((length + 1) * sizeof(char));
    srand(time(NULL));  // Seed the random number generator

    for (int i = 0; i < length; i++) {
        char character;

        // Generate a random character
        int random = rand() % 3;
        switch (random) {
            case 0:  // Generate a digit
                character = rand() % 10 + '0';
                break;
            case 1:  // Generate an uppercase letter
                character = rand() % 26 + 'A';
                break;
            case 2:  // Generate a lowercase letter
                character = rand() % 26 + 'a';
                break;
            default:
                character = '!';
        }

        password[i] = character;
    }

    password[length] = '\0';  // Add null terminator

    return password;
}

// Main function
int main() {
    int length;

    printf("Enter the length of the password you want: ");
    scanf("%d", &length);

    // Generate password
    char* password = generatePassword(length);

    printf("Your secured password: %s", password);

    free(password);  // Deallocate memory

    return 0;
}