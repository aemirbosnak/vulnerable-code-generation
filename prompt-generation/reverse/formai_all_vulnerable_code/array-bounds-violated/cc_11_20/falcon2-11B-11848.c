//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int maze[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int pacmanx = 5;
    int pacmany = 5;
    int ghostx = 8;
    int ghosty = 8;

    int direction = 1; // 1 = right, -1 = left, 0 = up, -1 = down

    printf("Welcome to Pac-Man!\n");
    printf("Use the arrow keys to move Pac-Man around the maze.\n");

    while (1) {
        if (direction == 1) {
            pacmany++;
        } else if (direction == -1) {
            pacmany--;
        } else if (direction == 0) {
            pacmanx--;
        } else {
            pacmanx++;
        }

        if (pacmany < 1 || pacmany > 9) {
            direction = -direction;
        } else if (pacmanx < 1 || pacmanx > 9) {
            direction = -direction;
        }

        if (pacmany == 9 && pacmanx == 9) {
            printf("Congratulations! You have eaten all the dots!\n");
            break;
        }

        printf("Pac-Man's position: %d, %d\n", pacmanx, pacmany);

        if (maze[pacmanx][pacmany] == 0) {
            printf("Pac-Man has eaten a dot!\n");
            maze[pacmanx][pacmany] = 1;
        } else if (maze[pacmanx][pacmany] == 1) {
            printf("Pac-Man has eaten a ghost!\n");
            maze[pacmanx][pacmany] = 2;
        }

        printf("Ghost's position: %d, %d\n", ghostx, ghosty);

        if (maze[ghostx][ghosty] == 0) {
            printf("Ghost has eaten a dot!\n");
            maze[ghostx][ghosty] = 1;
        } else if (maze[ghostx][ghosty] == 1) {
            printf("Ghost has eaten Pac-Man!\n");
            maze[ghostx][ghosty] = 2;
        }

        if (maze[pacmanx][pacmany] == 1 && maze[ghostx][ghosty] == 1) {
            printf("Game over!\n");
            break;
        }

        sleep(1); // Add a short delay to make the game more fluid
    }

    return 0;
}