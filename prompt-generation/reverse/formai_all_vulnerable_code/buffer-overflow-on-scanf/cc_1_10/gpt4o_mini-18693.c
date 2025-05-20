//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define UPPERCASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()-_=+[]{}|;:<>,.?/~"

void generateSecurePassword(char *password) {
    int i, upperCaseCount, lowerCaseCount, digitCount, specialCharCount;
    
    // Ensure the password includes at least 1 of each character type
    upperCaseCount = lowerCaseCount = digitCount = specialCharCount = 0;

    // Seed for random number generation
    srand(time(NULL));

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int charType = rand() % 4;  // 0: uppercase, 1: lowercase, 2: digit, 3: special
        switch (charType) {
            case 0:
                password[i] = UPPERCASE_LETTERS[rand() % strlen(UPPERCASE_LETTERS)];
                upperCaseCount++;
                break;
            case 1:
                password[i] = LOWERCASE_LETTERS[rand() % strlen(LOWERCASE_LETTERS)];
                lowerCaseCount++;
                break;
            case 2:
                password[i] = DIGITS[rand() % strlen(DIGITS)];
                digitCount++;
                break;
            case 3:
                password[i] = SPECIAL_CHARACTERS[rand() % strlen(SPECIAL_CHARACTERS)];
                specialCharCount++;
                break;
        }
    }
    
    // Ensure the password has at least one of each character set
    if (upperCaseCount == 0) {
        password[rand() % PASSWORD_LENGTH] = UPPERCASE_LETTERS[rand() % strlen(UPPERCASE_LETTERS)];
    }
    if (lowerCaseCount == 0) {
        password[rand() % PASSWORD_LENGTH] = LOWERCASE_LETTERS[rand() % strlen(LOWERCASE_LETTERS)];
    }
    if (digitCount == 0) {
        password[rand() % PASSWORD_LENGTH] = DIGITS[rand() % strlen(DIGITS)];
    }
    if (specialCharCount == 0) {
        password[rand() % PASSWORD_LENGTH] = SPECIAL_CHARACTERS[rand() % strlen(SPECIAL_CHARACTERS)];
    }

    password[PASSWORD_LENGTH] = '\0'; // Null terminate the password string
}

int main(void) {
    int numberOfPasswords, i;
    char password[PASSWORD_LENGTH + 1];

    printf("Welcome to the Secure Password Generator!\n");
    printf("-----------------------------------------\n");
    
    // Ask the user how many passwords they want to generate
    printf("How many secure passwords do you want to generate? ");
    scanf("%d", &numberOfPasswords);

    // Validate user input
    if (numberOfPasswords <= 0) {
        printf("Please enter a positive number!\n");
        return 1;
    }

    // Generate the requested number of passwords
    for (i = 0; i < numberOfPasswords; i++) {
        generateSecurePassword(password);
        printf("Secure Password %d: %s\n", i + 1, password);
    }

    printf("-----------------------------------------\n");
    printf("Enjoy your secure passwords!\n");
    
    return 0;
}