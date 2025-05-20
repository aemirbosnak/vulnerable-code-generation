//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LEN 10

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LEN];
    int x = 0, y = 0, z = 0; // Current position coordinate values
    int max_height = 50; // Maximum height the drone can reach 
    int min_height = 0; // Minimum height the drone can reach
    int speed = 10; // Speed at which the drone moves 
    int max_speed = 50; // Maximum speed the drone can move
    int min_speed = 1; // Minimum speed the drone can move

    printf("Welcome to the drone controller!\n");
    while(1) {
        printf("> ");
        scanf("%s", input);
        if(strcmp(input, "help") == 0) {
            printf("Available commands: up, down, left, right, forward, back, speed, height, help, exit\n");
        } else if(strcmp(input, "up") == 0) {
            if(z + speed > max_height) {
                printf("Cannot move higher than maximum height of %d\n", max_height);
            } else {
                z += speed;
                printf("Moved up to height %d\n", z);
            }
        } else if(strcmp(input, "down") == 0) {
            if(z - speed < min_height) {
                printf("Cannot move lower than minimum height of %d\n", min_height);
            } else {
                z -= speed;
                printf("Moved down to height %d\n", z);
            }
        } else if(strcmp(input, "left") == 0) {
            x -= speed;
            printf("Moved left to position (%d, %d, %d)\n", x, y, z);
        } else if(strcmp(input, "right") == 0) {
            x += speed;
            printf("Moved right to position (%d, %d, %d)\n", x, y, z);
        } else if(strcmp(input, "forward") == 0) {
            y += speed;
            printf("Moved forward to position (%d, %d, %d)\n", x, y, z);
        } else if(strcmp(input, "back") == 0) {
            y -= speed;
            printf("Moved back to position (%d, %d, %d)\n", x, y, z);
        } else if(strcmp(input, "speed") == 0) {
            int new_speed;
            printf("Enter new speed value (between %d-%d): ", min_speed, max_speed);
            scanf("%d", &new_speed);
            if(new_speed > max_speed || new_speed < min_speed) {
                printf("Invalid speed value. Valid speed range is %d-%d\n", min_speed, max_speed);
            } else {
                speed = new_speed;
                printf("Speed set to %d\n", speed);
            }
        } else if(strcmp(input, "height") == 0) {
            printf("Current height is %d\n", z);
        } else if(strcmp(input, "exit") == 0) {
            printf("Exiting drone controller. Bye!\n");
            break;
        } else {
            printf("Invalid command. Type 'help' for available commands.\n");
        }
    }
    return 0;
}