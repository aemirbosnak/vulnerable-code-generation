//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_map(int map[10][10], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                map[i][j] = 1;
            } else {
                map[i][j] = rand() % 2;
            }
        }
    }
}

void print_map(int map[10][10], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void move(int map[10][10], int player_x, int player_y, int direction) {
    if (direction == 1) {
        if (player_x > 0 && map[player_y][player_x - 1] == 0) {
            player_x--;
        }
    } else if (direction == 2) {
        if (player_y > 0 && map[player_y - 1][player_x] == 0) {
            player_y--;
        }
    } else if (direction == 3) {
        if (player_x < 9 && map[player_y][player_x + 1] == 0) {
            player_x++;
        }
    } else if (direction == 4) {
        if (player_y < 9 && map[player_y + 1][player_x] == 0) {
            player_y++;
        }
    }
}

int main() {
    int map[10][10];
    int player_x = 0;
    int player_y = 0;
    int width = 10;
    int height = 10;
    generate_map(map, width, height);
    print_map(map, width, height);
    while (1) {
        printf("Enter direction (1 up, 2 left, 3 down, 4 right): ");
        int direction;
        scanf("%d", &direction);
        move(map, player_x, player_y, direction);
        if (map[player_y][player_x] == 1) {
            printf("You hit a wall!\n");
        } else {
            printf("You moved successfully.\n");
        }
        print_map(map, width, height);
    }
    return 0;
}