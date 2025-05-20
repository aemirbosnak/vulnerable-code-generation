//FormAI DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printBoard(int board[ROWS][COLS]);
int getRandomNumber(int min, int max);
void playGame(int board[ROWS][COLS]);

int main()
{
    int board[ROWS][COLS] = {0};
  
    srand(time(NULL)); // seed random number generator with time
  
    // randomly place X's on the board
    for (int i = 0; i < 5; i++) {
        int row = getRandomNumber(0, ROWS-1);
        int col = getRandomNumber(0, COLS-1);
        if (board[row][col] == 0) {
            board[row][col] = 1;
        }
    }
  
    printf("Welcome to the X's and O's game!\n");
    printf("--------------------------------\n\n");
  
    printBoard(board); // print initial board
  
    playGame(board); // start the game
  
    return 0;
}

// prints the current state of the board
void printBoard(int board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else if (board[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// returns a random integer between min and max (inclusive)
int getRandomNumber(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// handles the logic of the game
void playGame(int board[ROWS][COLS])
{
    int score = 0;
    int row, col;
  
    // loop until all X's have been replaced
    while (score < 5) {
        printf("Enter the row and column number to place an O:\n");
        scanf("%d %d", &row, &col);
    
        // check if input is out of bounds
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid input! Please enter a valid row and column number.\n\n");
            continue;
        }
    
        // check if selected cell has already been filled
        if (board[row][col] == 2) {
            printf("That cell has already been filled! Please select another one.\n\n");
        } else {
            // place an O in the selected cell
            board[row][col] = 2;
        
            // check if an X was in this cell
            if (board[row][col] == 1) {
                score++;
                printf("You have replaced an X with an O! Score: %d\n\n", score);
            } else {
                printf("You placed an O in an empty cell. Try again.\n\n");
            }
        }
    
        printBoard(board); // print the updated board
    }
  
    printf("Congratulations! You have replaced all X's with O's and won the game!\n");
}