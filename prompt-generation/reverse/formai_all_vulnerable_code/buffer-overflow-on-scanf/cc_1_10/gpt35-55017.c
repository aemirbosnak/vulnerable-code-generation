//FormAI DATASET v1.0 Category: Robot movement control ; Style: distributed
// A Distributed Control System for a Robot to Move in a Grid

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Set grid size
    int grid_size = 5;

    // Set initial position of robot
    int x_pos = 0;
    int y_pos = 0;

    // Declare variables to store movement commands
    int x_cmd = 0;
    int y_cmd = 0;

    // Loop for taking movement commands
    while(1)
    {
        // Get movement commands from input
        printf("Enter x movement command for robot (-1 to quit): ");
        scanf("%d", &x_cmd);
        if(x_cmd == -1) break;

        printf("Enter y movement command for robot: ");
        scanf("%d", &y_cmd);

        // Calculate new position of robot
        int new_x_pos = x_pos + x_cmd;
        int new_y_pos = y_pos + y_cmd;

        // Check if new position is within grid
        if(new_x_pos < 0 || new_x_pos >= grid_size || new_y_pos < 0 || new_y_pos >= grid_size)
        {
            printf("Error: Robot cannot move outside of grid\n");
        }
        else
        {
            // Move robot to new position
            x_pos = new_x_pos;
            y_pos = new_y_pos;

            // Send movement commands to distributed control system
            printf("Sending movement commands (%d,%d) to distributed control system\n", x_cmd, y_cmd);

            // Wait for response from distributed control system
            printf("Waiting for response from distributed control system...\n");
            // Assume response time is 2 seconds
            sleep(2);

            // Receive response from distributed control system
            printf("Received response from distributed control system\n");

            // Print new position of robot
            printf("New position of robot: (%d,%d)\n", x_pos, y_pos);
        }
    }

    return 0;
}