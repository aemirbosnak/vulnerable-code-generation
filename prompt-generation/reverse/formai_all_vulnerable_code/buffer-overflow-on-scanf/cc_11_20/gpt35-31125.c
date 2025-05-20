//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#define MAX_DISTANCE 10000

int main() {
    int battery, distance, spd, alt;
    char command;

    printf("Enter Drone Battery Percentage: ");
    scanf("%d", &battery);

    if (battery < 10) {
        printf("Battery too low to fly, please charge the drone\n");
        return 0;
    }

    printf("Enter Maximum Drone Altitude (in meters): ");
    scanf("%d", &alt);

    printf("Connect Drone to Remote\n");

    printf("---Drone Control---\n\n");

    do {
        printf("Enter Command:\nF (Forward) | B (Backward) | R (Right) | L (Left) | U (Up) | D (Down) | Q (Quit)\n\n");
        scanf(" %c", &command);

        switch(command) {
            case 'F':
                printf("Enter Distant to Move Forward (in meters): ");
                scanf("%d", &distance);

                if (distance > MAX_DISTANCE) {
                    printf("Distance is too far, drone cannot move that far away\n");
                } else {
                    printf("Moving Drone Forward by %d meters...\n", distance);
                }
                break;

            case 'B':
                printf("Enter Distant to Move Backward (in meters): ");
                scanf("%d", &distance);

                if (distance > MAX_DISTANCE) {
                    printf("Distance is too far, drone cannot move that far away\n");
                } else {
                    printf("Moving Drone Backward by %d meters...\n", distance);
                }
                break;

            case 'R':
                printf("Enter Distant to Move Right (in meters): ");
                scanf("%d", &distance);

                if (distance > MAX_DISTANCE) {
                    printf("Distance is too far, drone cannot move that far away\n");
                } else {
                    printf("Moving Drone Right by %d meters...\n", distance);
                }
                break;

            case 'L':
                printf("Enter Distant to Move Left (in meters): ");
                scanf("%d", &distance);

                if (distance > MAX_DISTANCE) {
                    printf("Distance is too far, drone cannot move that far away\n");
                } else {
                    printf("Moving Drone Left by %d meters...\n", distance);
                }
                break;

            case 'U':
                printf("Enter Altitude to Move Up (in meters): ");
                scanf("%d", &alt);

                if (alt > MAX_DISTANCE) {
                    printf("Altitude is too high, drone cannot fly that high\n");
                } else {
                    printf("Flying Drone Up to %d meters...\n", alt);
                }
                break;

            case 'D':
                printf("Enter Altitude to Move Down (in meters): ");
                scanf("%d", &alt);

                if (alt < 0) {
                    printf("Drone cannot go down below ground level\n");
                } else {
                    printf("Flying Drone Down to %d meters...\n", alt);
                }
                break;

            case 'Q':
                printf("Quitting Program....\n");
                return 0;

            default:
                printf("Invalid Command, please try again\n");
                break;
        }

        printf("\n");

    } while(command != 'Q');

    return 0;
}