//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int intensity; // Range from 0 to 100
    int is_on;     // 1 for ON, 0 for OFF
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char* name) {
    if (light_count >= MAX_LIGHTS) {
        printf("Error: Maximum number of lights reached.\n");
        return;
    }
    strncpy(lights[light_count].name, name, NAME_LENGTH);
    lights[light_count].intensity = 0;
    lights[light_count].is_on = 0;
    light_count++;
    printf("Added light: %s\n", name);
}

void toggle_light(int index) {
    if (index < 0 || index >= light_count) {
        printf("Error: Light index out of range.\n");
        return;
    }
    lights[index].is_on = !lights[index].is_on;
    printf("Light %s is now %s.\n", lights[index].name, lights[index].is_on ? "ON" : "OFF");
}

void set_light_intensity(int index, int intensity) {
    if (index < 0 || index >= light_count) {
        printf("Error: Light index out of range.\n");
        return;
    }
    if (intensity < 0 || intensity > 100) {
        printf("Error: Intensity must be between 0 and 100.\n");
        return;
    }
    lights[index].intensity = intensity;
    printf("Light %s intensity set to %d.\n", lights[index].name, intensity);
}

void list_lights() {
    printf("Current Lights:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%d: %s - Status: %s, Intensity: %d\n",
            i + 1,
            lights[i].name,
            lights[i].is_on ? "ON" : "OFF",
            lights[i].intensity);
    }
}

void control_lights() {
    char command[50];
    while (1) {
        printf("\nEnter command (add, toggle, set, list, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[NAME_LENGTH];
            printf("Enter light name: ");
            scanf("%s", name);
            add_light(name);
        } else if (strcmp(command, "toggle") == 0) {
            int index;
            printf("Enter light index to toggle: ");
            scanf("%d", &index);
            toggle_light(index - 1); // Adjusting for 0-based index
        } else if (strcmp(command, "set") == 0) {
            int index, intensity;
            printf("Enter light index to set intensity: ");
            scanf("%d", &index);
            printf("Enter intensity (0-100): ");
            scanf("%d", &intensity);
            set_light_intensity(index - 1, intensity); // Adjusting for 0-based index
        } else if (strcmp(command, "list") == 0) {
            list_lights();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Smart Light Control.\n");
            break;
        } else {
            printf("Unknown command. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to Smart Home Light Control System!\n");
    control_lights();
    return 0;
}