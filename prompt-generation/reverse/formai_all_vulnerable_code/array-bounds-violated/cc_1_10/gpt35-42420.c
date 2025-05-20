//FormAI DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void printBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle(char cards[]) {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE - 1; i++) {
        int j = i + rand() / (RAND_MAX / (BOARD_SIZE * BOARD_SIZE - i) + 1);
        char temp = cards[j];
        cards[j] = cards[i];
        cards[i] = temp;
    }
}

int main() {
    char cards[BOARD_SIZE * BOARD_SIZE];

    // Initialize the cards
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i+=2) {
        cards[i] = i/2 + '0';
        cards[i+1] = i/2 + '0';
    }

    shuffle(cards);

    char board[BOARD_SIZE][BOARD_SIZE];
    int index = 0;

    // Fill the board with shuffled cards
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = cards[index];
            index++;
        }
    }

    printf("Welcome to the Memory Game!\n");

    char input[10];
    int firstSelectionRow, firstSelectionCol;
    int secondSelectionRow, secondSelectionCol;
    int tries = 0;

    do {
        printBoard(board);

        printf("Enter the row and column of your first selection: ");
        fgets(input, 10, stdin);
        sscanf(input, "%d%d", &firstSelectionRow, &firstSelectionCol);

        printf("Enter the row and column of your second selection: ");
        fgets(input, 10, stdin);
        sscanf(input, "%d%d", &secondSelectionRow, &secondSelectionCol);

        if (board[firstSelectionRow][firstSelectionCol] == board[secondSelectionRow][secondSelectionCol]) {
            printf("Matched!\n");
            board[firstSelectionRow][firstSelectionCol] = ' ';
            board[secondSelectionRow][secondSelectionCol] = ' ';
        } else {
            printf("Not a match.\n");
        }

        tries++;

    } while (tries < BOARD_SIZE*BOARD_SIZE/2);

    printf("Congratulations! You have completed the Memory Game in %d tries.\n", tries);

    return 0;
}