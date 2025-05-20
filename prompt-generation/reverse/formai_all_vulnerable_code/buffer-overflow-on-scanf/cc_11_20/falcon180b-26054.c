//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols, matches = 0, attempts = 0, choice, flag = 0, player = 1;
    char board[3][3];
    int numbers[6] = {1, 2, 3, 4, 5, 6};
    int values[6];
    srand(time(0));

    // Fill the board with random numbers
    for (int i = 0; i < 6; i++) {
        values[i] = numbers[rand() % 6];
        board[i / 3][i % 3] = values[i] + '0';
    }

    // Print the initial board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    while (matches < 6) {
        // Player's turn
        if (player % 2 == 1) {
            printf("\nPlayer 1's turn\n");
            printf("Enter the number of the card you want to flip: ");
            scanf("%d", &choice);
            choice--;

            if (board[choice / 3][choice % 3] == 'X') {
                printf("You already chose this card!\n");
            } else if (board[choice / 3][choice % 3]!= values[attempts]) {
                printf("Sorry, you chose the wrong card.\n");
                attempts++;
            } else {
                board[choice / 3][choice % 3] = 'X';
                matches++;
                printf("Congratulations, you found a match!\n");
            }
        } else {
            printf("\nPlayer 2's turn\n");
            printf("Enter the number of the card you want to flip: ");
            scanf("%d", &choice);
            choice--;

            if (board[choice / 3][choice % 3] == 'X') {
                printf("You already chose this card!\n");
            } else if (board[choice / 3][choice % 3]!= values[attempts]) {
                printf("Sorry, you chose the wrong card.\n");
                attempts++;
            } else {
                board[choice / 3][choice % 3] = 'X';
                matches++;
                printf("Congratulations, you found a match!\n");
            }
        }

        if (matches == 6) {
            printf("\nGame over! Player %d wins!\n", player);
            break;
        }

        player++;
        if (player > 2) {
            player = 1;
        }
    }

    return 0;
}