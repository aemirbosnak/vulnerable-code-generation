#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int joy_input[4];
    int speed = 0;
    int direction = 0;

    while (1)
    {
        printf("Enter joystick input (up, down, left, right): ");
        scanf("%d %d %d %d", &joy_input[0], &joy_input[1], &joy_input[2], &joy_input[3]);

        // Update speed and direction based on joystick input
        if (joy_input[0] > 0)
        {
            speed++;
            direction = 0;
        }
        else if (joy_input[1] > 0)
        {
            speed--;
            direction = 180;
        }
        else if (joy_input[2] > 0)
        {
            direction--;
            speed = 0;
        }
        else if (joy_input[3] > 0)
        {
            direction++;
            speed = 0;
        }

        // Ensure speed and direction stay within reasonable bounds
        if (speed > 5)
        {
            speed = 5;
        }
        if (speed < 0)
        {
            speed = 0;
        }
        if (direction < 0)
        {
            direction = 0;
        }
        if (direction > 179)
        {
            direction = 179;
        }

        // Print current speed and direction
        printf("Speed: %d, Direction: %d\n", speed, direction);
    }

    return 0;
}
