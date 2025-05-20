//FormAI DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void generateRandomCards(int arr[ROWS][COLS], int numOfCards);
void shuffleCards(int arr[ROWS][COLS], int numOfCards);
void displayCards(int arr[ROWS][COLS], int numOfCards);
void playGame(int arr[ROWS][COLS], int numOfCards);

int main() {
    int numOfCards = ROWS * COLS / 2;
    int cards[ROWS][COLS];

    generateRandomCards(cards, numOfCards);
    shuffleCards(cards, numOfCards);
    displayCards(cards, numOfCards);
    playGame(cards, numOfCards);

    return 0;
}

void generateRandomCards(int arr[ROWS][COLS], int numOfCards) {
    int num = 1;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(num > numOfCards) {
                arr[i][j] = 0;
                continue;
            }
            arr[i][j] = num / 2;
            num++;
        }
    }
}

void shuffleCards(int arr[ROWS][COLS], int numOfCards) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int randRow = rand() % ROWS;
            int randCol = rand() % COLS;

            int temp = arr[i][j];
            arr[i][j] = arr[randRow][randCol];
            arr[randRow][randCol] = temp;
        }
    }
}

void displayCards(int arr[ROWS][COLS], int numOfCards) {
    printf("Memory Game\n\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(arr[i][j] == 0) {
                printf(" * ");
            } else {
                printf(" %d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

void playGame(int arr[ROWS][COLS], int numOfCards) {
    int numCorrect = 0;
    int numAttempts = 0;
    int firstRow, firstCol, secondRow, secondCol;

    while(numCorrect < numOfCards) {
        printf("Enter the row and column number of the two cards you want to flip: ");
        scanf("%d %d %d %d", &firstRow, &firstCol, &secondRow, &secondCol);

        if(firstRow < 1 || firstRow > ROWS || firstCol < 1 || firstCol > COLS || secondRow < 1 || secondRow > ROWS || secondCol < 1 || secondCol > COLS) {
            printf("Invalid row or column number. Try again.\n");
            continue;
        }

        if(firstRow == secondRow && firstCol == secondCol) {
            printf("You cannot choose the same card twice. Try again.\n");
            continue;
        }

        if(arr[firstRow-1][firstCol-1] == 0 || arr[secondRow-1][secondCol-1] == 0) {
            printf("One or both of the cards you chose is already flipped over. Try again.\n");
            continue;
        }

        int firstCard = arr[firstRow-1][firstCol-1];
        int secondCard = arr[secondRow-1][secondCol-1];

        if(firstCard == secondCard) {
            printf("You got a match!\n");
            arr[firstRow-1][firstCol-1] = 0;
            arr[secondRow-1][secondCol-1] = 0;
            numCorrect++;
        } else {
            printf("Sorry, no match. Try again.\n");
        }

        numAttempts++;
    }

    printf("Congratulations! You won in %d attempts!\n", numAttempts);
}