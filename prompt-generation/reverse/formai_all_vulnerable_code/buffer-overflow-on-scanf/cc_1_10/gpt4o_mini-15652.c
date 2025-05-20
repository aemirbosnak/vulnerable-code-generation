//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[50];
    int brightness; // range from 0 to 100
    int is_on; // 1 for ON, 0 for OFF
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

void add_light(char *name) {
    if (light_count >= MAX_LIGHTS) {
        printf("Cannot add more lights. Maximum limit reached.\n");
        return;
    }
    strcpy(lights[light_count].name, name);
    lights[light_count].brightness = 0;
    lights[light_count].is_on = 0;
    light_count++;
    printf("Light %s added.\n", name);
}

void turn_on_light(int index) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index.\n");
        return;
    }
    lights[index].is_on = 1;
    printf("Light %s is turned ON.\n", lights[index].name);
}

void turn_off_light(int index) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index.\n");
        return;
    }
    lights[index].is_on = 0;
    printf("Light %s is turned OFF.\n", lights[index].name);
}

void set_brightness(int index, int brightness) {
    if (index < 0 || index >= light_count) {
        printf("Invalid light index.\n");
        return;
    }
    if (brightness < 0 || brightness > 100) {
        printf("Brightness must be between 0 and 100.\n");
        return;
    }
    lights[index].brightness = brightness;
    printf("Light %s brightness set to %d.\n", lights[index].name, brightness);
}

void display_lights() {
    printf("\nCurrent Light Status:\n");
    for (int i = 0; i < light_count; i++) {
        printf("Light %d: %s | Status: %s | Brightness: %d\n", 
               i, lights[i].name, 
               lights[i].is_on ? "ON" : "OFF", 
               lights[i].brightness);
    }
}

int main() {
    int choice, index, brightness;
    char name[50];

    while (1) {
        printf("\nSmart Home Light Control\n");
        printf("1. Add Light\n");
        printf("2. Turn ON Light\n");
        printf("3. Turn OFF Light\n");
        printf("4. Set Brightness\n");
        printf("5. Display Lights\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter light name: ");
                scanf("%s", name);
                add_light(name);
                break;
            case 2:
                printf("Enter light index to turn ON: ");
                scanf("%d", &index);
                turn_on_light(index);
                break;
            case 3:
                printf("Enter light index to turn OFF: ");
                scanf("%d", &index);
                turn_off_light(index);
                break;
            case 4:
                printf("Enter light index and brightness: ");
                scanf("%d %d", &index, &brightness);
                set_brightness(index, brightness);
                break;
            case 5:
                display_lights();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}