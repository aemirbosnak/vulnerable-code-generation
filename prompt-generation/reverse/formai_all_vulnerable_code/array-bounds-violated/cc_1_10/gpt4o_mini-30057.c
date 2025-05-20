//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_NUMBER 75

void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int numbers[BINGO_SIZE * BINGO_SIZE];
    for (int i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle the numbers
    for (int i = MAX_NUMBER - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill the card
    int idx = 0;
    for (int col = 0; col < BINGO_SIZE; col++) {
        for (int row = 0; row < BINGO_SIZE; row++) {
            card[row][col] = numbers[idx++];
        }
    }

    // Set the center to a free space
    card[2][2] = 0; // Free space!
}

void displayCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf("Here is your Bingo Card! 🎉\n");
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == 0) {
                printf(" *  "); // Free space
            } else {
                printf("%2d  ", card[row][col]);
            }
        }
        printf("\n");
    }
}

bool markCard(int card[BINGO_SIZE][BINGO_SIZE], int number) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == number) {
                card[row][col] = -1; // Mark the number
                return true;
            }
        }
    }
    return false;
}

bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE]) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((card[i][0] == -1 && card[i][1] == -1 && card[i][2] == -1 && card[i][3] == -1 && card[i][4] == -1) ||
            (card[0][i] == -1 && card[1][i] == -1 && card[2][i] == -1 && card[3][i] == -1 && card[4][i] == -1)) {
            return true;
        }
    }

    // Check diagonals
    if ((card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1 && card[3][3] == -1 && card[4][4] == -1) ||
        (card[0][4] == -1 && card[1][3] == -1 && card[2][2] == -1 && card[3][1] == -1 && card[4][0] == -1)) {
        return true;
    }

    return false;
}

int main() {
    srand(time(NULL));
    
    int card[BINGO_SIZE][BINGO_SIZE];
    initializeCard(card);

    displayCard(card);

    int calledNumber;
    printf("Let's play Bingo! 😃\n");
    printf("Enter -1 to quit.\n");

    while (true) {
        printf("Enter a called number (1-75): ");
        scanf("%d", &calledNumber);

        if (calledNumber == -1) {
            printf("Thanks for playing! Goodbye! 🎉\n");
            break;
        }
        
        if (calledNumber < 1 || calledNumber > 75) {
            printf("Please enter a valid number between 1 and 75.\n");
            continue;
        }

        if (markCard(card, calledNumber)) {
            printf("Marked %d on your card!\n", calledNumber);
            displayCard(card);
        } else {
            printf("%d is not on your card.\n", calledNumber);
        }

        if (checkBingo(card)) {
            printf("BINGO! You win! 🥳🎊\n");
            break;
        }
    }
    
    return 0;
}