//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define MAX_PLAYERS 5
#define MAX_NUMBERS 75

typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void initializeCard(BingoCard *card) {
    int number;
    srand(time(NULL));
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            do {
                number = rand() % (MAX_NUMBERS / BINGO_SIZE) + (i * (MAX_NUMBERS / BINGO_SIZE)) + 1;
            } while (isNumberInCard(card, number, i, j));
            card->card[i][j] = number;
            card->marked[i][j] = 0;
        }
    }
    card->marked[BINGO_SIZE / 2][BINGO_SIZE / 2] = 1; // Free space
}

int isNumberInCard(BingoCard *card, int number, int col) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card->card[i][col] == number) {
            return 1;
        }
    }
    return 0;
}

void printCard(BingoCard *card) {
    printf("B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->marked[i][j]) {
                printf("[%2d] ", card->card[i][j]);
            } else {
                printf(" %2d  ", card->card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void markNumber(BingoCard *card, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card->card[i][j] == number) {
                card->marked[i][j] = 1;
            }
        }
    }
}

int checkWin(BingoCard *card) {
    // Check rows
    for (int i = 0; i < BINGO_SIZE; i++) {
        int rowWin = 1;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (!card->marked[i][j]) {
                rowWin = 0;
                break;
            }
        }
        if (rowWin) return 1;
    }

    // Check columns
    for (int j = 0; j < BINGO_SIZE; j++) {
        int colWin = 1;
        for (int i = 0; i < BINGO_SIZE; i++) {
            if (!card->marked[i][j]) {
                colWin = 0;
                break;
            }
        }
        if (colWin) return 1;
    }

    // Check diagonals
    int diagWin1 = 1, diagWin2 = 1;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!card->marked[i][i]) {
            diagWin1 = 0;
        }
        if (!card->marked[i][BINGO_SIZE - 1 - i]) {
            diagWin2 = 0;
        }
    }

    return diagWin1 || diagWin2;
}

int main() {
    BingoCard cards[MAX_PLAYERS];
    int numPlayers, drawnNumbers[MAX_NUMBERS] = {0}, drawCount = 0;

    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return -1;
    }

    // Initialize Bingo cards
    for (int i = 0; i < numPlayers; i++) {
        initializeCard(&cards[i]);
        printf("Player %d's Bingo Card:\n", i + 1);
        printCard(&cards[i]);
    }

    // Start drawing numbers until a player wins or max rounds reached
    while (drawCount < MAX_NUMBERS) {
        int number = rand() % MAX_NUMBERS + 1;

        // Ensure number is unique
        if (!drawnNumbers[number - 1]) {
            drawnNumbers[number - 1] = 1;
            drawCount++;

            printf("Drawn number: %d\n", number);
            for (int i = 0; i < numPlayers; i++) {
                markNumber(&cards[i], number);
                if (checkWin(&cards[i])) {
                    printf("Player %d wins with number %d!\n", i + 1, number);
                    return 0;
                }
            }
            printf("\n");
            for (int i = 0; i < numPlayers; i++) {
                printf("Player %d's Card:\n", i + 1);
                printCard(&cards[i]);
            }
        }
    }

    printf("No players won this round.\n");
    return 0;
}