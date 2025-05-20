//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for password generation
const int MIN_PASSWORD_LENGTH = 8;
const int MAX_PASSWORD_LENGTH = 16;
const char LOWERCASE_CHARS[] = "abcdefghijklmnopqrstuvwxyz";
const char UPPERCASE_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char NUMERIC_CHARS[] = "0123456789";
const char SPECIAL_CHARS[] = "!@#$%^&*()-_=+[]{}\\|;:',.<>/?";

// Function to generate a random integer between min and max (inclusive)
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character from an array of characters
char random_char(const char* chars, int num_chars) {
    int index = random_int(0, num_chars - 1);
    return chars[index];
}

// Function to generate a secure password
void generate_password(char* password, int length) {
    // Add at least one character from each character set
    password[0] = random_char(LOWERCASE_CHARS, sizeof(LOWERCASE_CHARS) - 1);
    password[1] = random_char(UPPERCASE_CHARS, sizeof(UPPERCASE_CHARS) - 1);
    password[2] = random_char(NUMERIC_CHARS, sizeof(NUMERIC_CHARS) - 1);
    password[3] = random_char(SPECIAL_CHARS, sizeof(SPECIAL_CHARS) - 1);

    // Add remaining characters
    for (int i = 4; i < length; i++) {
        // Randomly choose a character set to use
        int char_set = random_int(0, 3);
        switch (char_set) {
            case 0:
                password[i] = random_char(LOWERCASE_CHARS, sizeof(LOWERCASE_CHARS) - 1);
                break;
            case 1:
                password[i] = random_char(UPPERCASE_CHARS, sizeof(UPPERCASE_CHARS) - 1);
                break;
            case 2:
                password[i] = random_char(NUMERIC_CHARS, sizeof(NUMERIC_CHARS) - 1);
                break;
            case 3:
                password[i] = random_char(SPECIAL_CHARS, sizeof(SPECIAL_CHARS) - 1);
                break;
        }
    }

    // Shuffle the password
    for (int i = 0; i < length; i++) {
        int j = random_int(0, length - 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get password length from user
    int length;
    printf("Enter length of password [%d-%d]: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Password length must be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Generate the password and print it to the console
    char password[MAX_PASSWORD_LENGTH + 1];
    password[length] = '\0';
    generate_password(password, length);
    printf("Your new secure password is: %s\n", password);

    return 0;
}