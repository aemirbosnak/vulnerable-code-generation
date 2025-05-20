//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a smart light
typedef struct {
    char room[50];
    int isOn;
    int brightness; // from 0 to 100
    char color[20];
} SmartLight;

// Function to initialize a light
void initLight(SmartLight *light, const char *room) {
    strcpy(light->room, room);
    light->isOn = 0;  // Light is off initially
    light->brightness = 0; // Brightness at 0
    strcpy(light->color, "White"); // Default color
}

// Function to turn on the light
void turnOn(SmartLight *light) {
    light->isOn = 1;
    printf("The light in %s is now ON!\n", light->room);
}

// Function to turn off the light
void turnOff(SmartLight *light) {
    light->isOn = 0;
    printf("The light in %s is now OFF!\n", light->room);
}

// Function to adjust brightness
void setBrightness(SmartLight *light, int brightness) {
    if (brightness >= 0 && brightness <= 100) {
        light->brightness = brightness;
        printf("The brightness in %s is set to %d%%!\n", light->room, light->brightness);
    } else {
        printf("Invalid brightness level! Please enter a value between 0 and 100.\n");
    }
}

// Function to change the color of the light
void changeColor(SmartLight *light, const char *color) {
    strcpy(light->color, color);
    printf("The color in %s has been changed to %s!\n", light->room, light->color);
}

// Function to display the status of the light
void displayStatus(SmartLight *light) {
    printf("Light Status in %s:\n", light->room);
    printf(" - Power: %s\n", light->isOn ? "ON" : "OFF");
    printf(" - Brightness: %d%%\n", light->brightness);
    printf(" - Color: %s\n", light->color);
}

int main() {
    SmartLight livingRoom;
    SmartLight bedroom;

    // Initialize lights in different rooms
    initLight(&livingRoom, "Living Room");
    initLight(&bedroom, "Bedroom");

    int choice;
    do {
        printf("\n=== Smart Home Light Control ===\n");
        printf("1. Turn ON Living Room Light\n");
        printf("2. Turn OFF Living Room Light\n");
        printf("3. Adjust Living Room Brightness\n");
        printf("4. Change Living Room Color\n");
        printf("5. Show Living Room Status\n");
        printf("6. Turn ON Bedroom Light\n");
        printf("7. Turn OFF Bedroom Light\n");
        printf("8. Adjust Bedroom Brightness\n");
        printf("9. Change Bedroom Color\n");
        printf("10. Show Bedroom Status\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: turnOn(&livingRoom); break;
            case 2: turnOff(&livingRoom); break;
            case 3: {
                int brightness;
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                setBrightness(&livingRoom, brightness);
                break;
            }
            case 4: {
                char color[20];
                printf("Enter color name: ");
                scanf("%s", color);
                changeColor(&livingRoom, color);
                break;
            }
            case 5: displayStatus(&livingRoom); break;
            case 6: turnOn(&bedroom); break;
            case 7: turnOff(&bedroom); break;
            case 8: {
                int brightness;
                printf("Enter brightness level (0-100): ");
                scanf("%d", &brightness);
                setBrightness(&bedroom, brightness);
                break;
            }
            case 9: {
                char color[20];
                printf("Enter color name: ");
                scanf("%s", color);
                changeColor(&bedroom, color);
                break;
            }
            case 10: displayStatus(&bedroom); break;
            case 11: printf("Exiting the Smart Home Light Control. Have a bright day!\n"); break;
            default: printf("Invalid choice! Please try again.\n"); break;
        }
    } while (choice != 11);

    return 0;
}