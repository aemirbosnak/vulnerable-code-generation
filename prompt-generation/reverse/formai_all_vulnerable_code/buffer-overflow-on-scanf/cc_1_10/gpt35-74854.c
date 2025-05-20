//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    double x = 0, y = 0, direction = 0, speed = 0;
    char input[10];

    printf("Welcome to Remote Control Vehicle Simulation\n");

    while(1)
    {
        printf("\nEnter command: ");
        scanf("%s", input);

        if(strcmp(input, "f") == 0)
        {
            x += speed * cos(direction * PI / 180);
            y += speed * sin(direction * PI / 180);
        }
        else if(strcmp(input, "b") == 0)
        {
            x -= speed * cos(direction * PI / 180);
            y -= speed * sin(direction * PI / 180);
        }
        else if(strcmp(input, "r") == 0)
        {
            direction += 10;
        }
        else if(strcmp(input, "l") == 0)
        {
            direction -= 10;
        }
        else if(strcmp(input, "+") == 0)
        {
            speed += 0.5;
        }
        else if(strcmp(input, "-") == 0)
        {
            speed -= 0.5;
        }
        else if(strcmp(input, "q") == 0)
        {
            printf("\nSimulation ended.\n");
            break;
        }
        else
        {
            printf("\nUnknown command.\n");
        }

        printf("Position: (%.2f, %.2f)\nDirection: %.2f\nSpeed: %.2f\n", x, y, direction, speed);
    }

    return 0;
}