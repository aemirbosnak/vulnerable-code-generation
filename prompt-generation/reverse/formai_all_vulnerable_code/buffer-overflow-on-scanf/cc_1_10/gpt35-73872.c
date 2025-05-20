//FormAI DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(int board[ROWS][COLS]){
    int num_elements = ROWS*COLS;
    int temp[num_elements];

    for(int i = 0; i < num_elements; i++){
        temp[i] = i/2 + 1;
    }

    srand(time(NULL));
    for(int i = 0; i < num_elements; i++){
        int random_index = rand()%num_elements;
        int temp_value = temp[i];
        temp[i] = temp[random_index];
        temp[random_index] = temp_value;
    }

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = temp[i*COLS + j];
        }
    }
}

void print_board(int board[ROWS][COLS], int revealed[ROWS][COLS]){
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(revealed[i][j]){
                printf("%d\t", board[i][j]);
            } else {
                printf("?\t");
            }
        }
        printf("\n");
    }
}

int main(){
    int board[ROWS][COLS];
    int revealed[ROWS][COLS] = {{0}};

    init_board(board);

    while(1){
        system("clear");
        print_board(board, revealed);
        int row1, col1, row2, col2;

        printf("Enter the coordinates of the first card:\n");
        scanf("%d %d", &row1, &col1);
        revealed[row1][col1] = 1;

        system("clear");
        print_board(board, revealed);

        printf("Enter the coordinates of the second card:\n");
        scanf("%d %d", &row2, &col2);
        revealed[row2][col2] = 1;

        if(board[row1][col1] == board[row2][col2]){
            printf("Match found!\n");
        }
        else {
            printf("No match.\n");
            revealed[row1][col1] = 0;
            revealed[row2][col2] = 0;
        }

        int all_revealed = 1;
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(!revealed[i][j]){
                    all_revealed = 0;
                }
            }
        }
        if(all_revealed){
            printf("Congratulations, you won!\n");
            break;
        }

        printf("Press enter to continue...");
        getchar();
    }

    return 0;
}