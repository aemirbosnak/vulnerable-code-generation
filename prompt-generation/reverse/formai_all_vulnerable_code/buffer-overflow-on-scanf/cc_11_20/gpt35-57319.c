//FormAI DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 50
#define MAX_Y 50

int main()
{
    int x = 0, y = 0;
    char direction;
    
    srand(time(NULL)); // Seed the random number generator
    
    while(1)
    {
        printf("Current position: (%d,%d)\n", x, y);
        printf("Enter direction (U/D/L/R): ");
        scanf(" %c", &direction); // Make sure to leave a space before %c to consume the newline character
        
        switch(direction)
        {
            case 'U':
            case 'u':
                if(y == MAX_Y) // Check if robot is already at the top edge
                {
                    printf("ERROR: Robot cannot move further up\n");
                }
                else
                {
                    y++; // Move robot up
                }
                break;
            case 'D':
            case 'd':
                if(y == 0) // Check if robot is already at the bottom edge
                {
                    printf("ERROR: Robot cannot move further down\n");
                }
                else
                {
                    y--; // Move robot down
                }
                break;
            case 'L':
            case 'l':
                if(x == 0) // Check if robot is already at the left edge
                {
                    printf("ERROR: Robot cannot move further left\n");
                }
                else
                {
                    x--; // Move robot left
                }
                break;
            case 'R':
            case 'r':
                if(x == MAX_X) // Check if robot is already at the right edge
                {
                    printf("ERROR: Robot cannot move further right\n");
                }
                else
                {
                    x++; // Move robot right
                }
                break;
            case 'S':
            case 's':
                printf("Shutting down...\n");
                return 0; // Exit program
            default:
                printf("ERROR: Invalid direction entered\n");
                break;
        }
        
        printf("New position: (%d,%d)\n", x, y);
        printf("Temperature: %d degrees Celsius\n", (rand() % 51) - 10); // Generate random temperature between -10 and 40 degrees Celsius
        printf("Humidity: %d%%\n\n", rand() % 101); // Generate random humidity percentage between 0 and 100
    }
    
    return 0; // Should never reach this point
}