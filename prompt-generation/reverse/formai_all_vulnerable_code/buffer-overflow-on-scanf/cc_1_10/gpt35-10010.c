//FormAI DATASET v1.0 Category: Smart home automation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Device statuses
#define OFF 0
#define ON 1

// Room structure
struct Room {
    int light_status;
    int temperature;
};

// Smart home functions
void turn_on_light(struct Room *room) {
    room->light_status = ON;
    printf("Light turned ON!\n");
}

void turn_off_light(struct Room *room) {
    room->light_status = OFF;
    printf("Light turned OFF!\n");
}

void increase_temperature(struct Room *room) {
    room->temperature++;
    printf("Temperature increased to %d degrees!\n", room->temperature);
}

void decrease_temperature(struct Room *room) {
    room->temperature--;
    printf("Temperature decreased to %d degrees!\n", room->temperature);
}

int main() {
    // Create rooms
    struct Room living_room = {
        .light_status = OFF,
        .temperature = 20
    };

    struct Room bedroom = {
        .light_status = OFF,
        .temperature = 18
    };

    // User input loop
    while (true) {
        // Print options
        printf("Select an option:\n");
        printf("1. Turn on living room light\n");
        printf("2. Turn off living room light\n");
        printf("3. Turn on bedroom light\n");
        printf("4. Turn off bedroom light\n");
        printf("5. Increase living room temperature\n");
        printf("6. Decrease living room temperature\n");
        printf("7. Increase bedroom temperature\n");
        printf("8. Decrease bedroom temperature\n");
        printf("9. Exit\n");

        // Get user input
        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                turn_on_light(&living_room);
                break;
            case 2:
                turn_off_light(&living_room);
                break;
            case 3:
                turn_on_light(&bedroom);
                break;
            case 4:
                turn_off_light(&bedroom);
                break;
            case 5:
                increase_temperature(&living_room);
                break;
            case 6:
                decrease_temperature(&living_room);
                break;
            case 7:
                increase_temperature(&bedroom);
                break;
            case 8:
                decrease_temperature(&bedroom);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}