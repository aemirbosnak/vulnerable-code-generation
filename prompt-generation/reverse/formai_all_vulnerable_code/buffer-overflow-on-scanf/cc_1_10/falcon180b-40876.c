//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_DICE 6

// Structure to hold player information
typedef struct {
    char name[20];
    int score;
} Player;

// Function to roll dice
int rollDice(int numDice) {
    int result = 0;
    for (int i = 0; i < numDice; i++) {
        result += rand() % 6 + 1;
    }
    return result;
}

// Function to print a player's turn
void printPlayerTurn(Player *player) {
    printf("It's %s's turn. ", player->name);
}

// Function to print the scores
void printScores(Player players[], int numPlayers) {
    printf("Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

// Function to start a new game
void startGame(Player players[], int numPlayers) {
    printf("Welcome to the game!\n");
    printScores(players, numPlayers);
}

// Function to play a round of the game
void playRound(Player players[], int numPlayers, int numDice) {
    int maxScore = 0;
    Player maxPlayer;

    for (int i = 0; i < numPlayers; i++) {
        players[i].score += rollDice(numDice);
        if (players[i].score > maxScore) {
            maxScore = players[i].score;
            maxPlayer = players[i];
        }
    }

    printf("Round complete.\n");
    printScores(players, numPlayers);

    if (maxScore == 63) {
        printf("%s wins the game!\n", maxPlayer.name);
        exit(0);
    }
}

int main() {
    srand(time(NULL));

    // Initialize players
    Player players[MAX_PLAYERS];
    int numPlayers = 0;
    char input[20];

    while (numPlayers < MAX_PLAYERS) {
        printf("Enter name of player %d: ", numPlayers + 1);
        scanf("%s", input);
        strcpy(players[numPlayers].name, input);
        numPlayers++;
    }

    // Start the game
    startGame(players, numPlayers);

    while (1) {
        int numDice;
        printf("Enter number of dice to roll (1-6): ");
        scanf("%d", &numDice);

        if (numDice < 1 || numDice > MAX_DICE) {
            printf("Invalid number of dice.\n");
            continue;
        }

        playRound(players, numPlayers, numDice);

        printf("Play again? (y/n): ");
        char playAgain;
        scanf(" %c", &playAgain);

        if (playAgain!= 'y') {
            break;
        }
    }

    return 0;
}