//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int speed = 0;
    char direction = 'N';
    int x_pos = 0;
    int y_pos = 0;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    while(1) 
    {
        printf("Current Speed: %d\n", speed);
        printf("Current Direction: %c\n", direction);
        printf("Current Position: (%d,%d)\n", x_pos, y_pos);

        printf("Enter a command (speed, direction, or quit):\n");

        char input[10];
        scanf("%s", input);

        if(strcmp(input, "speed") == 0) 
        {
            printf("Enter a speed (0-10):\n");
            int new_speed;
            scanf("%d", &new_speed);
            if(new_speed >= 0 && new_speed <= 10) 
            {
                speed = new_speed;
                printf("Speed set to %d\n", speed);
            } 
            else 
            {
                printf("Invalid speed entered\n");
            }
        } 
        else if(strcmp(input, "direction") == 0) 
        {
            printf("Enter a direction (N, S, E, or W):\n");
            char new_direction;
            scanf(" %c", &new_direction);
            if(new_direction == 'N' || new_direction == 'S' || new_direction == 'E' || new_direction == 'W') 
            {
                direction = new_direction;
                printf("Direction set to %c\n", direction);
            } 
            else 
            {
                printf("Invalid direction entered\n");
            }
        } 
        else if(strcmp(input, "quit") == 0) 
        {
            printf("Quitting program. Goodbye!\n");
            break;
        } 
        else 
        {
            printf("Invalid command entered\n");
        }

        switch(direction) 
        {
            case 'N':
                y_pos += speed;
                break;
            case 'S':
                y_pos -= speed;
                break;
            case 'E':
                x_pos += speed;
                break;
            case 'W':
                x_pos -= speed;
                break;
        }
    }

    return 0;
}