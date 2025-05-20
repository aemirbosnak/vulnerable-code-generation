//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 128

void generate_recursive(char *password, int index, int length, int has_upper, int has_lower, int has_digit, int has_special);
int valid_password(int length, int has_upper, int has_lower, int has_digit, int has_special);

const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *lower = "abcdefghijklmnopqrstuvwxyz";
const char *digits = "0123456789";
const char *special = "!@#$%^&*()-_=+[]{};:,.<>?";
const char *all_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{};:,.<>?";

int main() {
    int length;
    char password[MAX_LENGTH + 1];

    printf("Enter desired password length (1-%d): ", MAX_LENGTH);
    scanf("%d", &length);

    if (length < 1 || length > MAX_LENGTH) {
        printf("Invalid length! Please enter a length between 1 and %d.\n", MAX_LENGTH);
        return 1;
    }

    printf("Generating password...\n");
    srand(time(NULL)); // Seed for randomness

    // Start password generation
    generate_recursive(password, 0, length, 0, 0, 0, 0);
    
    return 0;
}

void generate_recursive(char *password, int index, int length, int has_upper, int has_lower, int has_digit, int has_special) {
    if (index == length) {
        if (valid_password(length, has_upper, has_lower, has_digit, has_special)) {
            password[length] = '\0'; // Null-terminate the string
            printf("Generated password: %s\n", password);
        }
        return; // Return if the length is achieved
    }

    for (int i = 0; i < strlen(all_characters); i++) {
        password[index] = all_characters[i];
        // Update flags for character types
        generate_recursive(password, index + 1, length,
                           has_upper || (password[index] >= 'A' && password[index] <= 'Z'),
                           has_lower || (password[index] >= 'a' && password[index] <= 'z'),
                           has_digit || (isdigit(password[index])),
                           has_special || (strchr(special, password[index]) != NULL));
    }
}

int valid_password(int length, int has_upper, int has_lower, int has_digit, int has_special) {
    // Check that the password contains at least one of each required character type
    return (has_upper && has_lower && has_digit && has_special);
}