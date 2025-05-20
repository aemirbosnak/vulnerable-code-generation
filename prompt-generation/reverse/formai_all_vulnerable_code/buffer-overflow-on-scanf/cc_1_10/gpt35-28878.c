//FormAI DATASET v1.0 Category: Smart home light control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10

bool lights[MAX_LIGHTS] = {false}; //Array to store the state of the lights, initially all lights are off

void print_status() {
    printf("\nSTATUS:\n");
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("Light %d: ", i+1);
        if (lights[i]) {
            printf("ON\n");
        } else {
            printf("OFF\n");
        }
    }
}

int main() {
    printf("Welcome to Smart Home Light Control!\n");

    int choice = 0;
    do {
        printf("\nWhat do you want to do?\n");
        printf("1. Turn a light ON\n");
        printf("2. Turn a light OFF\n");
        printf("3. Toggle a light\n");
        printf("4. Turn all lights ON\n");
        printf("5. Turn all lights OFF\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int light_num = 0;
        switch (choice) {
            case 1:
                printf("\nEnter the number of the light you want to turn ON: ");
                scanf("%d", &light_num);
                if (light_num < 1 || light_num > MAX_LIGHTS) {
                    printf("Invalid light number! Try again.\n");
                } else {
                    lights[light_num-1] = true;
                    printf("Light %d turned ON.\n", light_num);
                }
                break;
            case 2:
                printf("\nEnter the number of the light you want to turn OFF: ");
                scanf("%d", &light_num);
                if (light_num < 1 || light_num > MAX_LIGHTS) {
                    printf("Invalid light number! Try again.\n");
                } else {
                    lights[light_num-1] = false;
                    printf("Light %d turned OFF.\n", light_num);
                }
                break;
            case 3:
                printf("\nEnter the number of the light you want to toggle: ");
                scanf("%d", &light_num);
                if (light_num < 1 || light_num > MAX_LIGHTS) {
                    printf("Invalid light number! Try again.\n");
                } else {
                    lights[light_num-1] = !lights[light_num-1];
                    printf("Light %d toggled.\n", light_num);
                }
                break;
            case 4:
                for (int i = 0; i < MAX_LIGHTS; i++) {
                    lights[i] = true;
                }
                printf("All lights turned ON.\n");
                break;
            case 5:
                for (int i = 0; i < MAX_LIGHTS; i++) {
                    lights[i] = false;
                }
                printf("All lights turned OFF.\n");
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
        print_status();
    } while (choice != 6);

    return 0;
}