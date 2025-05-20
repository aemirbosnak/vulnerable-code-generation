//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_ENCOUNTERS 10
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int position;
} Player;

typedef struct {
    char description[100];
    int effect; // Positive or negative effect
} Encounter;

Encounter encounters[MAX_ENCOUNTERS] = {
    {"You encounter a floating blue elephant! Dance with it and move ahead 3 spaces.", 3},
    {"A mirror appears and whispers your name. Lose a turn to ponder.", -1},
    {"You find a spaghetti tree! Eat it and gain 2 spaces!", 2},
    {"A portal opens to a candyland! Go back 2 spaces, but enjoy the taste.", -2},
    {"You meet an octopus playing chess. Win a game to leap 4 spaces!", 4},
    {"The ground opens up, and you fall into a pit of jellybeans! Move back 3 spaces.", -3},
    {"A wise turtle offers riddles. Solve one to advance 5 spaces!", 5},
    {"You are surrounded by singing cacti. Embrace the melody and move 2 spaces.", 2},
    {"A wizard appears and casts a spell. You must roll again!", 0},
    {"You find yourself at a giant clock tower. Lose a turn in confusion!", -1}
};

void initialize_players(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        fgets(players[i].name, MAX_NAME_LENGTH, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline
        players[i].position = 0;
    }
}

void print_positions(Player players[], int num_players) {
    printf("\nCurrent positions:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s is at position %d\n", players[i].name, players[i].position);
    }
    printf("\n");
}

void encounter_event(Player *player) {
    int encounter_index = rand() % MAX_ENCOUNTERS;
    Encounter encounter = encounters[encounter_index];
    
    printf("%s encounters: %s\n", player->name, encounter.description);
    
    if (encounter.effect > 0) {
        player->position += encounter.effect;
        printf("%s moves forward %d spaces!\n", player->name, encounter.effect);
    } else if (encounter.effect < 0) {
        printf("%s is affected negatively, and loses %d steps!\n", player->name, -encounter.effect);
        player->position += encounter.effect; // Adding a negative number
    } else {
        printf("%s gets to roll again!\n", player->name);
    }
    
    printf("\n");
}

int main() {
    srand(time(NULL)); // Seed for randomness

    int num_players;
    Player players[MAX_PLAYERS];

    printf("Welcome to the Surrealist Table Game!\n");
    printf("How many players (1 - %d)? ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar(); // Consume newline character

    // Validation for number of players
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players! Restarting...\n");
        return 0;
    }

    initialize_players(players, num_players);
    
    // Game loop
    int turns = 0;
    while (1) {
        print_positions(players, num_players);
        
        for (int i = 0; i < num_players; i++) {
            if (players[i].position < 20) {
                printf("%s's turn (Turn %d):\n", players[i].name, turns + 1);
                encounter_event(&players[i]);
            } else {
                printf("%s has reached the dream destination!\n", players[i].name);
                return 0; // End game with a winner
            }
        }
        turns++;
    }

    return 0;
}