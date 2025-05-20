//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct Light {
    char name[30];
    int intensity; // 0 to 100
    int status; // 0 for off, 1 for on
} Light;

void initializeLights(Light lights[]) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        sprintf(lights[i].name, "Light_%d", i + 1);
        lights[i].intensity = 100; // start at full brightness
        lights[i].status = 0; // off by default
    }
}

void turnOnLight(Light *light) {
    light->status = 1;
    printf("%s awakens from slumber, glowing bright!\n", light->name);
}

void turnOffLight(Light *light) {
    light->status = 0;
    printf("%s fades into the night, silent and cool.\n", light->name);
}

void setLightIntensity(Light *light, int intensity) {
    if (intensity < 0 || intensity > 100) {
        printf("Intensify but fair Juliet, invalid input!\n");
    } else {
        light->intensity = intensity;
        printf("%s now shines with a brilliance of %d percent!\n", light->name, intensity);
    }
}

void listLights(Light lights[]) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s: %s, Intensity: %d\n", 
               lights[i].name, 
               lights[i].status ? "On" : "Off", 
               lights[i].intensity);
    }
}

int main() {
    Light lights[MAX_LIGHTS];
    initializeLights(lights);
    
    char command[50];
    int lightIndex, intensity;

    printf("Enter commands for thy lighting destiny! (type 'exit' to leave)\n");
    
    while (1) {
        printf("Command: ");
        gets(command);
        
        // Check for exit command
        if (strcmp(command, "exit") == 0) {
            printf("Alas, dear lights! Farewell!\n");
            break;
        }
        
        // Process the command
        if (sscanf(command, "turn on %d", &lightIndex) == 1) {
            if (lightIndex > 0 && lightIndex <= MAX_LIGHTS) {
                turnOnLight(&lights[lightIndex - 1]);
            } else {
                printf("O tragic error! Such a light cannot be found!\n");
            }
        } else if (sscanf(command, "turn off %d", &lightIndex) == 1) {
            if (lightIndex > 0 && lightIndex <= MAX_LIGHTS) {
                turnOffLight(&lights[lightIndex - 1]);
            } else {
                printf("O tragic error! Such a light cannot be found!\n");
            }
        } else if (sscanf(command, "set intensity %d %d", &lightIndex, &intensity) == 2) {
            if (lightIndex > 0 && lightIndex <= MAX_LIGHTS) {
                setLightIntensity(&lights[lightIndex - 1], intensity);
            } else {
                printf("O tragic error! Such a light cannot be found!\n");
            }
        } else if (strcmp(command, "list") == 0) {
            listLights(lights);
        } else {
            printf("Pray, what dost thou mean?\n");
        }
    }

    return 0;
}