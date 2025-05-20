//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[50];
    bool state;
} Light;

void update_lights(Light *lights) {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d: ", i + 1);
        if (lights[i].state) {
            printf("on\n");
        } else {
            printf("off\n");
        }
    }
}

int main() {
    Light lights[MAX_LIGHTS];
    memset(lights, 0, sizeof(lights));

    while (true) {
        char command[100];
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "turn on") == 0) {
            int index;
            printf("Enter light index: ");
            scanf("%d", &index);
            if (index >= 0 && index < MAX_LIGHTS) {
                lights[index].state = true;
                printf("Light %d turned on\n", index + 1);
            } else {
                printf("Invalid light index\n");
            }
        } else if (strcmp(command, "turn off") == 0) {
            int index;
            printf("Enter light index: ");
            scanf("%d", &index);
            if (index >= 0 && index < MAX_LIGHTS) {
                lights[index].state = false;
                printf("Light %d turned off\n", index + 1);
            } else {
                printf("Invalid light index\n");
            }
        } else if (strcmp(command, "update") == 0) {
            update_lights(lights);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}