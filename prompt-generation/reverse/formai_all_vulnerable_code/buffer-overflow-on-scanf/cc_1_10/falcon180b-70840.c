//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generate_maze(char maze[ROWS][COLS]);
void print_maze(char maze[ROWS][COLS]);
int check_win(char maze[ROWS][COLS]);

int main() {
    srand(time(NULL));

    char maze[ROWS][COLS];
    generate_maze(maze);

    int player_row = 0;
    int player_col = 0;

    while(1) {
        system("clear");
        print_maze(maze);

        char move;
        scanf("%c", &move);

        switch(move) {
            case 'w':
                if(player_row > 0 && maze[player_row-1][player_col]!= '#') {
                    player_row--;
                }
                break;
            case's':
                if(player_row < ROWS-1 && maze[player_row+1][player_col]!= '#') {
                    player_row++;
                }
                break;
            case 'a':
                if(player_col > 0 && maze[player_row][player_col-1]!= '#') {
                    player_col--;
                }
                break;
            case 'd':
                if(player_col < COLS-1 && maze[player_row][player_col+1]!= '#') {
                    player_col++;
                }
                break;
            default:
                break;
        }

        if(check_win(maze)) {
            printf("You win!\n");
            return 0;
        }
    }

    return 0;
}

void generate_maze(char maze[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    // Set start and exit points
    maze[0][0] = '.';
    maze[ROWS-1][COLS-1] = 'E';
}

void print_maze(char maze[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int check_win(char maze[ROWS][COLS]) {
    if(maze[ROWS-1][COLS-1] == '.') {
        return 1;
    }

    return 0;
}