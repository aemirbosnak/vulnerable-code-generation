//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXIMUM_PASSWORD_LENGTH 12

char* generate_password() {
    int i;
    srand((unsigned int)time(NULL));

    char* password = calloc(MAXIMUM_PASSWORD_LENGTH + 1, sizeof(char));
    if (!password) {
        printf("Error: Cannot allocate memory for password.");
        return NULL;
    }

    for (i = 0; i < MAXIMUM_PASSWORD_LENGTH; i++) {
        int random_character = rand() % 74 + 48; // Gets a random ASCII character between 48 and 122, inclusive.

        // Ensure only uppercase letters, lowercase letters, and digits are included in the password.
        while ((random_character > 57 && random_character < 65) || (random_character > 90 && random_character < 97)) {
            random_character = rand() % 74 + 48;
        }

        password[i] = (char)random_character;
    }

    password[MAXIMUM_PASSWORD_LENGTH] = '\0';

    return password;
}

int main() {
    int number_of_players = 0;
    printf("Enter the number of players: ");
    scanf("%d", &number_of_players);
    getchar(); // Need to add this getchar() to consume the newline character produced by pressing enter.

    char** player_names = calloc(number_of_players, sizeof(char*));
    if (!player_names) {
        printf("Error: Cannot allocate memory for player names.");
        return 1;
    }

    for (int i = 0; i < number_of_players; i++) {
        player_names[i] = calloc(100, sizeof(char));
        if (!player_names[i]) {
            printf("Error: Cannot allocate memory for player name.");
            return 1;
        }

        printf("Enter the name of player %d: ", i + 1);
        fgets(player_names[i], 100, stdin);
        strtok(player_names[i], "\n"); // Removes the newline character at the end of the player name.
    }

    printf("Generating passwords...\n");
    char** player_passwords = calloc(number_of_players, sizeof(char*));
    if (!player_passwords) {
        printf("Error: Cannot allocate memory for player passwords.");
        return 1;
    }

    for (int i = 0; i < number_of_players; i++) {
        player_passwords[i] = generate_password();
        printf("%s's password: %s\n", player_names[i], player_passwords[i]);
    }

    // Free dynamically allocated memory.
    for (int i = 0; i < number_of_players; i++) {
        free(player_names[i]);
        free(player_passwords[i]);
    }
    free(player_names);
    free(player_passwords);

    return 0;
}