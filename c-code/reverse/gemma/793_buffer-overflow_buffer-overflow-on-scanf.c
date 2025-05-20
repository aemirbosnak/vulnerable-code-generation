#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int joy_x, joy_y, speed = 0, direction = 0;

    while (1)
    {
        printf("Enter joystick input (x, y): ");
        scanf("%d %d", &joy_x, &joy_y);

        // Calculate direction and speed based on joystick input
        direction = (joy_x > 0) ? 1 : -1;
        speed = (joy_y > 0) ? joy_y : -joy_y;

        // Ensure speed and direction stay within limits
        if (speed > 5)
            speed = 5;
        if (speed < 0)
            speed = 0;
        if (direction > 1)
            direction = 1;
        if (direction < -1)
            direction = -1;

        // Print vehicle status
        printf("Speed: %d, Direction: %d\n", speed, direction);

        // Control vehicle movement
        // (code to move vehicle based on speed and direction)
    }

    return 0;
}
