//FormAI DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define number of rooms and rooms' initial light state
#define NUM_ROOMS 3
int room_states[NUM_ROOMS] = {0, 1, 0}; // 0 - light off, 1 - light on

// Function to print current light state of all rooms
void print_state() {
    printf("Current light state:\n");
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("Room %d: ", i+1);
        if (room_states[i]) {
            printf("ON\n");
        } else {
            printf("OFF\n");
        }
    }   
}

// Function to toggle the light state of a given room
void toggle_light(int room) {
    if (room > 0 && room <= NUM_ROOMS) {
        room_states[room-1] = !room_states[room-1]; // Toggle light state
        printf("Room %d light is now ", room);
        if (room_states[room-1]) {
            printf("ON.\n");
        } else {
            printf("OFF.\n");
        }
    } else {
        printf("Invalid room number.\n");
    }
}

int main() {
    int choice;
    do {
        // Prompt user for input
        printf("\nChoose an option:\n");
        printf("1. Check current light state\n");
        printf("2. Turn on/off light of a room\n");
        printf("3. Exit program\n");
        scanf("%d", &choice);
        
        // Process input
        switch (choice) {
            case 1:
                print_state();
                break;
            case 2:
                printf("Enter room number: ");
                int room;
                scanf("%d", &room);
                toggle_light(room);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(1);
    return 0;
}