//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>

int main() {
    int drone_power = 100;
    int drone_height = 0;
    int drone_heading = 0;

    printf("Welcome to C Drone Remote Control Program\n");

    while (drone_power > 0) {
        printf("\nChoose an action:\n");
        printf("1. Change height\n");
        printf("2. Change heading\n");
        printf("3. Display current status\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter new height: ");
                int new_height;
                scanf("%d", &new_height);

                if (new_height >= 0 && new_height <= 100) {
                    drone_height = new_height;
                    printf("Height has been changed to %d\n", drone_height);
                } else {
                    printf("Invalid height, try again.\n");
                }
                break;

            case 2:
                printf("\nEnter new heading: ");
                int new_heading;
                scanf("%d", &new_heading);

                if (new_heading >= 0 && new_heading < 360) {
                    drone_heading = new_heading;
                    printf("Heading has been changed to %d\n", drone_heading);
                } else {
                    printf("Invalid heading, try again.\n");
                }
                break;

            case 3:
                printf("\nCurrent status:\n");
                printf(" - Power: %d%%\n", drone_power);
                printf(" - Height: %d\n", drone_height);
                printf(" - Heading: %d\n", drone_heading);
                break;

            case 4:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice, try again.\n");
                break;
        }

        drone_power--;
    }

    printf("\nDrone has run out of power, exiting program.\n");
    return 0;
}