//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define MAX_NUM 75

void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]);
void printCard(int card[BINGO_SIZE][BINGO_SIZE]);
void drawNumbers(int drawn[], int *drawCount);
int checkForBingo(int card[BINGO_SIZE][BINGO_SIZE], int drawn[], int drawCount);
void markNumber(int card[BINGO_SIZE][BINGO_SIZE], int number);
void playBingo();
void playMultipleGames(int numGames);

int main() {
    int numGames;

    printf("Welcome to the Bingo Simulator!\n");
    printf("How many games would you like to play? ");
    scanf("%d", &numGames);

    playMultipleGames(numGames);
    return 0;
}

void playMultipleGames(int numGames) {
    for (int i = 0; i < numGames; i++) {
        printf("\nStarting Game %d:\n", i + 1);
        playBingo();
    }
}

void playBingo() {
    int card[BINGO_SIZE][BINGO_SIZE];
    int drawn[MAX_NUM] = {0};
    int drawCount = 0;

    initializeCard(card);
    printCard(card);
    
    while (1) {
        drawNumbers(drawn, &drawCount);

        printf("\nNumbers drawn so far: ");
        for (int i = 0; i < drawCount; i++) {
            printf("%d ", drawn[i]);
        }
        printf("\n");

        markNumber(card, drawn[drawCount - 1]);
        printCard(card);

        if (checkForBingo(card, drawn, drawCount)) {
            printf("\nBingo! You've won!\n");
            break;
        }

        char choice;
        printf("Do you want to continue drawing? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') {
            break;
        }
    }
}

void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int numbers[MAX_NUM] = {0};
    srand(time(NULL));
    
    // Fill the card, ensuring numbers per column are unique and within range
    for (int col = 0; col < BINGO_SIZE; col++) {
        int lowerBound = col * 15 + 1;
        int upperBound = lowerBound + 14;
        int count = 0;

        while (count < BINGO_SIZE) {
            int num = rand() % (upperBound - lowerBound + 1) + lowerBound;
            if (!numbers[num - 1]) {
                card[count][col] = num;
                numbers[num - 1] = 1; // Mark this number as used
                count++;
            }
        }
    }
    card[2][2] = 0; // Free space in the center
}

void printCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf("\nBINGO CARD:\n");
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == 0) {
                printf(" *  ");
            } else {
                printf("%2d  ", card[row][col]);
            }
        }
        printf("\n");
    }
}

void drawNumbers(int drawn[], int *drawCount) {
    static int numbersDrawn[MAX_NUM] = {0};
    
    if (*drawCount >= MAX_NUM) {
        printf("All numbers have been drawn!\n");
        return;
    }

    int number;
    do {
        number = rand() % MAX_NUM + 1;
    } while (numbersDrawn[number - 1]);

    numbersDrawn[number - 1] = 1; // Mark number as drawn
    drawn[(*drawCount)++] = number; // Add to drawn list
}

int checkForBingo(int card[BINGO_SIZE][BINGO_SIZE], int drawn[], int drawCount) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        int winRow = 1;
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] != 0 && !marked(card[row][col], drawn, drawCount)) {
                winRow = 0;
                break;
            }
        }
        if (winRow) return 1; // Win detected
    }

    for (int col = 0; col < BINGO_SIZE; col++) {
        int winCol = 1;
        for (int row = 0; row < BINGO_SIZE; row++) {
            if (card[row][col] != 0 && !marked(card[row][col], drawn, drawCount)) {
                winCol = 0;
                break;
            }
        }
        if (winCol) return 1; // Win detected
    }

    // Check diagonals
    int winDiagonal1 = 1, winDiagonal2 = 1;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card[i][i] != 0 && !marked(card[i][i], drawn, drawCount)) {
            winDiagonal1 = 0;
        }
        if (card[i][BINGO_SIZE - 1 - i] != 0 && !marked(card[i][BINGO_SIZE - 1 - i], drawn, drawCount)) {
            winDiagonal2 = 0;
        }
    }
    return winDiagonal1 || winDiagonal2; // Win detected
}

int marked(int number, int drawn[], int drawCount) {
    for (int i = 0; i < drawCount; i++) {
        if (drawn[i] == number) {
            return 1; // Number is marked
        }
    }
    return 0; // Number is not marked
}

void markNumber(int card[BINGO_SIZE][BINGO_SIZE], int number) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == number) {
                card[row][col] = 0; // Mark the number
            }
        }
    }
}