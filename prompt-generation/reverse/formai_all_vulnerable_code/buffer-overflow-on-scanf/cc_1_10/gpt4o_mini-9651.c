//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 128 // Maximum length of the password
#define MIN_LENGTH 8   // Minimum length of the password

void generate_password(char *password, int length, int include_upper, int include_lower, int include_digit, int include_special);
void add_character_set(char *set, int *set_size, int include_upper, int include_lower, int include_digit, int include_special);
void shuffle(char *password, int length);
void print_usage();

int main() {
    int length;
    char password[MAX_LENGTH + 1]; // Buffer to hold the password
    int include_upper = 0, include_lower = 0, include_digit = 0, include_special = 0;
    
    srand(time(NULL)); // Seed the random number generator with current time

    printf("Welcome to the Secure Password Generator!\n");
    
    // User input for password length
    printf("Enter the desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);
    
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length! Please choose a length between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return 1;
    }

    // User input for character types
    printf("Include uppercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &include_upper);

    printf("Include lowercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &include_lower);

    printf("Include digits? (1 for Yes, 0 for No): ");
    scanf("%d", &include_digit);

    printf("Include special characters? (1 for Yes, 0 for No): ");
    scanf("%d", &include_special);
    
    // Generate password
    generate_password(password, length, include_upper, include_lower, include_digit, include_special);
    
    // Print the generated password
    printf("Generated password: %s\n", password);

    return 0;
}

// Function to generate a password
void generate_password(char *password, int length, int include_upper, int include_lower, int include_digit, int include_special) {
    char char_set[256]; // Buffer to hold characters to choose from
    int set_size = 0;

    // Add chosen character sets
    add_character_set(char_set, &set_size, include_upper, include_lower, include_digit, include_special);
    
    if (set_size == 0) {
        printf("No character set chosen! At least one type must be selected.\n");
        exit(1);
    }
    
    // Generate password
    for (int i = 0; i < length; i++) {
        password[i] = char_set[rand() % set_size]; // Pick random characters
    }
    password[length] = '\0'; // Null terminate the string
    
    // Shuffle the password for better randomness
    shuffle(password, length);
}

// Function to add character sets to the available character set
void add_character_set(char *set, int *set_size, int include_upper, int include_lower, int include_digit, int include_special) {
    if (include_upper) {
        for (char c = 'A'; c <= 'Z'; c++) {
            set[(*set_size)++] = c; // Add uppercase letters
        }
    }
    if (include_lower) {
        for (char c = 'a'; c <= 'z'; c++) {
            set[(*set_size)++] = c; // Add lowercase letters
        }
    }
    if (include_digit) {
        for (char c = '0'; c <= '9'; c++) {
            set[(*set_size)++] = c; // Add digits
        }
    }
    if (include_special) {
        const char *special_chars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";
        while (*special_chars) {
            set[(*set_size)++] = *special_chars++; // Add special characters
        }
    }
}

// Function to shuffle the password for randomness
void shuffle(char *password, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap characters
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

void print_usage() {
    printf("Usage: password_generator\n");
    printf("Options:\n");
    printf("  -length <length>       Specify the length of the password\n");
    printf("  -upper                  Include uppercase letters\n");
    printf("  -lower                  Include lowercase letters\n");
    printf("  -digit                  Include digits\n");
    printf("  -special                Include special characters\n");
}