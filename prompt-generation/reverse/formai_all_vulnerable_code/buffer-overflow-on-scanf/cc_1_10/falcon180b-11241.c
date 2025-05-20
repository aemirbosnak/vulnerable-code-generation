//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int x, y;
} Point;

void generate_map(char map[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            map[i][j] = rand() % 2? '.' : '#';
        }
    }
}

int count_adjacent_walls(Point player, char map[SIZE][SIZE]) {
    int count = 0;
    if (map[player.x][player.y - 1] == '#') count++;
    if (map[player.x][player.y + 1] == '#') count++;
    if (map[player.x - 1][player.y] == '#') count++;
    if (map[player.x + 1][player.y] == '#') count++;
    return count;
}

void print_map(char map[SIZE][SIZE], Point player) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player.x && j == player.y) {
                printf("@");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char map[SIZE][SIZE];
    generate_map(map);

    Point player = {0, 0};
    while (1) {
        system("clear");
        print_map(map, player);

        char input;
        scanf("%c", &input);

        switch (input) {
            case 'w':
                if (player.y > 0 && count_adjacent_walls(player, map) == 1) {
                    player.y--;
                }
                break;
            case's':
                if (player.y < SIZE - 1 && count_adjacent_walls(player, map) == 1) {
                    player.y++;
                }
                break;
            case 'a':
                if (player.x > 0 && count_adjacent_walls(player, map) == 1) {
                    player.x--;
                }
                break;
            case 'd':
                if (player.x < SIZE - 1 && count_adjacent_walls(player, map) == 1) {
                    player.x++;
                }
                break;
            default:
                break;
        }
    }

    return 0;
}