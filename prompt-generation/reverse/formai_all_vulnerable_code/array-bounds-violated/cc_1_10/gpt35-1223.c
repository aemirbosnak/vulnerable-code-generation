//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_board(char board[3][3]){
    printf("\n\n");
    for(int i=0;i<3;i++){
        printf("\t\t\t");
        for(int j=0;j<3;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

bool check_winner(char board[3][3],char player){
    if(board[0][0]==player && board[0][1]==player && board[0][2]==player)
        return true;
    if(board[1][0]==player && board[1][1]==player && board[1][2]==player)
        return true;
    if(board[2][0]==player && board[2][1]==player && board[2][2]==player)
        return true;
    if(board[0][0]==player && board[1][0]==player && board[2][0]==player)
        return true;
    if(board[0][1]==player && board[1][1]==player && board[2][1]==player)
        return true;
    if(board[0][2]==player && board[1][2]==player && board[2][2]==player)
        return true;
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;
    return false;
}

bool check_board_full(char board[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' ')
                return false;
        }
    }
    return true;
}

int minimax(char board[3][3], int depth, bool maximizing_player, char user){
    if(check_winner(board, user)==true)
        return 10-depth;
    else if(check_winner(board, user=='X'?'O':'X')==true)
        return depth-10;
    else if(check_board_full(board)==true)
        return 0;
    
    int score;
    char other_player = maximizing_player?user:(user=='X'?'O':'X');
    int best_move = maximizing_player?-1000:1000;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j] = maximizing_player?user:other_player;

                if(maximizing_player){
                    score = minimax(board, depth+1, false, user);
                    if(score>best_move)
                        best_move = score;
                }
                else{
                    score = minimax(board, depth+1, true, user);
                    if(score<best_move)
                        best_move = score;
                }
                
                board[i][j] = ' ';
            }
        }
    }
    
    return best_move;
}

void computer_move(char board[3][3], char user){
    int best_score = -1000;
    int best_row = -1;
    int best_col = -1;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==' '){
                board[i][j] = user;
                int score = minimax(board, 0, false, user);
                board[i][j] = ' ';
                
                if(score>best_score){
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    
    board[best_row][best_col] = user;
}

int main(){
    char board[3][3] = {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    
    printf("\t\t\tTIC TAC TOE\n\n");
    printf("PLAYER 1 - X\n");
    printf("COMPUTER  - O\n\n");
    
    int turn = 1;
    while(true){
        if(turn%2!=0){
            int x,y;
            printf("Enter x and y coordinates for X (separated by a space): ");
            scanf("%d %d",&x,&y);
            if(board[x][y] == ' '){
                board[x][y] = 'X';
                print_board(board);
            }
            else{
                printf("\nInvalid move. Try again.\n\n");
                continue;
            }
            if(check_winner(board, 'X')==true){
                printf("\nPLAYER 1 WINS!\n");
                break;
            }
        }
        else{
            printf("\nCOMPUTER'S TURN\n");
            computer_move(board,'O');
            print_board(board);
            if(check_winner(board, 'O')==true){
                printf("\nCOMPUTER WINS!\n");
                break;
            }
        }

        if(check_board_full(board)==true){
            printf("\nDRAW!\n");
            break;
        }
        turn++;
    }
    return 0;
}