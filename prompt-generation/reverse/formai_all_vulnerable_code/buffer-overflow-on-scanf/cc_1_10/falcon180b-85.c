//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

struct light {
    char name[20];
    int state;
};

void set_light_state(struct light* light, int state) {
    light->state = state;
}

int get_light_state(struct light* light) {
    return light->state;
}

void turn_on_light(struct light* light) {
    set_light_state(light, 1);
    printf("Turning on %s\n", light->name);
}

void turn_off_light(struct light* light) {
    set_light_state(light, 0);
    printf("Turning off %s\n", light->name);
}

int main() {
    struct light lights[MAX_LIGHTS];
    int num_lights = 0;

    while (num_lights < MAX_LIGHTS) {
        printf("Enter name of light (or 'done' to finish): ");
        scanf("%s", lights[num_lights].name);

        if (strcmp(lights[num_lights].name, "done") == 0) {
            break;
        }

        num_lights++;
    }

    while (1) {
        printf("Enter command (turn_on, turn_off, or exit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "turn_on") == 0) {
            printf("Enter name of light to turn on: ");
            scanf("%s", command);

            int i;
            for (i = 0; i < num_lights; i++) {
                if (strcmp(command, lights[i].name) == 0) {
                    turn_on_light(&lights[i]);
                    break;
                }
            }

            if (i == num_lights) {
                printf("Light not found\n");
            }
        }
        else if (strcmp(command, "turn_off") == 0) {
            printf("Enter name of light to turn off: ");
            scanf("%s", command);

            int i;
            for (i = 0; i < num_lights; i++) {
                if (strcmp(command, lights[i].name) == 0) {
                    turn_off_light(&lights[i]);
                    break;
                }
            }

            if (i == num_lights) {
                printf("Light not found\n");
            }
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    return 0;
}