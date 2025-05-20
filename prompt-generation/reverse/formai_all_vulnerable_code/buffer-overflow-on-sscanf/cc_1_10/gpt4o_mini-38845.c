//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[30];
    int brightness; // value from 0 to 100
    int is_on;      // 0 for off, 1 for on
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

// Function to initialize lights
void initialize_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        strcpy(lights[i].name, "Light ");
        lights[i].name[6] = 'A' + i; // Name lights from A to J
        lights[i].brightness = 100; // Default brightness
        lights[i].is_on = 1; // Default state is on
        light_count++;
    }
}

// Function to display the status of all lights
void display_status() {
    printf("\n=== Smart Home Light Control Status ===\n");
    for (int i = 0; i < light_count; i++) {
        printf("Name: %s, State: %s, Brightness: %d\n", 
               lights[i].name, 
               lights[i].is_on ? "On" : "Off", 
               lights[i].brightness);
    }
    printf("========================================\n");
}

// Function to turn on a specific light
void turn_on_light(int index) {
    if (index >= 0 && index < light_count) {
        lights[index].is_on = 1;
        printf("%s is turned ON.\n", lights[index].name);
    } else {
        printf("Invalid light index.\n");
    }
}

// Function to turn off a specific light
void turn_off_light(int index) {
    if (index >= 0 && index < light_count) {
        lights[index].is_on = 0;
        printf("%s is turned OFF.\n", lights[index].name);
    } else {
        printf("Invalid light index.\n");
    }
}

// Function to set brightness
void set_brightness(int index, int brightness) {
    if (index >= 0 && index < light_count) {
        if (brightness >= 0 && brightness <= 100) {
            lights[index].brightness = brightness;
            printf("%s brightness set to %d%%.\n", lights[index].name, brightness);
        } else {
            printf("Brightness value must be between 0 and 100.\n");
        }
    } else {
        printf("Invalid light index.\n");
    }
}

// Function to handle user commands
void handle_command(char *command) {
    char action[10];
    int index, brightness;

    if (sscanf(command, "%s %d", action, &index) == 2) {
        if (strcmp(action, "turn_on") == 0) {
            turn_on_light(index);
        } else if (strcmp(action, "turn_off") == 0) {
            turn_off_light(index);
        }
    } else if (sscanf(command, "set_brightness %d %d", &index, &brightness) == 2) {
        set_brightness(index, brightness);
    } else if (strcmp(command, "status") == 0) {
        display_status();
    } else {
        printf("Invalid command. Available commands: turn_on <index>, turn_off <index>, set_brightness <index> <brightness>, status\n");
    }
}

int main() {
    char command[50];

    initialize_lights();
    
    while (1) {
        printf("Enter command (or 'exit' to quit): ");
        fgets(command, sizeof(command), stdin);
        
        // Remove newline character from command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Light Control. Goodbye!\n");
            break;
        }

        handle_command(command);
    }

    return 0;
}