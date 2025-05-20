//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights in the smart home
#define MAX_LIGHTS 10

// Struct to hold light state and brightness
typedef struct {
    char name[30];
    int is_on; // 1 for on, 0 for off
    int brightness; // 0 to 100
} SmartLight;

// Function prototypes
void initializeLights(SmartLight lights[], int size);
void printLightStatus(SmartLight lights[], int size);
void toggleLight(SmartLight *light);
void setBrightness(SmartLight *light, int brightness);
int getLightIndex(SmartLight lights[], int size, const char *name);

int main() {
    SmartLight lights[MAX_LIGHTS];
    int numberOfLights, choice, brightness;
    char lightName[30];

    // Initialize the system with lights
    printf("Enter the number of lights in your smart home (max %d): ", MAX_LIGHTS);
    scanf("%d", &numberOfLights);
    
    if (numberOfLights > MAX_LIGHTS || numberOfLights <= 0) {
        printf("Invalid number of lights.\n");
        return 1;
    }

    initializeLights(lights, numberOfLights);

    // Main menu loop
    do {
        printf("\nSmart Home Light Control:\n");
        printf("1. Print light status\n");
        printf("2. Toggle light\n");
        printf("3. Set brightness\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printLightStatus(lights, numberOfLights);
                break;
            case 2:
                printf("Enter the name of the light to toggle: ");
                scanf("%s", lightName);
                int lightIndex = getLightIndex(lights, numberOfLights, lightName);
                if (lightIndex != -1) {
                    toggleLight(&lights[lightIndex]);
                } else {
                    printf("Light not found.\n");
                }
                break;
            case 3:
                printf("Enter the name of the light to set brightness: ");
                scanf("%s", lightName);
                lightIndex = getLightIndex(lights, numberOfLights, lightName);
                if (lightIndex != -1) {
                    printf("Enter brightness (0 to 100): ");
                    scanf("%d", &brightness);
                    if (brightness >= 0 && brightness <= 100) {
                        setBrightness(&lights[lightIndex], brightness);
                    } else {
                        printf("Invalid brightness value. Must be between 0 and 100.\n");
                    }
                } else {
                    printf("Light not found.\n");
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize the lights
void initializeLights(SmartLight lights[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter the name for light %d: ", i + 1);
        scanf("%s", lights[i].name);
        lights[i].is_on = 0; // All lights are initially off
        lights[i].brightness = 0; // Default brightness is 0
    }
}

// Function to print the status of all lights
void printLightStatus(SmartLight lights[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Light: %s, Status: %s, Brightness: %d%%\n", 
                lights[i].name, 
                lights[i].is_on ? "On" : "Off", 
                lights[i].brightness);
    }
}

// Function to toggle the state of a light
void toggleLight(SmartLight *light) {
    light->is_on = !light->is_on;
    if (light->is_on) {
        printf("The light %s is turned ON.\n", light->name);
    } else {
        printf("The light %s is turned OFF.\n", light->name);
    }
}

// Function to set the brightness of a light
void setBrightness(SmartLight *light, int brightness) {
    light->brightness = brightness;
    printf("Set the brightness of light %s to %d%%.\n", light->name, light->brightness);
}

// Function to find the index of a light by name
int getLightIndex(SmartLight lights[], int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}