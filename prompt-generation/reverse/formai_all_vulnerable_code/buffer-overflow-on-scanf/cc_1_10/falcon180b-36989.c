//Falcon-180B DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ROUNDS 10

// Define the player structure
struct player {
    char name[50];
    int score;
};

// Function to initialize a player
void init_player(struct player *p, char *name) {
    strcpy(p->name, name);
    p->score = 0;
}

// Function to print a player's details
void print_player(struct player *p) {
    printf("Name: %s\n", p->name);
    printf("Score: %d\n", p->score);
}

// Function to generate a random score
int generate_score() {
    return rand() % 100;
}

// Function to play a round of the game
void play_round(struct player *players, int num_players) {
    int i;
    for (i = 0; i < num_players; i++) {
        players[i].score += generate_score();
    }
}

// Function to print the leaderboard
void print_leaderboard(struct player *players, int num_players) {
    int i;
    printf("Leaderboard:\n");
    for (i = 0; i < num_players; i++) {
        printf("%d. %s - %d points\n", i+1, players[i].name, players[i].score);
    }
}

// Function to play multiple rounds of the game
void play_game(struct player *players, int num_players, int num_rounds) {
    int i;
    for (i = 0; i < num_rounds; i++) {
        play_round(players, num_players);
        print_leaderboard(players, num_players);
    }
}

int main() {
    srand(time(NULL));

    // Initialize the players
    struct player players[MAX_PLAYERS];
    int num_players = 0;
    char name[50];
    while (num_players < MAX_PLAYERS) {
        printf("Enter a player name (or press enter to stop): ");
        scanf("%s", name);
        if (name[0]!= '\0') {
            init_player(&players[num_players], name);
            num_players++;
        }
    }

    // Play the game
    int num_rounds = 0;
    while (num_rounds < MAX_ROUNDS) {
        play_game(players, num_players, num_rounds);
        num_rounds++;
    }

    return 0;
}