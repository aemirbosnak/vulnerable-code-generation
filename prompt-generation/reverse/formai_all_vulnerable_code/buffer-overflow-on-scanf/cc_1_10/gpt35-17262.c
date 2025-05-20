//FormAI DATASET v1.0 Category: Smart home light control ; Style: Cryptic
#include <stdio.h>
#include <stdbool.h>

/* Setting necessary constants */
const int MAX_LIGHTS = 10;
const int MAX_BRIGHTNESS = 100;
const int MIN_BRIGHTNESS = 0;

/* Defining a light structure */
struct Light {
    bool isOn;
    int brightness;
};

/* Function to toggle a light on/off */
void toggleLight(struct Light *light) {
    if (light->isOn) {
        light->isOn = false;
        light->brightness = 0;
    } else {
        light->isOn = true;
        light->brightness = 50;
    }
}

/* Function to increase brightness of a light */
void increaseBrightness(struct Light *light) {
    if (light->isOn && light->brightness < MAX_BRIGHTNESS) {
        light->brightness += 10;
    }
}

/* Function to decrease brightness of a light */
void decreaseBrightness(struct Light *light) {
    if (light->isOn && light->brightness > MIN_BRIGHTNESS) {
        light->brightness -= 10;
    }
}

int main() {
    /* Initializing an array of 10 lights */
    struct Light lights[MAX_LIGHTS];

    /* Setting all lights to initial state */
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].isOn = false;
        lights[i].brightness = 0;
    }

    /* Turning on first light at 50% brightness */
    lights[0].isOn = true;
    lights[0].brightness = 50;

    /* Accepting user input for controlling lights */
    char choice = ' ';
    int lightNum = 0;
    while (true) {
        printf("Enter command (T to toggle, I to increase brightness, D to decrease brightness, Q to quit):\n");
        scanf(" %c", &choice);
        if (choice == 'Q') {
            break;
        }
        printf("Enter light number (1 to 10):\n");
        scanf(" %d", &lightNum);
        if (lightNum < 1 || lightNum > MAX_LIGHTS) {
            printf("Invalid light number\n");
            continue;
        }
        lightNum--;

        /* Calling appropriate function based on user choice */
        switch(choice) {
            case 'T':
                toggleLight(&lights[lightNum]);
                break;
            case 'I':
                increaseBrightness(&lights[lightNum]);
                break;
            case 'D':
                decreaseBrightness(&lights[lightNum]);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        /* Printing the state of all lights */
        for (int i = 0; i < MAX_LIGHTS; i++) {
            printf("Light %2d: %s, %3d%% brightness\n", i+1, lights[i].isOn ? "On" : "Off", lights[i].brightness);
        }
    }

    return 0;
}