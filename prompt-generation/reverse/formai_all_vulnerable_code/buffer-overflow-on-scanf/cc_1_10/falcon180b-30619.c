//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
};

void print_maze(int maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int check_win() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j]!= 1) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int player_x = 0, player_y = 0, moves = 0;
    int dx, dy;
    int choice;
    time_t start_time, end_time;

    srand(time(NULL));

    start_time = time(NULL);

    while (1) {
        system("clear");
        print_maze(maze);
        printf("Moves: %d\n", moves);

        if (check_win()) {
            end_time = time(NULL);
            printf("Congratulations! You won in %ld seconds.\n", end_time - start_time);
            break;
        }

        printf("Enter your choice:\n");
        printf("1. Move up\n");
        printf("2. Move down\n");
        printf("3. Move left\n");
        printf("4. Move right\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (player_y > 0 && maze[player_y - 1][player_x] == 0) {
                    player_y--;
                    moves++;
                }
                break;
            case 2:
                if (player_y < ROWS - 1 && maze[player_y + 1][player_x] == 0) {
                    player_y++;
                    moves++;
                }
                break;
            case 3:
                if (player_x > 0 && maze[player_y][player_x - 1] == 0) {
                    player_x--;
                    moves++;
                }
                break;
            case 4:
                if (player_x < COLS - 1 && maze[player_y][player_x + 1] == 0) {
                    player_x++;
                    moves++;
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}