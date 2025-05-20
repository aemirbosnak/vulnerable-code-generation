//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIALS "!@#$%^&*()-_=+[]{}|;:,.<>?/"

void generatePassword(int length, char *password) {
    // Ensure there are at least one character from each category
    password[0] = LOWERCASE[rand() % strlen(LOWERCASE)]; // Lowercase
    password[1] = UPPERCASE[rand() % strlen(UPPERCASE)]; // Uppercase
    password[2] = DIGITS[rand() % strlen(DIGITS)];       // Digit
    password[3] = SPECIALS[rand() % strlen(SPECIALS)];   // Special
    
    // Fill the rest of the password with a mix of all categories
    const char *all_characters = LOWERCASE UPPERCASE DIGITS SPECIALS;
    for (int i = 4; i < length; i++) {
        password[i] = all_characters[rand() % strlen(all_characters)];
    }
    
    // Shuffle the password to avoid predictable positions
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        // Swap characters
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    password[length] = '\0'; // Null-terminate the string
}

int main() {
    srand((unsigned int)time(NULL)); // Seed random number generator

    int length;
    printf("Enter the desired length of the password (minimum 8): ");
    scanf("%d", &length);

    // Validate input length
    if (length < 8) {
        printf("Password length must be at least 8 characters.\n");
        return 1;
    }

    char *password = malloc(length + 1); // Allocate memory for the password
    if (password == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    generatePassword(length, password);

    printf("Generated password: %s\n", password);

    free(password); // Free allocated memory
    return 0;
}