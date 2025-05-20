//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 10
#define NUM_CHARS 4
#define NUM_DIGITS 10
#define NUM_SPECIAL 5

int main() {
    char password[PASSWORD_LENGTH + 1]; // +1 for null terminator
    char chars[NUM_CHARS][PASSWORD_LENGTH];
    char digits[NUM_DIGITS];
    char specials[NUM_SPECIAL];
    int i, j, index, random;

    // Initialize character arrays
    for (i = 0; i < NUM_CHARS; i++) {
        for (j = 0; j < PASSWORD_LENGTH; j++) {
            chars[i][j] = 'A' + (i * PASSWORD_LENGTH) + j;
        }
        chars[i][PASSWORD_LENGTH] = '\0';
    }

    // Initialize digits array
    for (i = 0; i < NUM_DIGITS; i++) {
        digits[i] = '0' + i;
    }

    // Initialize special characters array
    for (i = 0; i < NUM_SPECIAL; i++) {
        specials[i] = "!@#$%^&*()_+-=[]{}|;:,.<>?[\"']"[i];
    }

    // Seed random number generator
    srand(time(NULL));

    // Generate password
    for (i = 0; i < PASSWORD_LENGTH; i++) {
        index = rand() % (NUM_CHARS + NUM_DIGITS + NUM_SPECIAL);
        if (index < NUM_CHARS) {
            password[i] = chars[index % NUM_CHARS][rand() % PASSWORD_LENGTH];
        } else if (index < NUM_CHARS + NUM_DIGITS) {
            password[i] = digits[index % NUM_DIGITS];
        } else {
            password[i] = specials[index % NUM_SPECIAL];
        }
    }

    // Add null terminator
    password[PASSWORD_LENGTH] = '\0';

    // Print password
    printf("Generated password: %s\n", password);

    return 0;
}