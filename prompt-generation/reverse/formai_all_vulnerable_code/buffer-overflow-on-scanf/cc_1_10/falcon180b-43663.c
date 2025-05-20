//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void print_maze(char maze[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

int main() {
    srand(time(NULL));

    char maze[MAX_ROWS][MAX_COLS];
    generate_maze(maze);

    int player_x = 0;
    int player_y = 0;

    while (1) {
        system("clear");
        print_maze(maze);

        char input;
        scanf("%c", &input);

        switch (input) {
            case 'w':
                if (player_y > 0 && maze[player_y - 1][player_x]!= '#') {
                    player_y--;
                }
                break;
            case's':
                if (player_y < MAX_ROWS - 1 && maze[player_y + 1][player_x]!= '#') {
                    player_y++;
                }
                break;
            case 'a':
                if (player_x > 0 && maze[player_y][player_x - 1]!= '#') {
                    player_x--;
                }
                break;
            case 'd':
                if (player_x < MAX_COLS - 1 && maze[player_y][player_x + 1]!= '#') {
                    player_x++;
                }
                break;
            default:
                break;
        }

        if (maze[player_y][player_x] == '*') {
            printf("You won!\n");
            break;
        }
    }

    return 0;
}