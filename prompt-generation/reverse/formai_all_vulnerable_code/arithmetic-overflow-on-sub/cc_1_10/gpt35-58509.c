//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int moves = 0;

void draw_grid(){
    printf("\n\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", grid[0][0], grid[0][1], grid[0][2]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", grid[1][0], grid[1][1], grid[1][2]);
    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", grid[2][0], grid[2][1], grid[2][2]);
    printf("\t     |     |     \n");
}

int check_winner(){
    // Check rows
    for(int i=0; i<3; i++){
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){
            return 1;
        }
    }
    
    // Check columns
    for(int i=0; i<3; i++){
        if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]){
            return 1;
        }
    }
    
    // Check diagonals
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
        return 1;
    }
    if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
        return 1;
    }
    
    // Check tie
    if(moves == 9){
        return -1;
    }
    
    return 0;
}

int minimax(char player){
    int win = check_winner();
    if(win != 0){
        if(win == 1){
            if(player == 'X'){
                return -10;
            } else {
                return 10;
            }
        } else {
            return 0;
        }
    }
    
    int score = 0;
    int best_score = (player == 'X') ? 1000 : -1000;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[i][j] != 'X' && grid[i][j] != 'O'){
                char prev_val = grid[i][j];
                grid[i][j] = player;
                moves++;
                
                if(player == 'X'){
                    score = minimax('O');
                } else {
                    score = minimax('X');
                }
                
                if(player == 'X'){
                    if(score < best_score){
                        best_score = score;
                    }
                } else {
                    if(score > best_score){
                        best_score = score;
                    }
                }
                
                grid[i][j] = prev_val;
                moves--;
            }
        }
    }
    
    return best_score;
}

void make_ai_move(){
    int best_score = 1000;
    int best_i, best_j;
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(grid[i][j] != 'X' && grid[i][j] != 'O'){
                char prev_val = grid[i][j];
                grid[i][j] = 'O';
                moves++;
                
                int score = minimax('X');
                
                if(score < best_score){
                    best_score = score;
                    best_i = i;
                    best_j = j;
                }
                
                grid[i][j] = prev_val;
                moves--;
            }
        }
    }
    
    grid[best_i][best_j] = 'O';
}

void play_game(){
    printf("\nWelcome to Paranoid Tic Tac Toe! You are 'X'. The computer is 'O'.\n");
    draw_grid();
    
    while(1){
        // Get human move
        int human_move;
        printf("\nYour turn (Enter 1-9): ");
        scanf("%d", &human_move);
        int i = (human_move-1) / 3;
        int j = (human_move-1) % 3;
        if(grid[i][j] == 'X' || grid[i][j] == 'O'){
            printf("\nInvalid move! Please enter a number that has not been played.\n");
            continue;
        }
        grid[i][j] = 'X';
        moves++;
        draw_grid();
        
        // Check for human win or tie
        int human_result = check_winner();
        if(human_result == 1){
            printf("\nCongratulations, you won!\n");
            break;
        }
        if(human_result == -1){
            printf("\nIt's a tie!\n");
            break;
        }
        
        // Get computer move
        printf("\nComputer is thinking...\n");
        make_ai_move();
        moves++;
        draw_grid();
        
        // Check for computer win or tie
        int ai_result = check_winner();
        if(ai_result == 1){
            printf("\nSorry, the computer won. Better luck next time!\n");
            break;
        }
        if(ai_result == -1){
            printf("\nIt's a tie!\n");
            break;
        }
    }
}

int main(){
    play_game();
    return 0;
}