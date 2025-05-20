//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()";

// Get random number within a range
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Generate a random character from a given character set
char get_random_character(char* character_set) {
    int index = get_random_number(0, strlen(character_set) - 1);
    return character_set[index];
}

// Generate a random password
char* generate_password(int length) {
    char* password = malloc(length + 1); // Allocate memory for the password

    // Generate a random character for each position in the password
    for (int i = 0; i < length; i++) {
        int character_set_index = get_random_number(0, 3); // Choose a random character set

        switch (character_set_index) {
            case 0:
                password[i] = get_random_character(lowercase);
                break;
            case 1:
                password[i] = get_random_character(uppercase);
                break;
            case 2:
                password[i] = get_random_character(digits);
                break;
            case 3:
                password[i] = get_random_character(symbols);
                break;
        }
    }

    password[length] = '\0'; // Terminate the password with a null character

    return password;
}

// Main function
int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Get the desired password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate a random password
    char* password = generate_password(length);

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}