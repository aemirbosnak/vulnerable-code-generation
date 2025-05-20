//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_intro();
void play_game();
void end_game();

int main() {
    game_intro();
    play_game();
    end_game();
    return 0;
}

void game_intro(){
    printf("Welcome to the Terminal Adventure Game!\n\n");
    printf("The objective of the game is to navigate through a maze and reach the treasure at the end.\n");
    printf("But beware! There will be obstacles along the way that you must avoid or overcome.\n\n");
    printf("Press any key to start the game...\n");
    getchar();
    system("clear");
}

void play_game(){
    int player_row = 1;
    int player_col = 1;
    int treasure_row = 9;
    int treasure_col = 9;
    int move_count = 0;
    int game_board[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };
    char input;

    while(player_row != treasure_row || player_col != treasure_col) {
        printf("Movement Count: %d\n", move_count);
        for(int row=0; row<10; row++) {
            printf("\n");
            for(int col=0; col<10; col++){
                if(row==player_row && col==player_col) {
                    printf("X ");
                } else if(row==treasure_row && col==treasure_col) {
                    printf("$ ");
                } else if(game_board[row][col] == 1) {
                    printf("O ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n\nUse WASD to move X: ");
        scanf(" %c", &input);
        switch(input){
            case 'W':
            case 'w':{
                if(game_board[player_row-1][player_col] == 0) {
                    player_row--;
                    move_count++;
                }
                break;
            }
            case 'A':
            case 'a':{
                if(game_board[player_row][player_col-1] == 0) {
                    player_col--;
                    move_count++;
                }
                break;
            }
            case 'S':
            case 's':{
                if(game_board[player_row+1][player_col] == 0) {
                    player_row++;
                    move_count++;
                }
                break;
            }
            case 'D':
            case 'd':{
                if(game_board[player_row][player_col+1] == 0) {
                    player_col++;
                    move_count++;
                }
                break;
            }
        }
        system("clear");
    }
}

void end_game(){
    printf("Congratulations, you have found the treasure!\n");
    printf("Thanks for playing the Terminal Adventure Game!\n");
}