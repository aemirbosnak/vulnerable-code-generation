//FormAI DATASET v1.0 Category: Table Game ; Style: enthusiastic
//Welcome to my coding world!
//I present to you a unique C Table Game - "The Pirate's Treasure Hunt!"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int treasure_row, treasure_col;

void initialize_board(int board[ROWS][COLS], int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            board[i][j] = 0;
        }
    }
}

void print_board(int board[ROWS][COLS], int rows, int cols){
    printf("\n\n");
    for(int i = 0; i < cols; i++){
        printf("\t%d", i+1);
    }
    printf("\n\n");
    for(int i = 0; i < rows; i++){
        printf("%d\t", i+1);
        for(int j = 0; j < cols; j++){
            if(board[i][j] == -1){
                printf("*\t");
            }
            else{
                printf("%d\t", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void plant_treasure(int board[ROWS][COLS]){
    srand(time(NULL));
    treasure_row = rand() % 4;
    treasure_col = rand() % 4;
    board[treasure_row][treasure_col] = -1;
}

int get_guess(int *row, int *col){
    printf("Enter your guess (row, col): ");
    scanf("%d %d", row, col);

    *row -= 1;
    *col -= 1;

    if(*row < 0 || *row >= ROWS || *col < 0 || *col >= COLS){
        printf("Invalid guess, try again.\n");
        return 0;
    }
    else{
        return 1;
    }
}

int get_distance(int guess_row, int guess_col){
    int distance = abs(guess_row - treasure_row) + abs(guess_col - treasure_col);
    return distance;
}

void play_game(){
    int board[ROWS][COLS];

    printf("Welcome to the Pirate's Treasure Hunt!\n");
    printf("You have to find the treasure in a 4x4 grid.\n");
    printf("To play the game, select a row and a column (from 1 to 4).\n");
    printf("Let's begin!\n");

    initialize_board(board, ROWS, COLS);
    plant_treasure(board);

    int attempts = 0;
    int guess_row, guess_col;

    while(1){
        print_board(board, ROWS, COLS);
        if(get_guess(&guess_row, &guess_col)){
            attempts++;
            if(board[guess_row][guess_col] == -1){
                printf("\nCongratulations! You found the treasure in %d attempts!\n", attempts);
                break;
            }
            else{
                int distance = get_distance(guess_row, guess_col);
                board[guess_row][guess_col] = distance;
                printf("Oops, you missed! The treasure is %d squares away from your guess.\n", distance);
            }
        }
    }
}

int main(){
    char play_again = 'y';

    while(play_again == 'y' || play_again == 'Y'){
        play_game();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
        if(play_again != 'y' && play_again != 'Y' && play_again != 'n' && play_again != 'N'){
            printf("Invalid selection. Exiting game.");
            break;
        }
    }

    printf("Thanks for playing The Pirate's Treasure Hunt! Goodbye!\n");
    return 0;
}