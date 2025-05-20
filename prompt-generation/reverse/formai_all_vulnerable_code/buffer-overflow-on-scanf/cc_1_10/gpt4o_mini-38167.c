//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0

typedef struct {
    char room[50];
    int status; // 1 for ON, 0 for OFF
    int brightness; // 0 to 100
} Light;

void initialize_light(Light *light, const char *room) {
    strcpy(light->room, room);
    light->status = LIGHT_OFF;
    light->brightness = 0;
}

void turn_on_light(Light *light) {
    light->status = LIGHT_ON;
    light->brightness = 100; // Default brightness
    printf("%s light is ON with brightness at %d%%.\n", light->room, light->brightness);
}

void turn_off_light(Light *light) {
    light->status = LIGHT_OFF;
    light->brightness = 0;
    printf("%s light is OFF.\n", light->room);
}

void set_brightness(Light *light, int brightness) {
    if (light->status == LIGHT_ON) {
        if (brightness >= 0 && brightness <= 100) {
            light->brightness = brightness;
            printf("%s light brightness set to %d%%.\n", light->room, light->brightness);
        } else {
            printf("Brightness value must be between 0 and 100.\n");
        }
    } else {
        printf("%s light is OFF. Please turn ON the light to adjust brightness.\n", light->room);
    }
}

void display_light_status(const Light *light) {
    if (light->status == LIGHT_ON) {
        printf("%s light is ON with brightness at %d%%.\n", light->room, light->brightness);
    } else {
        printf("%s light is OFF.\n", light->room);
    }
}

int main() {
    Light living_room;
    Light kitchen;
    Light bedroom;

    initialize_light(&living_room, "Living Room");
    initialize_light(&kitchen, "Kitchen");
    initialize_light(&bedroom, "Bedroom");

    int choice;
    int brightness;

    while (1) {
        printf("\nSmart Home Light Control System\n");
        printf("1. Turn ON Living Room Light\n");
        printf("2. Turn OFF Living Room Light\n");
        printf("3. Set Living Room Brightness\n");
        printf("4. Show Living Room Light Status\n");
        printf("5. Turn ON Kitchen Light\n");
        printf("6. Turn OFF Kitchen Light\n");
        printf("7. Set Kitchen Brightness\n");
        printf("8. Show Kitchen Light Status\n");
        printf("9. Turn ON Bedroom Light\n");
        printf("10. Turn OFF Bedroom Light\n");
        printf("11. Set Bedroom Brightness\n");
        printf("12. Show Bedroom Light Status\n");
        printf("0. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                turn_on_light(&living_room);
                break;
            case 2:
                turn_off_light(&living_room);
                break;
            case 3:
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(&living_room, brightness);
                break;
            case 4:
                display_light_status(&living_room);
                break;
            case 5:
                turn_on_light(&kitchen);
                break;
            case 6:
                turn_off_light(&kitchen);
                break;
            case 7:
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(&kitchen, brightness);
                break;
            case 8:
                display_light_status(&kitchen);
                break;
            case 9:
                turn_on_light(&bedroom);
                break;
            case 10:
                turn_off_light(&bedroom);
                break;
            case 11:
                printf("Enter brightness (0-100): ");
                scanf("%d", &brightness);
                set_brightness(&bedroom, brightness);
                break;
            case 12:
                display_light_status(&bedroom);
                break;
            case 0:
                printf("Exiting Smart Home Light Control System.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        sleep(1); // Adding a delay for better interaction
    }

    return 0;
}