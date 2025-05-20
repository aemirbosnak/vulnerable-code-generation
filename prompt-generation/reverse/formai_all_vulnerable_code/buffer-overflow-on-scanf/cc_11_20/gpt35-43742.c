//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: funny
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_remote_connected = true;
bool is_vehicle_on = false;
int vehicle_speed = 0;

int main()
{
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please make sure the remote is connected.\n");

    while (is_remote_connected)
    {
        char user_input;
        printf("Press 'p' to power on the vehicle or 'q' to quit: ");
        scanf(" %c", &user_input);

        switch (user_input)
        {
            case 'p':
                printf("Vehicle powering on...\n");
                is_vehicle_on = true;
                break;

            case 'q':
                printf("Remote disconnected. Goodbye!\n");
                is_remote_connected = false;
                break;

            default:
                printf("Invalid input. Try again.\n");
                break;
        }

        while (is_vehicle_on)
        {
            printf("Use the arrow keys to control the vehicle:\n");
            printf("up - increase speed | down - decrease speed | left - turn left | right - turn right | space - stop\n");

            char key_input;
            scanf(" %c", &key_input);

            switch (key_input)
            {
                case 'up':
                    vehicle_speed++;
                    printf("Vehicle speed: %d\n", vehicle_speed);
                    break;

                case 'down':
                    vehicle_speed--;
                    printf("Vehicle speed: %d\n", vehicle_speed);
                    break;

                case 'left':
                    printf("Vehicle turning left...\n");
                    break;

                case 'right':
                    printf("Vehicle turning right...\n");
                    break;

                case 'space':
                    vehicle_speed = 0;
                    printf("Vehicle stopped.\n");
                    break;

                default:
                    printf("Invalid input. Try again.\n");
                    break;
            }

            if (vehicle_speed < 0)
            {
                vehicle_speed = 0;
            }
            else if (vehicle_speed > 100)
            {
                vehicle_speed = 100;
            }
        }
    }

    return 0;
}