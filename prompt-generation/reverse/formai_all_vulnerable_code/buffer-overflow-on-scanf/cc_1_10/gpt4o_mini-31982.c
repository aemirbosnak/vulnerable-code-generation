//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char name[20];
    int is_on;
} Light;

Light lights[MAX_LIGHTS];
int num_lights = 0;

void init_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        sprintf(lights[i].name, "Light %d", i + 1);
        lights[i].is_on = 0;
    }
}

void display_lights() {
    printf("Current Lights Status:\n");
    for (int i = 0; i < num_lights; i++) {
        printf("%s - %s\n", lights[i].name, lights[i].is_on ? "ON" : "OFF");
    }
}

void toggle_light(int id) {
    if (id < 0 || id >= num_lights) {
        printf("Invalid light ID. Please choose a valid ID between 0 and %d.\n", num_lights - 1);
        return;
    }
    lights[id].is_on = !lights[id].is_on;
    printf("%s is now %s.\n", lights[id].name, lights[id].is_on ? "ON" : "OFF");
}

void add_light() {
    if (num_lights >= MAX_LIGHTS) {
        printf("Cannot add more lights, maximum limit reached.\n");
        return;
    }
    lights[num_lights].id = num_lights;
    sprintf(lights[num_lights].name, "Light %d", num_lights + 1);
    lights[num_lights].is_on = 0;
    num_lights++;
    printf("%s is added to the system.\n", lights[num_lights - 1].name);
}

void remove_light(int id) {
    if (id < 0 || id >= num_lights) {
        printf("Invalid light ID. Please choose a valid ID between 0 and %d.\n", num_lights - 1);
        return;
    }
    printf("%s has been removed from the system.\n", lights[id].name);
    for (int i = id; i < num_lights - 1; i++) {
        lights[i] = lights[i + 1];
    }
    num_lights--;
}

void show_menu() {
    printf("\nSmart Home Light Control System Menu:\n");
    printf("1. Display Lights\n");
    printf("2. Toggle Light\n");
    printf("3. Add Light\n");
    printf("4. Remove Light\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option, light_id;

    init_lights();

    while (1) {
        show_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                display_lights();
                break;
            case 2:
                printf("Enter light ID to toggle (0 to %d): ", num_lights - 1);
                scanf("%d", &light_id);
                toggle_light(light_id);
                break;
            case 3:
                add_light();
                break;
            case 4:
                printf("Enter light ID to remove (0 to %d): ", num_lights - 1);
                scanf("%d", &light_id);
                remove_light(light_id);
                break;
            case 5:
                printf("Exiting the Smart Home Light Control System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}