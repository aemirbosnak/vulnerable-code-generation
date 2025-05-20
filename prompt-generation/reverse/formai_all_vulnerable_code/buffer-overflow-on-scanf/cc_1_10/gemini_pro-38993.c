//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define the character sets to use for password generation
    char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char symbols[] = "!@#$%^&*()";

    // Determine the desired length of the password
    int password_length;
    printf("Enter the desired length of the password: ");
    scanf("%d", &password_length);

    // Ensure that the password length is within the valid range
    if (password_length < 1 || password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Please enter a value between 1 and %d.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Create a buffer to store the generated password
    char password[password_length + 1];

    // Generate the password
    for (int i = 0; i < password_length; i++) {
        // Select a random character set
        int character_set_index = rand() % 4;

        // Select a random character from the selected character set
        int character_index;
        switch (character_set_index) {
            case 0:
                character_index = rand() % (sizeof(lowercase_chars) - 1);
                password[i] = lowercase_chars[character_index];
                break;
            case 1:
                character_index = rand() % (sizeof(uppercase_chars) - 1);
                password[i] = uppercase_chars[character_index];
                break;
            case 2:
                character_index = rand() % (sizeof(digits) - 1);
                password[i] = digits[character_index];
                break;
            case 3:
                character_index = rand() % (sizeof(symbols) - 1);
                password[i] = symbols[character_index];
                break;
        }
    }

    // Terminate the password string with a null character
    password[password_length] = '\0';

    // Print the generated password
    printf("Generated password: %s\n", password);

    return 0;
}