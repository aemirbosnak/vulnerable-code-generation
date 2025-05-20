//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

// Function to print the Tic Tac Toe board
void print_board(char board[SIZE][SIZE]){
    printf("\n");
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf(" %c ",board[i][j]);
            if(j<SIZE-1){
                printf("|");
            }
        }
        printf("\n");
        if(i<SIZE-1){
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Function to check if the game is over
int game_over(char board[SIZE][SIZE], char symbol){
    int rows=0,cols=0,diag=0,rdiag=0;
    for(int i=0;i<SIZE;i++){
        rows = 0;
        cols = 0;
        for(int j=0;j<SIZE;j++){
            if(board[i][j] == symbol){
                rows++;
            }
            if(board[j][i] == symbol){
                cols++;
            }
            if(i==j && board[i][j] == symbol){
                diag++;
            }
            if(i+j == SIZE-1 && board[i][j] == symbol){
                rdiag++;
            }
        }
        if(rows == SIZE || cols == SIZE || diag == SIZE || rdiag == SIZE){
            return 1;
        }
    }
    return 0;
}

// Function to get computer's move
void get_computer_move(char board[SIZE][SIZE]){
    int x,y;
    do{
        x = rand() % SIZE;
        y = rand() % SIZE;
    }while(board[x][y] != '-');
    board[x][y] = 'O';
}

int main(){
    char board[SIZE][SIZE];

    // Initializing board
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            board[i][j] = '-';
        }
    }

    print_board(board);

    // Loop until game over
    while(!game_over(board,'O') && !game_over(board,'X')){
        int x,y;
        // Get user's move
        do{
            printf("Enter row number (1-3): ");
            scanf("%d",&x);
            printf("Enter column number (1-3): ");
            scanf("%d",&y);
            x -= 1;
            y -= 1;
        }while(x<0 || y<0 || x>=SIZE || y>=SIZE || board[x][y] != '-');

        board[x][y] = 'X';

        print_board(board);

        if(game_over(board,'X')){
            printf("Congratulations! You won!\n");
            break;
        }

        if(game_over(board,'O')){
            printf("Sorry! You lost!\n");
            break;
        }

        get_computer_move(board);

        print_board(board);

        if(game_over(board,'X')){
            printf("Congratulations! You won!\n");
            break;
        }

        if(game_over(board,'O')){
            printf("Sorry! You lost!\n");
            break;
        }

    }

    return 0;
}