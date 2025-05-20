//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main() {
    int i, j, k, c, x, y, score;
    char board[ROWS][COLS], ship[3] = {'S', 'S', 'S'}, guess[3] = {'_', '_', '_'};
    srand(time(0));
    
    // initialize board with empty spaces
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    
    // randomly place the ship horizontally
    x = rand() % ROWS;
    y = rand() % (COLS - 2);
    for(i = 0; i < 3; i++) {
        board[x][y+i] = ship[i];
    }
    
    // print the board with hidden ship
    printf("   A B C D E F G H I J\n");
    for(i = 0; i < ROWS; i++) {
        printf("%2d ", i+1);
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == 'S') {
                printf("_ ");
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
    
    // game loop
    score = 0;
    while(1) {
        // ask for user input
        printf("Enter row and column (e.g. 3B): ");
        scanf("%d%c", &c, &k);
        x = c - 1;
        y = k - 'A';
        
        // check for hit/miss
        if(board[x][y] == 'S') {
            printf("Hit!\n");
            board[x][y] = 'H';
            guess[score] = 'H';
            score++;
        } else {
            printf("Miss!\n");
            guess[score] = 'M';
            score++;
        }
        if(score == 3) {
            // print the board with revealed ship and guesses
            printf("   A B C D E F G H I J\n");
            for(i = 0; i < ROWS; i++) {
                printf("%2d ", i+1);
                for(j = 0; j < COLS; j++) {
                    if(board[i][j] == 'S') {
                        printf("_ ");
                    } else if(board[i][j] == 'H') {
                        printf("X ");
                    } else if(board[i][j] == 'M') {
                        printf("O ");
                    } else {
                        printf("%c ", board[i][j]);
                    }
                }
                printf("\n");
            }
            // print the user's guesses
            printf("Your guesses: ");
            for(i = 0; i < 3; i++) {
                printf("%c ", guess[i]);
            }
            printf("\n");
            // exit the game
            break;
        }
    }
    
    return 0;
}