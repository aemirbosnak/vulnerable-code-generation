//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10
#define LIGHT_ON 1
#define LIGHT_OFF 0

typedef struct {
    int id;
    char name[50];
    int status; // 1 for on, 0 for off
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

// Function to add a new light
void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        lights[light_count].id = light_count + 1;
        strcpy(lights[light_count].name, name);
        lights[light_count].status = LIGHT_OFF;
        light_count++;
        printf("Added light: %s\n", name);
    } else {
        printf("Maximum number of lights reached.\n");
    }
}

// Function to turn on a light by ID
void turn_on_light(int id) {
    if (id > 0 && id <= light_count) {
        lights[id - 1].status = LIGHT_ON;
        printf("Light '%s' is now ON.\n", lights[id - 1].name);
    } else {
        printf("Invalid light ID.\n");
    }
}

// Function to turn off a light by ID
void turn_off_light(int id) {
    if (id > 0 && id <= light_count) {
        lights[id - 1].status = LIGHT_OFF;
        printf("Light '%s' is now OFF.\n", lights[id - 1].name);
    } else {
        printf("Invalid light ID.\n");
    }
}

// Function to list all lights
void list_lights() {
    printf("\nCurrent Smart Lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("ID: %d, Name: %s, Status: %s\n", 
               lights[i].id, 
               lights[i].name, 
               lights[i].status == LIGHT_ON ? "ON" : "OFF");
    }
}

// Function to search for a light by name
void search_light(const char *name) {
    printf("\nSearching for light '%s'...\n", name);
    for (int i = 0; i < light_count; i++) {
        if (strcasecmp(lights[i].name, name) == 0) {
            printf("Found: ID: %d, Name: %s, Status: %s\n", 
                   lights[i].id, 
                   lights[i].name, 
                   lights[i].status == LIGHT_ON ? "ON" : "OFF");
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

// Function to toggle a light by ID
void toggle_light(int id) {
    if (id > 0 && id <= light_count) {
        lights[id - 1].status = !lights[id - 1].status; // Toggle status
        printf("Light '%s' is now %s.\n", lights[id - 1].name, 
               lights[id - 1].status == LIGHT_ON ? "ON" : "OFF");
    } else {
        printf("Invalid light ID.\n");
    }
}

// Main function
int main() {
    int choice, id;
    char name[50];

    // Initializing Smart Lights
    add_light("Living Room");
    add_light("Kitchen");
    add_light("Bedroom");
    add_light("Bathroom");

    do {
        printf("\n--- Smart Home Light Control System ---\n");
        printf("1. List Lights\n");
        printf("2. Turn On Light\n");
        printf("3. Turn Off Light\n");
        printf("4. Toggle Light\n");
        printf("5. Search Light\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_lights();
                break;
            case 2:
                printf("Enter Light ID to turn ON: ");
                scanf("%d", &id);
                turn_on_light(id);
                break;
            case 3:
                printf("Enter Light ID to turn OFF: ");
                scanf("%d", &id);
                turn_off_light(id);
                break;
            case 4:
                printf("Enter Light ID to TOGGLE: ");
                scanf("%d", &id);
                toggle_light(id);
                break;
            case 5:
                printf("Enter Light Name to SEARCH: ");
                scanf("%s", name);
                search_light(name);
                break;
            case 0:
                printf("Exiting Smart Home Control System...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
        sleep(1); // To simulate a brief pause
    } while (choice != 0);

    return 0;
}