//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LEN 20

// Player data structure
typedef struct player {
    char name[MAX_NAME_LEN];
    int fortune;
} player;

// Function to read player names and fortunes from a file
int read_players(player *players, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    int num_players = 0;
    while (fscanf(fp, "%s %d", players[num_players].name, &players[num_players].fortune) != EOF) {
        num_players++;
    }

    fclose(fp);

    return num_players;
}

// Function to compare two players' fortunes
int compare_players(const void *a, const void *b) {
    const player *player1 = (const player *)a;
    const player *player2 = (const player *)b;

    return player1->fortune - player2->fortune;
}

// Function to play the game
void play_game(player *players, int num_players) {
    // Sort players by fortune
    qsort(players, num_players, sizeof(player), compare_players);

    // Announce the winner
    printf("The winner is %s with a fortune of %d!\n", players[num_players - 1].name, players[num_players - 1].fortune);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Read player names and fortunes from a file
    player players[MAX_PLAYERS];
    int num_players = read_players(players, "players.txt");
    if (num_players == -1) {
        printf("Error reading players from file.\n");
        return 1;
    }

    // Play the game
    play_game(players, num_players);

    return 0;
}