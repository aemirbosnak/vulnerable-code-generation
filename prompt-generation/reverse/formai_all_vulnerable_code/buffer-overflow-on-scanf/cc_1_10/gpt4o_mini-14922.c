//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_NUMBER 75

void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]);
void printCard(int card[BINGO_SIZE][BINGO_SIZE]);
bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE]);
void drawNumber(int *drawnNumbers, int *numDrawn);
void markCard(int drawnNumber, int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE]);

int main() {
    int bingoCard[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE] = {false};
    int drawnNumbers[MAX_NUMBER] = {0};
    int numDrawn = 0;
    char continueGame;

    printf("Welcome to the Enchanted Bingo Night!\n");
    printf("Let the magic of love guide you as you play.\n\n");

    initializeCard(bingoCard);
    printCard(bingoCard);
    printf("Your card is ready! Let's begin the dance of numbers...\n");

    do {
        drawNumber(drawnNumbers, &numDrawn);
        printf("\nThe drawn number is... %d 🌟\n", drawnNumbers[numDrawn - 1]);
        markCard(drawnNumbers[numDrawn - 1], bingoCard, marked);

        printCard(bingoCard);

        if (checkBingo(bingoCard, marked)) {
            printf("Congratulations! You've found a magical Bingo! 💖\n");
            break;
        }

        printf("Would you like to continue playing? (y/n): ");
        scanf(" %c", &continueGame);
    } while (continueGame == 'y');

    printf("Thank you for sharing this romantic Bingo night! 💌\n");
    return 0;
}

void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int i, j;
    srand(time(NULL));

    for (j = 0; j < BINGO_SIZE; j++) {
        int start = j * 15 + 1;
        int end = start + 14;
        int nums[BINGO_SIZE] = {0};

        for (i = 0; i < BINGO_SIZE; ) {
            int num = rand() % (end - start + 1) + start;
            bool alreadyExists = false;
            for (int k = 0; k < i; k++) {
                if (nums[k] == num) {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists) {
                nums[i++] = num;
            }
        }

        for (i = 0; i < BINGO_SIZE; i++) {
            card[i][j] = nums[i];
        }
    }
    card[2][2] = 0; // free space
}

void printCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf("\nYour Bingo Card:\n");
    printf("-------------------\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == 0) {
                printf(" *  ");
            } else {
                printf("%2d  ", card[i][j]);
            }
        }
        printf("\n");
    }
    printf("-------------------\n");
}

bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE]) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (marked[i][0] && marked[i][1] && marked[i][2] && marked[i][3] && marked[i][4]) {
            return true; // Check rows
        }
        if (marked[0][i] && marked[1][i] && marked[2][i] && marked[3][i] && marked[4][i]) {
            return true; // Check columns
        }
    }
    if (marked[0][0] && marked[1][1] && marked[2][2] && marked[3][3] && marked[4][4]) {
        return true; // Check diagonal
    }
    if (marked[0][4] && marked[1][3] && marked[2][2] && marked[3][1] && marked[4][0]) {
        return true; // Check other diagonal
    }
    return false;
}

void drawNumber(int *drawnNumbers, int *numDrawn) {
    int newNumber;
    while (true) {
        newNumber = rand() % MAX_NUMBER + 1;
        bool alreadyDrawn = false;
        for (int i = 0; i < *numDrawn; i++) {
            if (drawnNumbers[i] == newNumber) {
                alreadyDrawn = true;
                break;
            }
        }
        if (!alreadyDrawn) {
            drawnNumbers[*numDrawn] = newNumber;
            (*numDrawn)++;
            break;
        }
    }
}

void markCard(int drawnNumber, int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE]) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == drawnNumber) {
                marked[i][j] = true;
            }
        }
    }
}