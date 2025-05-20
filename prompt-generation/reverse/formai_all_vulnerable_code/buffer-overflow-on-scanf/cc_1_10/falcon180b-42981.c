//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateCard(int card[5][5], int freeSpace) {
    // Generate a random number between 1 and 15
    int num = rand() % 15 + 1;

    // Check if the number is already in the row or column
    int row = (freeSpace / 5) * 5 + 1;
    int col = freeSpace % 5;
    while (num == card[row][col]) {
        num = rand() % 15 + 1;
    }

    // Place the number on the card
    card[row][col] = num;
}

void printCard(int card[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Initialize the bingo card with random numbers
    int card[5][5] = {{0}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            generateCard(card, 0);
        }
    }

    // Print the initial bingo card
    printf("Initial Bingo Card:\n");
    printCard(card);

    // Start the game
    int num;
    int freeSpace = 0;
    while (freeSpace < 25) {
        printf("Enter a number between 1 and 75: ");
        scanf("%d", &num);

        // Check if the number is on the card
        int row = 0, col = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (card[i][j] == num) {
                    row = i;
                    col = j;
                }
            }
        }

        // Mark the number on the card
        if (row!= 0 && col!= 0) {
            card[row][col] = -1;
            freeSpace++;
        }
    }

    // Check for a bingo
    int bingo = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card[i][j]!= -1) {
                bingo = 0;
                break;
            }
        }
        if (bingo == 1) {
            break;
        }
    }

    // Print the final bingo card
    printf("\nFinal Bingo Card:\n");
    printCard(card);

    if (bingo == 1) {
        printf("\nBingo!");
    } else {
        printf("\nNo bingo.");
    }

    return 0;
}