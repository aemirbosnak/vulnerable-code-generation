//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_NUM 75

// Function Prototypes
void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]);
void printCard(int card[BINGO_SIZE][BINGO_SIZE]);
bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE]);
void markCard(int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE], int number);
void generateRandomNumbers(int *numbers, int size);
void shuffle(int *array, int size);

// Main Function
int main() {
    srand(time(NULL));
    int bingoCard[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE] = {{false}};
    int numbers[MAX_NUM];
    int drawnNumber;
    bool gameWon = false;

    initializeCard(bingoCard);
    generateRandomNumbers(numbers, MAX_NUM);
    shuffle(numbers, MAX_NUM);

    printf("Your Bingo Card:\n");
    printCard(bingoCard);

    for (int i = 0; i < MAX_NUM && !gameWon; i++) {
        drawnNumber = numbers[i];
        printf("\nDrawn Number: %d\n", drawnNumber);
        markCard(bingoCard, marked, drawnNumber);
        printCard(bingoCard);

        // Check for Bingo
        gameWon = checkBingo(bingoCard, marked);
        if (gameWon) {
            printf("\nBINGO! You've won!\n");
        } else {
            printf("No Bingo yet.\n");
        }
        getchar(); // Wait for user input to continue
    }

    return 0;
}

// Initialize Bingo Card
void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int cols[BINGO_SIZE][15] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, // B
        {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}, // I
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45}, // N
        {46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60}, // G
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75}  // O
    };

    for (int col = 0; col < BINGO_SIZE; col++) {
        int numberSet[BINGO_SIZE];
        int minIdx = col * 15;
        int maxIdx = minIdx + 15;

        // Pick random numbers for the column
        for (int j = 0; j < BINGO_SIZE; j++) {
            int randIdx = rand() % (maxIdx - minIdx) + minIdx;
            numberSet[j] = cols[col][randIdx];
            cols[col][randIdx] = cols[col][minIdx]; // Avoid picking the same number
            minIdx++;
        }

        for (int j = 0; j < BINGO_SIZE; j++) {
            card[j][col] = numberSet[j];
        }
    }
    card[2][2] = 0; // Free space in the middle
}

// Print Bingo Card
void printCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf(" B   I   N   G   O\n");
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
}

// Mark the Bingo Card
void markCard(int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE], int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == number) {
                marked[i][j] = true;
            }
        }
    }
}

// Check for Bingo
bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE], bool marked[BINGO_SIZE][BINGO_SIZE]) {
    // Check Rows
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (marked[i][0] && marked[i][1] && marked[i][2] && marked[i][3] && marked[i][4]) {
            return true;
        }
    }

    // Check Columns
    for (int j = 0; j < BINGO_SIZE; j++) {
        if (marked[0][j] && marked[1][j] && marked[2][j] && marked[3][j] && marked[4][j]) {
            return true;
        }
    }

    // Check Diagonals
    if (marked[0][0] && marked[1][1] && marked[2][2] && marked[3][3] && marked[4][4]) {
        return true;
    }
    if (marked[0][4] && marked[1][3] && marked[2][2] && marked[3][1] && marked[4][0]) {
        return true;
    }

    return false;
}

// Generate Random Numbers
void generateRandomNumbers(int *numbers, int size) {
    for (int i = 0; i < size; i++) {
        numbers[i] = i + 1;
    }
}

// Shuffle Random Numbers
void shuffle(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}