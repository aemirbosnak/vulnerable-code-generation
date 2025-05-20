//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 10
#define SHIPS 5

int board[ROWS][COLS];
bool isShip[ROWS][COLS];
bool guessed[ROWS][COLS];

void init_board(){
    memset(board, 0, sizeof(board));
}

void init_ships(){
    memset(isShip, false, sizeof(isShip));
    srand(time(NULL));
    for (int i = 0; i < SHIPS; i++){
        int row = rand() % ROWS;
        int col = rand() % COLS;
        isShip[row][col] = true;
    }
}

void print_board(){
    printf("   ");
    for (int i = 0; i < COLS; i++){
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++){
        printf("%c| ", i + 'A');
        for (int j = 0; j < COLS; j++){
            if (!guessed[i][j]){
                printf(". ");
            }
            else{
                if (isShip[i][j]){
                    printf("* ");
                }
                else{
                    printf(". ");
                }
            }
        }
        printf("|\n");
    }
}

bool guess(int row, int col){
    if (guessed[row][col]){
        return false;
    }
    else{
        guessed[row][col] = true;
        return isShip[row][col];
    }
}

bool game_over(){
    int ships_left = SHIPS;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (isShip[i][j] && guessed[i][j]){
                ships_left--;
            }
        }
    }
    return ships_left == 0;
}

int main(){
    printf("Welcome to a minimalist Space Invaders game clone!\n");
    printf("There are %d ships hidden on a %d x %d board. \n", SHIPS, ROWS, COLS);
    printf("Enter coordinates to guess where the ships are!\n");
    
    init_board();
    init_ships();
    print_board();

    int row, col;
    while (!game_over()){
        printf("Guess row: ");
        scanf("%d", &row);
        row--;
        printf("Guess column: ");
        scanf("%d", &col);
        col--;
        if (guess(row, col)){
            printf("Hit!\n");
        }
        else{
            printf("Miss!\n");
        }
        print_board();
    }

    printf("You win!\n");
    return 0;
}