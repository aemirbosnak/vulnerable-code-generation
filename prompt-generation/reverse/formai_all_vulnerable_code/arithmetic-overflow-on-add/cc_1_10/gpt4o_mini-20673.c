//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function prototypes
void generatePassword(char *password, int length);
void displayPassword(char *password);
int isValidChar(char c);
void shuffle(char *password, int length);

// Constants for password character sets
const char LOWER[] = "abcdefghijklmnopqrstuvwxyz";
const char UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char DIGITS[] = "0123456789";
const char SPECIAL[] = "!@#$%^&*()-_=+[]{};:'\"\\|,.<>?/`~";

// Total character set size
const int LOWER_SIZE = sizeof(LOWER) - 1;
const int UPPER_SIZE = sizeof(UPPER) - 1;
const int DIGITS_SIZE = sizeof(DIGITS) - 1;
const int SPECIAL_SIZE = sizeof(SPECIAL) - 1;

int main() {
    int length;
    
    // Welcome message
    printf("🚀 Welcome to the Secure Password Generator! 🚀\n");
    printf("-----------------------------------------------------\n");
    
    // Get length of password from user
    printf("Enter the desired length of your password (minimum 8 characters): ");
    scanf("%d", &length);
    
    // Validate input length
    if (length < 8) {
        printf("❌ Password length must be at least 8 characters! Exiting...\n");
        return 1;
    }

    // Allocate memory for the generated password
    char *password = malloc((length + 1) * sizeof(char));
    if (password == NULL) {
        printf("❌ Memory allocation failed! Exiting...\n");
        return 1;
    }

    // Generate the password
    generatePassword(password, length);
    
    // Display the generated password
    displayPassword(password);

    // Cleanup
    free(password);
    printf("🎉 Thank you for using the Secure Password Generator! Goodbye! 🎉\n");
    
    return 0;
}

// Function to generate a secure password
void generatePassword(char *password, int length) {
    srand(time(NULL)); // Seed for random number generation
    
    // Start by at least adding one of each character type
    password[0] = LOWER[rand() % LOWER_SIZE];
    password[1] = UPPER[rand() % UPPER_SIZE];
    password[2] = DIGITS[rand() % DIGITS_SIZE];
    password[3] = SPECIAL[rand() % SPECIAL_SIZE];
    
    // Fill the rest of the password
    for (int i = 4; i < length; i++) {
        char randomChar;
        int charType = rand() % 4;
        switch (charType) {
            case 0:
                randomChar = LOWER[rand() % LOWER_SIZE];
                break;
            case 1:
                randomChar = UPPER[rand() % UPPER_SIZE];
                break;
            case 2:
                randomChar = DIGITS[rand() % DIGITS_SIZE];
                break;
            case 3:
                randomChar = SPECIAL[rand() % SPECIAL_SIZE];
                break;
        }
        password[i] = randomChar;
    }

    // Shuffle the password characters
    shuffle(password, length);
    
    // Null-terminate the password
    password[length] = '\0';
}

// Function to shuffle the password for additional security
void shuffle(char *password, int length) {
    for (int i = 0; i < length; i++) {
        int randIndex = rand() % length;
        // Swap characters
        char temp = password[i];
        password[i] = password[randIndex];
        password[randIndex] = temp;
    }
}

// Function to display the generated password
void displayPassword(char *password) {
    printf("🔒 Your secure password is: %s\n", password);
}