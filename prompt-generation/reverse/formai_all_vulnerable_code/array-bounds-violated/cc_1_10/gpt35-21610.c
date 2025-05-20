//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void generateBingoCard(int card[ROWS][COLS]);
void printBingoCard(int card[ROWS][COLS]);
int callNumber(int calledNumbers[MAX_NUM], int calledCount);

int main()
{
    int bingoCard[ROWS][COLS];
    int calledNumbers[MAX_NUM] = {0};
    int calledCount = 0;
    int win = 0;
    char ch;

    printf("\t\t\tBINGO SIMULATOR\n\n");

    generateBingoCard(bingoCard);
    printBingoCard(bingoCard);
    printf("Press ENTER to begin calling numbers...");
    scanf("%c", &ch);

    while (win == 0) {
        int calledNumber = callNumber(calledNumbers, calledCount);
        printf("Number called: %d\n", calledNumber);
        calledNumbers[calledCount++] = calledNumber;

        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (bingoCard[row][col] == calledNumber) {
                    bingoCard[row][col] = -1;
                    printBingoCard(bingoCard);
                }
            }
        }

        // Check for bingo
        for (int row = 0; row < ROWS; row++) {
            int rowSum = 0;
            int colSum = 0;
            for (int col = 0; col < COLS; col++) {
                rowSum += bingoCard[row][col];
                colSum += bingoCard[col][row];
            }
            if (rowSum == -5 || colSum == -5) {
                win = 1;
                printf("\nBINGO! You won!\n");
                break;
            }
        }

    }

    return 0;
}


void generateBingoCard(int card[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++) {
        int usedNumbers[MAX_NUM] = {0};
        for (int col = 0; col < COLS; col++) {
            int num;
            do {
                num = (rand() % 15) + (col * 15) + 1;
            } while (usedNumbers[num] != 0);
            usedNumbers[num] = 1;
            card[row][col] = num;
        }
    }
    card[2][2] = -1; // Free space in the center
}

void printBingoCard(int card[ROWS][COLS])
{
    printf("\n-------------------\n");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (card[row][col] == -1) {
                printf("|  * ");
            } else {
                printf("|%3d ", card[row][col]);
            }
        }
        printf("|\n-------------------\n");
    }
}

int callNumber(int calledNumbers[MAX_NUM], int calledCount)
{
    srand(time(NULL));
    int calledNumber;
    do
    {
        calledNumber = (rand() % MAX_NUM) + 1;
    } while (calledNumbers[calledNumber] != 0);
    return calledNumber;
}