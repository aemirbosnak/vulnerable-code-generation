//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define BINGO_SIZE 5
#define NUMBERS_RANGE 75

typedef struct {
    char name[50];
    int card[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} Player;

// Function Prototypes
void createBingoCard(Player *player);
void printBingoCard(Player player);
int drawNumber(int drawnNumbers[], int *drawnCount);
int checkBingo(Player player);
void declareWinner(Player players[], int totalPlayers);

int main() {
    int totalPlayers;
    Player players[MAX_PLAYERS];
    int drawnNumbers[NUMBERS_RANGE + 1] = {0}; // To keep track of drawn numbers
    int drawnCount = 0;
    int gameActive = 1;

    printf("Welcome to the Great Bingo of the Medieval Kingdom!\n");
    printf("How many players shall partake in this noble quest? (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &totalPlayers);

    if (totalPlayers < 1 || totalPlayers > MAX_PLAYERS) {
        printf("The number of players must be between 1 and %d. Farewell!\n", MAX_PLAYERS);
        return 1;
    }

    // Initialize Players
    for (int i = 0; i < totalPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        createBingoCard(&players[i]);
    }

    while (gameActive) {
        int number = drawNumber(drawnNumbers, &drawnCount);
        printf("\nA number is drawn from the great horn: %d\n", number);

        for (int i = 0; i < totalPlayers; i++) {
            // Mark the drawn number on each player's card
            for (int j = 0; j < BINGO_SIZE; j++) {
                for (int k = 0; k < BINGO_SIZE; k++) {
                    if (players[i].card[j][k] == number) {
                        players[i].marked[j][k] = 1;
                    }
                }
            }

            // Check if the player has won
            if (checkBingo(players[i])) {
                printf("Hear ye! Hear ye! %s hath declared Bingo!\n", players[i].name);
                declareWinner(players, totalPlayers);
                gameActive = 0;
                break;
            }
        }

        if (drawnCount >= NUMBERS_RANGE) {
            printf("All noble numbers have been drawn. The game ends in a draw!\n");
            gameActive = 0;
        }
    }

    printf("The Great Bingo has ended. Until next time, brave players!\n");
    return 0;
}

void createBingoCard(Player *player) {
    int numbers[NUMBERS_RANGE + 1] = {0}; 
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            int num;
            do {
                num = rand() % NUMBERS_RANGE + 1;
            } while (numbers[num]); // Ensure number uniqueness
            numbers[num] = 1;
            player->card[i][j] = num;
            player->marked[i][j] = 0; // Initialize marked status
        }
    }
    printf("The Bingo Card for Lord/Lady %s has been prepared:\n", player->name);
    printBingoCard(*player);
}

void printBingoCard(Player player) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player.marked[i][j]) {
                printf("[X]\t");
            } else {
                printf("[%d]\t", player.card[i][j]);
            }
        }
        printf("\n");
    }
}

int drawNumber(int drawnNumbers[], int *drawnCount) {
    int number;
    do {
        number = rand() % NUMBERS_RANGE + 1;
    } while (drawnNumbers[number]); // Ensures we do not repeat numbers
    drawnNumbers[number] = 1; 
    (*drawnCount)++;
    return number;
}

int checkBingo(Player player) {
    // Check rows and columns for Bingo
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((player.marked[i][0] && player.marked[i][1] && player.marked[i][2] &&
             player.marked[i][3] && player.marked[i][4]) ||
            (player.marked[0][i] && player.marked[1][i] && player.marked[2][i] &&
             player.marked[3][i] && player.marked[4][i])) {
            return 1; // Bingo found
        }
    }

    // Check diagonals for Bingo
    if ((player.marked[0][0] && player.marked[1][1] && player.marked[2][2] &&
         player.marked[3][3] && player.marked[4][4]) ||
        (player.marked[0][4] && player.marked[1][3] && player.marked[2][2] &&
         player.marked[3][1] && player.marked[4][0])) {
        return 1; // Bingo found
    }

    return 0; // No Bingo
}

void declareWinner(Player players[], int totalPlayers) {
    printf("And the champions of this fine game are:\n");
    for (int i = 0; i < totalPlayers; i++) {
        printf("- %s\n", players[i].name);
    }
}