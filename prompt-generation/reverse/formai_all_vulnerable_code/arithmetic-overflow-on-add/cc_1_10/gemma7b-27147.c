//Gemma-7B DATASET v1.0 Category: Image Classification system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Players 2

typedef struct Player {
    char name[20];
    int team;
    int score;
    int image_label;
} Player;

int main() {
    int num_players = 2;
    Player players[MAX_Players];

    // Initialize players
    for (int i = 0; i < num_players; i++) {
        players[i].name[0] = '\0';
        players[i].team = 0;
        players[i].score = 0;
        players[i].image_label = -1;
    }

    // Start the game
    for (int round = 0; round < 10; round++) {
        // Each player chooses an image label
        for (int i = 0; i < num_players; i++) {
            printf("%s, choose an image label: ", players[i].name);
            scanf("%d", &players[i].image_label);
        }

        // Check if the chosen labels are valid
        for (int i = 0; i < num_players; i++) {
            if (players[i].image_label < 0 || players[i].image_label > 9) {
                printf("Error: invalid image label.\n");
                players[i].image_label = -1;
            }
        }

        // Calculate the winner
        int winner = -1;
        for (int i = 0; i < num_players; i++) {
            if (players[i].image_label == players[winner].image_label) {
                winner = i;
            }
        }

        // Award points to the winner
        if (winner != -1) {
            players[winner].score++;
            printf("Congratulations, %s, you won the round!\n", players[winner].name);
        } else {
            printf("No winner.\n");
        }
    }

    // End the game
    printf("Thank you for playing!\n");

    return 0;
}