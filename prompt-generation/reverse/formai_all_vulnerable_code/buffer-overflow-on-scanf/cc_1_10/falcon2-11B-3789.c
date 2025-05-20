//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Globals
int board[5][5];
int ballNum;
int drawn[5];
int winning_num[5];
int winner = 0;
int draw_num = 0;

// Function to print the board
void print_board(int board[5][5]) {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to draw a ball and mark it on the board
void draw_ball(int ballNum) {
    srand(time(NULL));
    int rand_num = rand() % 5;
    int drawn_num = rand_num;
    while(drawn_num == ballNum) {
        rand_num = rand() % 5;
        drawn_num = rand_num;
    }

    board[drawn_num / 5][drawn_num % 5]++;
    printf("Drawn number: %d \n", drawn_num);
    printf("Board:\n");
    print_board(board);
    draw_num++;
}

// Function to check if there is a winner
void check_winner() {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(board[i][j] == 5) {
                winner = 1;
                printf("Player %d is the winner!\n", i);
                break;
            }
        }
        if(winner == 1) {
            break;
        }
    }
}

// Function to play the game
int main() {
    printf("Welcome to the C Bingo Simulator!\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            board[i][j] = 0;
        }
    }
    while(winner == 0){
        printf("Enter the number of the ball drawn: ");
        scanf("%d", &ballNum);
        draw_ball(ballNum);
        check_winner();
        if(winner == 1) {
            printf("The game is over!\n");
            break;
        }
    }
    return 0;
}