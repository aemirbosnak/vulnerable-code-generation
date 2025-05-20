//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

// declare global variables
int power = 0;
int altitude = 0;
int speed = 0;
bool isFlying = false;

// function prototypes
void takeOff();
void land();
void increaseSpeed(int increment);
void decreaseSpeed(int decrement);
void changeAltitude(int newAltitude);

int main() {

    // main menu loop
    while (true) {

        // display menu options
        printf("DRONE CONTROL MENU\n");
        printf("-------------------\n");
        printf("1. Power on/off\n");
        printf("2. Take off\n");
        printf("3. Land\n");
        printf("4. Increase speed\n");
        printf("5. Decrease speed\n");
        printf("6. Change altitude\n");
        printf("7. Exit\n");

        // prompt for user input
        int option;
        printf("\nEnter option: ");
        scanf("%d", &option);

        // handle user input
        switch(option) {
            case 1:
                // toggle power on/off
                if (power == 0) {
                    power = 1;
                    printf("Power on\n");
                } else {
                    power = 0;
                    printf("Power off\n");
                }
                break;
            case 2:
                // take off
                if (power == 1 && isFlying == false) {
                    takeOff();
                } else {
                    printf("Error: Drone is already flying or power is off\n");
                }
                break;
            case 3:
                // land
                if (power == 1 && isFlying == true) {
                    land();
                } else {
                    printf("Error: Drone is not flying or power is off\n");
                }
                break;
            case 4:
                // increase speed
                if (power == 1 && isFlying == true) {
                    increaseSpeed(1);
                } else {
                    printf("Error: Drone is not flying or power is off\n");
                }
                break;
            case 5:
                // decrease speed
                if (power == 1 && isFlying == true) {
                    decreaseSpeed(1);
                } else {
                    printf("Error: Drone is not flying or power is off\n");
                }
                break;
            case 6:
                // change altitude
                if (power == 1 && isFlying == true) {
                    int newAltitude;
                    printf("Enter new altitude: ");
                    scanf("%d", &newAltitude);
                    changeAltitude(newAltitude);
                } else {
                    printf("Error: Drone is not flying or power is off\n");
                }
                break;
            case 7:
                // exit program
                return 0;
            default:
                printf("Error: Invalid option\n");
        }
    }
}

void takeOff() {
    isFlying = true;
    speed = 10;
    altitude = 50;
    printf("Drone is now flying\n");
}

void land() {
    isFlying = false;
    speed = 0;
    altitude = 0;
    printf("Drone has landed\n");
}

void increaseSpeed(int increment) {
    speed += increment;
    printf("Speed increased to %d km/h\n", speed);
}

void decreaseSpeed(int decrement) {
    speed -= decrement;
    printf("Speed decreased to %d km/h\n", speed);
}

void changeAltitude(int newAltitude) {
    altitude = newAltitude;
    printf("Altitude changed to %d meters\n", altitude);
}