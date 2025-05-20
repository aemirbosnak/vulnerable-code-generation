//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_ROOMS 5
#define MAX_LIGHTS_PER_ROOM 10

// Define functions
void turnOnLight(int room, int light);
void turnOffLight(int room, int light);

// Define global variables
int lights[MAX_ROOMS][MAX_LIGHTS_PER_ROOM] = {0};

int main() {
    int selectedRoom, selectedLight, selectedAction;

    while (1) {
        // Display options for the user
        printf("\nSelect an option:\n");
        printf("1. Turn on a light\n");
        printf("2. Turn off a light\n");
        printf("3. Quit\n");

        // Get user input for selected action
        scanf("%d", &selectedAction);

        // Quit the program if selected action is 3
        if (selectedAction == 3) {
            break;
        }

        // Display available rooms for the user
        printf("\nAvailable rooms:\n");
        for (int i = 0; i < MAX_ROOMS; i++) {
            printf("%d. Room %d\n", i + 1, i + 1);
        }

        // Get user input for selected room
        printf("Select a room: ");
        scanf("%d", &selectedRoom);
        while (selectedRoom <= 0 || selectedRoom > MAX_ROOMS) {
            printf("Invalid room selection. Select a room: ");
            scanf("%d", &selectedRoom);
        }

        // Display available lights in the selected room for the user
        printf("\nAvailable lights in Room %d:\n", selectedRoom);
        for (int i = 0; i < MAX_LIGHTS_PER_ROOM; i++) {
            printf("%d. Light %d\n", i + 1, i + 1);
        }

        // Get user input for selected light
        printf("Select a light: ");
        scanf("%d", &selectedLight);
        while (selectedLight <= 0 || selectedLight > MAX_LIGHTS_PER_ROOM) {
            printf("Invalid light selection. Select a light: ");
            scanf("%d", &selectedLight);
        }

        // Perform the selected action on the selected light
        switch(selectedAction) {
            case 1:
                turnOnLight(selectedRoom - 1, selectedLight - 1);
                break;
            case 2:
                turnOffLight(selectedRoom - 1, selectedLight - 1);
                break;
            default:
                printf("Invalid action selected.\n");
                break;
        }

        // Notify the user of the current state of the selected light
        if (lights[selectedRoom - 1][selectedLight - 1] == 1) {
            printf("Light %d in Room %d is turned on.\n", selectedLight, selectedRoom);
        } else {
            printf("Light %d in Room %d is turned off.\n", selectedLight, selectedRoom);
        }
    }

    return 0;
}

// Turn on a specific light in a specific room
void turnOnLight(int room, int light) {
    lights[room][light] = 1;
}

// Turn off a specific light in a specific room
void turnOffLight(int room, int light) {
    lights[room][light] = 0;
}