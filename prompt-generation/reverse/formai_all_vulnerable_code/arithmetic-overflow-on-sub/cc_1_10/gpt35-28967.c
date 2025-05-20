//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void print_board(){
    printf(" ");
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", i+1);
    }
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", i+1);
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_winner(char symbol){
    // Check rows
    for(int i=0; i<BOARD_SIZE; i++){
        int count=0;
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == symbol){
                count++;
            }
        }
        if(count == BOARD_SIZE){
            return 1;
        }
    }

    // Check columns
    for(int j=0; j<BOARD_SIZE; j++){
        int count=0;
        for(int i=0; i<BOARD_SIZE; i++){
            if(board[i][j] == symbol){
                count++;
            }
        }
        if(count == BOARD_SIZE){
            return 1;
        }
    }

    // Check diagonal
    int count=0;
    for(int i=0; i<BOARD_SIZE; i++){
        if(board[i][i] == symbol){
            count++;
        }
    }
    if(count == BOARD_SIZE){
        return 1;
    }

    count=0;
    for(int i=0; i<BOARD_SIZE; i++){
        if(board[BOARD_SIZE-i-1][i] == symbol){
            count++;
        }
    }
    if(count == BOARD_SIZE){
        return 1;
    }

    // No winner found
    return 0;
}

int is_board_full(){
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}

int get_random_number(int min, int max){
    return rand()%(max-min+1) + min;
}

void computer_move(char symbol){
    while(1){
        int row = get_random_number(0, BOARD_SIZE-1);
        int col = get_random_number(0, BOARD_SIZE-1);

        if(board[row][col] == ' '){
            board[row][col] = symbol;
            printf("Computer move:\n");
            print_board();
            printf("\n");

            break;
        }
    }
}

int main(){
    srand(time(NULL));

    // Initialize the board
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            board[i][j] = ' ';
        }
    }

    // Print initial board
    printf("Initial board:\n");
    print_board();
    printf("\n");

    while(1){
        // Player move
        printf("Your move (row column): ");
        int row, col;
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(row<0 || row>=BOARD_SIZE || col<0 || col>=BOARD_SIZE || board[row][col]!=' '){
            printf("Invalid move!\n");
            continue;
        }
        board[row][col] = 'X';
        printf("Your move:\n");
        print_board();
        printf("\n");

        if(is_winner('X')){
            printf("Congrats! You won!\n");
            break;
        }
        if(is_board_full()){
            printf("Game over! No winner!\n");
            break;
        }

        // Computer move
        computer_move('O');

        if(is_winner('O')){
            printf("Sorry! You lost!\n");
            break;
        }
        if(is_board_full()){
            printf("Game over! No winner!\n");
            break;
        }
    }

    return 0;
}