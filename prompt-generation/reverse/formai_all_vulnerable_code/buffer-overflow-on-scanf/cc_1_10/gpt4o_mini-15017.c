//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define NUM_SPECIAL_CHARS 10
#define NUM_DIGITS 10
#define NUM_UPPER_ALPHA 26
#define NUM_LOWER_ALPHA 26

// Function to generate a secure random password
void generatePassword(char *password, int length) {
    const char specialChars[NUM_SPECIAL_CHARS] = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    const char upperAlpha[NUM_UPPER_ALPHA] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowerAlpha[NUM_LOWER_ALPHA] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[NUM_DIGITS] = "0123456789";

    // Ensure at least one character from each category
    password[0] = specialChars[rand() % NUM_SPECIAL_CHARS];
    password[1] = upperAlpha[rand() % NUM_UPPER_ALPHA];
    password[2] = lowerAlpha[rand() % NUM_LOWER_ALPHA];
    password[3] = digits[rand() % NUM_DIGITS];

    // Fill the rest of the password length with random characters from all categories
    for (int i = 4; i < length; i++) {
        int category = rand() % 4;
        switch (category) {
            case 0:
                password[i] = specialChars[rand() % NUM_SPECIAL_CHARS];
                break;
            case 1:
                password[i] = upperAlpha[rand() % NUM_UPPER_ALPHA];
                break;
            case 2:
                password[i] = lowerAlpha[rand() % NUM_LOWER_ALPHA];
                break;
            case 3:
                password[i] = digits[rand() % NUM_DIGITS];
                break;
        }
    }

    // Shuffle the password to make it more secure
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password string
    password[length] = '\0';
}

// Function to display password options to the user
void displayOptions() {
    printf("Secure Password Generator\n");
    printf("---------------------------\n");
    printf("Choose a password length between %d and %d:\n", MIN_LENGTH, MAX_LENGTH);
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    int length;

    displayOptions();
    // User input for password length
    while (1) {
        printf("Enter length: ");
        if (scanf("%d", &length) != 1 || length < MIN_LENGTH || length > MAX_LENGTH) {
            printf("Invalid length. Please enter a number between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
            while (getchar() != '\n'); // Clear invalid input
        } else {
            break; // Input is valid
        }
    }

    char password[MAX_LENGTH + 1]; // Create a buffer for the password

    generatePassword(password, length); // Generate the password

    printf("Generated Password: %s\n", password);

    return 0;
}