//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the structure for a Smart Light
typedef struct {
    char name[50];
    int brightness; // Range: 0 - 100
    int state; // 0: OFF, 1: ON
} SmartLight;

// Function prototypes
void displayMenu();
void addLight(SmartLight *lights, int *count);
void toggleLight(SmartLight *lights, int count);
void setBrightness(SmartLight *lights, int count);
void displayLights(SmartLight *lights, int count);

int main() {
    SmartLight lights[10]; // Array to hold up to 10 lights
    int lightCount = 0; // Current number of smart lights
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addLight(lights, &lightCount);
                break;
            case 2:
                toggleLight(lights, lightCount);
                break;
            case 3:
                setBrightness(lights, lightCount);
                break;
            case 4:
                displayLights(lights, lightCount);
                break;
            case 5:
                printf("Exiting the Smart Home Light Control System.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n==== Smart Home Light Control ====\n");
    printf("1. Add a new light\n");
    printf("2. Toggle light state\n");
    printf("3. Set light brightness\n");
    printf("4. Display all lights\n");
    printf("5. Exit\n");
}

void addLight(SmartLight *lights, int *count) {
    if (*count >= 10) {
        printf("Cannot add more lights. Maximum limit reached.\n");
        return;
    }

    SmartLight newLight;
    printf("Enter the name of the light: ");
    scanf("%s", newLight.name);
    newLight.brightness = 100; // Default brightness
    newLight.state = 1; // Default state ON

    lights[*count] = newLight;
    (*count)++;
    printf("Light '%s' added successfully.\n", newLight.name);
}

void toggleLight(SmartLight *lights, int count) {
    char name[50];
    printf("Enter the name of the light to toggle: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].state = !lights[i].state; // Toggle state
            printf("Light '%s' is now %s.\n", lights[i].name, lights[i].state ? "ON" : "OFF");
            return;
        }
    }
    
    printf("Light '%s' not found.\n", name);
}

void setBrightness(SmartLight *lights, int count) {
    char name[50];
    int brightness;
    printf("Enter the name of the light to set brightness: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            printf("Enter brightness level (0-100): ");
            scanf("%d", &brightness);
            
            if (brightness < 0 || brightness > 100) {
                printf("Invalid brightness level. It should be between 0 and 100.\n");
                return;
            }
            
            lights[i].brightness = brightness;
            printf("Brightness of light '%s' set to %d%%.\n", lights[i].name, lights[i].brightness);
            return;
        }
    }

    printf("Light '%s' not found.\n", name);
}

void displayLights(SmartLight *lights, int count) {
    if (count == 0) {
        printf("No lights available.\n");
        return;
    }
    
    printf("\n===== List of Smart Lights =====\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, State: %s, Brightness: %d%%\n", 
               lights[i].name, 
               lights[i].state ? "ON" : "OFF", 
               lights[i].brightness);
    }
}