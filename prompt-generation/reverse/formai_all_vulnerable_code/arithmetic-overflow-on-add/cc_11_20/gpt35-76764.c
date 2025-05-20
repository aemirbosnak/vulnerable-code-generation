//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int drone_speed;
    int drone_direction;
    int remote_direction;
    int remote_input = 0;

    printf("Welcome to the Drone Remote Control Program.\n");

    while (remote_input != 9) {
        printf("\nChoose an option from below:\n");
        printf("1 - Set Drone Speed (in meters per second)\n");
        printf("2 - Set Drone Direction (in degrees)\n");
        printf("3 - Set Remote Direction (in degrees)\n");
        printf("4 - Turn Drone Left\n");
        printf("5 - Turn Drone Right\n");
        printf("6 - Move Drone Forward\n");
        printf("7 - Move Drone Backward\n");
        printf("8 - Stop Drone\n");
        printf("9 - Quit\n");

        scanf("%d", &remote_input);

        switch (remote_input) {
            case 1:
                printf("Enter Drone speed (in meters per second): ");
                scanf("%d", &drone_speed);
                break;
            case 2:
                printf("Enter Drone direction (in degrees): ");
                scanf("%d", &drone_direction);
                break;
            case 3:
                printf("Enter Remote direction (in degrees): ");
                scanf("%d", &remote_direction);
                break;
            case 4:
                drone_direction += 90;
                break;
            case 5:
                drone_direction -= 90;
                break;
            case 6:
                drone_direction = remote_direction;
                printf("Drone moved forward\n");
                break;
            case 7:
                drone_direction = remote_direction + 180;
                printf("Drone moved backward\n");
                break;
            case 8:
                drone_speed = 0;
                printf("Drone stopped\n");
                break;
            case 9:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid input, please try again\n");
                break;
        }

        // Normalize the drone_direction angle between 0 and 360 degrees
        if (drone_direction < 0) {
            drone_direction += 360;
        } else if (drone_direction > 360) {
            drone_direction -= 360;
        }
    }

    return 0;
}