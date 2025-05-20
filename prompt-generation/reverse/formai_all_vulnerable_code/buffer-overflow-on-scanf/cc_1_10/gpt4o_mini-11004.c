//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char name[30];
    int is_on; // 1 for ON, 0 for OFF
} Light;

typedef struct {
    Light lights[MAX_LIGHTS];
    int total_lights;
} SmartHomeSystem;

// Function declarations
void initializeSystem(SmartHomeSystem *system);
void addLight(SmartHomeSystem *system, const char *name);
void removeLight(SmartHomeSystem *system, int id);
void toggleLight(SmartHomeSystem *system, int id);
void displayLights(const SmartHomeSystem *system);
void displayMenu();

int main() {
    SmartHomeSystem myHome;
    initializeSystem(&myHome);
    
    int choice;
    char light_name[30];
    int light_id;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", light_name);
                addLight(&myHome, light_name);
                break;
            case 2:
                printf("Enter light ID to remove: ");
                scanf("%d", &light_id);
                removeLight(&myHome, light_id);
                break;
            case 3:
                printf("Enter light ID to toggle: ");
                scanf("%d", &light_id);
                toggleLight(&myHome, light_id);
                break;
            case 4:
                displayLights(&myHome);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}

void initializeSystem(SmartHomeSystem *system) {
    system->total_lights = 0;
}

void addLight(SmartHomeSystem *system, const char *name) {
    if (system->total_lights < MAX_LIGHTS) {
        Light new_light;
        new_light.id = system->total_lights;
        strncpy(new_light.name, name, sizeof(new_light.name) - 1);
        new_light.name[sizeof(new_light.name) - 1] = '\0'; // Ensuring null-termination
        new_light.is_on = 0; // Light is initially OFF

        system->lights[system->total_lights] = new_light;
        system->total_lights++;
        printf("Light '%s' added with ID %d.\n", name, new_light.id);
    } else {
        printf("Max lights reached! Cannot add more.\n");
    }
}

void removeLight(SmartHomeSystem *system, int id) {
    if (id >= 0 && id < system->total_lights) {
        for (int i = id; i < system->total_lights - 1; i++) {
            system->lights[i] = system->lights[i + 1]; // Shift left
        }
        system->total_lights--;
        printf("Light with ID %d removed.\n", id);
    } else {
        printf("Invalid ID! Cannot remove light.\n");
    }
}

void toggleLight(SmartHomeSystem *system, int id) {
    if (id >= 0 && id < system->total_lights) {
        system->lights[id].is_on = !system->lights[id].is_on; // Toggle the light
        printf("Light %s is now %s.\n", system->lights[id].name, system->lights[id].is_on ? "ON" : "OFF");
    } else {
        printf("Invalid ID! Cannot toggle light.\n");
    }
}

void displayLights(const SmartHomeSystem *system) {
    if (system->total_lights == 0) {
        printf("No lights in the system.\n");
        return;
    }
    
    printf("Current lights status:\n");
    for (int i = 0; i < system->total_lights; i++) {
        printf("ID: %d, Name: %s, Status: %s\n", 
               system->lights[i].id, 
               system->lights[i].name, 
               system->lights[i].is_on ? "ON" : "OFF");
    }
}

void displayMenu() {
    printf("Smart Home Light Control Menu:\n");
    printf("1. Add Light\n");
    printf("2. Remove Light\n");
    printf("3. Toggle Light\n");
    printf("4. Display Lights\n");
    printf("5. Exit\n");
}