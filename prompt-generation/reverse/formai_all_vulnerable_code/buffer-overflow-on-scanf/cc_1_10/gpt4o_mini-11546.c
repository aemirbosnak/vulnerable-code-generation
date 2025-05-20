//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LIGHTS 10

typedef struct {
    char name[20];
    int brightness; // 0 to 100
    int is_on; // 1 for ON, 0 for OFF
} SmartLight;

SmartLight lights[MAX_LIGHTS];
int light_count = 0;

// Function to initialize a smart light
void add_light(const char *name) {
    if (light_count < MAX_LIGHTS) {
        strcpy(lights[light_count].name, name);
        lights[light_count].brightness = 0;
        lights[light_count].is_on = 0;
        light_count++;
        printf("Added light: %s\n", name);
    } else {
        printf("Light limit reached! Cannot add more lights.\n");
    }
}

// Function to turn on a light
void turn_on_light(int index) {
    if (index < light_count && index >= 0) {
        lights[index].is_on = 1;
        printf("%s is now ON.\n", lights[index].name);
    } else {
        printf("Invalid light index.\n");
    }
}

// Function to turn off a light
void turn_off_light(int index) {
    if (index < light_count && index >= 0) {
        lights[index].is_on = 0;
        printf("%s is now OFF.\n", lights[index].name);
    } else {
        printf("Invalid light index.\n");
    }
}

// Function to set brightness
void set_brightness(int index, int brightness) {
    if (index < light_count && index >= 0) {
        if (brightness >= 0 && brightness <= 100) {
            lights[index].brightness = brightness;
            printf("Brightness of %s set to %d%%.\n", lights[index].name, brightness);
        } else {
            printf("Brightness value must be between 0 and 100.\n");
        }
    } else {
        printf("Invalid light index.\n");
    }
}

// Function to display light status
void show_light_status() {
    for (int i = 0; i < light_count; i++) {
        printf("Light: %s | Status: %s | Brightness: %d%%\n", 
               lights[i].name, 
               lights[i].is_on ? "ON" : "OFF", 
               lights[i].brightness);
    }
}

// Function to control lights based on user input
void control_lights() {
    int option, index, brightness;
    char name[20];

    while (1) {
        printf("\n--- Smart Home Light Control ---\n");
        printf("1. Add Light\n");
        printf("2. Turn ON Light\n");
        printf("3. Turn OFF Light\n");
        printf("4. Set Brightness\n");
        printf("5. Show Light Status\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
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
                printf("Enter light index to set brightness: ");
                scanf("%d", &index);
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                set_brightness(index, brightness);
                break;
            case 5:
                show_light_status();
                break;
            case 6:
                printf("Exiting the Smart Home Light Control.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

int main() {
    control_lights();
    return 0;
}