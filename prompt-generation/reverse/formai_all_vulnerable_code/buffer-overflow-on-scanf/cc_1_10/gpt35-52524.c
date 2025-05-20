//FormAI DATASET v1.0 Category: Table Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0}; // initialize board with all zeroes
    srand(time(NULL)); // seed the random number generator with the current time
    
    // randomly place a single piece on the board
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    board[x][y] = 1;
    
    printf("Welcome to the Peaceful Table Game!\n");
    printf("Your goal is to move the piece to the other side of the board.\n");
    printf("Enter 'u' to move up, 'd' to move down, 'l' to move left, 'r' to move right.\n");
    
    print_board(board);
    
    while (x != BOARD_SIZE - 1) { // keep playing until the piece reaches the other side of the board
        char direction;
        scanf(" %c", &direction); // read the direction input from the user
        
        switch(direction) {
            case 'u':
                if (x > 0) {
                    x--;
                }
                break;
            case 'd':
                if (x < BOARD_SIZE - 1) {
                    x++;
                }
                break;
            case 'l':
                if (y > 0) {
                    y--;
                }
                break;
            case 'r':
                if (y < BOARD_SIZE - 1) {
                    y++;
                }
                break;
            default:
                printf("Invalid input. Please enter 'u', 'd', 'l', or 'r'\n");
                break;
        }
        
        board[x][y] = 1; // move the piece to the new location
        print_board(board); // print the updated board
    }
    
    printf("Congratulations! You have successfully moved the piece to the other side of the board!\n");
    
    return 0;
}