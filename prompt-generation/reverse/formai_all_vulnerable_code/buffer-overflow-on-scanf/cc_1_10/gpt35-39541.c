//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 8
#define MAX_THEORIES 10

int main() {
    char theories[MAX_THEORIES][100] = {
        "The moon landing was faked by the government.",
        "The earth is flat and governments have conspired to hide this fact.",
        "Chemtrails are being used to control the population.",
        "Area 51 is hiding evidence of alien life.",
        "The Illuminati controls the world's governments and economy.",
        "9/11 was a planned attack by the US government.",
        "The Bermuda Triangle is a portal to another dimension.",
        "The Zika virus was created by the government to control the population."
    };
    char players[MAX_PLAYERS][20] = {"Alice", "Bob", "Charlie", "Dave", "Eve", "Frank", "Grace", "Heidi"};
    int player_count = 0, theory_count = 0, num_players = 0, num_theories = 0;
    
    srand(time(0)); // Seed the random number generator
    
    printf("Welcome to the Conspiracy Theory Generator game!\n");
    printf("How many players are there? (max 8): ");
    scanf("%d", &num_players);
    while (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please choose a number between 1 and %d: ", MAX_PLAYERS);
        scanf("%d", &num_players);
    }
    printf("\n");
    
    printf("Great! Now, how many theories do you want to generate? (max 10): ");
    scanf("%d", &num_theories);
    while (num_theories < 1 || num_theories > MAX_THEORIES) {
        printf("Invalid number of theories. Please choose a number between 1 and %d: ", MAX_THEORIES);
        scanf("%d", &num_theories);
    }
    printf("\n");
    
    // Randomly assign players to theories
    for (int i = 0; i < num_theories; i++) {
        int player_index = rand() % num_players;
        printf("%s thinks that %s\n", players[player_index], theories[theory_count]);
        player_count++;
        if (player_count >= num_players) {
            player_count = 0;
            theory_count++;
        }
    }
    
    printf("\n");
    printf("Thanks for playing! Remember, don't trust the government...\n");
    
    return 0;
}