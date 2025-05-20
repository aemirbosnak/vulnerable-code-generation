//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void displayGrid(char grid[][3]);
void getPlayerMove(char grid[][3], char player);
int getComputerMove(char grid[][3]);
char checkForWin(char grid[][3]);

int main() {
    char grid[3][3] = { {' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '} };
    char player = 'X';
    char winner = ' ';

    //randomly decide who goes first
    srand(time(NULL));
    int first = rand() % 2; //0 for computer, 1 for player
    if (first == 0) {
        printf("Computer goes first!\n");
        getPlayerMove(grid, player); //player makes move first
        player = 'O';
    }
    else {
        printf("Player goes first!\n");
        player = 'X';
    }

    //game loop
    while (winner == ' ') {
        displayGrid(grid);
        if (player == 'X') {
            getPlayerMove(grid, player);
        }
        else {
            int move = getComputerMove(grid);
            printf("Computer chooses (%d, %d)\n", move / 3, move % 3);
            grid[move / 3][move % 3] = player;
        }
        winner = checkForWin(grid);
        //switch player
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }

    //display winner
    displayGrid(grid);
    printf("%c wins!!\n", winner);

    return 0;
}

void displayGrid(char grid[][3]) {
    printf("   0 1 2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d |", i);
        for (int j = 0; j < 3; j++) {
            printf("%c|", grid[i][j]);
        }
        printf("\n");
    }
}

void getPlayerMove(char grid[][3], char player) {
    int row, col;
    do {
        printf("Enter your move (row, col): ");
        scanf("%d %d", &row, &col);
    } while (row < 0 || row > 2 || col < 0 || col > 2 || grid[row][col] != ' ');
    grid[row][col] = player;
}

int getComputerMove(char grid[][3]) {
    //try to win
    for (int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        if (grid[row][col] == ' ') {
            grid[row][col] = 'O';
            char winner = checkForWin(grid);
            if (winner == 'O') {
                grid[row][col] = ' ';
                return i;
            }
            grid[row][col] = ' ';
        }
    }
    //try to block
    for (int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        if (grid[row][col] == ' ') {
            grid[row][col] = 'X';
            char winner = checkForWin(grid);
            if (winner == 'X') {
                grid[row][col] = 'O';
                return i;
            }
            grid[row][col] = ' ';
        }
    }
    //make a random move
    int move;
    do {
        move = rand() % 9;
    } while (grid[move / 3][move % 3] != ' ');
    grid[move / 3][move % 3] = 'O';
    return move;
}

char checkForWin(char grid[][3]) {
    //check rows
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
            return grid[i][0];
        }
    }
    //check columns
    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
            return grid[0][i];
        }
    }
    //check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
        return grid[0][0];
    }
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
        return grid[0][2];
    }
    //check for tie
    for (int i = 0; i < 9; i++) {
        int row = i / 3;
        int col = i % 3;
        if (grid[row][col] == ' ') {
            return ' ';
        }
    }
    //no winner and no tie
    return 'T';
}