//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Ephemeral drone remote control program
    float drone_heading;
    int drone_altitude;
    int drone_speed;
    char drone_status[50];
    char user_command[50];
    
    printf("Welcome to the ephemeral drone remote control program!\n");
    
    while (1) {
        printf("Enter a command (takeoff, land, up, down, left, right, forward, back, status, exit): ");
        scanf("%s", user_command);
        
        if (strcmp(user_command, "takeoff") == 0) {
            printf("Drone taking off...\n");
            drone_altitude = 50;
            drone_speed = 20;
            printf("Drone altitude: %d meters\n", drone_altitude);
            printf("Drone speed: %d km/h\n", drone_speed);
        }
        else if (strcmp(user_command, "land") == 0) {
            printf("Drone landing...\n");
            drone_altitude = 0;
            drone_speed = 0;
            printf("Drone altitude: %d meters\n", drone_altitude);
            printf("Drone speed: %d km/h\n", drone_speed);
        }
        else if (strcmp(user_command, "up") == 0) {
            printf("How high (in meters) would you like to go? ");
            scanf("%d", &drone_altitude);
            printf("Drone altitude: %d meters\n", drone_altitude);
        }
        else if (strcmp(user_command, "down") == 0) {
            printf("How low (in meters) would you like to go? ");
            scanf("%d", &drone_altitude);
            printf("Drone altitude: %d meters\n", drone_altitude);
        }
        else if (strcmp(user_command, "right") == 0) {
            printf("How many degrees to the right would you like to turn? ");
            scanf("%f", &drone_heading);
            printf("Drone heading: %.2f degrees\n", drone_heading);
        }
        else if (strcmp(user_command, "left") == 0) {
            printf("How many degrees to the left would you like to turn? ");
            scanf("%f", &drone_heading);
            printf("Drone heading: %.2f degrees\n", drone_heading);
        }
        else if (strcmp(user_command, "forward") == 0) {
            printf("How far (in meters) would you like to go forward? ");
            scanf("%d", &drone_altitude);
            printf("Drone altitude: %d meters\n", drone_altitude);
        }
        else if (strcmp(user_command, "back") == 0) {
            printf("How far (in meters) would you like to go back? ");
            scanf("%d", &drone_altitude);
            printf("Drone altitude: %d meters\n", drone_altitude);
        }
        else if (strcmp(user_command, "status") == 0) {
            printf("Drone status:\n");
            printf("Altitude: %d meters\n", drone_altitude);
            printf("Speed: %d km/h\n", drone_speed);
            printf("Heading: %.2f degrees\n", drone_heading);
            printf("Status: %s\n", drone_status);
        }
        else if (strcmp(user_command, "exit") == 0) {
            printf("Exiting program...\n");
            exit(0);
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}