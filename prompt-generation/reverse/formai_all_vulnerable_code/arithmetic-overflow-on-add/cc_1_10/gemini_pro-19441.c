//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Welcome the user to the program
void welcome() {
    printf("************************************************************************\n");
    printf("*                           Password Generator                           *\n");
    printf("*----------------------------------------------------------------------*\n");
    printf("* This program will generate a strong and unique password for you.        *\n");
    printf("* Just enter the desired password length, and we'll take care of the rest! *\n");
    printf("************************************************************************\n\n");
}

// Get the password length from the user
int get_length() {
    int length;
    printf("Enter the desired password length (minimum 8 characters): ");
    scanf("%d", &length);
    while (length < 8) {
        printf("Password must be at least 8 characters long. Please try again: ");
        scanf("%d", &length);
    }
    return length;
}

// Generate a random character
char generate_character() {
    int random = rand() % 94 + 33;
    while ((random >= 48 && random <= 57) || (random >= 65 && random <= 90) || (random >= 97 && random <= 122)) {
        random = rand() % 94 + 33;
    }
    return (char) random;
}

// Generate a random password
char *generate_password(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        password[i] = generate_character();
    }
    password[length] = '\0';
    return password;
}

// Display the generated password
void display_password(char *password) {
    printf("Your generated password is: %s\n", password);
}

// Free the password
void free_password(char *password) {
    free(password);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Welcome the user
    welcome();

    // Get the password length
    int length = get_length();

    // Generate a password
    char *password = generate_password(length);

    // Display the generated password
    display_password(password);

    // Free the password
    free_password(password);

    return 0;
}