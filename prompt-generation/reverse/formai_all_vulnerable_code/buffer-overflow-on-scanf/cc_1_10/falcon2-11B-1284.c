//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: real-life
#include <stdio.h>

int main() {
    // Initialize robot movement variables
    int x = 0;
    int y = 0;
    int heading = 0; // 0 for north, 90 for east, 180 for south, 270 for west

    // User input for movement direction
    printf("Enter movement direction (N, E, S, W): ");
    char direction;
    scanf(" %c", &direction);

    // Calculate new robot position
    switch (direction) {
        case 'N':
            y++;
            break;
        case 'E':
            x++;
            break;
        case 'S':
            y--;
            break;
        case 'W':
            x--;
            break;
        default:
            printf("Invalid direction. Robot stays at current position.\n");
            break;
    }

    // Robot movement logic
    switch (heading) {
        case 0:
            printf("Robot moves north.\n");
            break;
        case 90:
            printf("Robot moves east.\n");
            break;
        case 180:
            printf("Robot moves south.\n");
            break;
        case 270:
            printf("Robot moves west.\n");
            break;
        default:
            printf("Robot stays at current position.\n");
            break;
    }

    // Print final robot position
    printf("Robot position: (%d, %d)\n", x, y);

    return 0;
}