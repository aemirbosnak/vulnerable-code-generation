//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

// Smart home automation functions
void turnOnLights(int room) {
    printf("Turning on lights in room %d\n", room);
}

void turnOffLights(int room) {
    printf("Turning off lights in room %d\n", room);
}

void setTemperature(int room, int temperature) {
    printf("Setting temperature in room %d to %d degrees\n", room, temperature);
}

void lockDoor(int room) {
    printf("Locking door in room %d\n", room);
}

void unlockDoor(int room) {
    printf("Unlocking door in room %d\n", room);
}

// Main program
int main() {
    int choice;
    char command[50];

    while(1) {
        printf("Enter command (turnOnLights roomNumber turnOffLights setTemperature roomNumber temperature lockDoor roomNumber unlockDoor): ");
        scanf("%s", command);

        // Extract room number from command
        int room = 0;
        for(int i=0; i<strlen(command); i++) {
            if(isdigit(command[i])) {
                room = room*10 + (command[i] - '0');
            }
        }

        // Execute command
        switch(command[0]) {
            case 't':
            case 'T':
                turnOnLights(room);
                break;
            case 'f':
            case 'F':
                turnOffLights(room);
                break;
            case's':
            case 'S':
                setTemperature(room, 0);
                break;
            case 'l':
            case 'L':
                lockDoor(room);
                break;
            case 'u':
            case 'U':
                unlockDoor(room);
                break;
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}