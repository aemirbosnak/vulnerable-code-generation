//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: multiplayer
#include <stdio.h>
#include <time.h>

#define MAX_Players 4

typedef struct Player {
    char name[20];
    int speed;
    int score;
} Player;

int main() {
    int numPlayers = 2;
    Player players[MAX_Players];

    // Initialize players
    for (int i = 0; i < numPlayers; i++) {
        players[i].name[0] = 'A' + i;
        players[i].speed = 50 + i;
        players[i].score = 0;
    }

    // Start the game
    int round = 0;
    while (round < 5) {
        // Each player types a word
        for (int i = 0; i < numPlayers; i++) {
            printf("%s, type a word: ", players[i].name);
            char word[20];
            scanf("%s", word);

            // Calculate the word length
            int wordLength = 0;
            for (int j = 0; word[j] != '\0'; j++) {
                wordLength++;
            }

            // Update the player's score
            players[i].score += wordLength * players[i].speed;
        }

        // End the round
        round++;
    }

    // Print the final scores
    printf("Final scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}