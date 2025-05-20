//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void print_map(char map[10][10], int player_x, int player_y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == player_x && j == player_y) {
                printf("@");
            } else if (map[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char map[10][10] = { {0} };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2;
        }
    }

    int player_x = 0;
    int player_y = 0;
    map[player_x][player_y] = 0;

    while (1) {
        system("clear");
        print_map(map, player_x, player_y);

        char move;
        scanf("%c", &move);

        switch (move) {
            case 'w':
                if (player_y > 0 && map[player_x][player_y - 1] == 0) {
                    player_y--;
                    map[player_x][player_y] = 0;
                }
                break;
            case's':
                if (player_y < 9 && map[player_x][player_y + 1] == 0) {
                    player_y++;
                    map[player_x][player_y] = 0;
                }
                break;
            case 'a':
                if (player_x > 0 && map[player_x - 1][player_y] == 0) {
                    player_x--;
                    map[player_x][player_y] = 0;
                }
                break;
            case 'd':
                if (player_x < 9 && map[player_x + 1][player_y] == 0) {
                    player_x++;
                    map[player_x][player_y] = 0;
                }
                break;
            default:
                printf("Invalid move\n");
        }
    }

    return 0;
}