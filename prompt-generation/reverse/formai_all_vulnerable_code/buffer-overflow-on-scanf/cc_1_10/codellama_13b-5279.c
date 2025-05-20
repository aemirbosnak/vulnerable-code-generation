//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#define NUM_LIGHTS 5

typedef struct {
    int id;
    char name[20];
    bool is_on;
    int brightness;
    int temperature;
} Light;

void turn_light_on(Light *light) {
    light->is_on = true;
}

void turn_light_off(Light *light) {
    light->is_on = false;
}

void set_light_brightness(Light *light, int brightness) {
    light->brightness = brightness;
}

void set_light_temperature(Light *light, int temperature) {
    light->temperature = temperature;
}

void print_light_state(Light *light) {
    printf("Light %d (%s): %s, brightness: %d, temperature: %d\n", light->id, light->name, light->is_on ? "on" : "off", light->brightness, light->temperature);
}

int main() {
    Light lights[NUM_LIGHTS] = {
        {1, "Kitchen", false, 100, 2700},
        {2, "Living Room", false, 100, 3000},
        {3, "Bedroom", false, 100, 2500},
        {4, "Hallway", false, 100, 2200},
        {5, "Bathroom", false, 100, 3200}
    };

    for (int i = 0; i < NUM_LIGHTS; i++) {
        print_light_state(&lights[i]);
    }

    while (true) {
        int choice;
        printf("Enter a command: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                turn_light_on(&lights[0]);
                break;
            case 2:
                turn_light_off(&lights[0]);
                break;
            case 3:
                set_light_brightness(&lights[0], 50);
                break;
            case 4:
                set_light_temperature(&lights[0], 3000);
                break;
            case 5:
                turn_light_on(&lights[1]);
                break;
            case 6:
                turn_light_off(&lights[1]);
                break;
            case 7:
                set_light_brightness(&lights[1], 75);
                break;
            case 8:
                set_light_temperature(&lights[1], 2700);
                break;
            case 9:
                turn_light_on(&lights[2]);
                break;
            case 10:
                turn_light_off(&lights[2]);
                break;
            case 11:
                set_light_brightness(&lights[2], 100);
                break;
            case 12:
                set_light_temperature(&lights[2], 2500);
                break;
            case 13:
                turn_light_on(&lights[3]);
                break;
            case 14:
                turn_light_off(&lights[3]);
                break;
            case 15:
                set_light_brightness(&lights[3], 75);
                break;
            case 16:
                set_light_temperature(&lights[3], 2200);
                break;
            case 17:
                turn_light_on(&lights[4]);
                break;
            case 18:
                turn_light_off(&lights[4]);
                break;
            case 19:
                set_light_brightness(&lights[4], 100);
                break;
            case 20:
                set_light_temperature(&lights[4], 3200);
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        for (int i = 0; i < NUM_LIGHTS; i++) {
            print_light_state(&lights[i]);
        }
    }

    return 0;
}