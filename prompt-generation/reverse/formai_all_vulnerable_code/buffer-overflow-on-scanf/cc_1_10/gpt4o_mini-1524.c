//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lights
#define MAX_LIGHTS 10

// Light structure to represent each light in the smart home
typedef struct {
    char name[50];
    int is_on;
    int brightness; // from 0 (off) to 100 (full brightness)
} Light;

// Smart home system structure
typedef struct {
    Light lights[MAX_LIGHTS];
    int count; // To keep track of the number of lights
} SmartHome;

// Function prototypes
void initializeLights(SmartHome *home);
void displayMenu();
void addLight(SmartHome *home);
void toggleLight(SmartHome *home);
void changeBrightness(SmartHome *home);
void displayLightStatus(SmartHome *home);
void exitProgram();

int main() {
    SmartHome home;
    initializeLights(&home);
    int choice;

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addLight(&home);
                break;
            case 2:
                toggleLight(&home);
                break;
            case 3:
                changeBrightness(&home);
                break;
            case 4:
                displayLightStatus(&home);
                break;
            case 5:
                exitProgram();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void initializeLights(SmartHome *home) {
    home->count = 0; // Initialize the count of lights to zero
}

void displayMenu() {
    printf("\nSmart Home Light Control System\n");
    printf("1. Add Light\n");
    printf("2. Toggle Light\n");
    printf("3. Change Light Brightness\n");
    printf("4. Display Light Status\n");
    printf("5. Exit\n");
}

void addLight(SmartHome *home) {
    if (home->count >= MAX_LIGHTS) {
        printf("Cannot add more lights. Maximum limit reached.\n");
        return;
    }
    
    Light newLight;
    printf("Enter the name of the light: ");
    scanf("%s", newLight.name);
    newLight.is_on = 0; // Initially off
    newLight.brightness = 0; // Initially off

    home->lights[home->count++] = newLight; // Add the light to the home
    printf("Light '%s' added successfully.\n", newLight.name);
}

void toggleLight(SmartHome *home) {
    char name[50];
    printf("Enter the name of the light to toggle: ");
    scanf("%s", name);

    for (int i = 0; i < home->count; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].is_on = !home->lights[i].is_on; // Toggle the state
            printf("Light '%s' is now %s.\n", 
                   home->lights[i].name, 
                   home->lights[i].is_on ? "ON" : "OFF");
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void changeBrightness(SmartHome *home) {
    char name[50];
    int brightness;
    printf("Enter the name of the light to change brightness: ");
    scanf("%s", name);
    
    printf("Enter brightness level (0-100): ");
    scanf("%d", &brightness);
    
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }

    for (int i = 0; i < home->count; i++) {
        if (strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].brightness = brightness;
            printf("Brightness of light '%s' set to %d.\n", 
                   home->lights[i].name, brightness);
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void displayLightStatus(SmartHome *home) {
    printf("\nLight Status:\n");
    for (int i = 0; i < home->count; i++) {
        printf("Name: %s, Status: %s, Brightness: %d%%\n", 
               home->lights[i].name, 
               home->lights[i].is_on ? "ON" : "OFF", 
               home->lights[i].brightness);
    }
}

void exitProgram() {
    printf("Exiting the Smart Home Light Control System.\n");
}