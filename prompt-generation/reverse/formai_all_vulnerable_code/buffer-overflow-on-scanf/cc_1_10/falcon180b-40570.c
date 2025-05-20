//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int status;
    int brightness;
} Light;

Light lights[MAX_LIGHTS];

void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].status = 0;
        lights[i].brightness = 0;
        strcpy(lights[i].name, "Light");
        lights[i].name[4] += i + 1;
    }
}

int main() {
    init_lights();
    char command[50];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "on") == 0) {
            int light_index;
            printf("Enter light index: ");
            scanf("%d", &light_index);
            if (light_index >= 1 && light_index <= MAX_LIGHTS) {
                lights[light_index - 1].status = 1;
                printf("Light %s turned on.\n", lights[light_index - 1].name);
            } else {
                printf("Invalid light index.\n");
            }
        } else if (strcmp(command, "off") == 0) {
            int light_index;
            printf("Enter light index: ");
            scanf("%d", &light_index);
            if (light_index >= 1 && light_index <= MAX_LIGHTS) {
                lights[light_index - 1].status = 0;
                printf("Light %s turned off.\n", lights[light_index - 1].name);
            } else {
                printf("Invalid light index.\n");
            }
        } else if (strcmp(command, "brightness") == 0) {
            int light_index;
            int brightness;
            printf("Enter light index: ");
            scanf("%d", &light_index);
            if (light_index >= 1 && light_index <= MAX_LIGHTS) {
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                if (brightness >= 0 && brightness <= 100) {
                    lights[light_index - 1].brightness = brightness;
                    printf("Light %s brightness set to %d.\n", lights[light_index - 1].name, brightness);
                } else {
                    printf("Invalid brightness.\n");
                }
            } else {
                printf("Invalid light index.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}