//FormAI DATASET v1.0 Category: Smart home automation ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>

int living_room_lights = 0;
int kitchen_lights = 0;
bool living_room_tv = false;
bool bedroom_ac = false;

void toggle_living_room_lights() {
    if (living_room_lights == 0) {
        printf("Turning on living room lights...\n");
        living_room_lights = 1;
    }
    else {
        printf("Turning off living room lights...\n");
        living_room_lights = 0;
    }
}

void toggle_kitchen_lights() {
    if (kitchen_lights == 0) {
        printf("Turning on kitchen lights...\n");
        kitchen_lights = 1;
    }
    else {
        printf("Turning off kitchen lights...\n");
        kitchen_lights = 0;
    }
}

void toggle_living_room_tv() {
    if (living_room_tv == false) {
        printf("Turning on living room TV...\n");
        living_room_tv = true;
    }
    else {
        printf("Turning off living room TV...\n");
        living_room_tv = false;
    }
}

void toggle_bedroom_ac() {
    if (bedroom_ac == false) {
        printf("Turning on bedroom AC...\n");
        bedroom_ac = true;
    }
    else {
        printf("Turning off bedroom AC...\n");
        bedroom_ac = false;
    }
}

int main() {
    int option;
    do {
        printf("\n---------------\n");
        printf("1. Toggle living room lights\n");
        printf("2. Toggle kitchen lights\n");
        printf("3. Toggle living room TV\n");
        printf("4. Toggle bedroom AC\n");
        printf("5. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                toggle_living_room_lights();
                break;
            case 2:
                toggle_kitchen_lights();
                break;
            case 3:
                toggle_living_room_tv();
                break;
            case 4:
                toggle_bedroom_ac();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while(option != 5);

    return 0;
}