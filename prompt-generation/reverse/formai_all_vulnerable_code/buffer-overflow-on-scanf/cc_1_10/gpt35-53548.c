//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include<stdio.h>
#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE]; // tic tac toe board

// initialize board
void init_board(){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            board[i][j] = '-';
        }
    }
}

// print board
void print_board(){
    printf("\n");
    for(int i=0;i<BOARD_SIZE;i++){
        printf("\t\t\t\t");
        for(int j=0;j<BOARD_SIZE;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// check if position is valid
int valid_position(int x, int y){
    if(x>=0 && x<BOARD_SIZE && y>=0 && y<BOARD_SIZE && board[x][y]=='-')
        return 1;
    return 0;
}

// check if game is over
int game_over(){
    // horizontal
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[i][0]!='-' && board[i][0]==board[i][1] && board[i][0]==board[i][2])
            return 1;
    }
    // vertical
    for(int i=0;i<BOARD_SIZE;i++){
        if(board[0][i]!='-' && board[0][i]==board[1][i] && board[0][i]==board[2][i])
            return 1;
    }
    // diagonal
    if(board[0][0]!='-' && board[0][0]==board[1][1] && board[0][0]==board[2][2])
        return 1;
    if(board[0][2]!='-' && board[0][2]==board[1][1] && board[0][2]==board[2][0])
        return 1;
    // tie
    int tie = 1;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j]=='-'){
                tie = 0;
                break;
            }
        }
        if(!tie){
            break;
        }
    }
    if(tie){
        return 2;
    }
    return 0;
}

// get user input
void get_input(int *x, int *y){
    printf("Enter row and column number (1-3): ");
    scanf("%d %d", x, y);
    (*x)--;
    (*y)--;
}

// move of AI
void ai_move(int *x, int *y){
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j]=='-'){
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

// player move
void player_move(){
    int x,y;
    do{
        get_input(&x,&y);
    }while(!valid_position(x,y));
    board[x][y] = 'X';
}

// AI move
void computer_move(){
    int x,y;
    ai_move(&x,&y);
    board[x][y] = 'O';
}

// main function
int main(){
    init_board();
    print_board();
    while(1){
        player_move();
        print_board();
        if(game_over()==1){
            printf("You won!\n");
            return 0;
        }
        else if(game_over()==2){
            printf("Tie game\n");
            return 0;
        }
        computer_move();
        print_board();
        if(game_over()==1){
            printf("Computer won!\n");
            return 0;
        }
        else if(game_over()==2){
            printf("Tie game\n");
            return 0;
        }
    }
    return 0;
}