//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5

typedef struct {
    int numbers[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

void generateBingoCard(BingoCard *card) {
    int num, col, row;
    bool isDuplicate;

    // Generate numbers for each column
    for (col = 0; col < BINGO_SIZE; col++) {
        isDuplicate = false;
        int range_start = col * 15 + 1;
        int range_end = range_start + 15;

        for (row = 0; row < BINGO_SIZE; row++) {
            do {
                isDuplicate = false;
                num = rand() % (range_end - range_start) + range_start;

                for (int i = 0; i < row; i++) {
                    if (card->numbers[i][col] == num) {
                        isDuplicate = true;
                        break;
                    }
                }
            } while (isDuplicate);

            card->numbers[row][col] = num;
            card->marked[row][col] = false;
        }
    }
    card->marked[2][2] = true;  // Free space in the middle
}

void printBingoCard(BingoCard *card) {
    printf("\nBingo Card:\n");
    printf("-------------------------\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->marked[row][col]) {
                printf("[X] ");
            } else {
                printf("[%2d] ", card->numbers[row][col]);
            }
        }
        printf("\n");
    }
    printf("-------------------------\n");
}

bool checkBingo(BingoCard *card) {
    // Check rows and columns for bingo
    for (int i = 0; i < BINGO_SIZE; i++) {
        bool rowBingo = true;
        bool colBingo = true;

        for (int j = 0; j < BINGO_SIZE; j++) {
            if (!card->marked[i][j]) {
                rowBingo = false;
            }
            if (!card->marked[j][i]) {
                colBingo = false;
            }
        }
        if (rowBingo || colBingo) {
            return true;
        }
    }

    // Check diagonals for bingo
    bool diagonal1 = true;
    bool diagonal2 = true;
    
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (!card->marked[i][i]) {
            diagonal1 = false;
        }
        if (!card->marked[i][BINGO_SIZE - 1 - i]) {
            diagonal2 = false;
        }
    }

    return diagonal1 || diagonal2;
}

void drawNumberAndMarkCard(BingoCard *card) {
    int drawnNumber = rand() % 75 + 1;  // Drawn number between 1 and 75
    printf("Drawn Number: %d\n", drawnNumber);

    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->numbers[row][col] == drawnNumber) {
                card->marked[row][col] = true;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    BingoCard card;
    generateBingoCard(&card);
    printBingoCard(&card);

    int turn;
    printf("Enter the number of turns to simulate: ");
    scanf("%d", &turn);

    for (int i = 0; i < turn; i++) {
        drawNumberAndMarkCard(&card);
        printBingoCard(&card);
        if (checkBingo(&card)) {
            printf("BINGO! You've won!\n");
            break;
        }
    }

    return 0;
}