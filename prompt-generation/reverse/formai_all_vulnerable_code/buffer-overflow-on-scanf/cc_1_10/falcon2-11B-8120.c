//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 2
#define MAX_ROLLS 3

typedef struct {
    int player;
    int score;
} Player;

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    int rolls[MAX_ROLLS];
    int current_player = 0;
    int current_roll = 0;
    int total_score = 0;
    int total_rolls = 0;

    printf("Welcome to Dice Game!\n");
    printf("Enter the number of players (1-2): ");
    int num_players = 0;
    scanf("%d", &num_players);

    for (int i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
        scanf("%d", &players[i].player);
        players[i].score = 0;
    }

    printf("\nLet's roll!\n");

    while (total_score < MAX_ROLLS && total_rolls < MAX_ROLLS) {
        printf("Player %d's turn.\n", current_player + 1);
        printf("Rolls remaining: %d\n", MAX_ROLLS - total_rolls);
        printf("Rolls left: %d\n", rolls[current_roll]);

        rolls[current_roll] = rand() % 6 + 1;
        printf("Roll: %d\n", rolls[current_roll]);

        if (rolls[current_roll] == 1) {
            printf("You rolled a 1!\n");
            rolls[current_roll] = rand() % 6 + 1;
            printf("Roll: %d\n", rolls[current_roll]);
        }

        total_score += rolls[current_roll];
        total_rolls++;

        if (total_score > 100) {
            printf("You won!\n");
            break;
        }

        if (total_rolls >= MAX_ROLLS) {
            printf("You lost!\n");
            break;
        }

        current_roll++;
        if (current_roll >= MAX_ROLLS) {
            current_roll = 0;
            current_player++;
            if (current_player >= num_players) {
                current_player = 0;
            }
        }
    }

    printf("Final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d - %d\n", i + 1, players[i].score);
    }

    return 0;
}