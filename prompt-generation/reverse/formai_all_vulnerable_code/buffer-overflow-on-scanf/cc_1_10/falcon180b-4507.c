//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_COMMANDS 20

typedef struct {
    char name[50];
    bool on;
} Device;

typedef struct {
    char name[50];
    char command[100];
    bool enabled;
} Command;

int num_devices = 0;
Device devices[MAX_DEVICES];
int num_commands = 0;
Command commands[MAX_COMMANDS];

void add_device(char* name) {
    strcpy(devices[num_devices].name, name);
    devices[num_devices].on = false;
    num_devices++;
}

void toggle_device(int index) {
    devices[index].on =!devices[index].on;
}

void add_command(char* name, char* command, bool enabled) {
    strcpy(commands[num_commands].name, name);
    strcpy(commands[num_commands].command, command);
    commands[num_commands].enabled = enabled;
    num_commands++;
}

void execute_command(int index) {
    if (commands[index].enabled) {
        system(commands[index].command);
    }
}

void main() {
    add_device("Living Room Light");
    add_device("Bedroom Light");
    add_command("Turn on Living Room Light", "echo 1 > /dev/ttyACM0", true);
    add_command("Turn off Living Room Light", "echo 0 > /dev/ttyACM0", true);
    add_command("Turn on Bedroom Light", "echo 1 > /dev/ttyACM1", true);
    add_command("Turn off Bedroom Light", "echo 0 > /dev/ttyACM1", true);

    while (true) {
        printf("Select a device:\n");
        for (int i = 0; i < num_devices; i++) {
            printf("%d. %s\n", i+1, devices[i].name);
        }
        int choice;
        scanf("%d", &choice);
        toggle_device(choice-1);

        printf("Select a command:\n");
        for (int i = 0; i < num_commands; i++) {
            printf("%d. %s\n", i+1, commands[i].name);
        }
        scanf("%d", &choice);
        execute_command(choice-1);
    }
}