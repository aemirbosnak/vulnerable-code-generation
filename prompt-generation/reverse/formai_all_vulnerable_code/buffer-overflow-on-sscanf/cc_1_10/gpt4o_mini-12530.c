//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define BUFFER_SIZE 100

typedef struct {
    char name[20];
    int brightness; // 0-100
    int is_on; // 1 for on, 0 for off
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void initialize_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        snprintf(lights[i].name, sizeof(lights[i].name), "Light %d", i + 1);
        lights[i].brightness = 0;
        lights[i].is_on = 0;
    }
    light_count = MAX_LIGHTS;
}

void display_lights() {
    printf("\n--- Current Light Status ---\n");
    for (int i = 0; i < light_count; i++) {
        printf("%s - Status: %s, Brightness: %d%%\n",
               lights[i].name,
               lights[i].is_on ? "ON" : "OFF",
               lights[i].brightness);
    }
    printf("-----------------------------\n");
}

void turn_on_light(int index) {
    if (index >= 0 && index < light_count) {
        lights[index].is_on = 1;
        lights[index].brightness = 50; // Set default brightness
        printf("%s is now ON with brightness %d%%\n", lights[index].name, lights[index].brightness);
    } else {
        printf("Invalid light index!\n");
    }
}

void turn_off_light(int index) {
    if (index >= 0 && index < light_count) {
        lights[index].is_on = 0;
        lights[index].brightness = 0;
        printf("%s is now OFF.\n", lights[index].name);
    } else {
        printf("Invalid light index!\n");
    }
}

void adjust_brightness(int index, int brightness) {
    if (index >= 0 && index < light_count) {
        if (lights[index].is_on) {
            if (brightness >= 0 && brightness <= 100) {
                lights[index].brightness = brightness;
                printf("Adjusted %s brightness to %d%%\n", lights[index].name, lights[index].brightness);
            } else {
                printf("Brightness value should be between 0 and 100!\n");
            }
        } else {
            printf("%s is OFF. Turn it ON first to adjust brightness.\n", lights[index].name);
        }
    } else {
        printf("Invalid light index!\n");
    }
}

void command_prompt() {
    char command[BUFFER_SIZE];
    int light_index = -1;
    int brightness = -1;

    while (1) {
        printf("\nEnter command (ON, OFF, SET <index> <brightness>, SHOW, QUIT): ");
        fgets(command, BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strcmp(command, "QUIT") == 0) {
            break;
        } 
        else if (strcmp(command, "SHOW") == 0) {
            display_lights();
        } 
        else if (sscanf(command, "ON %d", &light_index) == 1) {
            turn_on_light(light_index - 1); // User sees lights indexed from 1
        } 
        else if (sscanf(command, "OFF %d", &light_index) == 1) {
            turn_off_light(light_index - 1);
        } 
        else if (sscanf(command, "SET %d %d", &light_index, &brightness) == 2) {
            adjust_brightness(light_index - 1, brightness);
        } 
        else {
            printf("Invalid command! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    initialize_lights();
    command_prompt();
    printf("Exiting Smart Home Light Control System... Farewell!\n");
    return 0;
}