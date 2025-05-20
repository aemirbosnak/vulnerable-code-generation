//FormAI DATASET v1.0 Category: Smart home light control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Light {
    bool on;
    int intensity;
    char color[10];
} Light;

int main() {
    Light livingRoom = {true, 100, "white"};
    Light bedroom = {false, 0, "off"};

    printf("Welcome to Smart Home Light Control Program\n");
    printf("Here are the available commands:\n");
    printf("- Press 1 to toggle living room light\n");
    printf("- Press 2 to change living room light intensity\n");
    printf("- Press 3 to change living room light color\n");
    printf("- Press 4 to toggle bedroom light\n");
    printf("- Press 5 to change bedroom light intensity\n");
    printf("- Press 6 to change bedroom light color\n");
    printf("- Press 0 to exit program\n");

    int choice = -1;
    while (choice != 0) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                livingRoom.on = !livingRoom.on;
                printf("Living room light is now %s\n", livingRoom.on ? "on" : "off");
                break;
            }
            case 2: {
                printf("Enter living room light intensity (0-100): ");
                int intensity;
                scanf("%d", &intensity);

                if (intensity < 0) {
                    printf("Intensity cannot be negative. Set intensity to 0.\n");
                    livingRoom.intensity = 0;
                } else if (intensity > 100) {
                    printf("Intensity cannot be greater than 100. Set intensity to 100.\n");
                    livingRoom.intensity = 100;
                } else {
                    printf("Living room light intensity set to %d\n", intensity);
                    livingRoom.intensity = intensity;
                }
                break;
            }
            case 3: {
                printf("Enter living room light color: ");
                scanf("%s", livingRoom.color);
                break;
            }
            case 4: {
                bedroom.on = !bedroom.on;
                if (bedroom.on) {
                    printf("Bedroom light is now on. Sweet dreams!\n");
                } else {
                    printf("Bedroom light is now off. Don't let the bedbugs bite!\n");
                }
                break;
            }
            case 5: {
                printf("Enter bedroom light intensity (0-100): ");
                int intensity;
                scanf("%d", &intensity);

                if (intensity < 0) {
                    printf("Intensity cannot be negative. Set intensity to 0.\n");
                    bedroom.intensity = 0;
                } else if (intensity > 100) {
                    printf("Intensity cannot be greater than 100. Set intensity to 100.\n");
                    bedroom.intensity = 100;
                } else {
                    printf("Bedroom light intensity set to %d\n", intensity);
                    bedroom.intensity = intensity;
                }
                break;
            }
            case 6: {
                printf("Enter bedroom light color: ");
                scanf("%s", bedroom.color);
                break;
            }
            case 0: {
                printf("Exiting program...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
    }
    return 0;
}