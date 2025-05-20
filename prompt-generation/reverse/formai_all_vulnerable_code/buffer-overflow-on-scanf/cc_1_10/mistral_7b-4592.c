//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_TRIES 3
#define NUM_ELEMENTS 6
#define SEED_VALUE 1337

// Custom structure to store elements of Zorgoth's magical password array
typedef struct {
    char symbol;
    int weight;
} Element;

// Zorgoth's magical password array
Element symbols[NUM_ELEMENTS] = {
    {'A', 4}, {'B', 3}, {'C', 2}, {'D', 5}, {'E', 1}, {'F', 3}
};

// Function to check password strength based on Zorgoth's arcane rules
int checkStrength(const char *password) {
    int length = strlen(password), tries = 0;
    int password_sum = 0;

    if (length < MIN_LENGTH) {
        printf("Error: Password must be at least %d characters long.\n", MIN_LENGTH);
        return -1;
    }

    srand(SEED_VALUE + time(NULL));
    char shuffled_password[length];
    strcpy(shuffled_password, password);

    for (size_t i = 0; i < length; i++) {
        int index = rand() % NUM_ELEMENTS;
        shuffled_password[i] = symbols[index].symbol;
        password_sum += symbols[index].weight;
    }

    for (int i = 0; i < MAX_TRIES; i++) {
        char guess[length];
        strcpy(guess, shuffled_password);
        int guess_sum = 0;

        for (size_t j = 0; j < length; j++) {
            guess[j] = tolower(guess[j]);
            int index = rand() % NUM_ELEMENTS;
            guess[j] = symbols[index].symbol;
            guess_sum += symbols[index].weight;
        }

        if (strcmp(password, guess) == 0) {
            printf("Congratulations! Your password '%s' is strong enough.\n", password);
            return 1;
        }

        tries++;
        if (tries == MAX_TRIES) {
            printf("Error: Maximum number of tries reached. Please try again with a different password.\n");
            return -1;
        }
    }

    printf("Error: Unable to find a match after %d tries. Your password may not be strong enough.\n", MAX_TRIES);
    return -1;
}

int main() {
    char password[MIN_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int result = checkStrength(password);

    if (result == -1) {
        printf("Program terminated due to an error.\n");
    }

    return 0;
}