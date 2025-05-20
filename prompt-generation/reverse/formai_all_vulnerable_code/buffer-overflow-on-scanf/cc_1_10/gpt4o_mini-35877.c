//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 100
#define NAME_LENGTH 50

typedef enum {
    OFF,
    ON
} LightStatus;

typedef struct {
    char name[NAME_LENGTH];
    LightStatus status;
} Light;

Light lights[MAX_LIGHTS];
int total_lights = 0;

void add_light(const char* name) {
    if (total_lights >= MAX_LIGHTS) {
        printf("Max number of lights reached. Cannot add more lights.\n");
    } else {
        strncpy(lights[total_lights].name, name, NAME_LENGTH);
        lights[total_lights].status = OFF;
        total_lights++;
        printf("Light '%s' added successfully.\n", name);
    }
}

void turn_on_light(const char* name) {
    for (int i = 0; i < total_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].status = ON;
            printf("Light '%s' is now ON.\n", name);
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void turn_off_light(const char* name) {
    for (int i = 0; i < total_lights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lights[i].status = OFF;
            printf("Light '%s' is now OFF.\n", name);
            return;
        }
    }
    printf("Light '%s' not found.\n", name);
}

void list_lights() {
    if (total_lights == 0) {
        printf("No lights have been added yet.\n");
        return;
    }
    printf("List of lights:\n");
    for (int i = 0; i < total_lights; i++) {
        printf(" - %s: %s\n", lights[i].name, lights[i].status == ON ? "ON" : "OFF");
    }
}

void display_menu() {
    printf("\nSmart Home Light Control\n");
    printf("1. Add Light\n");
    printf("2. Turn On Light\n");
    printf("3. Turn Off Light\n");
    printf("4. List All Lights\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char name[NAME_LENGTH];

    do {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                add_light(name);
                break;
            case 2:
                printf("Enter light name to turn ON: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                turn_on_light(name);
                break;
            case 3:
                printf("Enter light name to turn OFF: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                turn_off_light(name);
                break;
            case 4:
                list_lights();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}