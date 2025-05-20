//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define LIGHT_NAME_LENGTH 30

// Structure to hold the light information
typedef struct {
    char name[LIGHT_NAME_LENGTH];
    int is_on;
} SmartLight;

// Function declarations
void initializeLights(SmartLight lights[], int light_count);
void printLightStatus(SmartLight lights[], int light_count);
void toggleLight(SmartLight *light);
void performUserAction(SmartLight lights[], int light_count, int action);

int main() {
    SmartLight lights[MAX_LIGHTS];
    int light_count = 5; // Let's say we have 5 cool lights
    initializeLights(lights, light_count);

    // A happy little light control interface
    printf("Welcome to the Home of Light: Where Brightness is a Mode of Life!\n\n");
    sleep(1);
    
    while (1) {
        printLightStatus(lights, light_count);
        printf("What would you like to do?\n");
        printf("1. Toggle a light\n");
        printf("2. Show light status\n");
        printf("3. Exit this glowing kingdom\n");
        printf("Your Choice (1-3): ");
        
        int choice;
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Thank you for using Home of Light! May your days be brighter!\n");
            break;
        } else if (choice == 1) {
            printf("Which light would you like to toggle (0-%d)? ", light_count - 1);
            int light_index;
            scanf("%d", &light_index);
            if (light_index >= 0 && light_index < light_count) {
                toggleLight(&lights[light_index]);
            } else {
                printf("Oops! That's not a light. Try again!\n");
                sleep(1);
            }
        } else if (choice == 2) {
            int action = 0; // Just for fun - not using a specific action
            performUserAction(lights, light_count, action);
        } else {
            printf("That's not a valid choice, let's stick to the lights!\n\n");
            sleep(1);
        }
    }

    return 0;
}

// Initializes the light names and their status
void initializeLights(SmartLight lights[], int light_count) {
    char *names[] = {"Living Room", "Kitchen", "Bedroom", "Bathroom", "Hallway"};
    
    for (int i = 0; i < light_count; i++) {
        strcpy(lights[i].name, names[i]);
        lights[i].is_on = rand() % 2; // Randomly set lights on/off for fun
    }
}

// Prints the status of all the lights
void printLightStatus(SmartLight lights[], int light_count) {
    printf("\nCurrent status of lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%s - %s\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
    }
    printf("\n");
}

// Toggles the state of a given light
void toggleLight(SmartLight *light) {
    light->is_on = !light->is_on;
    const char *state = light->is_on ? "ON" : "OFF";
    printf("The light in the %s is now %s! Yay!\n", light->name, state);
}

// Performs a user action, but let's keep it simple
void performUserAction(SmartLight lights[], int light_count, int action) {
    // This is where you can add your fun actions
    // But for now let's just tease them
    printf("You chose action '%d'! So scintillating, maybe on the next update!\n", action);
}