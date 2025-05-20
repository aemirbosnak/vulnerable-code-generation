//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define NUM_PASSWORDS 5

// Function to generate a secure password
void generate_password(char *password, int length) {
    // Possible characters for the password
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";
    
    // All possible characters combined
    const char *all_characters = "abcdefghijklmnopqrstuvwxyz"
                                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "0123456789"
                                  "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";

    // Ensure to include at least one character from each category
    password[0] = lowercase[rand() % strlen(lowercase)];
    password[1] = uppercase[rand() % strlen(uppercase)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special[rand() % strlen(special)];

    // Fill the rest of the password with random characters
    for (int i = 4; i < length; i++) {
        password[i] = all_characters[rand() % strlen(all_characters)];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password
    password[length] = '\0';
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create an array to hold multiple passwords
    char passwords[NUM_PASSWORDS][PASSWORD_LENGTH + 1];

    printf("Welcome to the Secure Password Generator!\n\n");

    for (int i = 0; i < NUM_PASSWORDS; i++) {
        printf("Generating password %d...\n", i + 1);
        generate_password(passwords[i], PASSWORD_LENGTH);
        printf("Generated Password %d: %s\n", i + 1, passwords[i]);
    }

    printf("\nAll passwords generated successfully!\n");
    
    // Provide additional options
    char choice;
    printf("Would you like to save these passwords to a file? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        FILE *file = fopen("generated_passwords.txt", "w");
        if (file == NULL) {
            fprintf(stderr, "Error: Unable to open file for writing.\n");
            return 1;
        }
        fprintf(file, "Generated Passwords:\n\n");
        for (int i = 0; i < NUM_PASSWORDS; i++) {
            fprintf(file, "Password %d: %s\n", i + 1, passwords[i]);
        }
        fclose(file);
        printf("Passwords saved to 'generated_passwords.txt'.\n");
    } else {
        printf("Passwords will not be saved. Exiting the program.\n");
    }

    return 0;
}