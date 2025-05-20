//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Alan Touring
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool powerOn = false; // drone starts off
    bool inFlight = false; // drone is not flying
    int altitude = 0; // drone is on the ground
    int direction = 0; // drone is facing north
    int speed = 0; // drone is not moving

    printf("Welcome to C Drone Remote Control\n");
    printf("Please enter a command:\n");

    while (true) {
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "powerOn") == 0) {
            powerOn = true;
            printf("Drone has been powered on\n");
        }
        else if (strcmp(command, "powerOff") == 0) {
            powerOn = false;
            printf("Drone has been powered off\n");
        }
        else if (strcmp(command, "takeoff") == 0) {
            if (powerOn && !inFlight) {
                inFlight = true;
                altitude = 10;
                speed = 5;
                printf("Drone has taken off\n");
            }
            else if (!powerOn) {
                printf("Please power on the drone first\n");
            }
            else if (inFlight) {
                printf("Drone is already in the air\n");
            }
        }
        else if (strcmp(command, "land") == 0) {
            if (inFlight) {
                altitude = 0;
                speed = 0;
                inFlight = false;
                printf("Drone has landed\n");
            }
            else {
                printf("Drone is already on the ground\n");
            }
        }
        else if (strcmp(command, "up") == 0) {
            if (inFlight) {
                altitude += 5;
                printf("Drone has ascended to %d meters\n", altitude);
            }
            else {
                printf("Drone is not in flight\n");
            }
        }
        else if (strcmp(command, "down") == 0) {
            if (inFlight) {
                if (altitude <= 5) {
                    altitude = 0;
                    speed = 0;
                    inFlight = false;
                    printf("Drone has landed\n");
                }
                else {
                    altitude -= 5;
                    printf("Drone has descended to %d meters\n", altitude);
                }
            }
            else {
                printf("Drone is not in flight\n");
            }
        }
        else if (strcmp(command, "forward") == 0) {
            if (inFlight) {
                if (direction == 0) {
                    printf("Drone has moved forward 10 meters\n");
                }
                else if (direction == 90) {
                    printf("Drone has moved right 10 meters\n");
                }
                else if (direction == 180) {
                    printf("Drone has moved backwards 10 meters\n");
                }
                else if (direction == 270) {
                    printf("Drone has moved left 10 meters\n");
                }
            }
            else {
                printf("Drone is not in flight\n");
            }
        }
        else if (strcmp(command, "left") == 0) {
            if (inFlight) {
                direction = (direction + 270) % 360;
                printf("Drone has turned left\n");
            }
            else {
                printf("Drone is not in flight\n");
            }
        }
        else if (strcmp(command, "right") == 0) {
            if (inFlight) {
                direction = (direction + 90) % 360;
                printf("Drone has turned right\n");
            }
            else {
                printf("Drone is not in flight\n");
            }
        }
        else if (strcmp(command, "speed") == 0) {
           if (inFlight) {
                printf("Please enter a speed:\n");
                int newSpeed;
                scanf("%d", &newSpeed);
                if (newSpeed <= 10) {
                    speed = newSpeed;
                    printf("Drone is now flying at %d km/h\n", speed);
                }
                else {
                    printf("Maximum speed is 10 km/h\n");
                }
           }
           else {
                printf("Drone is not in flight\n");
           }
        }
        else if (strcmp(command, "status") == 0) {
            if (powerOn) {
                printf("Drone is powered on\n");
                if (inFlight) {
                    printf("Drone is in flight at %d meters, facing %d degrees, at %d km/h\n", altitude, direction, speed);
                }
                else {
                    printf("Drone is on the ground\n");
                }
            }
            else {
                printf("Drone is powered off\n");
            }
        }
        else {
            printf("Invalid command\n");
        }
    }
    
    return 0;
}