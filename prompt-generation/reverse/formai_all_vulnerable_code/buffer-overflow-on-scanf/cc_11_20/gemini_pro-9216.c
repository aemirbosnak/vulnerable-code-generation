//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define the cyberpunk-themed smart home devices
typedef struct {
    char *name;
    int status; // 0 = off, 1 = on
} device;

device devices[] = {
    { "Neon Display", 0 },
    { "Biometric Scanner", 0 },
    { "Holographic Projector", 0 },
    { "Cybernetic Arm", 0 },
    { "Hacker Terminal", 0 },
};

// Define the commands that can be used to control the devices
typedef enum {
    ON,
    OFF,
    TOGGLE,
    LIST
} command;

// Define the main function
int main() {
    // Get the command from the user
    command c;
    printf("Enter a command (on, off, toggle, list): ");
    char buf[16];
    scanf("%s", buf);
    if (strcmp(buf, "on") == 0) {
        c = ON;
    } else if (strcmp(buf, "off") == 0) {
        c = OFF;
    } else if (strcmp(buf, "toggle") == 0) {
        c = TOGGLE;
    } else if (strcmp(buf, "list") == 0) {
        c = LIST;
    } else {
        printf("Invalid command\n");
        return EXIT_FAILURE;
    }

    // Execute the command
    switch (c) {
        case ON:
            printf("Turning on all devices\n");
            for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
                devices[i].status = 1;
            }
            break;
        case OFF:
            printf("Turning off all devices\n");
            for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
                devices[i].status = 0;
            }
            break;
        case TOGGLE:
            printf("Toggling all devices\n");
            for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
                devices[i].status = !devices[i].status;
            }
            break;
        case LIST:
            printf("Listing all devices\n");
            for (int i = 0; i < sizeof(devices) / sizeof(device); i++) {
                printf("%s: %s\n", devices[i].name, devices[i].status ? "on" : "off");
            }
            break;
    }

    return EXIT_SUCCESS;
}