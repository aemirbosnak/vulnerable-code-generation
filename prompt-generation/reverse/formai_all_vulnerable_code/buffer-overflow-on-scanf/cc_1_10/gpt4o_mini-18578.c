//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LIGHTS 10
#define COMMAND_LENGTH 100

typedef struct {
    char name[30];
    int brightness; // 0-100 percentage
    int status; // 1 for ON, 0 for OFF
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void initialize_lights() {
    for(int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].brightness = 100; // Default brightness
        lights[i].status = 0; // All lights are OFF
    }
}

void display_lights() {
    printf("Current Smart Lights Status:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%s - Status: %s, Brightness: %d%%\n", 
               lights[i].name,
               lights[i].status ? "ON" : "OFF",
               lights[i].brightness);
    }
}

void toggle_light(int index) {
    lights[index].status = !lights[index].status;
    printf("%s is now %s.\n", lights[index].name, lights[index].status ? "ON" : "OFF");
}

void set_brightness(int index, int brightness) {
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness value! Please enter a value between 0 and 100.\n");
        return;
    }
    lights[index].brightness = brightness;
    printf("%s brightness set to %d%%.\n", lights[index].name, brightness);
}

void execute_command(char *command) {
    char action[20], light_name[30];
    int brightness;

    sscanf(command, "%s %s %d", action, light_name, &brightness);
    
    for (int i = 0; i < light_count; i++) {
        if (strcmp(lights[i].name, light_name) == 0) {
            if (strcmp(action, "toggle") == 0) {
                toggle_light(i);
            } else if (strcmp(action, "brightness") == 0) {
                set_brightness(i, brightness);
            } else {
                printf("Unknown command: %s\n", action);
            }
            return;
        }
    }
    printf("Light not found: %s\n", light_name);
}

void command_prompt() {
    char command[COMMAND_LENGTH];
    
    while (1) {
        printf("Enter a command (e.g., toggle Light 1 or brightness Light 1 75): ");
        fgets(command, COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Home Light Control.\n");
            break;
        }
        
        execute_command(command);
        display_lights();
    }
}

int main() {
    int num_lights;
    
    printf("Welcome to the Smart Home Light Control System!\n");
    printf("How many lights would you like to manage (max %d)? ", MAX_LIGHTS);
    scanf("%d", &num_lights);
    getchar(); // Consume newline character left in buffer
    
    if (num_lights < 1 || num_lights > MAX_LIGHTS) {
        printf("Invalid number of lights! Setting to maximum of %d.\n", MAX_LIGHTS);
        num_lights = MAX_LIGHTS;
    }
    
    light_count = num_lights;
    initialize_lights();
    
    display_lights();
    command_prompt();
    
    printf("Thank you for using the Smart Home Light Control System!\n");
    return 0;
}