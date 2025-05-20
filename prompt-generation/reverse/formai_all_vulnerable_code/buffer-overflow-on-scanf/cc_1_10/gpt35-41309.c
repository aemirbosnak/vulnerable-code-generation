//FormAI DATASET v1.0 Category: Smart home light control ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to turn on the lights
void light_on(bool* light, int room_num) {
    light[room_num] = true;
    printf("Light in room %d is now on.\n", room_num);
}

// Function to turn off the lights
void light_off(bool* light, int room_num) {
    light[room_num] = false;
    printf("Light in room %d is now off.\n", room_num);
}

int main() {
    // Array to track the lights in each room
    bool light[5] = {false, false, false, false, false};

    // Welcome message
    printf("Welcome to the Smart Home Light Control System!\n");

    // Main loop
    while (true) {
        // Display menu
        printf("\n");
        printf("Please select an option:\n");
        printf("1. Turn on the lights\n");
        printf("2. Turn off the lights\n");
        printf("3. Exit\n");

        // Get user input
        int choice;
        scanf("%d", &choice);

        // Process user input
        switch (choice) {
            case 1:
                // Turn on the lights
                printf("\nWhich room would you like to turn on the lights for? (1-5)\n");
                int room_on;
                scanf("%d", &room_on);
                if (room_on < 1 || room_on > 5) {
                    printf("Invalid room number!\n");
                    break;
                }
                light_on(light, room_on - 1);
                break;
            
            case 2:
                // Turn off the lights
                printf("\nWhich room would you like to turn off the lights for? (1-5)\n");
                int room_off;
                scanf("%d", &room_off);
                if (room_off < 1 || room_off > 5) {
                    printf("Invalid room number!\n");
                    break;
                }
                light_off(light, room_off - 1);
                break;

            case 3:
                // Exit program
                printf("\nGoodbye!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid option!\n");
                break;
        }
    }

    return 0;
}