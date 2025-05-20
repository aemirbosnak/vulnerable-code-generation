//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define LEFT 'a'
#define RIGHT 'd'
#define UP 'w'
#define DOWN 's'

bool isFlying = false; //initialize the drone in non-flying state
int altitude = 0; //initialize the altitude to ground level

int main() {
    printf("Welcome to your C drone remote control program!\n");
    printf("Commands: 'w' to move up, 's' to move down, 'a' to move left, 'd' to move right\n\n");

    char input;
    while (true) {
        printf("Enter a command: ");
        scanf("%c", &input);

        switch(input) {
            case UP:
                if (!isFlying) { //if drone is not flying, prompt user to take off
                    printf("Drone is not flying. Take off first. Press 't' to take off\n");
                } else {
                    altitude++;
                    printf("Drone moved up. Altitude is now %d\n", altitude);
                }
                break;

            case DOWN:
                if (!isFlying) { //if drone is not flying, prompt user to take off
                    printf("Drone is not flying. Take off first. Press 't' to take off\n");
                } else {
                    if (altitude > 0) { //drone cannot go below ground level
                        altitude--;
                        printf("Drone moved down. Altitude is now %d\n", altitude);
                    } else {
                        printf("Drone cannot go below ground level\n");
                    }
                }
                break;

            case LEFT:
                if (!isFlying) { //if drone is not flying, prompt user to take off
                    printf("Drone is not flying. Take off first. Press 't' to take off\n");
                } else {
                    printf("Drone moved left\n");
                }
                break;

            case RIGHT:
                if (!isFlying) { //if drone is not flying, prompt user to take off
                    printf("Drone is not flying. Take off first. Press 't' to take off\n");
                } else {
                    printf("Drone moved right\n");
                }
                break;

            case 't':
                if (!isFlying) { //take off if drone is not already flying
                    isFlying = true;
                    printf("Drone has taken off. Altitude is now %d\n", altitude);
                } else {
                    printf("Drone is already flying\n");
                }
                break;

            case 'l':
                if (isFlying) { //land the drone if it is flying
                    isFlying = false;
                    altitude = 0;
                    printf("Drone has landed. Altitude is now %d\n", altitude); //reset altitude to ground level
                } else {
                    printf("Drone is not flying\n");
                }
                break;

            default:
                printf("Invalid command\n");

        }
        while (getchar() != '\n');
        usleep(500000); //add a half second delay after each command to simulate drone movement
        system("clear"); //clear the console to show updated drone position   
    }
    return 0;
}