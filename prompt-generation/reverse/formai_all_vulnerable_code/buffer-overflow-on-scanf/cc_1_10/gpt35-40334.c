//FormAI DATASET v1.0 Category: Memory Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

typedef enum {FALSE, TRUE} boolean;

boolean is_match(int first_num, int second_num, int match_arr[ROWS][COLS], boolean check_matrix[ROWS][COLS]) {
    boolean status;
    if (first_num == second_num) {
        status = TRUE;
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(match_arr[i][j]==first_num){
                    check_matrix[i][j]=TRUE;
                }
            }
        }
    }
    else {
        status = FALSE;
    }
    return status;
}

boolean is_game_over(boolean matrix[ROWS][COLS]) {
    boolean status = TRUE;
    for(int i=0; i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            if(matrix[i][j]==FALSE) {
                status = FALSE;
                break;
            }
        }
    }
    return status;
}

void display_board(int board[ROWS][COLS], boolean matrix[ROWS][COLS]) {
    printf("\n***********\n");
    for(int i=0;i<ROWS;i++) {
        printf("| ");
        for(int j=0;j<COLS;j++) {
            if(matrix[i][j]==TRUE) {
                printf("%d | ",board[i][j]);
            }
            else {
                printf("? | ");
            }
        }
        printf("\n");
    }
    printf("***********\n");
}

void generate_random_numbers(int match_arr[ROWS][COLS]) {
    int count = 0;
    while(count<8) {
        int i = rand() % ROWS;
        int j = rand() % COLS;
        if(match_arr[i][j] == 0) {
            match_arr[i][j]=count+1;
            count++;
        }
    }
}

int main(void) {
    int match_arr[ROWS][COLS] = {0};
    boolean matrix[ROWS][COLS] = {FALSE};
    int first_num=0;
    int second_num=0;
    int moves_count=0;
    do {
        printf("Moves: %d\n",moves_count);
        display_board(match_arr,matrix);
        printf("Enter first number:\n");
        scanf("%d",&first_num);
        printf("Enter second number:\n");
        scanf("%d",&second_num);
        boolean match = is_match(first_num,second_num,match_arr,matrix);
        if(match==TRUE) {
            printf("You have made a match!\n");
        }
        else {
            printf("No match found.\n");
        }
        moves_count++;
    }while(is_game_over(matrix)!=TRUE);

    printf("Game Over! You won in %d moves!\n", moves_count);
    return 0;
}