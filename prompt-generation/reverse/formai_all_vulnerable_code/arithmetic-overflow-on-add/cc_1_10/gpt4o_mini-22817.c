//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL "!"

void generatePassword(int length, char *password) {
    const char *characters = LOWERCASE UPPERCASE DIGITS SPECIAL;
    int totalCharacters = strlen(characters);
    
    if (length < 4) {
        printf("Password length should be at least 4 characters.\n");
        return;
    }

    // Ensure at least one character from each category is included
    password[0] = LOWERCASE[rand() % strlen(LOWERCASE)];
    password[1] = UPPERCASE[rand() % strlen(UPPERCASE)];
    password[2] = DIGITS[rand() % strlen(DIGITS)];
    password[3] = SPECIAL[rand() % strlen(SPECIAL)];

    // Fill the rest of the password
    for (int i = 4; i < length; i++) {
        password[i] = characters[rand() % totalCharacters];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Terminate the string
    password[length] = '\0';
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    int length;
    printf("Enter desired password length (minimum 4): ");
    scanf("%d", &length);

    char *password = (char *)malloc((length + 1) * sizeof(char)); // +1 for null terminator
    if (password == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit with an error code
    }

    generatePassword(length, password);
    printf("Generated Secure Password: %s\n", password);

    // Free allocated memory
    free(password);
    return 0;
}