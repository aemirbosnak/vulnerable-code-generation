//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_ROOMS 5
#define MAX_LIGHTS_PER_ROOM 3

struct Room {
    bool lights[MAX_LIGHTS_PER_ROOM];
};

struct SmartHome {
    struct Room rooms[MAX_ROOMS];
    int current_room;
    int current_light;
};

int main() {
    struct SmartHome home;
    home.current_room = 0;
    home.current_light = 0;

    // Initialize all lights to off
    for (int i = 0; i < MAX_ROOMS; i++) {
        for (int j = 0; j < MAX_LIGHTS_PER_ROOM; j++) {
            home.rooms[i].lights[j] = false;
        }
    }

    // Enter main loop
    while (true) {
        // Clear the screen
        system("clear");

        // Print smart home status
        printf("Smart Home Status:\n");
        printf("--------------------\n");
        for (int i = 0; i < MAX_ROOMS; i++) {
            printf("Room %d: ", i);
            for (int j = 0; j < MAX_LIGHTS_PER_ROOM; j++) {
                printf("%c ", home.rooms[i].lights[j] ? 'X' : '_');
            }
            printf("\n");
        }

        // Prompt user for action
        printf("\nWhat would you like to do?\n");
        printf("1. Toggle Light\n");
        printf("2. Next Light\n");
        printf("3. Previous Light\n");
        printf("4. Next Room\n");
        printf("5. Previous Room\n");
        printf("6. Exit\n");
        printf("> ");
        int action;
        scanf("%d", &action);

        // Perform chosen action
        switch (action) {
            case 1:
                home.rooms[home.current_room].lights[home.current_light] = !home.rooms[home.current_room].lights[home.current_light];
                break;
            case 2:
                home.current_light = (home.current_light + 1) % MAX_LIGHTS_PER_ROOM;
                break;
            case 3:
                home.current_light = (home.current_light - 1) % MAX_LIGHTS_PER_ROOM;
                if (home.current_light < 0) {
                    home.current_light = MAX_LIGHTS_PER_ROOM - 1;
                }
                break;
            case 4:
                home.current_room = (home.current_room + 1) % MAX_ROOMS;
                break;
            case 5:
                home.current_room = (home.current_room - 1) % MAX_ROOMS;
                if (home.current_room < 0) {
                    home.current_room = MAX_ROOMS - 1;
                }
                break;
            case 6:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Pause to simulate post-apocalyptic power fluctuations
        sleep(1);
    }
}