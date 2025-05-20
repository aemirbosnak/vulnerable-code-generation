//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int batteryLevel = 100;
int altitude = 0;
int speed = 0;
int direction = 0;

void displayMenu() {
    printf("**** Welcome to C Drone Remote Control ****\n");
    printf("1. Take off\n");
    printf("2. Land\n");
    printf("3. Increase altitude\n");
    printf("4. Decrease altitude\n");
    printf("5. Increase speed\n");
    printf("6. Decrease speed\n");
    printf("7. Turn left\n");
    printf("8. Turn right\n");
    printf("9. Check battery level\n");
    printf("10. Quit\n");
    printf("Enter your choice: ");
}

void takeOff() {
    if(altitude == 0) {
        printf("Drone took off successfully\n");
        altitude = 1;
    }
    else {
        printf("Drone is already in the air\n");
    }
}

void land() {
    if(altitude == 0) {
        printf("Drone is already on the ground\n");
    }
    else {
        printf("Drone landed successfully\n");
        altitude = 0;
    }
}

void increaseAltitude() {
    if(altitude == 0) {
        printf("Drone is on the ground. Cannot increase altitude\n");
    }
    else if(altitude == 10) {
        printf("Maximum altitude reached\n");
    }
    else {
        altitude++;
        printf("Altitude increased to %d\n", altitude);
    }
}

void decreaseAltitude() {
    if(altitude == 0) {
        printf("Drone is on the ground\n");
    }
    else if(altitude == 1) {
        printf("Drone is at minimum altitude\n");
    }
    else {
        altitude--;
        printf("Altitude decreased to %d\n", altitude);
    }
}

void increaseSpeed() {
    if(altitude == 0) {
        printf("Drone is on the ground. Cannot increase speed\n");
    }
    else if(speed == 10) {
        printf("Maximum speed reached\n");
    }
    else {
        speed++;
        printf("Speed increased to %d\n", speed);
    }
}

void decreaseSpeed() {
    if(altitude == 0) {
        printf("Drone is on the ground\n");
    }
    else if(speed == 0) {
        printf("Drone is already at minimum speed\n");
    }
    else {
        speed--;
        printf("Speed decreased to %d\n", speed);
    }
}

void turnLeft() {
    if(altitude == 0) {
        printf("Drone is on the ground. Cannot turn left\n");
    }
    else {
        direction--;
        if(direction < 0) {
            direction = 3;
        }
        printf("Turning left. New direction: %d\n", direction);
    }
}

void turnRight() {
    if(altitude == 0) {
        printf("Drone is on the ground. Cannot turn right\n");
    }
    else {
        direction++;
        if(direction > 3) {
            direction = 0;
        }
        printf("Turning right. New direction: %d\n", direction);
    }
}

void checkBatteryLevel() {
    printf("Battery level: %d%%\n", batteryLevel);
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                takeOff();
                break;
            case 2:
                land();
                break;
            case 3:
                increaseAltitude();
                break;
            case 4:
                decreaseAltitude();
                break;
            case 5:
                increaseSpeed();
                break;
            case 6:
                decreaseSpeed();
                break;
            case 7:
                turnLeft();
                break;
            case 8:
                turnRight();
                break;
            case 9:
                checkBatteryLevel();
                break;
            case 10:
                printf("Exiting C Drone Remote Control...\n");
                break;
            default:
                printf("Invalid choice. Please try again\n");
        }

        if(choice != 10) {
            printf("\n");
        }

    } while(choice != 10);

    return 0;
}