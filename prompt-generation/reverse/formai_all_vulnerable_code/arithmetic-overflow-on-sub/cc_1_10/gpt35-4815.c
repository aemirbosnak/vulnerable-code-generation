//FormAI DATASET v1.0 Category: Memory Game ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 4
#define COLS 4

void display(int arr[ROWS][COLS], int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void shuffle(int arr[ROWS*COLS], int size){
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        int temp = arr[i];
        int j = rand() % size;
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main(){
    int arr[ROWS][COLS] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int flat_arr[ROWS*COLS] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    shuffle(flat_arr, ROWS*COLS);
    for (int i = 0; i < ROWS*COLS; i++){
        arr[i/COLS][i%COLS] = flat_arr[i];
    }

    printf("Welcome to the Surrealist Memory Game!\n");
    printf("You will need to match pairs of surreal symbols to win the game.\n");
    printf("Here are the possible surreal symbols in the game:\n\n");
    printf("1. A melting clock\n2. A lobster phone\n3. A tree without roots\n4. An elephant on stilts\n\n");

    int game_arr[ROWS][COLS] = {0};
    int game_over = 0;
    int pairs_found = 0;
    while (!game_over){
        display(game_arr, ROWS, COLS);

        printf("Enter the coordinates of the first symbol you would like to reveal (row,col): ");
        int r1,c1;
        scanf("%d,%d", &r1, &c1);
        game_arr[r1-1][c1-1] = arr[r1-1][c1-1];

        display(game_arr, ROWS, COLS);

        printf("Enter the coordinates of the second symbol you would like to reveal (row,col): ");
        int r2,c2;
        scanf("%d,%d", &r2, &c2);
        game_arr[r2-1][c2-1] = arr[r2-1][c2-1];

        display(game_arr, ROWS, COLS);

        if (arr[r1-1][c1-1] == arr[r2-1][c2-1]){
            printf("Congratulations! You found a pair of surreal symbols!\n");
            pairs_found++;
            if (pairs_found == ROWS*COLS/2){
                printf("You have found all the pairs! Congratulations, you have won!\n");
                game_over = 1;
            }
        } else {
            printf("Oops, sorry! Those symbols don't match. Try again.\n");
            game_arr[r1-1][c1-1] = 0;
            game_arr[r2-1][c2-1] = 0;
        }
    }

    return 0;
}