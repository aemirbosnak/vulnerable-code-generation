//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 4
#define NUM_COLS 4
#define NUM_PAIRS 8

int main() {
    int board[NUM_ROWS][NUM_COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int matches = 0;
    int turns = 0;
    int choice;
    int flag = 0;
    int player = 1;
    int comp_choice;
    int i, j;
    srand(time(0));

    printf("Welcome to the Memory Game!\n");
    printf("You will be player 1 and the computer will be player 2.\n");
    printf("There are %d pairs of cards on the board.\n", NUM_PAIRS);
    printf("Player 1, please choose a card:\n");

    while (flag == 0) {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 16) {
            if (board[player - 1][choice - 1]!= -1) {
                board[player - 1][choice - 1] = -1;
                matches++;
                turns++;
                player = 2;
                flag = 1;
            } else {
                printf("Sorry, you already chose that card.\n");
                turns++;
            }
        } else {
            printf("Invalid choice, please try again.\n");
            turns++;
        }
    }

    while (flag == 0) {
        comp_choice = rand() % 16 + 1;
        if (board[2][comp_choice - 1]!= -1) {
            board[2][comp_choice - 1] = -1;
            matches++;
            turns++;
            player = 1;
            flag = 1;
        }
    }

    while (flag == 0) {
        i = 0;
        j = 0;
        while (i < NUM_ROWS && j < NUM_COLS) {
            if (board[0][j] == board[1][j]) {
                board[0][j] = -1;
                board[1][j] = -1;
                matches++;
            }
            j++;
        }
        i++;
    }

    printf("Game over!\n");
    printf("You made %d matches in %d turns.\n", matches, turns);

    return 0;
}