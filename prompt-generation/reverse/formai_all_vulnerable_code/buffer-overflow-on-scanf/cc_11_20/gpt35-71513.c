//FormAI DATASET v1.0 Category: Smart home light control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_LIGHTS 5

int main() {
    bool lights[NUM_LIGHTS] = {false}; // initialize all lights to off
    srand(time(NULL)); // seed random number generator

    printf("Welcome to the Smart Home Light Control System!\n");
    printf("You have %d lights in your house.\n", NUM_LIGHTS);

    while (true) { // loop infinitely until user exits
        printf("\nWhat would you like to do?\n");
        printf("1. Turn a light on\n");
        printf("2. Turn a light off\n");
        printf("3. Check the status of a light\n");
        printf("4. Randomly turn a light on/off\n");
        printf("5. Exit\n");
        printf("> ");

        int choice;
        scanf("%d", &choice); // get user choice

        switch (choice) {
            case 1: { // turn a light on
                printf("\nWhich light? ");
                int light;
                scanf("%d", &light);
                if (light < 1 || light > NUM_LIGHTS) {
                    printf("Invalid choice!\n");
                    break;
                }
                lights[light-1] = true; // turn light on
                printf("Light %d turned on.\n", light);
                break;
            }
            case 2: { // turn a light off
                printf("\nWhich light? ");
                int light;
                scanf("%d", &light);
                if (light < 1 || light > NUM_LIGHTS) {
                    printf("Invalid choice!\n");
                    break;
                }
                lights[light-1] = false; // turn light off
                printf("Light %d turned off.\n", light);
                break;
            }
            case 3: { // check light status
                printf("\nWhich light? ");
                int light;
                scanf("%d", &light);
                if (light < 1 || light > NUM_LIGHTS) {
                    printf("Invalid choice!\n");
                    break;
                }
                if (lights[light-1]) {
                    printf("Light %d is on.\n", light);
                } else {
                    printf("Light %d is off.\n", light);
                }
                break;
            }
            case 4: { // random light control
                int light = rand() % NUM_LIGHTS + 1; // choose a random light
                if (rand() % 2 == 0) {
                    lights[light-1] = true; // turn light on
                    printf("Light %d turned on.\n", light);
                } else {
                    lights[light-1] = false; // turn light off
                    printf("Light %d turned off.\n", light);
                }
                break;
            }
            case 5: { // exit program
                printf("\nGoodbye!\n");
                return 0;
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    }
}