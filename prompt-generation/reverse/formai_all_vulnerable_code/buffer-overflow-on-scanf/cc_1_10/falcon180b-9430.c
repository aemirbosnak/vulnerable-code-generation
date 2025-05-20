//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10
#define ON 1
#define OFF 0

// initialize all lights to off
bool lights[MAX_LIGHTS] = {OFF};

void toggle_light(int light_num) {
    if (light_num >= 0 && light_num < MAX_LIGHTS) {
        lights[light_num] =!lights[light_num];
        printf("Light %d toggled.\n", light_num);
    } else {
        printf("Invalid light number.\n");
    }
}

void turn_on_all_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i] = ON;
    }
    printf("All lights turned on.\n");
}

void turn_off_all_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i] = OFF;
    }
    printf("All lights turned off.\n");
}

int main() {
    int choice;
    do {
        printf("Smart Home Light Control\n");
        printf("1. Toggle light\n");
        printf("2. Turn on all lights\n");
        printf("3. Turn off all lights\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light number: ");
                scanf("%d", &choice);
                toggle_light(choice);
                break;
            case 2:
                turn_on_all_lights();
                break;
            case 3:
                turn_off_all_lights();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}