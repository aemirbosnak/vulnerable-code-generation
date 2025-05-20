//GPT-4o-mini DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define GRID_SIZE 5
#define MAX_PLAYERS 4
#define MAX_TREASURES 3

typedef struct {
    char name[50];
    int treasures_found;
} Player;

typedef struct {
    int x;
    int y;
    int searched;
} Treasure;

void initialize_game(Player players[], int num_players, Treasure treasures[], int num_treasures) {
    for (int i = 0; i < num_players; i++) {
        players[i].treasures_found = 0;
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
    }

    srand(time(NULL));

    for (int i = 0; i < num_treasures; i++) {
        treasures[i].x = rand() % GRID_SIZE;
        treasures[i].y = rand() % GRID_SIZE;
        treasures[i].searched = 0;
    }
}

void display_grid(Treasure treasures[], int num_treasures) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            char display_char = '.';
            for (int k = 0; k < num_treasures; k++) {
                if (treasures[k].searched == 0 && treasures[k].x == i && treasures[k].y == j) {
                    display_char = '?'; // Unknown treasure position
                    break;
                }
            }
            printf("%c ", display_char);
        }
        printf("\n");
    }
}

void search_for_treasure(Player *player, Treasure treasures[], int num_treasures) {
    int x, y;
    printf("%s, enter coordinates to search (x y): ", player->name);
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        printf("Invalid coordinates! Please try again.\n");
        return;
    }

    int found = 0;

    for (int i = 0; i < num_treasures; i++) {
        if (treasures[i].x == x && treasures[i].y == y && treasures[i].searched == 0) {
            treasures[i].searched = 1;
            player->treasures_found++;
            found = 1;
            printf("Congratulations %s! You found a treasure at (%d, %d)!\n", player->name, x, y);
            break;
        }
    }

    if (!found) {
        printf("No treasure found at (%d, %d). Better luck next time!\n", x, y);
    }
}

void display_scores(Player players[], int num_players) {
    printf("\nScores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d treasures found\n", players[i].name, players[i].treasures_found);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    Treasure treasures[MAX_TREASURES];
    int num_players, turn = 0;

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Enter number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    initialize_game(players, num_players, treasures, MAX_TREASURES);

    while (turn < MAX_TREASURES) {
        display_grid(treasures, MAX_TREASURES);
        search_for_treasure(&players[turn % num_players], treasures, MAX_TREASURES);
        turn++;
    }

    display_scores(players, num_players);
    printf("Game over!\n");

    return 0;
}