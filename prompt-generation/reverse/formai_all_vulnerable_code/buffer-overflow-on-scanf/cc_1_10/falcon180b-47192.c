//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 0
#define L 1
#define U 2
#define D 3

int maze[4][4] = {{0, 0, 1, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
int player_pos_x = 0;
int player_pos_y = 0;
int score = 0;

void init_maze() {
    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            maze[i][j] = rand() % 2;
        }
    }
    player_pos_x = 0;
    player_pos_y = 0;
    score = 0;
}

void draw_maze() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

void move_player(int direction) {
    switch (direction) {
        case R:
            if (player_pos_x < 3 && maze[player_pos_y][player_pos_x + 1] == 0) {
                player_pos_x++;
                score++;
            }
            break;
        case L:
            if (player_pos_x > 0 && maze[player_pos_y][player_pos_x - 1] == 0) {
                player_pos_x--;
                score++;
            }
            break;
        case U:
            if (player_pos_y > 0 && maze[player_pos_y - 1][player_pos_x] == 0) {
                player_pos_y--;
                score++;
            }
            break;
        case D:
            if (player_pos_y < 3 && maze[player_pos_y + 1][player_pos_x] == 0) {
                player_pos_y++;
                score++;
            }
            break;
    }
}

int main() {
    init_maze();
    while (1) {
        draw_maze();
        printf("Score: %d\n", score);
        printf("Press R to move right, L to move left, U to move up, D to move down: ");
        char direction;
        scanf("%c", &direction);
        move_player(direction);
    }
    return 0;
}