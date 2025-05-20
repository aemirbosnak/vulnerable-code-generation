//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define UPPERCASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define NUMBERS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()-_=+[]{}|;:,.<>?/"

void generate_secure_password(char *password, int length) {
    const char *character_sets[] = {
        UPPERCASE_LETTERS,
        LOWERCASE_LETTERS,
        NUMBERS,
        SPECIAL_CHARACTERS
    };

    // Ensure the password is at least as long as the number of character sets 
    int sets_count = sizeof(character_sets) / sizeof(character_sets[0]);
    if (length < sets_count) {
        fprintf(stderr, "[ERROR] Password length should be at least %d characters.\n", sets_count);
        return;
    }

    // Seed the random number generator
    srand(time(NULL));
    
    // Generate one character from each set to ensure each category is represented
    for (int i = 0; i < sets_count; i++) {
        int idx = rand() % strlen(character_sets[i]);
        password[i] = character_sets[i][idx];
    }

    // Fill remaining password characters with a mix of all sets
    for (int i = sets_count; i < length; i++) {
        int total_characters = 0;
        for (int j = 0; j < sets_count; j++) {
            total_characters += strlen(character_sets[j]);
        }
        int idx = rand() % total_characters;

        // Find which set the random index falls into
        int accumulated = 0;
        for (int j = 0; j < sets_count; j++) {
            accumulated += strlen(character_sets[j]);
            if (idx < accumulated) {
                idx = rand() % strlen(character_sets[j]);
                password[i] = character_sets[j][idx];
                break;
            }
        }
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password string
    password[length] = '\0';
}

int main() {
    int num_passwords;
    char password[PASSWORD_LENGTH + 1];

    printf("Welcome to the Secure Password Generator!\n");
    printf("How many passwords would you like to generate? ");
    scanf("%d", &num_passwords);

    if (num_passwords <= 0) {
        fprintf(stderr, "[ERROR] Please enter a positive number of passwords.\n");
        return 1;
    }

    printf("\nGenerating %d secure passwords:\n", num_passwords);
    for (int i = 0; i < num_passwords; i++) {
        generate_secure_password(password, PASSWORD_LENGTH);
        printf("Password %d: %s\n", i + 1, password);
    }

    printf("\nThank you for using the Secure Password Generator. Stay safe!\n");
    return 0;
}