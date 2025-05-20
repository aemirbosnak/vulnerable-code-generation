//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct drone {
    char name[20];
    int altitude;
    int speed;
    int batteryLevel;
};

void displayDrone(struct drone d) {
    printf("Name: %s\n", d.name);
    printf("Altitude: %d M\n", d.altitude);
    printf("Speed: %d KM/H\n", d.speed);
    printf("Battery Level: %d %%\n", d.batteryLevel);
}

void increaseAltitude(struct drone *d) {
    if ((*d).altitude < 1000) {
        (*d).altitude += 100;
        printf("Altitude increased to %d M.\n", (*d).altitude);
    } else {
        printf("Maximum altitude reached!\n");
    }
}

void decreaseAltitude(struct drone *d) {
    if ((*d).altitude > 0) {
        (*d).altitude -= 100;
        printf("Altitude decreased to %d M.\n", (*d).altitude);
    } else {
        printf("Minimum altitude reached!\n");
    }
}

void increaseSpeed(struct drone *d) {
    if ((*d).speed < 500) {
        (*d).speed += 50;
        printf("Speed increased to %d KM/H.\n", (*d).speed);
    } else {
        printf("Maximum speed reached!\n");
    }
}

void decreaseSpeed(struct drone *d) {
    if ((*d).speed > 0) {
        (*d).speed -= 50;
        printf("Speed decreased to %d KM/H.\n", (*d).speed);
    } else {
        printf("Minimum speed reached!\n");
    }
}

void rechargeBattery(struct drone *d) {
    (*d).batteryLevel = 100;
    printf("Battery level recharged to 100%%\n");
}

void checkBattery(struct drone d) {
    printf("Battery level: %d%%\n", d.batteryLevel);
}

int main () {
    struct drone myDrone;
    strcpy(myDrone.name, "C-Drone");
    myDrone.altitude = 0;
    myDrone.speed = 0;
    myDrone.batteryLevel = 100;

    printf("Welcome to C-Drone Remote Control\n");
    printf("--------------------------------\n");

    while (1) {
        displayDrone(myDrone);

        printf("\nCommands:\n");
        printf("1. Increase Altitude (I)\n");
        printf("2. Decrease Altitude (D)\n");
        printf("3. Increase Speed (F)\n");
        printf("4. Decrease Speed (S)\n");
        printf("5. Recharge Battery (R)\n");
        printf("6. Check Battery (B)\n");
        printf("7. Quit (Q)\n");

        char option;
        printf("\nSelect an option: ");
        scanf(" %c", &option);

        switch(option) {
            case 'I':
            case 'i':
                increaseAltitude(&myDrone);
                break;
            case 'D':
            case 'd':
                decreaseAltitude(&myDrone);
                break;
            case 'F':
            case 'f':
                increaseSpeed(&myDrone);
                break;
            case 'S':
            case 's':
                decreaseSpeed(&myDrone);
                break;
            case 'R':
            case 'r':
                rechargeBattery(&myDrone);
                break;
            case 'B':
            case 'b':
                checkBattery(myDrone);
                break;
            case 'Q':
            case 'q':
                printf("Thank you for using C-Drone Remote Control.\n");
                return 0;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    }

    return 0;
}