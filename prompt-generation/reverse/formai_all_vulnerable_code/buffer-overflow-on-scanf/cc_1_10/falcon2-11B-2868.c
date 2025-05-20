//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Initialize the vehicle
    int vehicleID = 1;
    int speed = 0;
    int direction = 1; // 1 = forward, 0 = backward
    int turn = 0; // 1 = right, 0 = left
    int targetSpeed = 10;

    // Loop forever
    while (1) {
        // Get user input
        printf("Vehicle %d - Input your command: ", vehicleID);
        char command[50];
        scanf("%s", command);

        // Process the command
        if (strcmp(command, "forward") == 0) {
            speed = targetSpeed;
        } else if (strcmp(command, "backward") == 0) {
            speed = -targetSpeed;
        } else if (strcmp(command, "right") == 0) {
            turn = 1;
        } else if (strcmp(command, "left") == 0) {
            turn = 0;
        } else if (strcmp(command, "stop") == 0) {
            speed = 0;
            turn = 0;
        } else {
            printf("Invalid command\n");
            continue;
        }

        // Update the vehicle's state
        direction = (direction + turn) % 2; // toggle direction
        speed += direction * 2; // adjust speed based on direction
        if (speed > 100) {
            speed = 100;
        } else if (speed < -100) {
            speed = -100;
        }

        // Send the updated state to the other vehicles
        printf("Vehicle %d - Sending state: %d, %d, %d, %d\n", vehicleID, direction, speed, turn, targetSpeed);
        printf("Vehicle %d - Received state: %d, %d, %d, %d\n", vehicleID, direction, speed, turn, targetSpeed);
        sleep(1);
    }
    return 0;
}