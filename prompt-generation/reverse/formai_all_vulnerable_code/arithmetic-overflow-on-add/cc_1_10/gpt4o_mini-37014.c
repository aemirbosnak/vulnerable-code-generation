//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16
#define NUM_PASSWORDS 5

// Function Prototypes
void generate_password(char *password);
void print_passwords(char passwords[NUM_PASSWORDS][PASSWORD_LENGTH + 1]);

// A whimsical character set to create our magical passwords!
const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char digits[] = "0123456789";
const char symbols[] = "!@#$%^&*()-_=+<>?[]{}|;:,.~`";

// The grand function to generate a single password
void generate_password(char *password) {
    // Seed the random generator
    srand(time(0) + rand());

    // Ensure the password is a magical mixture of different character types
    password[0] = uppercase[rand() % (sizeof(uppercase) - 1)];
    password[1] = lowercase[rand() % (sizeof(lowercase) - 1)];
    password[2] = digits[rand() % (sizeof(digits) - 1)];
    password[3] = symbols[rand() % (sizeof(symbols) - 1)];

    // Fill the rest of the password with random characters
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        int char_type = rand() % 4; // Pick a char set
        switch (char_type) {
            case 0:
                password[i] = uppercase[rand() % (sizeof(uppercase) - 1)];
                break;
            case 1:
                password[i] = lowercase[rand() % (sizeof(lowercase) - 1)];
                break;
            case 2:
                password[i] = digits[rand() % (sizeof(digits) - 1)];
                break;
            case 3:
                password[i] = symbols[rand() % (sizeof(symbols) - 1)];
                break;
        }
    }
    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the password string
}

// The magical function that prints all the enchanting passwords
void print_passwords(char passwords[NUM_PASSWORDS][PASSWORD_LENGTH + 1]) {
    printf("✨ Here are your secure passwords! ✨\n");
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        printf("Password %d: %s\n", i + 1, passwords[i]);
    }
}

int main() {
    // An array to hold our magical passwords
    char passwords[NUM_PASSWORDS][PASSWORD_LENGTH + 1];

    // Let the magic begin - generating the passwords!
    for (int i = 0; i < NUM_PASSWORDS; i++) {
        generate_password(passwords[i]);
    }

    // Reveal the enchantment to the user
    print_passwords(passwords);

    return 0; // The end of our fantastical journey
}