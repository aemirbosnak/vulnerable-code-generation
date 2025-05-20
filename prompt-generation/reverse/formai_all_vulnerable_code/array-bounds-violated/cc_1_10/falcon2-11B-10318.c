//Falcon2-11B DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16
#define UPPERCASE_CHARS 26
#define LOWERCASE_CHARS 26
#define DIGITS 10
#define SYMBOLS 32

int main() {
    char password[PASSWORD_LENGTH];

    // Seed the random number generator
    srand(time(NULL));

    // Create the password
    int index = 0;
    int upperCase = rand() % UPPERCASE_CHARS;
    int lowerCase = rand() % LOWERCASE_CHARS;
    int digits = rand() % DIGITS;
    int symbols = rand() % SYMBOLS;

    // Add random uppercase, lowercase, digits, and symbols
    for (int i = 0; i < upperCase; i++) {
        password[index] = 'A' + rand() % UPPERCASE_CHARS;
        index++;
    }
    for (int i = 0; i < lowerCase; i++) {
        password[index] = 'a' + rand() % LOWERCASE_CHARS;
        index++;
    }
    for (int i = 0; i < digits; i++) {
        password[index] = '0' + rand() % DIGITS;
        index++;
    }
    for (int i = 0; i < symbols; i++) {
        password[index] = '!@#$%^&*()' + rand() % SYMBOLS;
        index++;
    }

    // Add random lowercase characters
    for (int i = 0; i < PASSWORD_LENGTH - upperCase - lowerCase - digits - symbols; i++) {
        password[index] = 'a' + rand() % LOWERCASE_CHARS;
        index++;
    }

    // Add random uppercase characters
    for (int i = 0; i < PASSWORD_LENGTH - upperCase - lowerCase - digits - symbols; i++) {
        password[index] = 'A' + rand() % UPPERCASE_CHARS;
        index++;
    }

    // Add random digits
    for (int i = 0; i < PASSWORD_LENGTH - upperCase - lowerCase - digits - symbols; i++) {
        password[index] = '0' + rand() % DIGITS;
        index++;
    }

    // Add random symbols
    for (int i = 0; i < PASSWORD_LENGTH - upperCase - lowerCase - digits - symbols; i++) {
        password[index] = '!@#$%^&*()' + rand() % SYMBOLS;
        index++;
    }

    printf("Your password is: %s\n", password);

    return 0;
}