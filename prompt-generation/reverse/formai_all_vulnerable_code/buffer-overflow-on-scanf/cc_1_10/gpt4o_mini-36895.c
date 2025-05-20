//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    int id;
    char name[20];
    int brightness; // 0 to 100
    int is_on;
} Light;

Light lights[MAX_LIGHTS];
int light_count = 0;

void initialize_lights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        sprintf(lights[i].name, "Light %d", i + 1);
        lights[i].brightness = 0;
        lights[i].is_on = 0;
    }
    light_count = MAX_LIGHTS;
}

void display_menu() {
    printf("\nSmart Home Light Control System\n");
    printf("1. Display Lights\n");
    printf("2. Turn On Light\n");
    printf("3. Turn Off Light\n");
    printf("4. Set Brightness\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void display_lights() {
    printf("\nCurrent Lights Status:\n");
    for (int i = 0; i < light_count; i++) {
        printf("%s - %s, Brightness: %d%%\n", lights[i].name, lights[i].is_on ? "ON" : "OFF", lights[i].brightness);
    }
}

void turn_on_light(int id) {
    if (id < 0 || id >= light_count) {
        printf("Invalid light ID.\n");
        return;
    }
    lights[id].is_on = 1;
    printf("%s is now ON.\n", lights[id].name);
}

void turn_off_light(int id) {
    if (id < 0 || id >= light_count) {
        printf("Invalid light ID.\n");
        return;
    }
    lights[id].is_on = 0;
    printf("%s is now OFF.\n", lights[id].name);
}

void set_brightness(int id, int brightness) {
    if (id < 0 || id >= light_count) {
        printf("Invalid light ID.\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    lights[id].brightness = brightness;
    printf("Brightness of %s set to %d%%.\n", lights[id].name, brightness);
}

int main() {
    int choice, light_id, brightness;

    initialize_lights();

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_lights();
                break;

            case 2:
                printf("Enter light ID to turn ON (0 to %d): ", light_count - 1);
                scanf("%d", &light_id);
                turn_on_light(light_id);
                break;

            case 3:
                printf("Enter light ID to turn OFF (0 to %d): ", light_count - 1);
                scanf("%d", &light_id);
                turn_off_light(light_id);
                break;

            case 4:
                printf("Enter light ID to set brightness (0 to %d): ", light_count - 1);
                scanf("%d", &light_id);
                printf("Enter brightness (0 to 100): ");
                scanf("%d", &brightness);
                set_brightness(light_id, brightness);
                break;

            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
        }
        sleep(1); // Add a short delay for better user experience
    }

    return 0;
}