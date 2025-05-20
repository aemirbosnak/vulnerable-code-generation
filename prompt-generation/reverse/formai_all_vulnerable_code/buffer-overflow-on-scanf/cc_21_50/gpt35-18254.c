//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 25
#define COL 25

// function to draw the game board
void drawBoard(int board[][COL], int pac_x, int pac_y) {
    
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {

            if(board[i][j] == 0) {
                printf("#");        // draw wall
            }
            else if(i == pac_x && j == pac_y) {
                printf("P");        // draw Pac-Man
            }
            else if(board[i][j] == 1) {
                printf(".");        // draw dot
            }
        }
        printf("\n");
    }
}

int main() {

    // initialize board
    int board[ROW][COL] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,0},
        {0,1,1,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,0,1,0,0,1,0},
        {0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0},
        {0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,0},
        {0,1,0,0,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0},
        {0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,1,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0},
        {0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
        {0,1,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,0,1,1,1,0,1,1,0},
        {0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0,0,0,1,0},
        {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0},
        {0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0},
        {0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,1,1,0,1,1,0},
        {0,1,1,1,1,1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,0,0,1,0},
        {0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,0,1,0,1,1,1,1,1,0},
        {0,1,1,0,1,1,0,0,0,1,1,1,1,0,1,1,1,1,0,0,1,1,1,1,0},
        {0,1,1,0,0,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,0,0,0,1,0},
        {0,1,0,0,1,1,1,0,1,1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,0},
        {0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };

    // initialize position of Pac-Man
    int pac_x = 13;
    int pac_y = 12;

    // set seed for random number generation
    srand(time(NULL));

    // initialize score and loop counter
    int score = 0;
    int counter = 0;

    while(1) {

        system("clear");        // clear the screen
        
        drawBoard(board, pac_x, pac_y);        // draw the game board

        printf("\nScore: %d\n", score);        // display score

        // check if there is no more dots remaining
        int dots_remain = 0;
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COL; j++) {
                if(board[i][j] == 1) {
                    dots_remain = 1;
                    break;
                }
            }
            if(dots_remain) break;
        }
        if(!dots_remain) {
            printf("You Win!\n");
            break;
        }

        // randomly place a power pill
        if(counter == 200) {
            int x, y;
            do {
                x = rand() % ROW;
                y = rand() % COL;
            } while(board[x][y] != 1);
            board[x][y] = 2;
            printf("Power Pill added!\n");
        }

        // check if Pac-Man has eaten a dot or power pill
        if(board[pac_x][pac_y] == 1) {
            board[pac_x][pac_y] = 2;        // mark dot as eaten
            score += 10;
        }
        else if(board[pac_x][pac_y] == 2) {
            board[pac_x][pac_y] = 3;        // mark power pill as eaten
            score += 50;
        }

        // move Pac-Man based on user input
        char input;
        printf("Move (w/a/s/d): ");
        scanf(" %c", &input);

        if(input == 'w') {
            if(pac_x > 0 && board[pac_x-1][pac_y] != 0) pac_x--;
        }
        else if(input == 'a') {
            if(pac_y > 0 && board[pac_x][pac_y-1] != 0) pac_y--;
        }
        else if(input == 's') {
            if(pac_x < ROW-1 && board[pac_x+1][pac_y] != 0) pac_x++;
        }
        else if(input == 'd') {
            if(pac_y < COL-1 && board[pac_x][pac_y+1] != 0) pac_y++;
        }

        // decrement counter
        counter--;

        // wait for a short period of time to slow down the game loop
        for(long int i=0; i<30000000; i++);

        // check if Pac-Man has collided with a ghost
        if(board[pac_x][pac_y] == 4) {
            printf("Game Over!\n");
            break;
        }

        // randomly move the ghosts
        for(int i=1; i<=4; i++) {
            int ghost_x, ghost_y;
            do {
                ghost_x = rand() % ROW;
                ghost_y = rand() % COL;
            } while(board[ghost_x][ghost_y] != i);
            int ghost_next_x = ghost_x, ghost_next_y = ghost_y;
            if(rand() % 2 == 0) {
                if(ghost_x < pac_x && board[ghost_x+1][ghost_y] != 0) ghost_next_x++;
                else if(ghost_x > pac_x && board[ghost_x-1][ghost_y] != 0) ghost_next_x--;
            }
            else {
                if(ghost_y < pac_y && board[ghost_x][ghost_y+1] != 0) ghost_next_y++;
                else if(ghost_y > pac_y && board[ghost_x][ghost_y-1] != 0) ghost_next_y--;
            }
            if(board[ghost_next_x][ghost_next_y] == 2) score += 50;        // increment score if ghost collides with power pill
            if(board[ghost_next_x][ghost_next_y] == 3) board[ghost_next_x][ghost_next_y] = i;        // reset ghost position if it collides with Pac-Man during power pill
            if(board[ghost_next_x][ghost_next_y] == 1 || board[ghost_next_x][ghost_next_y] == 3) board[ghost_next_x][ghost_next_y] = i;        // move ghost if it is possible to move to the next position
        }

        // set Pac-Man's previous position to 1
        board[pac_x][pac_y] = 1;

    }

    return 0;
}