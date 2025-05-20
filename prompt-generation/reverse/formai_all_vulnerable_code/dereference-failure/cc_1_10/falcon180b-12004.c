//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_map(char map[10][10], int player_x, int player_y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2? '#' : '.';
        }
    }
    map[player_y][player_x] = '@';
}

void print_map(char map[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void move_player(char map[10][10], int *player_x, int *player_y, int dx, int dy) {
    int new_x = *player_x + dx;
    int new_y = *player_y + dy;

    if (map[new_y][new_x] == '.') {
        *player_x = new_x;
        *player_y = new_y;
    }
}

int main() {
    srand(time(NULL));

    char map[10][10];
    int player_x = 0;
    int player_y = 0;

    create_map(map, player_x, player_y);

    while (1) {
        system("clear");
        print_map(map);

        char key;
        scanf("%c", &key);

        switch (key) {
            case 'w':
                move_player(map, &player_x, &player_y, -1, 0);
                break;
            case's':
                move_player(map, &player_x, &player_y, 1, 0);
                break;
            case 'a':
                move_player(map, &player_x, &player_y, 0, -1);
                break;
            case 'd':
                move_player(map, &player_x, &player_y, 0, 1);
                break;
            case 'q':
                exit(0);
        }
    }

    return 0;
}