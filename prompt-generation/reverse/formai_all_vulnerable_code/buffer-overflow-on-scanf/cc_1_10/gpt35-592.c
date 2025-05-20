//FormAI DATASET v1.0 Category: Game ; Style: Donald Knuth
/*The following program is a game called "Whack-A-Mole" written in the style of Donald Knuth*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

/*Function to display the game board*/
void display_board(char board[ROWS][COLS]) {
    printf("\n-------------------\n");
    for(int i=0;i<ROWS;i++) {
        printf("|");
        for(int j=0;j<COLS;j++) {
            printf(" %c |",board[i][j]);
        }
        printf("\n-------------------\n");
    }
}

int main() {

    /*Variable Declarations*/
    char board[ROWS][COLS];
    int score = 0, time_spent = 0;

    /*Seed for random number generation*/
    srand(time(NULL));

    /*Initializing the board*/
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            board[i][j] = '-';
        }
    }

    /*Main game loop*/
    while(1) {

        /*Display the board*/
        display_board(board);

        /*Generate random mole coordinates*/
        int x = rand() % ROWS;
        int y = rand() % COLS;

        /*Place the mole on the board*/
        board[x][y] = 'M';

        /*Get user input for mole whack*/
        printf("Enter row and column to whack the mole: ");
        int row, col;
        scanf("%d %d",&row,&col);

        /*Whack the mole if user input is same as mole coordinates*/
        if(row == x && col == y) {
            printf("You whacked the mole!\n");
            board[x][y] = '-';
            score++;
        }
        else {
            printf("Missed!\n");
        }

        /*Calculate time spent and end game if time limit reached*/
        time_spent++;
        if(time_spent == 30) {
            printf("Game over! Your score is %d\n",score);
            break;
        }
    }

    return 0;
}