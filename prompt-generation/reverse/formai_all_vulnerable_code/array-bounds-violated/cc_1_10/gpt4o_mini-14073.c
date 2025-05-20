//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MAX_NUM 75

typedef struct {
    int grid[SIZE][SIZE];
    int marked[SIZE][SIZE];
    int bingo;
} BingoCard;

void initializeCard(BingoCard *card) {
    int num, row, col, count = 0;
    int nums[MAX_NUM] = {0};

    while (count < SIZE * SIZE) {
        num = rand() % MAX_NUM + 1;
        if (nums[num] == 0) {
            nums[num] = 1;
            row = count / SIZE;
            col = count % SIZE;
            card->grid[row][col] = num;
            card->marked[row][col] = 0;
            count++;
        }
    }
}

void printCard(BingoCard *card) {
    printf("Your Bingo Card:\n");
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (card->marked[r][c]) {
                printf("[X] ");
            } else {
                printf("[%2d] ", card->grid[r][c]);
            }
        }
        printf("\n");
    }
}

void markNumber(BingoCard *card, int number) {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (card->grid[r][c] == number) {
                card->marked[r][c] = 1;
                return;
            }
        }
    }
}

int checkBingo(BingoCard *card) {
    int row, col;

    // Check rows
    for (row = 0; row < SIZE; row++) {
        int bingo = 1;
        for (col = 0; col < SIZE; col++) {
            if (!card->marked[row][col]) {
                bingo = 0;
                break;
            }
        }
        if (bingo) return 1;
    }

    // Check columns
    for (col = 0; col < SIZE; col++) {
        int bingo = 1;
        for (row = 0; row < SIZE; row++) {
            if (!card->marked[row][col]) {
                bingo = 0;
                break;
            }
        }
        if (bingo) return 1;
    }

    // Check diagonals
    int bingo = 1;
    for (row = 0; row < SIZE; row++) {
        if (!card->marked[row][row]) {
            bingo = 0;
            break;
        }
    }
    if (bingo) return 1;

    bingo = 1;
    for (row = 0; row < SIZE; row++) {
        if (!card->marked[row][SIZE - 1 - row]) {
            bingo = 0;
            break;
        }
    }
    if (bingo) return 1;

    return 0;
}

void callNumber(int *calledNumbers, int *count) {
    int num;
    do {
        num = rand() % MAX_NUM + 1;
        if (!calledNumbers[num]) {
            calledNumbers[num] = 1;
            (*count)++;
            printf("Called number: %d\n", num);
            break;
        }
    } while (1);
}

int main() {
    srand(time(NULL));

    BingoCard myCard;
    myCard.bingo = 0;
    initializeCard(&myCard);

    printCard(&myCard);

    int calledNumbers[MAX_NUM] = {0};
    int numberOfCalls = 0;

    while (!myCard.bingo) {
        callNumber(calledNumbers, &numberOfCalls);
        markNumber(&myCard, calledNumbers[numberOfCalls]);

        printCard(&myCard);
        myCard.bingo = checkBingo(&myCard);
        if (myCard.bingo) {
            printf("Bingo! You won after %d calls!\n", numberOfCalls);
        }
    }

    return 0;
}