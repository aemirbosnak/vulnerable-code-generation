//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 128

// Function to check if a character is special
int is_special(char ch) {
    const char *special_chars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";
    return strchr(special_chars, ch) != NULL;
}

// Function to generate a random character given the type
char generate_random_character(int include_uppercase, int include_lowercase, int include_digits, int include_special) {
    int char_type = rand() % 4; // Randomly select character type
    if (include_uppercase && char_type == 0) {
        return 'A' + rand() % 26; // Uppercase letters
    }
    if (include_lowercase && char_type == 1) {
        return 'a' + rand() % 26; // Lowercase letters
    }
    if (include_digits && char_type == 2) {
        return '0' + rand() % 10; // Digits
    }
    if (include_special && char_type == 3) {
        const char *special_chars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";
        return special_chars[rand() % strlen(special_chars)]; // Special characters
    }
    return generate_random_character(include_uppercase, include_lowercase, include_digits, include_special);
}

// Function to generate a secure password
void generate_password(int length, int include_uppercase, int include_lowercase, int include_digits, int include_special) {
    char password[MAX_LENGTH + 1]; // '+1' for null terminator

    for (int i = 0; i < length; i++) {
        password[i] = generate_random_character(include_uppercase, include_lowercase, include_digits, include_special);
    }
    password[length] = '\0'; // Null terminate the string

    // Print the generated password
    printf("Generated Password: %s\n", password);
}

int main() {
    int length;
    int include_uppercase, include_lowercase, include_digits, include_special;

    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n\n");

    // Get the password length
    do {
        printf("Enter the desired length of the password (1 to %d): ", MAX_LENGTH);
        scanf("%d", &length);
    } while (length < 1 || length > MAX_LENGTH);

    // Get the character inclusion preferences
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &include_uppercase);
    
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &include_lowercase);
    
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &include_digits);
    
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &include_special);

    // Check if at least one character type is selected
    if (!include_uppercase && !include_lowercase && !include_digits && !include_special) {
        printf("Error: You must select at least one character type!\n");
        return 1;
    }

    // Generate the password
    generate_password(length, include_uppercase, include_lowercase, include_digits, include_special);

    return 0;
}