//FormAI DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 10

struct Light {
    int id;
    int brightness;
    int state; // 0 - off, 1 - on
};

int main() {
    int i, n;

    // Initialization
    struct Light *lights = (struct Light *) malloc(MAX_LIGHTS * sizeof(struct Light));
    if (lights == NULL) {
        printf("Error: insufficient memory\n");
        return 1;
    }

    printf("How many lights in the house? ");
    scanf("%d", &n);

    if (n > MAX_LIGHTS) {
        printf("Warning: maximum number of lights exceeded. Reducing to %d.\n", MAX_LIGHTS);
        n = MAX_LIGHTS;
    }

    for (i = 0; i < n; i++) {
        lights[i].id = i + 1;
        lights[i].brightness = 50; // Default value
        lights[i].state = 0; // Lights are off by default
    }

    // Main loop
    while (1) {
        int choice, light_id;

        printf("\n--- SMART HOME LIGHT CONTROL ---\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. Adjust brightness of a light\n");
        printf("4. Show status of all lights\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID of the light to turn on: ");
                scanf("%d", &light_id);

                if (light_id < 1 || light_id > n) {
                    printf("Error: invalid light ID.\n");
                }
                else if (lights[light_id - 1].state == 1) {
                    printf("Light %d is already on.\n", light_id);
                }
                else {
                    lights[light_id - 1].state = 1;
                    printf("Light %d turned on.\n", light_id);
                }

                break;

            case 2:
                printf("Enter ID of the light to turn off: ");
                scanf("%d", &light_id);

                if (light_id < 1 || light_id > n) {
                    printf("Error: invalid light ID.\n");
                }
                else if (lights[light_id - 1].state == 0) {
                    printf("Light %d is already off.\n", light_id);
                }
                else {
                    lights[light_id - 1].state = 0;
                    printf("Light %d turned off.\n", light_id);
                }

                break;

            case 3:
                printf("Enter ID of the light to adjust brightness: ");
                scanf("%d", &light_id);

                if (light_id < 1 || light_id > n) {
                    printf("Error: invalid light ID.\n");
                }
                else {
                    int brightness;
                    printf("Enter new brightness (0-100): ");
                    scanf("%d", &brightness);

                    if (brightness < 0 || brightness > 100) {
                        printf("Error: invalid brightness level.\n");
                    }
                    else {
                        lights[light_id - 1].brightness = brightness;
                        printf("Brightness of light %d adjusted to %d.\n", light_id, brightness);
                    }
                }

                break;

            case 4:
                printf("--- LIGHT STATUS ---\n");

                for (i = 0; i < n; i++) {
                    printf("Light %d: %s, brightness %d\n", lights[i].id,
                           lights[i].state == 1 ? "on" : "off", lights[i].brightness);
                }

                break;

            case 5:
                printf("Goodbye.\n");
                free(lights);
                return 0;

            default:
                printf("Error: invalid choice.\n");
        }
    }
}