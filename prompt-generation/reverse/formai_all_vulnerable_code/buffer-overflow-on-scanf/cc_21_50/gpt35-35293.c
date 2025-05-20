//FormAI DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int playerTurn = 1;  //Variable to keep track of player's turn
    int table[10] = {0};  //Variable to store our table state
    int positionChoice;  //Variable to store player input for choosing cells
    int remainingCells = 9;  //Variable to keep track of remaining empty cells
    int winner = 0;  //Variable to store who won the game

    srand(time(NULL)); //Seed the randomizer with time

    printf("\n>>> Welcome to the Unique C Table Game! <<<\n\n");
    printf("Rules: This game between two players can be played on a 3x3 table.\n\
Each player can choose an empty cell number from 1 to 9 to place their mark (either 'X' or 'O').\n\
The objective of the game is to place three marks in a row, horizontally, vertically, or diagonally.\n\n");

    //Repeat until there's a winner or the table is full
    while(remainingCells > 0 && winner == 0){
        //Show the current table state
        printf("Table:\n");
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                printf("%c ", table[i*3 + j] == 0 ? '_' : table[i*3 + j]);
            }
            printf("\n");
        }

        //Ask the player to choose a cell
        printf("\nPlayer %d (%c), choose a cell number: ", playerTurn, playerTurn == 1 ? 'X' : 'O');
        scanf("%d", &positionChoice);

        //Check if the position choice is valid
        if(positionChoice > 0 && positionChoice < 10 && table[positionChoice-1] == 0){
            //Place the player's mark in the chosen cell
            table[positionChoice-1] = playerTurn == 1 ? 'X' : 'O';

            //Check if the player won
            if(
                ((table[0] == table[1] && table[1] == table[2] && table[0] != 0) ||  //Top row
                (table[3] == table[4] && table[4] == table[5] && table[3] != 0) ||  //Middle row
                (table[6] == table[7] && table[7] == table[8] && table[6] != 0) ||  //Bottom row
                (table[0] == table[3] && table[3] == table[6] && table[0] != 0) ||  //Left column
                (table[1] == table[4] && table[4] == table[7] && table[1] != 0) ||  //Middle column
                (table[2] == table[5] && table[5] == table[8] && table[2] != 0) ||  //Right column
                (table[0] == table[4] && table[4] == table[8] && table[0] != 0) ||  //Diagonal top-left to bottom-right
                (table[2] == table[4] && table[4] == table[6] && table[2] != 0))   //Diagonal bottom-left to top-right
            ){
                winner = playerTurn;
            }

            //Switch to next player's turn
            playerTurn = playerTurn == 1 ? 2 : 1;
            remainingCells--;
        }
        else{
            //The position choice was not valid
            printf("Invalid position choice, please choose an empty cell number from 1 to 9!\n");
        }
    }

    //Show the final table state
    printf("Table:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%c ", table[i*3 + j] == 0 ? '_' : table[i*3 + j]);
        }
        printf("\n");
    }

    //Check if there's a winner or a draw
    if(winner > 0){
        printf("Player %d (%c) won the game! Congratulations!\n", winner, winner == 1 ? 'X' : 'O');
    }
    else{
        printf("The game is a draw! Good job both players!\n");
    }

    return 0;
}