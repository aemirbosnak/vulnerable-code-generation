//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 50

// Structure to represent each room's light status
typedef struct {
    char name[MAX_NAME_LENGTH];
    int is_on;
} Room;

// Function to initialize rooms
void initialize_rooms(Room rooms[], int num_rooms) {
    for (int i = 0; i < num_rooms; i++) {
        printf("Enter name for room %d: ", i + 1);
        fgets(rooms[i].name, MAX_NAME_LENGTH, stdin);
        rooms[i].name[strcspn(rooms[i].name, "\n")] = 0; // Remove newline character
        rooms[i].is_on = 0; // Initialize the light status to OFF
    }
}

// Function to toggle light in a specific room
void toggle_light(Room *room) {
    room->is_on = !room->is_on; // Toggle light status
    printf("The light in the %s is turned %s.\n", room->name, room->is_on ? "ON" : "OFF");
}

// Function to display all rooms and their light status
void display_rooms(Room rooms[], int num_rooms) {
    printf("\nRoom Light Status:\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("Room: %s - Light is %s\n", rooms[i].name, rooms[i].is_on ? "ON" : "OFF");
    }
}

// Function to set a timer to turn off the light after a certain period
void set_timer(Room *room, int seconds) {
    printf("Setting timer for %d seconds in the %s...\n", seconds, room->name);
    sleep(seconds); // Simulate waiting time
    room->is_on = 0; // Automatically turn off light
    printf("The light in the %s has been turned OFF after %d seconds.\n", room->name, seconds);
}

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms;

    // Get the number of rooms from the user
    printf("Enter the number of rooms (maximum %d): ", MAX_ROOMS);
    scanf("%d", &num_rooms);
    getchar(); // Clear newline character after number input
    
    if (num_rooms < 1 || num_rooms > MAX_ROOMS) {
        fprintf(stderr, "Invalid number of rooms. Please enter a number between 1 and %d.\n", MAX_ROOMS);
        return EXIT_FAILURE;
    }

    // Initialize rooms
    initialize_rooms(rooms, num_rooms);
    
    int choice;
    while (1) {
        printf("\nSmart Home Light Control Menu:\n");
        printf("1. Toggle Light\n");
        printf("2. Show Room Status\n");
        printf("3. Set Timer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character after choice input

        switch (choice) {
            case 1: {
                int room_number;
                printf("Enter room number to toggle light (1-%d): ", num_rooms);
                scanf("%d", &room_number);
                getchar();
                if (room_number < 1 || room_number > num_rooms) {
                    fprintf(stderr, "Invalid room number!\n");
                } else {
                    toggle_light(&rooms[room_number - 1]);
                }
                break;
            }
            case 2:
                display_rooms(rooms, num_rooms);
                break;
            case 3: {
                int room_number, timer;
                printf("Enter room number to set timer (1-%d): ", num_rooms);
                scanf("%d", &room_number);
                getchar();
                if (room_number < 1 || room_number > num_rooms) {
                    fprintf(stderr, "Invalid room number!\n");
                } else {
                    printf("Enter timer duration in seconds: ");
                    scanf("%d", &timer);
                    getchar();
                    set_timer(&rooms[room_number - 1], timer);
                }
                break;
            }
            case 4:
                printf("Exiting Smart Home Light Control. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return EXIT_SUCCESS;
}