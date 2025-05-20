//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

char map[10][10];
int player_x = 0;
int player_y = 0;
int score = 0;
bool game_over = false;

void init_map() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = '#';
        }
    }
    map[0][0] = 'S';
    map[9][9] = 'E';
}

void print_map() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void move(int dx, int dy) {
    int new_x = player_x + dx;
    int new_y = player_y + dy;

    if (new_x >= 0 && new_x < 10 && new_y >= 0 && new_y < 10 && map[new_x][new_y]!= '#') {
        player_x = new_x;
        player_y = new_y;
    }
}

int main() {
    srand(time(NULL));
    init_map();

    while (!game_over) {
        print_map();
        printf("Score: %d\n", score);

        char input;
        scanf(" %c", &input);

        switch (input) {
        case 'w':
        case 'W':
            move(0, -1);
            break;
        case's':
        case 'S':
            move(0, 1);
            break;
        case 'a':
        case 'A':
            move(-1, 0);
            break;
        case 'd':
        case 'D':
            move(1, 0);
            break;
        default:
            break;
        }

        if (player_x == 9 && player_y == 9) {
            game_over = true;
            printf("Congratulations! You won!\n");
        }
    }

    return 0;
}