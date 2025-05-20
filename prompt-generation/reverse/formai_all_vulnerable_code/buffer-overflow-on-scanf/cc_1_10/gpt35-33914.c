//FormAI DATASET v1.0 Category: Smart home automation ; Style: ephemeral
#include <stdio.h>
#include <stdbool.h>

// These functions simulate the functionality of different home devices
void turn_on_light() {
    printf("The light is on\n");
}

void turn_off_light() {
    printf("The light is off\n");
}

void turn_on_fan() {
    printf("The fan is on\n");
}

void turn_off_fan() {
    printf("The fan is off\n");
}

void unlock_door() {
    printf("The door is unlocked\n");
}

void lock_door() {
    printf("The door is locked\n");
}

int main() {
    // These variables store the current state of different devices
    bool is_light_on = false;
    bool is_fan_on = false;
    bool is_door_locked = true;

    // The user can input different commands to control the devices
    char command[20];
    while (true) {
        printf("Enter command: ");
        scanf("%s", command);

        // Check the input and execute the corresponding function
        if (strcmp(command, "on") == 0 && !is_light_on) {
            turn_on_light();
            is_light_on = true;
        } else if (strcmp(command, "off") == 0 && is_light_on) {
            turn_off_light();
            is_light_on = false;
        } else if (strcmp(command, "fan_on") == 0 && !is_fan_on) {
            turn_on_fan();
            is_fan_on = true;
        } else if (strcmp(command, "fan_off") == 0 && is_fan_on) {
            turn_off_fan();
            is_fan_on = false;
        } else if (strcmp(command, "unlock") == 0 && is_door_locked) {
            unlock_door();
            is_door_locked = false;
        } else if (strcmp(command, "lock") == 0 && !is_door_locked) {
            lock_door();
            is_door_locked = true;
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}