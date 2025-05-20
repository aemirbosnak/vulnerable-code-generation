//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define NUM_SPECIAL_CHARACTERS 10
#define NUM_DIGITS 10
#define NUM_UPPERCASE 26
#define NUM_LOWERCASE 26

void generatePassword(char *password) {
    const char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lower[] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[] = "0123456789";
    const char special[] = "!@#$%^&*()-_+=<>?/|";

    // Ensuring at least one character from each category is included
    password[0] = upper[rand() % NUM_UPPERCASE];
    password[1] = lower[rand() % NUM_LOWERCASE];
    password[2] = digits[rand() % NUM_DIGITS];
    password[3] = special[rand() % NUM_SPECIAL_CHARACTERS];

    // Fill the rest of the password length with random characters from all categories
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        int category = rand() % 4;
        switch (category) {
            case 0:
                password[i] = upper[rand() % NUM_UPPERCASE];
                break;
            case 1:
                password[i] = lower[rand() % NUM_LOWERCASE];
                break;
            case 2:
                password[i] = digits[rand() % NUM_DIGITS];
                break;
            case 3:
                password[i] = special[rand() % NUM_SPECIAL_CHARACTERS];
                break;
        }
    }
    
    // Shuffle the password to prevent predictable patterns
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int numPasswords;
    printf("Welcome to the Magical Password Generator!\n");
    printf("How many secure passwords would you like to generate? ");
    scanf("%d", &numPasswords);
    
    char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator
    printf("\nHere are your magical passwords:\n");
    
    for (int i = 0; i < numPasswords; i++) {
        generatePassword(password);
        printf("Password %d: %s\n", i + 1, password);
    }

    printf("\nRemember to keep your passwords safe!\n");
    return 0;
}