//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Character sets for password generation
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char digits[] = "0123456789";
char symbols[] = "!@#$%^&*()<>?/\|";

// Function to generate a random character from a given character set
char generate_random_char(char *charset) {
    int index = rand() % strlen(charset);
    return charset[index];
}

// Function to generate a random password of a given length
char *generate_password(int length) {
    char *password = malloc(length + 1);  // Allocate memory for the password
    for (int i = 0; i < length; i++) {
        // Randomly select a character set and generate a random character from it
        int charset_index = rand() % 4;
        switch (charset_index) {
            case 0:
                password[i] = generate_random_char(lowercase);
                break;
            case 1:
                password[i] = generate_random_char(uppercase);
                break;
            case 2:
                password[i] = generate_random_char(digits);
                break;
            case 3:
                password[i] = generate_random_char(symbols);
                break;
        }
    }
    password[length] = '\0';  // Add null terminator to the end of the password
    return password;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Get password length from user
    int length;
    printf("Enter desired password length: ");
    scanf("%d", &length);

    // Generate and print the password
    char *password = generate_password(length);
    printf("Generated password: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}