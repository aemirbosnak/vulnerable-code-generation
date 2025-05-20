//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLUMNS 5

int player_position = 2;

bool game_over = false;

int score = 0;

char board[ROWS][COLUMNS] = {
    {' ', ' ', '@', ' ', ' '},
    {'@', '@', '@', '@', '@'},
    {'@', '@', '@', '@', '@'},
    {'@', '@', '@', '@', '@'},
    {'@', '@', '@', '@', '@'},
};

void print_board() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLUMNS;j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void update_board() {
    // move player
    board[ROWS-1][player_position] = ' ';
    board[ROWS-1][player_position+1] = '@';

    // move enemy
    for(int i=0;i<ROWS-1;i++) {
        for(int j=0;j<COLUMNS;j++) {
            if(board[i][j] == '@') {
                board[i][j] = ' ';
                board[i+1][j] = '@';
            }
        }
    }

    // check for collision
    if(board[ROWS-1][player_position+1] == '@') {
        game_over = true;
    } else {
        score++;
    }
}

int main() {
    printf("Welcome to the Linux Space Invaders!\n");
    printf("Use the arrow keys to move your player and avoid the enemies.\n");
    printf("Press q to quit the game.\n");
    
    while(!game_over) {
        print_board();
        update_board();

        // read user input
        char input;
        scanf(" %c", &input);

        // move player
        if(input == 'a' && player_position > 0) {
            player_position--;
        } else if(input == 'd' && player_position < COLUMNS-2) {
            player_position++;
        }

        // quit game
        if(input == 'q') {
            game_over = true;
        }
    }

    printf("Game Over! Your score is %d\n", score);

    return 0;
}