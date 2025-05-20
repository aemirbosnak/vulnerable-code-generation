//FormAI DATASET v1.0 Category: Smart home light control ; Style: authentic
// Smart home light control example program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LIGHTS 10

struct Light {
    int id;
    bool state;
    int brightness;
};

void printLights(struct Light* lights, int numLights) {
    printf("--------------------------------------------------\n");
    printf("| Light ID | State | Brightness |\n");
    printf("--------------------------------------------------\n");
    for(int i=0; i<numLights; i++) {
        printf("| %-8d| %-6s| %-11d|\n", lights[i].id, (lights[i].state) ? "ON" : "OFF", lights[i].brightness);
    }
    printf("--------------------------------------------------\n");
}

void turnOnLight(struct Light* light) {
    light->state = true;
    printf("Light %d is turned ON\n", light->id);
}

void turnOffLight(struct Light* light) {
    light->state = false;
    printf("Light %d is turned OFF\n", light->id);
}

void setBrightness(struct Light* light, int brightness) {
    light->brightness = brightness;
    printf("Brightness of Light %d is set to %d\n", light->id, brightness);
}

int main() {
    // Initialize lights
    struct Light lights[MAX_LIGHTS];
    for(int i=0; i<MAX_LIGHTS; i++) {
        lights[i].id = i+1;
        lights[i].state = false;
        lights[i].brightness = 0;
    }

    // User interaction loop
    char command[20];
    while(1) {
        printf("Enter command: ");
        scanf("%s", command);
        if(strcmp(command, "quit") == 0) {
            break;
        }
        else if(strcmp(command, "list") == 0) {
            printLights(lights, MAX_LIGHTS);
        }
        else if(strcmp(command, "on") == 0) {
            int lightId;
            printf("Enter Light ID: ");
            scanf("%d", &lightId);
            if(lightId < 1 || lightId > MAX_LIGHTS) {
                printf("Invalid Light ID. Please try again\n");
            }
            else {
                turnOnLight(&lights[lightId-1]);
            }
        }
        else if(strcmp(command, "off") == 0) {
            int lightId;
            printf("Enter Light ID: ");
            scanf("%d", &lightId);
            if(lightId < 1 || lightId > MAX_LIGHTS) {
                printf("Invalid Light ID. Please try again\n");
            }
            else {
                turnOffLight(&lights[lightId-1]);
            }
        }
        else if(strcmp(command, "brightness") == 0) {
            int lightId, brightness;
            printf("Enter Light ID: ");
            scanf("%d", &lightId);
            if(lightId < 1 || lightId > MAX_LIGHTS) {
                printf("Invalid Light ID. Please try again\n");
            }
            else {
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                if(brightness < 0 || brightness > 100) {
                    printf("Invalid brightness level. Please try again\n");
                }
                else {
                    setBrightness(&lights[lightId-1], brightness);
                }
            }
        }
        else {
            printf("Invalid command. Please try again\n");
        }
    }

    return 0;
}