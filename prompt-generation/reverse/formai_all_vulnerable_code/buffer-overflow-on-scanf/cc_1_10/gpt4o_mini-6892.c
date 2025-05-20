//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Function to generate a random secure password
void generate_password(int length, bool use_upper, bool use_lower, bool use_numbers, bool use_symbols) {
    // Define the character sets that will be used to generate the password
    const char *upper_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower_chars = "abcdefghijklmnopqrstuvwxyz";
    const char *number_chars = "0123456789";
    const char *symbol_chars = "!@#$%^&*()-_=+<>?";
    
    // Variable to hold the selected characters based on user preference
    char selected_chars[256];
    int idx = 0;

    // Concatenate character sets based on user choices
    if (use_upper) {
        strcpy(selected_chars + idx, upper_chars);
        idx += strlen(upper_chars);
    }
    if (use_lower) {
        strcpy(selected_chars + idx, lower_chars);
        idx += strlen(lower_chars);
    }
    if (use_numbers) {
        strcpy(selected_chars + idx, number_chars);
        idx += strlen(number_chars);
    }
    if (use_symbols) {
        strcpy(selected_chars + idx, symbol_chars);
        idx += strlen(symbol_chars);
    }
    selected_chars[idx] = '\0'; // Null-terminate the selected characters string
    int selected_length = strlen(selected_chars);
    
    // Check if any character types were selected
    if (selected_length == 0) {
        printf("Error: No character types selected for password generation.\n");
        return;
    }

    // Array to hold the generated password
    char password[length + 1];
    
    // Seed the random number generator
    srand(time(NULL));

    // Generate the password
    for (int i = 0; i < length; i++) {
        int random_index = rand() % selected_length; // Generate a random index
        password[i] = selected_chars[random_index];   // Select the character from the pooled characters
    }
    password[length] = '\0'; // Null-terminate the password string
    printf("Generated Password: %s\n", password); // Output the generated password
}

// Function to get user preferences
void get_user_preferences(int *length, bool *use_upper, bool *use_lower, bool *use_numbers, bool *use_symbols) {
    // Prompt user for password length
    printf("Enter desired password length (minimum 8): ");
    scanf("%d", length);
    
    // Validate password length
    if (*length < 8) {
        printf("Password length must be at least 8. Defaulting to 8.\n");
        *length = 8; // Default value
    }

    // Prompt user for character type selections
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", use_upper);
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", use_lower);
    printf("Include numbers? (1 for yes, 0 for no): ");
    scanf("%d", use_numbers);
    printf("Include symbols? (1 for yes, 0 for no): ");
    scanf("%d", use_symbols);
}

// Main function
int main() {
    int length;
    bool use_upper = false, use_lower = false, use_numbers = false, use_symbols = false;

    // Get user preferences for password generation
    get_user_preferences(&length, &use_upper, &use_lower, &use_numbers, &use_symbols);
    
    // Generate the secure password based on user preferences
    generate_password(length, use_upper, use_lower, use_numbers, use_symbols);

    return 0;
}