//FormAI DATASET v1.0 Category: Game ; Style: curious
//Welcome to the wildest game of Snake and Ladder!

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 10
#define COLS 10

int num_grid[ROWS][COLS];
char board[ROWS][COLS];

void initialize(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            num_grid[i][j]=i*COLS+j+1;
            board[i][j]='-';
        }
    }
}

void display_board(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int snake_start=1, snake_end=50, ladder_start=25, ladder_end=65; 
    int snake_pos, ladder_pos, num;
    char player_name[20];
    printf("Enter player name: ");
    scanf("%s", player_name);
    printf("Welcome %s to Snake and Ladder game!\n", player_name);
    initialize();
    display_board();
    printf("\n");
    while(1){
        printf("Press 'r' to roll the dice\n");
        char option;
        scanf(" %c", &option);   
        if(option=='r'){
            num=rand()%6+1;
            printf("You got %d\n", num);
            for(int i=0; i<ROWS; i++){
                for(int j=0; j<COLS; j++){
                    if(num_grid[i][j]==num){
                        if(board[i][j]=='S'){
                            //Game of Snake
                            printf("\nOh No! There is a Snake here and you are back at %d\n", snake_start);
                            board[i][j]='*';
                            board[ROWS-(snake_start-1)/10-1][(snake_start-1)%10]='@';
                            snake_pos=0;
                            break;
                        }
                        else if(board[i][j]=='L'){
                            //Game of Ladder
                            printf("\nCongrats! You have climbed the ladder and reached %d\n", ladder_end);
                            board[i][j]='*';
                            board[ROWS-(ladder_end-1)/10-1][(ladder_end-1)%10]='O';
                            ladder_pos=0;
                            break;
                        }
                        else{
                            board[i][j]='O';
                        }
                    }
                    else if(snake_pos==0 && num_grid[i][j]==snake_start){
                        board[ROWS-i-1][j]='@';
                        snake_pos=1;
                    }
                    else if(ladder_pos==0 && num_grid[i][j]==ladder_start){
                        board[ROWS-i-1][j]='*';
                        ladder_pos=1;
                    }
                }
            }
            if(num==6){
                printf("\nYou got a 6, you can roll the dice again\n");
                continue;
            }
        }
        if(num_grid[ROWS-1][0]==ladder_end || num_grid[ROWS-1][1]==ladder_end){
            printf("\nCongrats %s, you have won!!\n", player_name);
            break;
        }
        display_board();
        printf("\n");
    }

    return 0;
}