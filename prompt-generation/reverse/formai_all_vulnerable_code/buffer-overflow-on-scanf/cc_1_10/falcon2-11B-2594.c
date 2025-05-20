//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to print the board
void print_board(int board[][8], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check for checkers move
int is_valid_move(int board[][8], int player, int i, int j){
    // Check if the move is valid
    if(board[i][j] == 0){
        return 0;
    }
    else if(board[i][j] == player){
        return 1;
    }
    else if(board[i][j] == -player){
        return -1;
    }
    else{
        return 0;
    }
}

// Function to make a move
void make_move(int board[][8], int player, int i, int j){
    // Make the move
    board[i][j] = player;
}

// Function to check for checkers win
int is_checkers_win(int board[][8], int player){
    // Check for a win
    for(int i=0; i<8; i++){
        if(board[i][0] == player && board[i][7] == player){
            return 1;
        }
        if(board[0][i] == player && board[7][i] == player){
            return 1;
        }
        if(board[0][0] == player && board[7][7] == player){
            return 1;
        }
        if(board[0][7] == player && board[7][0] == player){
            return 1;
        }
    }
    return 0;
}

// Function to check for checkers draw
int is_checkers_draw(int board[][8]){
    // Check for a draw
    for(int i=0; i<8; i++){
        if(board[i][0] == 0 && board[i][7] == 0){
            return 1;
        }
        if(board[0][i] == 0 && board[7][i] == 0){
            return 1;
        }
        if(board[0][0] == 0 && board[7][7] == 0){
            return 1;
        }
        if(board[0][7] == 0 && board[7][0] == 0){
            return 1;
        }
    }
    return 0;
}

// Function to play a checkers game
void play_checkers(int board[][8]){
    int player_turn;
    int i, j;

    // Print the initial board
    print_board(board, 8);

    // Play until a winner or a draw is determined
    while(1){
        // Print the board
        print_board(board, 8);

        // Get the player's turn
        printf("Player %d's turn:\n", board[0][0]);
        scanf("%d", &player_turn);

        // Check if the player's move is valid
        if(is_valid_move(board, player_turn, 0, 0)){
            make_move(board, player_turn, 0, 0);
        }
        else{
            printf("Invalid move!\n");
            continue;
        }

        // Check if the player won
        if(is_checkers_win(board, player_turn)){
            printf("Player %d won!\n", player_turn);
            return;
        }

        // Check if there is a draw
        if(is_checkers_draw(board)){
            printf("Draw!\n");
            return;
        }

        // Switch to the opponent's turn
        player_turn = -player_turn;
    }
}

// Main function
int main(){
    int board[8][8];
    int i, j;

    // Initialize the board
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            board[i][j] = 0;
        }
    }

    // Play the game
    play_checkers(board);

    return 0;
}