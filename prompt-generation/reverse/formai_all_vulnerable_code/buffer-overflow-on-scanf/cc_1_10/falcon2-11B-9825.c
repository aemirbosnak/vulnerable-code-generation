//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void light_on(char* room) {
    char command[100];
    sprintf(command, "echo \"%s on\" | /home/pi/bin/python3 /home/pi/lights.py", room);
    system(command);
}

void light_off(char* room) {
    char command[100];
    sprintf(command, "echo \"%s off\" | /home/pi/bin/python3 /home/pi/lights.py", room);
    system(command);
}

void thermostat_on(char* room) {
    char command[100];
    sprintf(command, "echo \"%s on\" | /home/pi/bin/python3 /home/pi/thermostat.py", room);
    system(command);
}

void thermostat_off(char* room) {
    char command[100];
    sprintf(command, "echo \"%s off\" | /home/pi/bin/python3 /home/pi/thermostat.py", room);
    system(command);
}

void lock_door(char* room) {
    char command[100];
    sprintf(command, "echo \"%s locked\" | /home/pi/bin/python3 /home/pi/lock.py", room);
    system(command);
}

void unlock_door(char* room) {
    char command[100];
    sprintf(command, "echo \"%s unlocked\" | /home/pi/bin/python3 /home/pi/lock.py", room);
    system(command);
}

int main(void) {
    char room[100];
    printf("Enter the room name: ");
    scanf("%s", room);

    printf("Enter the command (on/off): ");
    char command[100];
    scanf("%s", command);

    if (strcmp(command, "on") == 0) {
        if (strcmp(room, "living_room") == 0) {
            light_on(room);
            thermostat_on(room);
            lock_door(room);
        } else if (strcmp(room, "bedroom") == 0) {
            light_on(room);
            thermostat_off(room);
            lock_door(room);
        } else if (strcmp(room, "kitchen") == 0) {
            light_off(room);
            thermostat_on(room);
            lock_door(room);
        } else {
            printf("Invalid room name.\n");
        }
    } else if (strcmp(command, "off") == 0) {
        if (strcmp(room, "living_room") == 0) {
            light_off(room);
            thermostat_off(room);
            lock_door(room);
        } else if (strcmp(room, "bedroom") == 0) {
            light_off(room);
            thermostat_off(room);
            lock_door(room);
        } else if (strcmp(room, "kitchen") == 0) {
            light_on(room);
            thermostat_off(room);
            lock_door(room);
        } else {
            printf("Invalid room name.\n");
        }
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}