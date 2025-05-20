//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define constants for password generation
#define PASSWORD_LENGTH 12
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[]{};:,.<>?/"
#define TOTAL_CHAR_SETS (sizeof(LOWERCASE_CHARS) - 1 + sizeof(UPPERCASE_CHARS) - 1 + sizeof(DIGITS) - 1 + sizeof(SPECIAL_CHARS) - 1)

void generate_password(char* password) {
    // Seed the random number generator
    srand(time(NULL));

    // Ensure at least one character from each category is included
    password[0] = LOWERCASE_CHARS[rand() % (sizeof(LOWERCASE_CHARS) - 1)];
    password[1] = UPPERCASE_CHARS[rand() % (sizeof(UPPERCASE_CHARS) - 1)];
    password[2] = DIGITS[rand() % (sizeof(DIGITS) - 1)];
    password[3] = SPECIAL_CHARS[rand() % (sizeof(SPECIAL_CHARS) - 1)];

    // Fill remaining characters
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        int char_set = rand() % 4; // Randomly choose a character set

        switch (char_set) {
            case 0:
                password[i] = LOWERCASE_CHARS[rand() % (sizeof(LOWERCASE_CHARS) - 1)];
                break;
            case 1:
                password[i] = UPPERCASE_CHARS[rand() % (sizeof(UPPERCASE_CHARS) - 1)];
                break;
            case 2:
                password[i] = DIGITS[rand() % (sizeof(DIGITS) - 1)];
                break;
            case 3:
                password[i] = SPECIAL_CHARS[rand() % (sizeof(SPECIAL_CHARS) - 1)];
                break;
        }
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null terminate the password string
    password[PASSWORD_LENGTH] = '\0';
}

void print_generated_passwords(int count) {
    char password[PASSWORD_LENGTH + 1];

    printf("Generated Secure Passwords:\n");
    for (int i = 0; i < count; i++) {
        generate_password(password);
        printf("%d: %s\n", i + 1, password);
    }
}

int main() {
    int number_of_passwords;

    // Ask user for the number of passwords to generate
    printf("Enter the number of passwords to generate: ");
    scanf("%d", &number_of_passwords);

    // Validate input
    if (number_of_passwords <= 0) {
        printf("Please enter a positive number.\n");
        return 1;
    }

    print_generated_passwords(number_of_passwords);

    return 0;
}