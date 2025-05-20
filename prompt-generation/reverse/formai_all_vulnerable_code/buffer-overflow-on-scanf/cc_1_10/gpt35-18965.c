//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define NUM_LIGHTS 5

typedef enum { OFF, ON } LightState;

typedef struct {
    int id;
    LightState state;
} Light;

void toggleLight(Light *l) {
    if (l->state == OFF) {
        l->state = ON;
    } else {
        l->state = OFF;
    }
}

void printLightState(Light l) {
    printf("Light %d is %s\n", l.id, l.state ? "ON" : "OFF");
}

void printAllLightStates(Light *lights, int n) {
    for (int i = 0; i < n; i++) {
        printLightState(lights[i]);
    }
}

int main() {
    Light lights[NUM_LIGHTS] = {
        {1, OFF},
        {2, OFF},
        {3, OFF},
        {4, OFF},
        {5, ON},
    };

    printf("Welcome to Smart Home Light Control\n\n");
    printAllLightStates(lights, NUM_LIGHTS);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Toggle a light\n");
        printf("2. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id;
            printf("Enter light ID: ");
            scanf("%d", &id);

            if (id < 1 || id > NUM_LIGHTS) {
                printf("Invalid light ID\n");
            } else {
                toggleLight(&lights[id-1]);
            }
            printAllLightStates(lights, NUM_LIGHTS);
        }
    } while (choice != 2);

    printf("Goodbye!\n");

    return EXIT_SUCCESS;
}