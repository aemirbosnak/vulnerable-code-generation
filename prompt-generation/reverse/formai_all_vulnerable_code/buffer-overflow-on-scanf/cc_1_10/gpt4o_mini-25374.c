//GPT-4o-mini DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 50
#define GRID_SIZE 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    int position;
} Player;

void initializePlayers(Player players[], int numPlayers) {
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
        players[i].position = 0;
    }
}

void printWelcomeMessage() {
    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Each player will take turns rolling a die to move across a grid.\n");
    printf("The first player to reach the end of the grid wins!\n");
}

void printGrid(Player players[], int numPlayers) {
    printf("\nGrid Position:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf(" %d ", i + 1);
    }
    printf("\n");

    for (int j = 0; j < numPlayers; j++) {
        printf("%s ", players[j].name);
        for (int i = 0; i < GRID_SIZE; i++) {
            if (players[j].position == i) {
                printf(" * ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
}

int rollDie() {
    return (rand() % 6) + 1; // Simulates rolling a die
}

void playGame(Player players[], int numPlayers) {
    int gameWon = 0;
    while (!gameWon) {
        for (int i = 0; i < numPlayers; i++) {
            printf("%s's turn:\n", players[i].name);
            int roll = rollDie();
            printf("You rolled a %d.\n", roll);
            players[i].position += roll;

            if (players[i].position >= GRID_SIZE) {
                players[i].position = GRID_SIZE - 1; // Prevents overshooting
                printf("%s reached the end of the grid and wins the game!\n", players[i].name);
                gameWon = 1;
                break;
            }

            players[i].score += roll; // Update score
            printGrid(players, numPlayers);
        }
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    Player players[MAX_PLAYERS];
    int numPlayers;

    printWelcomeMessage();

    printf("Enter number of players (1-4): ");
    scanf("%d", &numPlayers);
    while (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Please enter a valid number of players (1-4): ");
        scanf("%d", &numPlayers);
    }

    initializePlayers(players, numPlayers);
    printGrid(players, numPlayers);
    playGame(players, numPlayers);
    
    printf("Game Over! Here are the final scores:\n");
    for (int j = 0; j < numPlayers; j++) {
        printf("%s: %d\n", players[j].name, players[j].score);
    }

    return 0;
}