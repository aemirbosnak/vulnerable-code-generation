//FormAI DATASET v1.0 Category: Memory Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(int board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    for(int i=0;i<BOARD_SIZE;i++) {
        for(int j=0;j<BOARD_SIZE;j++) {
            if(revealed[i][j]) {
                printf("%d\t", board[i][j]);
            } else {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0};
    int score = 0;

    // Fill the board randomly
    srand(time(NULL));
    for(int i=0;i<BOARD_SIZE;i++) {
        for(int j=0;j<BOARD_SIZE;j++) {
            board[i][j] = rand()%10+1;
        }
    }

    // Play the game
    while(score < BOARD_SIZE*BOARD_SIZE/2) { // Game continues until all pairs are found
        print_board(board, revealed);
        printf("Score: %d\n", score);

        // Get the user input
        int x1, y1, x2, y2;
        printf("Enter the coordinates of two cards to reveal (separated by a space): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        // Reveal the cards
        revealed[x1][y1] = 1;
        revealed[x2][y2] = 1;
        if(board[x1][y1] == board[x2][y2]) { // If the cards match
            score++;
        } else { // If the cards do not match
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        }
    }

    // Game over
    printf("Congratulations, you won the game with a score of %d!\n", score);

    return 0;
}