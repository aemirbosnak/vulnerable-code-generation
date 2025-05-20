//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define NUMBERS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()-_=+[]{};:,.<>?/|`~"
#define TOTAL_CHARACTERS (strlen(UPPERCASE) + strlen(LOWERCASE) + strlen(NUMBERS) + strlen(SPECIAL_CHARACTERS))

void generate_secure_password(char *password) {
    // Variable to store random characters
    char character_pool[TOTAL_CHARACTERS + 1];
    
    // Combine all character sets into one
    strcpy(character_pool, UPPERCASE);
    strcat(character_pool, LOWERCASE);
    strcat(character_pool, NUMBERS);
    strcat(character_pool, SPECIAL_CHARACTERS);
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Ensure at least one character from each character set is used
    password[0] = UPPERCASE[rand() % strlen(UPPERCASE)];
    password[1] = LOWERCASE[rand() % strlen(LOWERCASE)];
    password[2] = NUMBERS[rand() % strlen(NUMBERS)];
    password[3] = SPECIAL_CHARACTERS[rand() % strlen(SPECIAL_CHARACTERS)];
    
    // Fill the remaining length of the password
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        password[i] = character_pool[rand() % TOTAL_CHARACTERS];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;  // Pick a random index
        char temp = password[i];           // Swap characters
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the string
    password[PASSWORD_LENGTH] = '\0';
}

int main() {
    char password[PASSWORD_LENGTH + 1];  // +1 for null terminator
    int number_of_passwords;

    // Prompt the user for the number of passwords to generate
    printf("Welcome to the Secure Password Generator!\n");
    printf("How many passwords would you like to generate? ");
    scanf("%d", &number_of_passwords);

    // Generate the requested number of passwords
    for (int i = 0; i < number_of_passwords; i++) {
        generate_secure_password(password);
        printf("Generated Password %d: %s\n", i + 1, password);
    }

    return 0;
}