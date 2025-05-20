//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 3
#define COL_SIZE 3

int bingo[ROW_SIZE][COL_SIZE] = { 0 };
int player[ROW_SIZE][COL_SIZE] = { 0 };

int generateRandomNumber();
void initializeBoard();
void printBoard();
void playGame();
int gameOver();

int main() {

    //Initialize the game board
    initializeBoard();
    
    //Print the game instructions
    printf("Welcome to the C Bingo Simulator!\n\n");
    printf("Instructions:\n");
    printf("1. The computer will randomly generate a number from 1-9.\n");
    printf("2. If the number appears on your board, mark it.\n");
    printf("3. The first player to get three in a row wins!\n\n");
    
    //Print the initial game board
    printBoard();

    //Play the game
    playGame();

    printf("Game Over!\n");
    return 0;
}

//Function to generate a random number from 1-9
int generateRandomNumber() {
    srand(time(NULL));
    return (rand() % 9) + 1;
}

//Function to initialize the game board
void initializeBoard() {
    int i, j;
    for(i = 0; i < ROW_SIZE; i++) {
        for(j = 0; j < COL_SIZE; j++) {
            bingo[i][j] = generateRandomNumber();
        }
    }
}

//Function to print the game board
void printBoard() {
    int i, j;
    for(i = 0; i < ROW_SIZE; i++) {
        for(j = 0; j < COL_SIZE; j++) {
            printf("%d ", player[i][j]);
        }
        printf("\t");
        for(j = 0; j < COL_SIZE; j++) {
            printf("%d ", bingo[i][j]);
        }
        printf("\n\n");
    }
}

//Function to play the game
void playGame() {
    int i, j, count = 0, number;
    while(1) {
        //Prompt the player to enter a number
        printf("Enter a number from 1-9: ");
        scanf("%d", &number);

        //Check if the number is in the game board
        for(i = 0; i < ROW_SIZE; i++) {
            for(j = 0; j < COL_SIZE; j++) {
                if(bingo[i][j] == number) {
                    player[i][j] = number;
                    count++;
                }
            }
        }

        //Print the updated game board
        printBoard();

        //Check if the game is over
        if(gameOver(count)) {
            printf("Congratulations! You have won!\n");
            break;
        }
        else if(count == 9) {
            printf("Sorry, you have lost. Better luck next time!\n");
            break;
        }
    }
}

//Function to check if the game is over
int gameOver(int count) {
    int i, j;

    //Check if any row is complete
    for(i = 0; i < ROW_SIZE; i++) {
        if(player[i][0] != 0 && player[i][0] == player[i][1] && player[i][1] == player[i][2]) {
            return 1;
        }
    }

    //Check if any column is complete
    for(i = 0; i < COL_SIZE; i++) {
        if(player[0][i] != 0 && player[0][i] == player[1][i] && player[1][i] == player[2][i]) {
            return 1;
        }
    }

    //Check if the diagonal is complete
    if(player[0][0] != 0 && player[0][0] == player[1][1] && player[1][1] == player[2][2]) {
        return 1;
    }
    if(player[0][2] != 0 && player[0][2] == player[1][1] && player[1][1] == player[2][0]) {
        return 1;
    }

    return 0;
}