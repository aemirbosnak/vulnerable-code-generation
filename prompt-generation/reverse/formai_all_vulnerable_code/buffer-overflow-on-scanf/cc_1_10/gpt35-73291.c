//FormAI DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_game_board(int**, int, int);
void generate_random_board(int**, int, int);
int get_number_of_neighbors(int**, int, int, int, int);
void update_board(int**, int, int);

int main(){
    // Seed the random number generator
    srand((unsigned)time(NULL));
    
    // Prompt user for board dimensions
    int rows, columns;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Allocate memory for game board
    int **board = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        board[i] = (int*)malloc(columns * sizeof(int));
    }
    
    // Generate random starting board
    generate_random_board(board, rows, columns);
    printf("Initial board:\n");
    print_game_board(board, rows, columns);

    // Play the Game of Life for 10 iterations
    for(int i = 0; i < 10; i++){
        update_board(board, rows, columns);
        printf("Board after %d iterations:\n", i+1);
        print_game_board(board, rows, columns);
    }

    // Free memory
    for(int i = 0; i < rows; i++){
        free(board[i]);
    }
    free(board);
    board = NULL;
    return 0;
}

void print_game_board(int** board, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(board[i][j] == 0){
                printf(".");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void generate_random_board(int** board, int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            board[i][j] = rand() % 2;
        }
    }
}

int get_number_of_neighbors(int** board, int rows, int columns, int row, int column){
    int num_neighbors = 0;
    for(int i = row-1; i <= row+1; i++){
        for(int j = column-1; j <= column+1; j++){
            if(i >= 0 && i < rows && j >= 0 && j < columns && !(i == row && j == column)){
                num_neighbors += board[i][j];
            }
        }
    }
    return num_neighbors;
}

void update_board(int** board, int rows, int columns){
    int **new_board = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        new_board[i] = (int*)malloc(columns * sizeof(int));
    }

    // Update the board using the rules of the Game of Life
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            int num_neighbors = get_number_of_neighbors(board, rows, columns, i, j);
            if(board[i][j] == 1 && (num_neighbors == 2 || num_neighbors == 3)){
                new_board[i][j] = 1;
            }
            else if(board[i][j] == 0 && num_neighbors == 3){
                new_board[i][j] = 1;
            }
            else{
                new_board[i][j] = 0;
            }
        }
    }

    // Copy the new board to the old board and free memory
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            board[i][j] = new_board[i][j];
        }
        free(new_board[i]);
    }
    free(new_board);
    new_board = NULL;
}