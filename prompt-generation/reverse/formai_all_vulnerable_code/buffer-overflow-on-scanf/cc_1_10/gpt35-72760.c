//FormAI DATASET v1.0 Category: Smart home automation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define surrealistic devices
#define FISHBOWL 0
#define CLOCK 1
#define LIGHTS 2
#define THERMOSTAT 3
#define DOOR 4

// Define global variables for device statuses
int fishbowl_status = 0;
int clock_status = 0;
int lights_status = 0;
int thermostat_status = 0;
int door_status = 0;

// Define functions to toggle devices
void toggle_fishbowl() {
    fishbowl_status = !fishbowl_status;
    printf("The fishbowl is now %s.\n", fishbowl_status ? "ON" : "OFF");
}

void toggle_clock() {
    clock_status = !clock_status;
    printf("The clock is now %s.\n", clock_status ? "ON" : "OFF");
}

void toggle_lights() {
    lights_status = !lights_status;
    printf("The lights are now %s.\n", lights_status ? "ON" : "OFF");
}

void toggle_thermostat() {
    thermostat_status = !thermostat_status;
    printf("The thermostat is now %s.\n", thermostat_status ? "ON" : "OFF");
}

void toggle_door() {
    door_status = !door_status;
    printf("The door is now %s.\n", door_status ? "OPEN" : "CLOSED");
}

int main() {
    printf("Welcome to Smart Home Automation in Surrealist Style!\n");
    printf("Use the following commands to control your home devices.\n\n");
    printf("Toggle the Fishbowl: fb_toggle\n");
    printf("Toggle the Clock: cl_toggle\n");
    printf("Toggle the Lights: lt_toggle\n");
    printf("Toggle the Thermostat: th_toggle\n");
    printf("Toggle the Door: do_toggle\n\n");

    char input[10];
    while (true) {
        printf("Enter command: ");
        scanf("%s", input);

        if (strcmp(input, "fb_toggle") == 0) {
            toggle_fishbowl();
        } else if (strcmp(input, "cl_toggle") == 0) {
            toggle_clock();
        } else if (strcmp(input, "lt_toggle") == 0) {
            toggle_lights();
        } else if (strcmp(input, "th_toggle") == 0) {
            toggle_thermostat();
        } else if (strcmp(input, "do_toggle") == 0) {
            toggle_door();
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}