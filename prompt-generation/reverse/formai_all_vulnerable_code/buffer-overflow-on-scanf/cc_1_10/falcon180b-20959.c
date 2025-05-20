//Falcon-180B DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of attempts
#define MAX_ATTEMPTS 5

// Define the delay between attempts in milliseconds
#define DELAY_MS 1000

// Define the password length
#define PASSWORD_LENGTH 8

// Define the valid characters for the password
char valid_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

// Function prototypes
void generate_password(char* password);
int is_valid_password(char* password);

int main() {
    char password[PASSWORD_LENGTH + 1] = {0};
    int attempts = 0;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate the password
    generate_password(password);

    // Print the password
    printf("Your password is: %s\n", password);

    // Get the user to enter the password
    printf("Please enter your password: ");
    scanf("%s", password);

    // Validate the password
    while (!is_valid_password(password) && attempts < MAX_ATTEMPTS) {
        // Print an error message and wait for a short delay
        printf("Invalid password. Please try again.\n");
        usleep(DELAY_MS * 1000);

        // Increment the number of attempts
        attempts++;

        // Regenerate the password
        generate_password(password);

        // Print the new password
        printf("Your password is: %s\n", password);

        // Get the user to enter the password
        printf("Please enter your password: ");
        scanf("%s", password);
    }

    // Exit the program
    return 0;
}

// Function to generate a random password
void generate_password(char* password) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = valid_chars[rand() % strlen(valid_chars)];
    }
    password[PASSWORD_LENGTH] = '\0';
}

// Function to validate the password
int is_valid_password(char* password) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (!strchr(valid_chars, password[i])) {
            return 0;
        }
    }
    return 1;
}