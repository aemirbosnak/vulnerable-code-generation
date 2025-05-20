//FormAI DATASET v1.0 Category: Robot movement control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Robot position
int x = 0;
int y = 0;

// Function to move the robot
void move(char direction, int distance) {
    switch (direction) {
        case 'U':
            y += distance;
            break;
        case 'D':
            y -= distance;
            break;
        case 'L':
            x -= distance;
            break;
        case 'R':
            x += distance;
            break;
        default:
            printf("Invalid direction.\n");
    }
}

int main() {
    printf("Welcome to C Robot!\n");
    printf("Your current position is (%d, %d).\n", x, y);

    // Get user inputs
    char input[100];
    printf("Enter your move (e.g. U 5 to move up by 5): ");
    fgets(input, 100, stdin);

    // Parse user inputs
    char direction;
    int distance;
    if (sscanf(input, " %c %d", &direction, &distance) != 2) {
        printf("Invalid input format.\n");
        return 1;
    }

    // Move the robot
    move(direction, distance);

    // Print updated position
    printf("Your new position is (%d, %d).\n", x, y);

    return 0;
}