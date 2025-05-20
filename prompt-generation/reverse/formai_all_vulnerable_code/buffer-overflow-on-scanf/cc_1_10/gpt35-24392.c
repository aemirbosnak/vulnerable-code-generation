//FormAI DATASET v1.0 Category: Smart home light control ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to turn on/off the smart light
void smart_light_control(int state) {
    if (state == 0) {
        printf("Smart Light is Off\n");
    } else {
        printf("Smart Light is On\n");
    }
}

// Function to change the brightness level of the smart light
void change_brightness(int level) {
    if (level < 0) {
        level = 0;
    } else if (level > 100) {
        level = 100;
    }
    
    printf("Smart Light brightness level is %d\n", level);
}

int main() {
    int state = 0;
    int brightness = 50;
    
    // Initial state of the smart light
    smart_light_control(state);
    change_brightness(brightness);
    
    // Wait for user input and control the smart light accordingly
    while (1) {
        char command[100];
        printf("Enter command: ");
        scanf("%s", command);
        
        if (strcmp(command, "on") == 0) {
            state = 1;
            smart_light_control(state);
        } else if (strcmp(command, "off") == 0) {
            state = 0;
            smart_light_control(state);
        } else if (strcmp(command, "brighter") == 0) {
            brightness += 10;
            change_brightness(brightness);
        } else if (strcmp(command, "dimmer") == 0) {
            brightness -= 10;
            change_brightness(brightness);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Light Control System\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }
    
    return 0;
}