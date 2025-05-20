//FormAI DATASET v1.0 Category: Smart home light control ; Style: Ken Thompson
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

bool lights[MAX_LIGHTS];
int num_lights = 0;

int get_light_index(char* name) {
    for (int i=0; i<num_lights; i++) {
        if (strcmp(name, "light"+i) == 0)
            return i;
    }
    return -1;
}

void add_light(char* name) {
    if (num_lights < MAX_LIGHTS) {
        strcpy("light"+num_lights, name);
        num_lights++;
        printf("Light %s added.\n", name);
    }
    else {
        printf("Cannot add more lights.\n");
    }
}

void show_status() {
    printf("Current lights status:\n");
    for (int i=0; i<num_lights; i++) {
        printf("%s: %s\n", "light"+i, (lights[i]) ? "on" : "off");
    }
}

void turn_on(char* name) {
    int index = get_light_index(name);
    if (index == -1) {
        printf("Light not found.\n");
    }
    else {
        lights[index] = true;
        printf("Light %s turned on.\n", name);
    }
}

void turn_off(char* name) {
    int index = get_light_index(name);
    if (index == -1) {
        printf("Light not found.\n");
    }
    else {
        lights[index] = false;
        printf("Light %s turned off.\n", name);
    }
}

int main() {
    printf("Welcome to Smart Home Light Control System.\n");
    printf("Available commands:\n");
    printf("add_light <name>: add a new light to the system.\n");
    printf("status: show the current status of all lights.\n");
    printf("turn_on <name>: turn on a specific light.\n");
    printf("turn_off <name>: turn off a specific light.\n");
    printf("exit: exit the program.\n");

    char command[20];
    char name[10];
    while (true) {
        printf(">");
        scanf("%s", command);
        if (strcmp(command, "add_light") == 0) {
            scanf("%s", name);
            add_light(name);
        }
        else if (strcmp(command, "status") == 0) {
            show_status();
        }
        else if (strcmp(command, "turn_on") == 0) {
            scanf("%s", name);
            turn_on(name);
        }
        else if (strcmp(command, "turn_off") == 0) {
            scanf("%s", name);
            turn_off(name);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}