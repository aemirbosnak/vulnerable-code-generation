//FormAI DATASET v1.0 Category: Chess AI ; Style: ephemeral
#include<stdio.h>

// defining the chess board
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

// function to print the board
void print_board(){
    int i, j;
    printf("\n");
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to make a move
void make_move(){
    char from[2], to[2];
    int from_x, from_y, to_x, to_y;
    printf("Enter from position: ");
    scanf("%s", from);
    printf("Enter to position: ");
    scanf("%s", to);
    
    from_x = from[1] - '1';
    from_y = from[0] - 'a';
    to_x = to[1] - '1';
    to_y = to[0] - 'a';
    
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = ' ';
}

int main(){
    printf("Welcome to Chess AI\n");
    printf("Type 'quit' to leave\n");
    int i;
    for(i = 0; i < 100; i++){
        print_board();
        make_move();
    }
    return 0;
}