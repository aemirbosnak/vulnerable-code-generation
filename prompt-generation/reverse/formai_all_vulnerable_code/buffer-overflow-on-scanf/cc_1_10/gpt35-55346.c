//FormAI DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to print the game board
void print_board(char board[][4], int size){
    printf("\n");
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(board[i][j] == 'X' || board[i][j] == 'O'){
                printf(" %c ", board[i][j]);
            }
            else{
                printf("   ");
            }
            if(j<size-1){
                printf("|");
            }
        }
        printf("\n");
        if(i<size-1){
            printf("-----------\n");
        }
    }
    printf("\n");
}

//function to shuffle the board and randomly place the markers
void shuffle_board(char board[][4], int size){
    srand(time(NULL));
    int count_x = 0;
    int count_o = 0;
    while(count_x < 4 && count_o < 4){
        int i = rand() % size;
        int j = rand() % size;
        if(board[i][j] != 'X' && board[i][j] != 'O'){
            if(rand() % 2 == 0){
                board[i][j] = 'X';
                count_x++;
            }
            else{
                board[i][j] = 'O';
                count_o++;
            }
        }
    }
}

//function to determine if the game is over
int game_over(char board[][4], int size){
    int count_x = 0;
    int count_o = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(board[i][j] == 'X'){
                count_x++;
            }
            else if(board[i][j] == 'O'){
                count_o++;
            }
        }
    }
    if(count_x == 4 || count_o == 4){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char board[4][4] = {{' ',' ',' ',' '}, {' ',' ',' ',' '}, {' ',' ',' ',' '}, {' ',' ',' ',' '}};
    printf("Welcome to the Memory Game\n");
    int player_turn = 1;
    shuffle_board(board, 4);
    printf("Player %d goes first\n", player_turn);
    print_board(board, 4);
    printf("Enter the row and column number to reveal the marker (ex. 1 2): ");
    int row1, col1, row2, col2;
    scanf("%d %d", &row1, &col1);
    board[row1-1][col1-1] = (player_turn == 1) ? 'X' : 'O';
    printf("Waiting for next player...\n");
    print_board(board, 4);
    printf("Enter the row and column number to reveal the marker (ex. 2 3): ");
    scanf("%d %d", &row2, &col2);
    board[row2-1][col2-1] = (player_turn == 1) ? 'X' : 'O';
    if(board[row1-1][col1-1] == board[row2-1][col2-1]){
        printf("Match found!\n");
    }
    else{
        printf("No match, switching turns...\n");
        player_turn = (player_turn == 1) ? 2 : 1;
    }
    print_board(board, 4);
    while(!game_over(board, 4)){
        printf("Player %d's turn\n", player_turn);
        printf("Enter the row and column number to reveal the marker (ex. 3 4): ");
        scanf("%d %d", &row1, &col1);
        board[row1-1][col1-1] = (player_turn == 1) ? 'X' : 'O';
        printf("Waiting for next player...\n");
        print_board(board, 4);
        printf("Enter the row and column number to reveal the marker (ex. 2 1): ");
        scanf("%d %d", &row2, &col2);
        board[row2-1][col2-1] = (player_turn == 1) ? 'X' : 'O';
        if(board[row1-1][col1-1] == board[row2-1][col2-1]){
            printf("Match found!\n");
        }
        else{
            printf("No match, switching turns...\n");
            player_turn = (player_turn == 1) ? 2 : 1;
        }
        print_board(board, 4);
    }
    printf("Game over!\n");
    printf("Player %d wins!\n", (player_turn == 1) ? 2 : 1);
    return 0;
}