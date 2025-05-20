//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the table
void printTable(int table[3][3]) {
    printf("  1 2 3 \n");
    printf("--------\n");
    for(int i=0; i<3; i++){
        printf("%c| ", 'A' + i);
        for(int j=0; j<3; j++){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

// function to check if there is a winner
int checkWinner(int table[3][3], int player) {
    // check rows
    for(int i=0; i<3; i++){
        if(table[i][0] == player && table[i][1] == player && table[i][2] == player){
            return 1;
        }
    }
    // check columns
    for(int j=0; j<3; j++){
        if(table[0][j] == player && table[1][j] == player && table[2][j] == player){
            return 1;
        }
    }
    // check diagonals
    if(table[0][0] == player && table[1][1] == player && table[2][2] == player){
        return 1;
    }
    if(table[0][2] == player && table[1][1] == player && table[2][0] == player){
        return 1;
    }
    return 0;
}

// function to play the game
void playGame() {
    // initialize the table
    int table[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            table[i][j] = 0;
        }
    }
    
    // initialize the players
    int player1 = 1;
    int player2 = 2;
    
    // initialize the current player
    int currentPlayer = player1;
    
    // initialize the number of moves
    int moves = 0;
    
    // play the game
    while(moves < 9){
        // print the table
        printTable(table);
        
        // get input from the player
        char row;
        int col;
        printf("Player %d's turn. Enter a position (e.g. A2): ", currentPlayer);
        scanf(" %c%d", &row, &col);
        
        // convert the input to table indices
        int rowIndex = row - 'A';
        int colIndex = col - 1;
        
        // check if the position is valid
        if(table[rowIndex][colIndex] != 0){
            printf("Position already taken. Try again.\n");
            continue;
        }
        
        // update the table
        table[rowIndex][colIndex] = currentPlayer;
        
        // check if there is a winner
        if(checkWinner(table, currentPlayer)){
            printf("Player %d wins!\n", currentPlayer);
            return;
        }
        
        // switch to the other player
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
        
        // increment the number of moves
        moves++;
    }
    
    // if there is no winner and all positions are taken, it's a tie
    printf("It's a tie!\n");
}

int main() {
    srand(time(NULL)); // initialize the random seed
    
    while(1){ // loop to play multiple games
        // print the menu
        printf("MENU:\n");
        printf("1. Play game\n");
        printf("2. Quit\n");
        printf("Select an option: ");
        
        // get input from the user
        int option;
        scanf("%d", &option);
        
        switch(option){
            case 1:
                playGame(); // play the game
                break;
            case 2:
                printf("Goodbye!\n"); // exit the program
                exit(0);
            default:
                printf("Invalid option. Try again.\n"); // invalid option
        }
    }
    
    return 0;
}