//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10

typedef enum { OFF, ON } LightState;

typedef struct {
    char name[20];
    LightState state;
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void add_light(const char *name) {
    if (light_count >= MAX_LIGHTS) {
        printf("Maximum light limit reached!\n");
        return;
    }
    strncpy(lights[light_count].name, name, sizeof(lights[light_count].name) - 1);
    lights[light_count].name[sizeof(lights[light_count].name) - 1] = '\0';
    lights[light_count].state = OFF;
    light_count++;
    printf("Light %s added successfully.\n", name);
}

void show_lights() {
    printf("Current Lights:\n");
    for (int i = 0; i < light_count; i++) {
        const char *state_str = lights[i].state == ON ? "ON" : "OFF";
        printf("[%d] %s - %s\n", i, lights[i].name, state_str);
    }
}

void toggle_light(int index) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index!\n");
        return;
    }
    lights[index].state = lights[index].state == ON ? OFF : ON;
    const char *state_str = lights[index].state == ON ? "ON" : "OFF";
    printf("Light %s is now %s.\n", lights[index].name, state_str);
}

void remove_light(int index) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index!\n");
        return;
    }
    for (int i = index; i < light_count - 1; i++) {
        lights[i] = lights[i + 1];
    }
    light_count--;
    printf("Light at index %d has been removed successfully.\n", index);
}

void control_lights() {
    int choice, index;
    char name[20];

    while (1) {
        printf("\nSmart Light Control Menu:\n");
        printf("1. Add Light\n");
        printf("2. Show Lights\n");
        printf("3. Toggle Light\n");
        printf("4. Remove Light\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the light: ");
                scanf("%s", name);
                add_light(name);
                break;
            case 2:
                show_lights();
                break;
            case 3:
                printf("Enter the index of the light to toggle: ");
                scanf("%d", &index);
                toggle_light(index);
                break;
            case 4:
                printf("Enter the index of the light to remove: ");
                scanf("%d", &index);
                remove_light(index);
                break;
            case 5:
                printf("Exiting Smart Light Control System. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Smart Home Light Control System!\n");
    control_lights();
    return 0;
}