//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NP 10
#define NS 5

typedef struct {
    char name[20];
    int score;
} player_t;

player_t players[NP] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0},
    {"David", 0},
    {"Eve", 0}
};

int main() {
    srand(time(NULL));

    // Game initialization
    printf("Welcome to the Visionary Table Game!\n");
    printf("Please select a player to start:\n");

    for (int i = 0; i < NP; i++) {
        printf("%d. %s (%d)\n", i + 1, players[i].name, players[i].score);
    }

    int player_choice = getchar();
    int player_index = player_choice - '1';

    // Game loop
    while (1) {
        // Roll the dice
        int roll = rand() % 6 + 1;

        // Update player scores
        if (player_index == 1) {
            players[0].score += roll;
        } else if (player_index == 2) {
            players[1].score += roll;
        } else if (player_index == 3) {
            players[2].score += roll;
        } else if (player_index == 4) {
            players[3].score += roll;
        } else {
            players[4].score += roll;
        }

        // Print the updated scores
        for (int i = 0; i < NP; i++) {
            printf("%d. %s (%d)\n", i + 1, players[i].name, players[i].score);
        }

        // Check for game over
        if (players[0].score > 100 || players[1].score > 100 ||
                players[2].score > 100 || players[3].score > 100 || players[4].score > 100) {
            break;
        }

        // Update the player choice
        player_choice = getchar();
        player_index = player_choice - '1';
    }

    // Print the final scores
    for (int i = 0; i < NP; i++) {
        printf("%d. %s (%d)\n", i + 1, players[i].name, players[i].score);
    }

    return 0;
}