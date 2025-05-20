//FormAI DATASET v1.0 Category: Smart home light control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define structure for light bulb
struct LightBulb {
    int id;
    char name[20];
    int brightness;
    int status; // 0 for off, 1 for on
} bulbs[3];

// Switch light bulb on/off
void toggleBulb(int id) {
    if (bulbs[id].status == 0) {
        bulbs[id].status = 1;
        printf("%s is now on.\n", bulbs[id].name);
    } else {
        bulbs[id].status = 0;
        printf("%s is now off.\n", bulbs[id].name);
    }
}

// Change brightness level of light bulb
void changeBrightness(int id, int brightness) {
    bulbs[id].brightness = brightness;
    printf("%s brightness is now %d.\n", bulbs[id].name, bulbs[id].brightness);
}

int main() {
    // Populate light bulbs array
    bulbs[0].id = 0;
    strcpy(bulbs[0].name, "Living Room");
    bulbs[0].brightness = 50;
    bulbs[0].status = 1;

    bulbs[1].id = 1;
    strcpy(bulbs[1].name, "Bedroom");
    bulbs[1].brightness = 75;
    bulbs[1].status = 0;

    bulbs[2].id = 2;
    strcpy(bulbs[2].name, "Kitchen");
    bulbs[2].brightness = 100;
    bulbs[2].status = 1;

    // User interface
    printf("Welcome to Smart Home Light Control!\n");
    while(1) {
        int choice, id, brightness;
        printf("\nPlease choose an option:\n");
        printf("1. Turn light bulb on/off\n");
        printf("2. Change brightness level of light bulb\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Please enter light bulb ID (0-2):\n");
            scanf("%d", &id);
            toggleBulb(id);
        } else if (choice == 2) {
            printf("Please enter light bulb ID (0-2):\n");
            scanf("%d", &id);
            printf("Please enter brightness level (0-100):\n");
            scanf("%d", &brightness);
            changeBrightness(id, brightness);
        } else if (choice == 3) {
            printf("Thank you for using Smart Home Light Control.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}