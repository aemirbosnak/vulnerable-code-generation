//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the minimum and maximum password lengths
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// Define the character classes for the password
#define CHARACTER_CLASS_LOWER 0x01
#define CHARACTER_CLASS_UPPER 0x02
#define CHARACTER_CLASS_DIGIT 0x04
#define CHARACTER_CLASS_SPECIAL 0x08

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Function to check if a character is in a given character class
int character_in_class(char character, int character_class) {
    switch (character_class) {
        case CHARACTER_CLASS_LOWER:
            return islower(character);
        case CHARACTER_CLASS_UPPER:
            return isupper(character);
        case CHARACTER_CLASS_DIGIT:
            return isdigit(character);
        case CHARACTER_CLASS_SPECIAL:
            return ispunct(character);
        default:
            return 0;
    }
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int password_strength = PASSWORD_STRENGTH_WEAK;
    int character_classes = 0;

    // Check the length of the password
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }

    // Check the character classes of the password
    for (int i = 0; i < strlen(password); i++) {
        if (character_in_class(password[i], CHARACTER_CLASS_LOWER)) {
            character_classes |= CHARACTER_CLASS_LOWER;
        } else if (character_in_class(password[i], CHARACTER_CLASS_UPPER)) {
            character_classes |= CHARACTER_CLASS_UPPER;
        } else if (character_in_class(password[i], CHARACTER_CLASS_DIGIT)) {
            character_classes |= CHARACTER_CLASS_DIGIT;
        } else if (character_in_class(password[i], CHARACTER_CLASS_SPECIAL)) {
            character_classes |= CHARACTER_CLASS_SPECIAL;
        }
    }

    // Check the number of character classes in the password
    if (character_classes == 1) {
        password_strength = PASSWORD_STRENGTH_WEAK;
    } else if (character_classes == 2) {
        password_strength = PASSWORD_STRENGTH_MEDIUM;
    } else if (character_classes >= 3) {
        password_strength = PASSWORD_STRENGTH_STRONG;
    }

    return password_strength;
}

// Function to generate a random password
char *generate_random_password(int length) {
    // Define the character set for the password
    char character_set[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";

    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = character_set[rand() % strlen(character_set)];
    }

    // Null-terminate the password
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password
    int password_strength = check_password_strength(password);

    // Print the password strength
    switch (password_strength) {
        case PASSWORD_STRENGTH_WEAK:
            printf("The password is weak.\n");
            break;
        case PASSWORD_STRENGTH_MEDIUM:
            printf("The password is medium.\n");
            break;
        case PASSWORD_STRENGTH_STRONG:
            printf("The password is strong.\n");
            break;
    }

    // Generate a random password
    char *random_password = generate_random_password(16);

    // Print the random password
    printf("A random password: %s\n", random_password);

    // Free the memory allocated for the random password
    free(random_password);

    return 0;
}