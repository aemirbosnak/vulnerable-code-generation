//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PLAYERS 10
#define BINGO_SIZE 5
#define TOTAL_NUMBERS 75

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
    char name[30];
} Player;

void initializeBingoCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int columnStart = 1;
    for (int j = 0; j < BINGO_SIZE; j++) {
        int columnEnd = columnStart + 14; // 15 numbers range for each column
        int numbers[15];
        
        // Generate unique numbers for each column
        for (int k = 0; k < 15; k++) {
            numbers[k] = columnStart + k;
        }

        // Shuffle numbers in the column
        for (int k = 15 - 1; k > 0; k--) {
            int randomIndex = rand() % (k + 1);
            int temp = numbers[k];
            numbers[k] = numbers[randomIndex];
            numbers[randomIndex] = temp;
        }

        // Fill the Bingo card
        for (int i = 0; i < BINGO_SIZE; i++) {
            if (i == 2 && j == 2) {
                card[i][j] = 0; // Center space is free
            } else {
                int number = numbers[i < 2 ? i : i + 1];
                card[i][j] = number;
            }
        }
        
        columnStart += 15;
    }
}

void printBingoCard(Player player) {
    printf("%s's Bingo Card:\n", player.name);
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player.marked[i][j]) {
                printf("[X] ");
            } else {
                printf("[%2d] ", player.card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void markNumber(Player *player, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (player->card[i][j] == number) {
                player->marked[i][j] = true;
            }
        }
    }
}

bool checkBingo(Player player) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        bool rowBingo = true;
        bool colBingo = true;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (!player.marked[i][j]) rowBingo = false;
            if (!player.marked[j][i]) colBingo = false;
        }
        if (rowBingo || colBingo) return true;
    }
    
    // Check diagonals
    bool diag1Bingo = true, diag2Bingo = true;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!player.marked[i][i]) diag1Bingo = false;
        if (!player.marked[i][BINGO_SIZE-i-1]) diag2Bingo = false;
    }
    
    return diag1Bingo || diag2Bingo;
}

int main() {
    srand(time(NULL));
    
    int numPlayers;
    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }
    
    Player players[MAX_PLAYERS];
    
    // Initialize players and their Bingo cards
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        initializeBingoCard(players[i].card);
        for (int j = 0; j < BINGO_SIZE; j++) {
            for (int k = 0; k < BINGO_SIZE; k++) {
                players[i].marked[j][k] = false;
            }
        }
    }

    bool gameOver = false;
    while (!gameOver) {
        int calledNumber = rand() % TOTAL_NUMBERS + 1;
        printf("Number called: %d\n", calledNumber);
        
        for (int i = 0; i < numPlayers; i++) {
            markNumber(&players[i], calledNumber);
            printBingoCard(players[i]);
            if (checkBingo(players[i])) {
                printf("%s wins with Bingo!\n", players[i].name);
                gameOver = true;
                break;
            }
        }
        
        // To simulate a delay for the next number call
        printf("Press Enter to call next number...\n");
        getchar(); // To consume newline
        getchar(); // Wait for next input
    }

    return 0;
}