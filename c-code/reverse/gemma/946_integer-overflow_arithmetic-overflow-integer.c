#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int distance = 0;
    int speed = 0;
    int direction = 0;

    printf("Enter distance (in meters): ");
    scanf("%d", &distance);

    // Integer overflow vulnerability: multiplying distance by speed can cause an integer overflow
    speed = distance * 2;

    // Calculate direction based on user input
    printf("Enter direction (0 for forward, 1 for right, 2 for back, 3 for left): ");
    scanf("%d", &direction);

    // Move the vehicle
    switch (direction)
    {
        case 0:
            printf("Moving forward...\n");
            break;
        case 1:
            printf("Moving right...\n");
            break;
        case 2:
            printf("Moving back...\n");
            break;
        case 3:
            printf("Moving left...\n");
            break;
        default:
            printf("Invalid direction.\n");
    }

    // Display the final position of the vehicle
    printf("Final position: %d meters, %d meters.\n", distance, speed);

    return 0;
}
