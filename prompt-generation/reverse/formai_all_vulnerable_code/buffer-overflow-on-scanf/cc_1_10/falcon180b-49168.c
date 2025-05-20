//Falcon-180B DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void generate_maze(char maze[10][10]);
void print_maze(char maze[10][10]);
int check_win(int player_x, int player_y);
void move_player(char maze[10][10], int *player_x, int *player_y, char direction);

int main() {
    srand(time(0));
    char maze[10][10];
    int player_x = 0, player_y = 0;
    generate_maze(maze);
    print_maze(maze);

    while (!check_win(player_x, player_y)) {
        char direction;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &direction);
        move_player(maze, &player_x, &player_y, direction);
        print_maze(maze);
    }

    printf("Congratulations, you won!");
    return 0;
}

void generate_maze(char maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || i == 9 || j == 0 || j == 9) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = rand() % 2? '.' : '#';
            }
        }
    }
}

void print_maze(char maze[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int check_win(int player_x, int player_y) {
    return 0;
}

void move_player(char maze[10][10], int *player_x, int *player_y, char direction) {
    int new_x = *player_x, new_y = *player_y;

    switch (direction) {
        case 'w':
            new_y--;
            break;
        case 'a':
            new_x--;
            break;
        case's':
            new_y++;
            break;
        case 'd':
            new_x++;
            break;
        default:
            break;
    }

    if (maze[new_y][new_x] == '.') {
        *player_x = new_x;
        *player_y = new_y;
    }
}