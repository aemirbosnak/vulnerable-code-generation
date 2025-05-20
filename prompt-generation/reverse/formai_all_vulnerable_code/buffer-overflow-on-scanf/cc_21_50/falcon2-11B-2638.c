//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

int main() {
    Point pacman = {0, 0};
    Point ghost[4] = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};

    srand(time(NULL));

    while (1) {
        printf("--------------------------------------\n");
        printf("-    Pac-Man: %d,%d\n", pacman.x, pacman.y);
        printf("-    Ghost:  %d,%d %d,%d %d,%d %d,%d\n", ghost[0].x, ghost[0].y, ghost[1].x, ghost[1].y, ghost[2].x, ghost[2].y, ghost[3].x, ghost[3].y);

        int move = 0;
        int x, y;
        do {
            printf("Choose a move: ");
            printf("(1) Up\n");
            printf("(2) Down\n");
            printf("(3) Left\n");
            printf("(4) Right\n");
            printf("(0) Quit\n");
            scanf("%d", &move);
        } while (move!= 0 && move!= 1 && move!= 2 && move!= 3 && move!= 4);

        switch (move) {
            case 0:
                break;
            case 1:
                y = pacman.y + 1;
                break;
            case 2:
                y = pacman.y - 1;
                break;
            case 3:
                x = pacman.x - 1;
                break;
            case 4:
                x = pacman.x + 1;
                break;
        }

        if (x == -1 || x == 10 || y == -1 || y == 10) {
            printf("Game Over!\n");
            break;
        }

        pacman.x = x;
        pacman.y = y;

        if (pacman.x == ghost[0].x && pacman.y == ghost[0].y ||
            pacman.x == ghost[1].x && pacman.y == ghost[1].y ||
            pacman.x == ghost[2].x && pacman.y == ghost[2].y ||
            pacman.x == ghost[3].x && pacman.y == ghost[3].y) {
            printf("You lose!\n");
            break;
        }

        for (int i = 0; i < 4; i++) {
            int x = ghost[i].x + 1;
            int y = ghost[i].y + 1;
            if (x == 10 || y == 10) {
                ghost[i].x = rand() % 10 + 1;
                ghost[i].y = rand() % 10 + 1;
            } else if (x == pacman.x && y == pacman.y) {
                printf("You win!\n");
                break;
            }
        }
    }

    return 0;
}