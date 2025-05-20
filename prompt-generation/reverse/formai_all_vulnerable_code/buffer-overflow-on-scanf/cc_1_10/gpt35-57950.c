//FormAI DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void printBoard(int board[ROWS][COLS], int reveal[ROWS][COLS]){
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(reveal[i][j])
                printf("%d ", board[i][j]);
            else
                printf("? ");
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    
    int board[ROWS][COLS] = { {1, 2, 3, 4},
                              {1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {5, 6, 7, 8} };
    int reveal[ROWS][COLS] = {0};
    
    int flatBoard[ROWS*COLS];
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            flatBoard[j+i*COLS] = board[i][j];
        }
    }
    
    shuffle(flatBoard, ROWS*COLS);
    
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = flatBoard[j+i*COLS];
        }
    }
    
    int row1, col1, row2, col2, moves = 0;

    while(1){
        printBoard(board, reveal);
        printf("Enter row and col of first card to reveal: ");
        scanf("%d %d", &row1, &col1);
        if(row1 >=0 && row1 <= ROWS-1 && col1 >= 0 && col1 <= COLS-1){
            reveal[row1][col1] = 1;
            printBoard(board, reveal);
            printf("Enter row and col of second card to reveal: ");
            scanf("%d %d", &row2, &col2);
            if(row2 >=0 && row2 <= ROWS-1 && col2 >= 0 && col2 <= COLS-1){
                reveal[row2][col2] = 1;
                printBoard(board, reveal);
                if(board[row1][col1] == board[row2][col2]){
                    printf("Match!\n");
                }else{
                    printf("Not a match!\n");
                    reveal[row1][col1] = 0;
                    reveal[row2][col2] = 0;
                }
                moves++;
                if(moves == ROWS*COLS/2){
                    printf("Congratulations! You won in %d moves!\n", moves);
                    break;
                }
            }else{
                printf("Invalid row/col!\n");
            }
        }else{
            printf("Invalid row/column!\n");
        }
    }

    return 0;
}