//FormAI DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(int board[][BOARD_SIZE]);
void shuffle_board(int board[][BOARD_SIZE]);
int check_game_over(int board[][BOARD_SIZE]);
void play_game(int board[][BOARD_SIZE]);

int main(){
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    shuffle_board(board);
    print_board(board);
    play_game(board);
    return 0;
}

void print_board(int board[][BOARD_SIZE]){
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle_board(int board[][BOARD_SIZE]){
    srand(time(NULL));
    int values[BOARD_SIZE * BOARD_SIZE / 2];
    for(int i=0; i<BOARD_SIZE * BOARD_SIZE / 2; i++){
        values[i] = i+1;
    }

    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            int index = rand() % (BOARD_SIZE * BOARD_SIZE / 2);
            board[i][j] = values[index];
            board[BOARD_SIZE - 1 - i][BOARD_SIZE - 1 - j] = values[index];
            values[index] = 0;
        }
    }
}

int check_game_over(int board[][BOARD_SIZE]){
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}

void play_game(int board[][BOARD_SIZE]){
    int moves = 0;
    while(!check_game_over(board)){
        printf("Enter the row and col numbers (0 to %d) of two cards separated by a space:\n", BOARD_SIZE-1);
        int row1, col1, row2, col2;
        scanf("%d%d%d%d", &row1, &col1, &row2, &col2);

        // check input validity
        if(row1 < 0 || row1 >= BOARD_SIZE || row2 < 0 || row2 >= BOARD_SIZE
            || col1 < 0 || col1 >= BOARD_SIZE || col2 < 0 || col2 >= BOARD_SIZE){
            printf("Invalid input, please try again.\n");
            continue;
        }
        if(board[row1][col1] == 0 || board[row2][col2] == 0){
            printf("One or both cards are already flipped, please choose again.\n");
            continue;
        }
        if(board[row1][col1] != board[row2][col2]){
            printf("Sorry, incorrect match. Please try again.\n");
            board[row1][col1] = 0;
            board[row2][col2] = 0;
            print_board(board);
        }
        else{
            printf("You found a match! Great job!\n");
            board[row1][col1] = 0;
            board[row2][col2] = 0;
            print_board(board);
            moves++;
        }
    }
    printf("Congratulations! You won the game in %d moves!\n", moves);
}