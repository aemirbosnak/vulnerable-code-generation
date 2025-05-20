//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants for the game settings
#define MAX_PLAYERS 4
#define MIN_PLAYERS 2
#define MAX_ROUNDS 10
#define MAX_TURNS 3
#define MAX_DICE 6
#define MIN_DICE 1

// Player struct for storing player data
typedef struct {
    char name[20];
    int score;
} Player;

// Function prototypes
int rollDice(int numDice);
void playRound(Player players[], int numPlayers);
void printScoreboard(Player players[], int numPlayers);

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    int numPlayers;
    do {
        printf("How many players will be playing? (2-4): ");
        scanf("%d", &numPlayers);
        if (numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS) {
            printf("Invalid number of players\n");
        }
    } while (numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS);
    
    Player players[MAX_PLAYERS];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    
    printf("\nStarting the game!\n\n");
    
    for (int round = 0; round < MAX_ROUNDS; round++) {
        printf("Round %d:\n", round+1);
        playRound(players, numPlayers);
        printScoreboard(players, numPlayers);
    }
    
    printf("\nEnd of game!\n");
    printScoreboard(players, numPlayers);
    
    return 0;
}

// Function to simulate a roll of a number of dice
int rollDice(int numDice) {
    int total = 0;
    for (int i = 0; i < numDice; i++) {
        total += rand() % MAX_DICE + MIN_DICE;
    }
    return total;
}

// Function to play a round of the game
void playRound(Player players[], int numPlayers) {
    for (int turn = 0; turn < MAX_TURNS; turn++) {
        for (int i = 0; i < numPlayers; i++) {
            printf("%s's turn. Press enter to roll the dice.", players[i].name);
            getchar();
            int score = rollDice(2);
            printf("You rolled %d.\n", score);
            players[i].score += score;
        }
    }
}

// Function to print the current scoreboard
void printScoreboard(Player players[], int numPlayers) {
    printf("\nCurrent scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    printf("\n");
}