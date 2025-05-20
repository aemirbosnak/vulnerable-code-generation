//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//initialize the tic tac toe board
char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

//function to check if the game is over
int isGameOver() {
    //check for horizontal win
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    //check for vertical win
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    //check for diagonal win
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ') {
        return 1;
    }
    //check for tie
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 2;
}

//function to print the tic tac toe board
void printBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

//function for the AI to take its turn
void aiTurn(char symbol) {
    int i, j;
    printf("The AI is thinking...\n");
    //pause for a moment to simulate thinking
    for(int k = 0; k < 100000000; k++);
    //generate random coordinates until an empty space is found
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while(board[i][j] != ' ');
    //update the board
    board[i][j] = symbol;
    printf("The AI's move:\n");
    printBoard();
}

int main() {
    printf("Welcome to the surreal game of tic tac toe!\n");
    printf("You will be playing against the AI in a surrealist battle of wits.\n");
    //wait for the player to hit enter to start the game
    getchar();
    //initialize the random number generator with the current time
    srand((unsigned) time(NULL));
    //print the initial board
    printBoard();
    //game loop
    while(1) {
        //player's turn
        int row, col;
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        //validate input and update the board
        if(row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == ' ') {
            board[row-1][col-1] = 'X';
            printf("Your move:\n");
            printBoard();
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }
        //check for game over
        int result = isGameOver();
        if(result == 1) {
            printf("Congradulations! You won!\n");
            break;
        } else if(result == 2) {
            printf("It's a tie!\n");
            break;
        }
        //AI's turn
        aiTurn('O');
        //check for game over
        result = isGameOver();
        if(result == 1) {
            printf("Sorry, the AI won. Better luck next time!\n");
            break;
        } else if(result == 2) {
            printf("It's a tie!\n");
            break;
        }
    }
    return 0;
}