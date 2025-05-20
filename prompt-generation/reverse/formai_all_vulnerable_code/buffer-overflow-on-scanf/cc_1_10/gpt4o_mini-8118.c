//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 4
#define MAX_PLAYERS 2

typedef struct {
    char name[30];
    int score;
} Player;

void initialize_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
}

void print_scoreboard(Player players[], int num_players) {
    printf("\nScoreboard:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("\n");
}

void display_table(int table[TABLE_SIZE][TABLE_SIZE]) {
    printf("Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            printf("%2d ", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fill_table(int table[TABLE_SIZE][TABLE_SIZE]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            table[i][j] = rand() % 10 + 1;  // Fill table with random values from 1 to 10
        }
    }
}

int player_turn(Player *player, int table[TABLE_SIZE][TABLE_SIZE]) {
    int row, col;
    printf("%s's Turn! Choose a row (0 to %d) and column (0 to %d): ", player->name, TABLE_SIZE - 1, TABLE_SIZE - 1);
    scanf("%d %d", &row, &col);

    if (row >= 0 && row < TABLE_SIZE && col >= 0 && col < TABLE_SIZE) {
        int points = table[row][col];
        table[row][col] = 0;  // Remove the value from the table
        player->score += points; // Update player's score
        printf("%s scores %d points!\n", player->name, points);
        return points;
    } else {
        printf("Invalid move! Please try again.\n");
        return 0; // No points for an invalid move
    }
}

void play_game(Player players[], int num_players) {
    int table[TABLE_SIZE][TABLE_SIZE];
    fill_table(table);
    int total_turns = 0;

    while (total_turns < TABLE_SIZE * TABLE_SIZE) {
        for (int i = 0; i < num_players; i++) {
            display_table(table);
            int points = player_turn(&players[i], table);
            if (points > 0) {
                total_turns++;
            }

            if (total_turns >= TABLE_SIZE * TABLE_SIZE) {
                break; // Exit the loop if all turns are taken
            }
        }
    }

    printf("Game Over!\n");
    print_scoreboard(players, num_players);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Player players[MAX_PLAYERS];
    int num_players;

    printf("Welcome to the Score Table Game!\n");
    do {
        printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
        scanf("%d", &num_players);
    } while (num_players < 1 || num_players > MAX_PLAYERS);

    initialize_players(players, num_players);
    play_game(players, num_players);
    
    return 0;
}