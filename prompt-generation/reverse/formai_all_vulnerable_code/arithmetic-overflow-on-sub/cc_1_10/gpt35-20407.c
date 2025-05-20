//FormAI DATASET v1.0 Category: Smart home automation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Declare constants */
#define NUM_ROOMS 5
#define MAX_TEMP 80
#define MIN_TEMP 60

/* Struct to represent a room */
typedef struct Room {
    int temperature;
    bool lights_on;
} Room;

/* Function to initialize rooms */
void initialize_rooms(Room* rooms) {
    /* Generate random temperatures and turn off lights for each room */
    for(int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        rooms[i].lights_on = false;
    }
}

/* Function to print the state of all rooms */
void print_rooms(Room* rooms) {
    printf("Current state of rooms:\n");
    for(int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d - Temperature: %d degrees, Lights: %s\n", i+1, rooms[i].temperature, rooms[i].lights_on ? "On" : "Off");
    }
}

/* Function to turn on/off lights for a specific room */
void toggle_lights(Room* room) {
    room->lights_on = !room->lights_on;
    printf("Room temperature is now %d degrees and lights are %s\n", room->temperature, room->lights_on ? "On" : "Off");
}

/* Function to adjust temperature for a specific room */
void adjust_temp(Room* room, int temp_change) {
    room->temperature += temp_change;
    printf("Room temperature is now %d degrees and lights are %s\n", room->temperature, room->lights_on ? "On" : "Off");
}

int main() {
    /* Seed random number generator */
    srand(time(0));
    
    /* Initialize rooms */
    Room rooms[NUM_ROOMS];
    initialize_rooms(rooms);

    /* Print initial state of rooms */
    print_rooms(rooms);

    /* Interaction loop */
    int room_num, choice, temp_change;
    while(true) {
        printf("\nEnter room number or 0 to exit: ");
        scanf("%d", &room_num);
        if(room_num == 0) break; /* Exit loop */

        printf("Choose action:\n");
        printf("1. Toggle lights\n");
        printf("2. Adjust temperature\n");
        printf("3. Cancel\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                toggle_lights(&rooms[room_num-1]);
                break;
            case 2:
                printf("Enter temperature change (positive to increase, negative to decrease): ");
                scanf("%d", &temp_change);
                adjust_temp(&rooms[room_num-1], temp_change);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice\n");
        }

        /* Print updated state of rooms */
        print_rooms(rooms);
    }

    return 0;
}