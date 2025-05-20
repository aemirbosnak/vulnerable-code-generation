//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH  10
#define MAP_HEIGHT 10

char map[MAP_WIDTH][MAP_HEIGHT];
int player_x, player_y;

void generate_map() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (i == 0 || i == MAP_WIDTH - 1 || j == 0 || j == MAP_HEIGHT - 1) {
                map[i][j] = '#';
            } else {
                map[i][j] = ' ';
            }
        }
    }
}

void place_player() {
    player_x = MAP_WIDTH / 2;
    player_y = MAP_HEIGHT / 2;
}

void print_map() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            if (i == player_x && j == player_y) {
                printf("@");
            } else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
}

void move_player(int dx, int dy) {
    if (map[player_x + dx][player_y + dy] != '#') {
        player_x += dx;
        player_y += dy;
    }
}

int main() {
    srand(time(NULL));

    generate_map();
    place_player();

    while (1) {
        print_map();

        int dx, dy;
        printf("Enter direction (WASD): ");
        scanf(" %c", &dx);

        switch (dx) {
            case 'w':
                dy = -1;
                break;
            case 'a':
                dy = 0;
                dx = -1;
                break;
            case 's':
                dy = 1;
                break;
            case 'd':
                dy = 0;
                dx = 1;
                break;
        }

        move_player(dx, dy);
    }

    return 0;
}