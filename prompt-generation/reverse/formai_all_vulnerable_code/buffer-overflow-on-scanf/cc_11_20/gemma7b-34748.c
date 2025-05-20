//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand(time(&t));

    int map[10][10] = {{0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 1, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                              {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                              {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}
                           };

    int player_x = 0;
    int player_y = 0;

    char direction = ' ';

    while (direction != 'q') {
        system("cls");
        printf("Map:");
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                if (x == player_x && y == player_y) {
                    printf("P ");
                } else if (map[y][x] == 1) {
                    printf("# ");
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }

        printf("Enter direction (w, a, s, d, q): ");
        scanf(" %c", &direction);

        switch (direction) {
            case 'w':
                player_y--;
                break;
            case 'a':
                player_x--;
                break;
            case 's':
                player_y++;
                break;
            case 'd':
                player_x++;
                break;
            case 'q':
                break;
            default:
                printf("Invalid direction.\n");
        }

        if (map[player_y][player_x] == 1) {
            printf("Game Over!\n");
            direction = 'q';
        }
    }

    return 0;
}