//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int state; // 0 for off, 1 for on
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void initialize_lights() {
    for (int i = 0; i < light_count; ++i) {
        lights[i].state = 0; // all lights off initially
    }
}

void add_light(const char* light_name) {
    if (light_count < MAX_LIGHTS) {
        strncpy(lights[light_count].name, light_name, MAX_NAME_LEN - 1);
        lights[light_count].name[MAX_NAME_LEN - 1] = '\0'; // ensure null-termination
        lights[light_count].state = 0; // light is off
        light_count++;
        printf("Added light: %s\n", light_name);
    } else {
        printf("Maximum number of lights reached! Cannot add more.\n");
    }
}

void toggle_light(const char* light_name) {
    for (int i = 0; i < light_count; ++i) {
        if (strcmp(lights[i].name, light_name) == 0) {
            lights[i].state = !lights[i].state; // toggle state
            printf("%s is now %s\n", lights[i].name, lights[i].state ? "ON" : "OFF");
            return;
        }
    }
    printf("Light named %s not found!\n", light_name);
}

void list_lights() {
    if (light_count == 0) {
        printf("No lights added.\n");
        return;
    }
    printf("Current Lights:\n");
    for (int i = 0; i < light_count; ++i) {
        printf("%s: %s\n", lights[i].name, lights[i].state ? "ON" : "OFF");
    }
}

void turn_on_light(const char* light_name) {
    for (int i = 0; i < light_count; ++i) {
        if (strcmp(lights[i].name, light_name) == 0) {
            if (lights[i].state == 0) {
                lights[i].state = 1; // turn on light
                printf("%s is now ON\n", lights[i].name);
            } else {
                printf("%s is already ON\n", lights[i].name);
            }
            return;
        }
    }
    printf("Light named %s not found!\n", light_name);
}

void turn_off_light(const char* light_name) {
    for (int i = 0; i < light_count; ++i) {
        if (strcmp(lights[i].name, light_name) == 0) {
            if (lights[i].state == 1) {
                lights[i].state = 0; // turn off light
                printf("%s is now OFF\n", lights[i].name);
            } else {
                printf("%s is already OFF\n", lights[i].name);
            }
            return;
        }
    }
    printf("Light named %s not found!\n", light_name);
}

void wait_for_command() {
    char command[256];
    char light_name[MAX_NAME_LEN];
    
    while (1) {
        printf("\nEnter command (add, toggle, on, off, list, quit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "quit") == 0) {
            printf("Exiting Smart Light Control...\n");
            break;
        } else if (strcmp(command, "list") == 0) {
            list_lights();
        } else if (sscanf(command, "add %s", light_name) == 1) {
            add_light(light_name);
        } else if (sscanf(command, "toggle %s", light_name) == 1) {
            toggle_light(light_name);
        } else if (sscanf(command, "on %s", light_name) == 1) {
            turn_on_light(light_name);
        } else if (sscanf(command, "off %s", light_name) == 1) {
            turn_off_light(light_name);
        } else {
            printf("Unknown command: %s\n", command);
        }
        usleep(500000); // sleep for 500 ms to simulate processing delay
    }
}

int main() {
    initialize_lights();
    wait_for_command();
    return 0;
}