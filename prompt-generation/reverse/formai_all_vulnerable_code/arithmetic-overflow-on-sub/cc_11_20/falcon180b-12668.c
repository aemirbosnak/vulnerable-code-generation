//Falcon-180B DATASET v1.0 Category: Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int maze[10][10]; // create a 10x10 maze
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2; // randomly assign walls to maze
        }
    }
    int player_x = 0;
    int player_y = 0;
    int player_dir = 0; // 0 = up, 1 = right, 2 = down, 3 = left
    int score = 0;
    int game_over = 0;
    int start_time = time(NULL);
    while (!game_over) {
        system("clear"); // clear the console
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (maze[i][j] == 1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("Score: %d\n", score);
        printf("Time: %d seconds\n", time(NULL) - start_time);
        if (player_dir == 0) {
            if (player_y > 0 && maze[player_x][player_y-1] == 0) {
                player_y--;
            }
        } else if (player_dir == 1) {
            if (player_x < 9 && maze[player_x+1][player_y] == 0) {
                player_x++;
            }
        } else if (player_dir == 2) {
            if (player_y < 9 && maze[player_x][player_y+1] == 0) {
                player_y++;
            }
        } else if (player_dir == 3) {
            if (player_x > 0 && maze[player_x-1][player_y] == 0) {
                player_x--;
            }
        }
        if (maze[player_x][player_y] == 0) {
            score++;
        } else {
            game_over = 1;
        }
    }
    return 0;
}