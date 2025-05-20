//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char map[10][10];
int player_x = 0, player_y = 0;
int score = 0;
int game_over = 0;

void init_map() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2? '.' : '#';
        }
    }
    map[0][0] = '@';
}

void draw_map() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
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
        draw_map();
        printf("Score: %d\n", score);

        char input;
        scanf("%c", &input);

        switch (input) {
            case 'w':
                move(0, -1);
                break;
            case 'a':
                move(-1, 0);
                break;
            case's':
                move(0, 1);
                break;
            case 'd':
                move(1, 0);
                break;
            case 'q':
                game_over = 1;
                break;
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}