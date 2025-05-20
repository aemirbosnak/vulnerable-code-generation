//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";

int generateRandomNumberInRange(int min, int max) {
    int result = 0;
    result = rand() % (max - min + 1) + min;
    return result;
}

void shuffle(char *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            char t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void generatePassword(char* password) {
    int passwordLength = generateRandomNumberInRange(MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    password[passwordLength] = '\0';
    for (int i = 0; i < passwordLength; i++) {
        int randomIndex = generateRandomNumberInRange(0, sizeof(characters) - 1);
        password[i] = characters[randomIndex];
    }
    shuffle(password, passwordLength);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of players
    int numPlayers;
    printf("How many players? ");
    scanf("%d", &numPlayers);
    printf("\n");

    // Validate the number of players
    if (numPlayers <= 0) {
        printf("Invalid number of players. Must be greater than 0.\n");
        return 1;
    }

    // Allocate memory for the players' passwords
    char **passwords = (char**)malloc(numPlayers * sizeof(char*));
    for (int i = 0; i < numPlayers; i++) {
        passwords[i] = (char*)malloc(MAX_PASSWORD_LENGTH + 1);
    }

    printf("Generated passwords:\n");

    // Generate passwords for each player
    for (int i = 0; i < numPlayers; i++) {
        generatePassword(passwords[i]);
        printf("Player %d: %s\n", i + 1, passwords[i]);
    }

    // Free the memory used for the passwords
    for (int i = 0; i < numPlayers; i++) {
        free(passwords[i]);
    }
    free(passwords);

    return 0;
}