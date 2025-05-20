//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char player = 'X';
int moves = 0;

void drawBoard(){
    printf("\n\n   Tic Tac Toe\n");
    printf("   ------------\n\n");
    printf("   %c | %c | %c\n",board[0][0],board[0][1],board[0][2]);
    printf("   --+---+--\n");
    printf("   %c | %c | %c\n",board[1][0],board[1][1],board[1][2]);
    printf("   --+---+--\n");
    printf("   %c | %c | %c\n",board[2][0],board[2][1],board[2][2]);
}

int checkWin(){
    int i, row, col;
    
    // Check rows and columns for a win
    for(i=0;i<3;i++){
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){  // row win
            return 1;
        }
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){ // column win
            return 1;
        }
    }
    
    // Check diagonals for a win
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){ // diagonal 1 win
        return 1;
    }
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){ // diagonal 2 win
        return 1;
    }
    
    // Check for a draw
    if(moves == 9){
        return 2; // draw
    }
    return 0; // game not over
}

int minimax(int depth, int isMaxPlayer){
    int score = checkWin();
    if(score == 1 || score == 2){ // If there is a win or draw
        if(score == 1){
            return -10; // The computer player wins
        }
        else{
            return 0; // Draw
        }
    }
    if(isMaxPlayer){
        int bestScore = -1000; // The default minimum
        int i, j;
        for(i=0;i<3;i++){ // Check all possible moves
            for(j=0;j<3;j++){
                if(board[i][j] == ' '){ // If the move is valid
                    board[i][j] = 'O'; // Make the move
                    int newScore = minimax(depth+1, 0); // Recursively check the new board
                    board[i][j] = ' '; // Undo the move
                    if(newScore > bestScore){ // Update the best score if necessary
                        bestScore = newScore;
                    }
                }
            }
        }
        return bestScore;
    }
    else{
        int bestScore = 1000; // The default maximum
        int i, j;
        for(i=0;i<3;i++){ // Check all possible moves
            for(j=0;j<3;j++){
                if(board[i][j] == ' '){ // If the move is valid
                    board[i][j] = 'X'; // Make the move
                    int newScore = minimax(depth+1, 1); // Recursively check the new board
                    board[i][j] = ' '; // Undo the move
                    if(newScore < bestScore){ // Update the best score if necessary
                        bestScore = newScore;
                    }
                }
            }
        }
        return bestScore;
    }
}

void computerMove(){
    int i, j, bestScore = -1000, score;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(board[i][j] == ' '){ // If the move is valid
                board[i][j] = 'O'; // Make the move
                score = minimax(0, 0); // Get the score
                board[i][j] = ' '; // Undo the move
                if(score > bestScore){ // Update the best score if necessary
                    bestScore = score;
                    // Set the computer's move to this position
                    board[i][j] = 'O';
                }
            }
        }
    }
}

void playerMove(){
    int row, col;
    printf("\n\n Player %c, enter your move (row,col):",player);
    scanf("%d,%d",&row,&col);
    while(row < 0 || row > 2 || col < 0 || col > 2){
        printf("\n\n Invalid move, please enter your move (row,col):");
        scanf("%d,%d",&row,&col);
    }
    while(board[row][col] != ' '){
        printf("\n\n Spot already taken, please enter your move (row,col):");
        scanf("%d,%d",&row,&col);
    }
    board[row][col] = player;
}

void switchPlayer(){
    if(player == 'X'){
        player = 'O';
    }
    else{
        player = 'X';
    }
}

int main(){
    int win, playAgain = 1;
    while(playAgain == 1){ // While the players want to continue playing
        moves = 0;
        while(1){
            drawBoard();
            playerMove();
            moves++;
            win = checkWin();
            if(win != 0){ // If the game is over
                break;
            }
            computerMove();
            moves++;
            win = checkWin();
            if(win != 0){ // If the game is over
                break;
            }
        }
        drawBoard();
        if(win == 1){
            printf("\n\n Player %c wins!\n",player);
        }
        else{
            printf("\n\n Draw!\n");
        }
        printf("\n\n Do you want to play again? (1 for yes, 0 for no):");
        scanf("%d",&playAgain);
        if(playAgain == 1){
            // Reset the board
            int i, j;
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    board[i][j] = ' ';
                }
            }
        }
    }
    printf("\n\n Thanks for playing!");
    return 0;
}