//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct drone {
    char name[50];
    float x, y, z;
    int altitude;
    int battery_level;
};

int main() {
    struct drone my_drone;
    int option, x_offset, y_offset, z_offset;

    printf("Welcome to the Drone Remote Control!\n");
    printf("What is the name of your drone? ");
    fgets(my_drone.name, sizeof(my_drone.name), stdin);
    printf("Name set to %s.\n", my_drone.name);

    printf("Enter the initial coordinates (x, y, z): ");
    scanf("%f %f %f", &my_drone.x, &my_drone.y, &my_drone.z);
    printf("Coordinates set to (%f, %f, %f).\n", my_drone.x, my_drone.y, my_drone.z);

    printf("What is the initial altitude? ");
    scanf("%d", &my_drone.altitude);
    printf("Altitude set to %d.\n", my_drone.altitude);

    printf("What is the initial battery level? ");
    scanf("%d", &my_drone.battery_level);
    printf("Battery level set to %d.\n", my_drone.battery_level);

    printf("Choose an option:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Move left\n");
    printf("4. Move right\n");
    printf("5. Move up\n");
    printf("6. Move down\n");
    printf("7. Land\n");
    printf("8. Takeoff\n");
    printf("9. Quit\n");

    while (1) {
        printf("\nChoose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Moving forward...\n");
                x_offset = 0.5;
                y_offset = 0.0;
                z_offset = 0.0;
                my_drone.x += x_offset;
                my_drone.y += y_offset;
                my_drone.z += z_offset;
                break;
            case 2:
                printf("Moving backward...\n");
                x_offset = -0.5;
                y_offset = 0.0;
                z_offset = 0.0;
                my_drone.x -= x_offset;
                my_drone.y += y_offset;
                my_drone.z += z_offset;
                break;
            case 3:
                printf("Moving left...\n");
                x_offset = 0.0;
                y_offset = 0.5;
                z_offset = 0.0;
                my_drone.x += x_offset;
                my_drone.y -= y_offset;
                my_drone.z += z_offset;
                break;
            case 4:
                printf("Moving right...\n");
                x_offset = 0.0;
                y_offset = -0.5;
                z_offset = 0.0;
                my_drone.x -= x_offset;
                my_drone.y -= y_offset;
                my_drone.z += z_offset;
                break;
            case 5:
                printf("Moving up...\n");
                x_offset = 0.0;
                y_offset = 0.0;
                z_offset = 0.5;
                my_drone.x += x_offset;
                my_drone.y += y_offset;
                my_drone.z -= z_offset;
                break;
            case 6:
                printf("Moving down...\n");
                x_offset = 0.0;
                y_offset = 0.0;
                z_offset = -0.5;
                my_drone.x -= x_offset;
                my_drone.y -= y_offset;
                my_drone.z -= z_offset;
                break;
            case 7:
                printf("Landing...\n");
                my_drone.altitude = 0;
                break;
            case 8:
                printf("Taking off...\n");
                my_drone.altitude = 10;
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }

        printf("Coordinates after move: (%f, %f, %f)\n", my_drone.x, my_drone.y, my_drone.z);
        printf("Altitude: %d\n", my_drone.altitude);
        printf("Battery level: %d\n", my_drone.battery_level);

        printf("\nPress any key to continue...");
        getchar();
    }

    return 0;
}