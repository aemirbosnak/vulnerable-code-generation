//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PLAYERS 10
#define BINGO_SIZE 5
#define MAX_NUMBER 75

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

BingoCard createBingoCard();
void displayBingoCard(BingoCard card);
void markNumber(BingoCard *card, int number);
bool checkBingo(BingoCard card);
void drawNumber(int *drawnNumbers, int *count);

int main() {
    srand(time(NULL));
    int numPlayers = 0;
    BingoCard players[MAX_PLAYERS];
    int drawnNumbers[MAX_NUMBER] = {0};
    int drawnCount = 0;
    char continueGame = 'y';

    // Input number of players
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    // Create Bingo Cards for players
    for (int i = 0; i < numPlayers; i++) {
        players[i] = createBingoCard();
        printf("\nPlayer %d's Bingo Card:\n", i + 1);
        displayBingoCard(players[i]);
    }

    // Bingo game loop
    while (continueGame == 'y') {
        drawNumber(drawnNumbers, &drawnCount);
        printf("Drawn number: %d\n", drawnNumbers[drawnCount - 1]);

        for (int i = 0; i < numPlayers; i++) {
            markNumber(&players[i], drawnNumbers[drawnCount - 1]);
            if (checkBingo(players[i])) {
                printf("Player %d wins!\n", i + 1);
                continueGame = 'n'; // End game if a player wins
                break;
            }
        }

        if (continueGame == 'y') {
            printf("Do you want to continue drawing numbers? (y/n): ");
            scanf(" %c", &continueGame);
        }
    }

    printf("Game over!\n");
    return 0;
}

BingoCard createBingoCard() {
    BingoCard card;
    int nums[MAX_NUMBER] = {0};
    int count = 0;

    // Fill the Bingo card
    for (int col = 0; col < BINGO_SIZE; col++) {
        for (int row = 0; row < BINGO_SIZE; row++) {
            int num;
            do {
                num = rand() % MAX_NUMBER + 1; // numbers between 1 and 75
            } while (nums[num - 1] != 0); // Ensure unique numbers
            nums[num - 1] = 1;
            card.card[row][col] = num;
            card.marked[row][col] = false;
        }
    }
    card.marked[BINGO_SIZE/2][BINGO_SIZE/2] = true; // Center free space
    return card;
}

void displayBingoCard(BingoCard card) {
    printf(" | B | I | N | G | O |\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        printf(" | ");
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card.marked[row][col]) {
                printf(" * | ");
            } else {
                printf("%2d | ", card.card[row][col]);
            }
        }
        printf("\n");
    }
}

void markNumber(BingoCard *card, int number) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->card[row][col] == number) {
                card->marked[row][col] = true;
                return;
            }
        }
    }
}

bool checkBingo(BingoCard card) {
    // Check rows
    for (int row = 0; row < BINGO_SIZE; row++) {
        bool rowBingo = true;
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (!card.marked[row][col]) {
                rowBingo = false;
                break;
            }
        }
        if (rowBingo) return true;
    }

    // Check columns
    for (int col = 0; col < BINGO_SIZE; col++) {
        bool colBingo = true;
        for (int row = 0; row < BINGO_SIZE; row++) {
            if (!card.marked[row][col]) {
                colBingo = false;
                break;
            }
        }
        if (colBingo) return true;
    }

    // Check diagonals
    bool diagBingo1 = true, diagBingo2 = true;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!card.marked[i][i]) {
            diagBingo1 = false;
        }
        if (!card.marked[i][BINGO_SIZE - 1 - i]) {
            diagBingo2 = false;
        }
    }

    return diagBingo1 || diagBingo2;
}

void drawNumber(int *drawnNumbers, int *count) {
    int num;
    do {
        num = rand() % MAX_NUMBER + 1;
    } while (drawnNumbers[num - 1] != 0); // Ensure unique draws
    drawnNumbers[num - 1] = 1; // Mark the number as drawn
    drawnNumbers[(*count)++] = num;
}