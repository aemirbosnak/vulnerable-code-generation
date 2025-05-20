//Code Llama-13B DATASET v1.0 Category: Terminal Based Game ; Style: modular
// game.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define game constants
#define MAX_PLAYERS 5
#define MAX_ROUNDS 10
#define MAX_POINTS 10

// define game structs
typedef struct {
    int id;
    char name[20];
    int points;
} Player;

typedef struct {
    int id;
    int player_id;
    int points;
} Round;

// define game functions
void print_title() {
    printf("Welcome to the Game of Points!\n");
    printf("=============================\n");
    printf("\n");
}

void print_instructions() {
    printf("Instructions:\n");
    printf("------------\n");
    printf("1. Each player will take turns rolling a die and adding the number to their score.\n");
    printf("2. The game ends after %d rounds.\n", MAX_ROUNDS);
    printf("3. The player with the highest score at the end of the game wins.\n");
    printf("\n");
}

void print_players(Player* players, int num_players) {
    printf("Players:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%d. %s (%d points)\n", i + 1, players[i].name, players[i].points);
    }
}

void print_rounds(Round* rounds, int num_rounds) {
    printf("Rounds:\n");
    for (int i = 0; i < num_rounds; i++) {
        printf("%d. %s rolled %d and scored %d points.\n", rounds[i].id, rounds[i].player_id, rounds[i].points);
    }
}

void print_winner(Player* players, int num_players) {
    printf("The winner is %s with %d points!\n", players[0].name, players[0].points);
}

// game logic
void play_game() {
    // initialize game variables
    Player players[MAX_PLAYERS];
    Round rounds[MAX_ROUNDS];
    int num_players = 0;
    int num_rounds = 0;

    // initialize players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i + 1;
        players[i].points = 0;
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        num_players++;
    }

    // initialize rounds
    for (int i = 0; i < MAX_ROUNDS; i++) {
        rounds[i].id = i + 1;
        rounds[i].player_id = 0;
        rounds[i].points = 0;
    }

    // play game
    int current_player = 0;
    while (num_rounds < MAX_ROUNDS) {
        // get player input
        printf("Player %d's turn.\n", current_player + 1);
        printf("Roll the die: ");
        int roll = rand() % 6 + 1;
        printf("You rolled a %d.\n", roll);

        // update player points
        players[current_player].points += roll;
        printf("You scored %d points.\n", roll);

        // update round information
        rounds[num_rounds].player_id = current_player + 1;
        rounds[num_rounds].points = roll;
        num_rounds++;

        // update current player
        current_player = (current_player + 1) % num_players;

        // check for winner
        if (players[0].points >= MAX_POINTS) {
            break;
        }
    }

    // print results
    print_title();
    print_players(players, num_players);
    print_rounds(rounds, num_rounds);
    print_winner(players, num_players);
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}