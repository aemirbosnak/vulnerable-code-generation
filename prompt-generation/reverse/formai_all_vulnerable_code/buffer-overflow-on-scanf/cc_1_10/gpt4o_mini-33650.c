//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[]{}|;:,.<>?/`~"
#define DEFAULT_PASSWORD_LENGTH 12
#define MAX_PASSWORD_LENGTH 128

void generate_password(char *password, int length, int include_special, int include_upper, int include_lower, int include_digits) {
    char character_pool[MAX_PASSWORD_LENGTH] = "";
    int pool_size = 0;

    // Build the character pool based on user preferences
    if (include_lower) {
        strcpy(character_pool + pool_size, LOWERCASE);
        pool_size += strlen(LOWERCASE);
    }
    if (include_upper) {
        strcpy(character_pool + pool_size, UPPERCASE);
        pool_size += strlen(UPPERCASE);
    }
    if (include_digits) {
        strcpy(character_pool + pool_size, DIGITS);
        pool_size += strlen(DIGITS);
    }
    if (include_special) {
        strcpy(character_pool + pool_size, SPECIAL_CHARS);
        pool_size += strlen(SPECIAL_CHARS);
    }

    // Ensure the pool is not empty
    if (pool_size == 0) {
        printf("Error: At least one character type must be selected.\n");
        return;
    }

    // Generate the password
    for (int i = 0; i < length; i++) {
        int random_index = rand() % pool_size;
        password[i] = character_pool[random_index];
    }
    password[length] = '\0'; // Null-terminate the string
}

int main() {
    srand(time(0)); // Seed the random number generator
    char password[MAX_PASSWORD_LENGTH];
    int length, include_special, include_upper, include_lower, include_digits;

    // Get user preferences
    printf("Welcome to the Secure Password Generator!\n");
    printf("Enter desired password length (8 - 128, default is 12): ");
    scanf("%d", &length);

    // Default length if input is out of bounds
    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        length = DEFAULT_PASSWORD_LENGTH;
    }

    // Include character types
    printf("Include lowercase letters? (1 = yes, 0 = no): ");
    scanf("%d", &include_lower);
    printf("Include uppercase letters? (1 = yes, 0 = no): ");
    scanf("%d", &include_upper);
    printf("Include digits? (1 = yes, 0 = no): ");
    scanf("%d", &include_digits);
    printf("Include special characters? (1 = yes, 0 = no): ");
    scanf("%d", &include_special);

    generate_password(password, length, include_special, include_upper, include_lower, include_digits);
    printf("Generated Password: %s\n", password);

    return 0;
}