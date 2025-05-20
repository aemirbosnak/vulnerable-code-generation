//FormAI DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define GAME_OVER -1

void print_board(int board[ROWS][COLS]);
int get_guess();
void update_board(int board[ROWS][COLS], int guess, int* score);
int check_game_over(int board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS] = { {1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16} };
    
    int score = 0;
    srand(time(NULL));
    
    while(1) {
        print_board(board);
        int guess = get_guess();
        update_board(board, guess, &score);
        int state = check_game_over(board);
        
        if(state == GAME_OVER) {
            printf("Game over! Your final score is: %d\n", score);
            break;
        }
    }
    
    return 0;
}

void print_board(int board[ROWS][COLS]) {
    printf("Score: 0\n");
    printf("------------------------------\n");
    
    for(int i = 0; i < ROWS; i++) {
        printf("| ");
        for(int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("|\n");
    }
    
    printf("------------------------------\n");
}

int get_guess() {
    int guess;
    printf("Enter a number to turn over: ");
    scanf("%d", &guess);
    return guess;
}

void update_board(int board[ROWS][COLS], int guess, int* score) {
    int found = 0;
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == guess) {
                board[i][j] = -1;
                found = 1;
            }
        }
    }
    
    if(found) {
        (*score)++;
    } else {
        printf("Wrong guess, try again!\n");
    }
}

int check_game_over(int board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] != -1) {
                return 0;
            }
        }
    }
    
    return GAME_OVER;
}