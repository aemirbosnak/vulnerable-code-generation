//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    char direction[10];
    int distance;

    // Prompt user for direction and distance
    printf("Enter direction (N, E, S, W): ");
    scanf("%s", direction);

    printf("Enter distance (in meters): ");
    scanf("%d", &distance);

    // Process direction and distance
    switch(direction[0]) {
        case 'N':
            printf("Moving north by %d meters\n", distance);
            break;
        case 'E':
            printf("Moving east by %d meters\n", distance);
            break;
        case 'S':
            printf("Moving south by %d meters\n", distance);
            break;
        case 'W':
            printf("Moving west by %d meters\n", distance);
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }

    // Move robot
    if (strcmp(direction, "N") == 0) {
        // Move north
        printf("Moving north\n");
    } else if (strcmp(direction, "E") == 0) {
        // Move east
        printf("Moving east\n");
    } else if (strcmp(direction, "S") == 0) {
        // Move south
        printf("Moving south\n");
    } else if (strcmp(direction, "W") == 0) {
        // Move west
        printf("Moving west\n");
    } else {
        // Invalid direction
        printf("Invalid direction!\n");
    }

    return 0;
}