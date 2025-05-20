//FormAI DATASET v1.0 Category: Smart home light control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// constants
#define NUM_LIGHTS 5
#define MAX_BRIGHTNESS 100

// function prototypes
void print_menu();
void print_lights(int lights[]);
void turn_on_lights(int lights[]);
void turn_off_lights(int lights[]);
void set_brightness(int lights[]);

// main function
int main() {
    int lights[NUM_LIGHTS] = {0};
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                turn_on_lights(lights);
                break;
            case 2:
                turn_off_lights(lights);
                break;
            case 3:
                set_brightness(lights);
                break;
            case 4:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while(true);

    return 0;
}

// function definitions

// prints the menu options
void print_menu() {
    printf("\nSmart Home Light Control\n");
    printf("------------------------\n");
    printf("1. Turn On Lights\n");
    printf("2. Turn Off Lights\n");
    printf("3. Set Brightness\n");
    printf("4. Exit\n\n");
}

// prints the status of each light
void print_lights(int lights[]) {
    printf("\nLight Status:\n");
    for(int i = 0; i < NUM_LIGHTS; i++) {
        printf("Light %d: %d%%\n", i+1, lights[i]);
    }
}

// turns on all the lights to max brightness
void turn_on_lights(int lights[]) {
    for(int i = 0; i < NUM_LIGHTS; i++) {
        lights[i] = MAX_BRIGHTNESS;
    }
    printf("\nTurning on all lights.\n");
    print_lights(lights);
}

// turns off all the lights
void turn_off_lights(int lights[]) {
    for(int i = 0; i < NUM_LIGHTS; i++) {
        lights[i] = 0;
    }
    printf("\nTurning off all lights.\n");
    print_lights(lights);
}

// sets the brightness of each light
void set_brightness(int lights[]) {
    int light_num, brightness;

    printf("\nSet Brightness\n");
    printf("--------------\n");
    print_lights(lights);

    do {
        printf("Select a light to change brightness: ");
        scanf("%d", &light_num);
    } while(light_num < 1 || light_num > NUM_LIGHTS);

    do {
        printf("Enter brightness level (0-100): ");
        scanf("%d", &brightness);
    } while(brightness < 0 || brightness > 100);

    lights[light_num-1] = brightness;

    printf("\nSetting brightness for Light %d to %d%%.\n", light_num, brightness);
    print_lights(lights);
}