//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int battery = 100;
    int altitude = 0;
    int temperature = 20;
    int humidity = 60;
    char remoteControl[10];

    printf("Welcome to the C Drone Remote Control System!\n");

    while (battery > 0) {
        printf("Current Battery Level: %d%%\n", battery);
        printf("Current Altitude: %dm\n", altitude);
        printf("Current Temperature: %dC\n", temperature);
        printf("Current Humidity: %d%%\n", humidity);
        printf("Enter Command: ");
        scanf("%s", remoteControl);

        if (strcmp(remoteControl, "up") == 0) {
            if (altitude < 50) {
                altitude += 10;
                printf("Drone is up!\n");
            }
            else {
                printf("Drone cannot go higher than 50m!\n");
            }
        }
        else if (strcmp(remoteControl, "down") == 0) {
            if (altitude > 0) {
                altitude -= 10;
                printf("Drone is down!\n");
            }
            else {
                printf("Drone is already on the ground!\n");
            }
        }
        else if (strcmp(remoteControl, "left") == 0) {
            printf("Drone is moving left!\n");
        }
        else if (strcmp(remoteControl, "right") == 0) {
            printf("Drone is moving right!\n");
        }
        else if (strcmp(remoteControl, "forward") == 0) {
            printf("Drone is moving forward!\n");
        }
        else if (strcmp(remoteControl, "back") == 0) {
            printf("Drone is moving back!\n");
        }
        else if (strcmp(remoteControl, "land") == 0) {
            altitude = 0;
            printf("Drone has landed!\n");
        }
        else {
            printf("Invalid Command! Please try again.\n");
        }

        temperature += (rand() % 3) - 1; // Fluctuate Temperature
        humidity += (rand() % 3) - 1; // Fluctuate Humidity
        battery -= rand() % 5; // Reduce Battery

        if (battery <= 0) {
            printf("Battery is Low! Drone is landing!\n");
            altitude = 0;
        }
    }

    printf("Drone has shut down!\n");

    return 0;
}