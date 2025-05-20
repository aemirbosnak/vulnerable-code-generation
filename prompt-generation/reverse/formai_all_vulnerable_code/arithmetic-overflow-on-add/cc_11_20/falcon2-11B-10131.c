//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
    char direction[100]; // Array to store direction of robot movement
    int x, y; // Coordinates of robot on the grid
    int grid[10][10]; // 10x10 grid to represent the environment
    int max_x, max_y; // Maximum x and y coordinates of grid

    printf("Enter the starting position of robot (x, y): ");
    scanf("%d %d", &x, &y);

    max_x = x + 1; // Maximum x coordinate of grid is one more than the starting position
    max_y = y + 1; // Maximum y coordinate of grid is one more than the starting position

    printf("Enter the direction of movement (N, S, E, W): ");
    scanf("%s", direction);

    switch (direction[0]) {
        case 'N':
            grid[x][y] = 1;
            break;
        case 'S':
            grid[x][y] = -1;
            break;
        case 'E':
            grid[x][y] = 1;
            break;
        case 'W':
            grid[x][y] = -1;
            break;
        default:
            printf("Invalid direction. Please enter N, S, E, or W.\n");
            return 1;
    }

    while (1) {
        printf("Current position: (%d, %d)\n", x, y);
        printf("Enter the direction of movement (N, S, E, W): ");
        scanf("%s", direction);

        switch (direction[0]) {
            case 'N':
                if (y > 0) {
                    y--;
                    grid[x][y] = 1;
                }
                else {
                    printf("Robot cannot move in this direction. Please enter N, S, E, or W.\n");
                    return 1;
                }
                break;
            case 'S':
                if (y < max_y) {
                    y++;
                    grid[x][y] = -1;
                }
                else {
                    printf("Robot cannot move in this direction. Please enter N, S, E, or W.\n");
                    return 1;
                }
                break;
            case 'E':
                if (x < max_x) {
                    x++;
                    grid[x][y] = 1;
                }
                else {
                    printf("Robot cannot move in this direction. Please enter N, S, E, or W.\n");
                    return 1;
                }
                break;
            case 'W':
                if (x > 0) {
                    x--;
                    grid[x][y] = -1;
                }
                else {
                    printf("Robot cannot move in this direction. Please enter N, S, E, or W.\n");
                    return 1;
                }
                break;
            default:
                printf("Invalid direction. Please enter N, S, E, or W.\n");
                return 1;
        }
    }

    return 0;
}