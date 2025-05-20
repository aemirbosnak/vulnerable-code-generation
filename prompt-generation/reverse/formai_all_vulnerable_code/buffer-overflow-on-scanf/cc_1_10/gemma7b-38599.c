//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Define the map dimensions
    int x_max = 100;
    int y_max = 100;

    // Create a simulated GPS device
    int current_x = 0;
    int current_y = 0;

    // Simulate GPS signal noise
    int noise = rand() % 10;

    // Set the time
    time_t t = time(NULL);

    // Loop to simulate navigation
    while (1)
    {
        // Update the simulated GPS device
        current_x += noise;
        current_y += noise;

        // Print the current position
        printf("Current position: (%d, %d)\n", current_x, current_y);

        // Check if the user wants to quit
        char input;
        printf("Press 'q' to quit: ");
        scanf("%c", &input);

        // If the user wants to quit, exit the loop
        if (input == 'q')
        {
            break;
        }

        // Sleep for a while
        sleep(1);
    }

    // Print a goodbye message
    printf("Goodbye!\n");

    return 0;
}