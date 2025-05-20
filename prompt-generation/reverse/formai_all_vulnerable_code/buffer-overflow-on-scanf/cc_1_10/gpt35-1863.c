//FormAI DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <string.h>

/* Define the maximum number of lights that can be controlled */
#define MAX_LIGHTS 10

/* Define the maximum length of light names */
#define MAX_NAME_LENGTH 20

/* Define a structure to hold information about each light */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int brightness;
    int on;
} Light;

/* Define an array of lights */
Light lights[MAX_LIGHTS];

/* Define a function to initialize the lights */
void initLights() {
    int i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        /* Set the name of the light */
        snprintf(lights[i].name, MAX_NAME_LENGTH, "Light %d", i+1);
        /* Set the brightness to 0 */
        lights[i].brightness = 0;
        /* Set the light to off */
        lights[i].on = 0;
    }
}

/* Define a function to print the menu of options */
void printMenu() {
    printf("1. Turn a light on\n");
    printf("2. Turn a light off\n");
    printf("3. Set the brightness of a light\n");
    printf("4. Print the status of all lights\n");
    printf("5. Exit\n");
}

/* Define a function to turn a light on */
void turnOn(int index) {
    if (index < 0 || index >= MAX_LIGHTS) {
        printf("Invalid light index\n");
        return;
    }
    lights[index].on = 1;
    printf("Turned %s on\n", lights[index].name);
}

/* Define a function to turn a light off */
void turnOff(int index) {
    if (index < 0 || index >= MAX_LIGHTS) {
        printf("Invalid light index\n");
        return;
    }
    lights[index].on = 0;
    printf("Turned %s off\n", lights[index].name);
}

/* Define a function to set the brightness of a light */
void setBrightness(int index, int brightness) {
    if (index < 0 || index >= MAX_LIGHTS) {
        printf("Invalid light index\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Invalid brightness value\n");
        return;
    }
    lights[index].brightness = brightness;
    printf("Set the brightness of %s to %d\n", lights[index].name, brightness);
}

/* Define a function to print the status of all lights */
void printStatus() {
    int i;
    for (i = 0; i < MAX_LIGHTS; i++) {
        printf("%s is ", lights[i].name);
        if (lights[i].on) {
            printf("on");
            if (lights[i].brightness > 0) {
                printf(" at %d%% brightness", lights[i].brightness);
            }
        } else {
            printf("off");
        }
        printf("\n");
    }
}

int main() {
    int option, index, brightness;
    initLights();
    do {
        printMenu();
        printf("Enter an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter the index of the light to turn on: ");
                scanf("%d", &index);
                turnOn(index);
                break;
            case 2:
                printf("Enter the index of the light to turn off: ");
                scanf("%d", &index);
                turnOff(index);
                break;
            case 3:
                printf("Enter the index of the light to set the brightness of: ");
                scanf("%d", &index);
                printf("Enter the brightness value (0-100): ");
                scanf("%d", &brightness);
                setBrightness(index, brightness);
                break;
            case 4:
                printStatus();
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (option != 5);
    return 0;
}