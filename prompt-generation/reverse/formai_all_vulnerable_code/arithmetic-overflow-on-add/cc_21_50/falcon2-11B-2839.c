//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: peaceful
#include <stdio.h>

int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    int dx = 1;
    int dy = 0;
    int dz = 0;

    while (1) {
        printf("The robot is at position (%d, %d, %d)\n", x, y, z);
        printf("Enter a direction (N, E, S, W, U, D, L, R): ");
        scanf("%s", &dx);
        printf("Enter a distance (positive for forward, negative for backward): ");
        scanf("%d", &dy);
        printf("Enter a direction (N, E, S, W, U, D, L, R): ");
        scanf("%s", &dz);

        if (dx == 'N') {
            y++;
        } else if (dx == 'E') {
            x++;
        } else if (dx == 'S') {
            y--;
        } else if (dx == 'W') {
            x--;
        } else if (dx == 'U') {
            z++;
        } else if (dx == 'D') {
            z--;
        } else if (dx == 'L') {
            if (dy == 1) {
                x--;
            } else if (dy == -1) {
                x++;
            }
        } else if (dx == 'R') {
            if (dy == 1) {
                y--;
            } else if (dy == -1) {
                y++;
            }
        }

        if (dy > 0) {
            x += dx * dy;
        } else if (dy < 0) {
            x -= dx * abs(dy);
        }

        if (dz == 'N') {
            y += dy * dz;
        } else if (dz == 'E') {
            x += dx * dz;
        } else if (dz == 'S') {
            y -= dy * dz;
        } else if (dz == 'W') {
            x -= dx * dz;
        } else if (dz == 'U') {
            z += dy * dz;
        } else if (dz == 'D') {
            z -= dy * dz;
        }

        if (x < 0 || x > 100 || y < 0 || y > 100 || z < 0 || z > 100) {
            break;
        }
    }

    printf("The robot has reached its destination.\n");

    return 0;
}