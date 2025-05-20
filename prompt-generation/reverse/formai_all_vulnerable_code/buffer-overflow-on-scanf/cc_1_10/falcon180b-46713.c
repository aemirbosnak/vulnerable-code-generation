//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: excited
/* C Bingo Simulator */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateBingoCard(int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            card[i][j] = rand() % 15 + 1;
        }
    }
}

void printBingoCard(int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int checkBingo(int card[ROWS][COLS], int num) {
    int i, j, count = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == num) {
                count++;
            }
        }
    }
    if (count == 5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int bingoCard[ROWS][COLS];
    int playerCard[ROWS][COLS];
    int num, count = 0;
    srand(time(NULL));
    generateBingoCard(bingoCard);
    printf("Bingo Card:\n");
    printBingoCard(bingoCard);
    printf("\n");
    while (count < 5) {
        printf("Enter a number between 1 and 15: ");
        scanf("%d", &num);
        if (checkBingo(bingoCard, num)) {
            printf("Bingo!\n");
            count++;
        } else {
            printf("Sorry, %d is not on your card.\n", num);
        }
    }
    return 0;
}

/* End of C Bingo Simulator */