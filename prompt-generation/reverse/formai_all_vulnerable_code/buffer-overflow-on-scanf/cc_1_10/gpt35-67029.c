//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>

#define MAX_LIGHTS 10

int main()
{
    int n_lights;
    int light_states[MAX_LIGHTS];
    int i;

    // get number of lights
    printf("How many lights are in your home? (up to %d)\n", MAX_LIGHTS);
    scanf("%d", &n_lights);

    // init all lights to OFF
    for (i = 0; i < n_lights; i++) {
        light_states[i] = 0;
    }

    while (1) {
        // display the current state of the lights
        printf("%d lights: ", n_lights);
        for (i = 0; i < n_lights; i++) {
            if (light_states[i] == 0) {
                printf("OFF ");
            } else {
                printf("ON ");
            }
        }
        printf("\n");

        // get user input
        printf("Which light would you like to toggle? (1-%d): ", n_lights);
        int light_idx;
        scanf("%d", &light_idx);

        // check for quit command
        if (light_idx == 0)
            break;

        // toggle light state
        if (light_idx <= n_lights && light_idx > 0) {
            light_states[light_idx-1] = !light_states[light_idx-1];
            printf("Toggled light %d\n", light_idx);
        } else {
            printf("Invalid light number\n");
        }
    }

    return 0;
}