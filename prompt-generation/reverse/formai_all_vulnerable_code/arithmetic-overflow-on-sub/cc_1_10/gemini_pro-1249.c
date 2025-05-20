//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the light states
#define OFF 0
#define ON 1

// Define the room types
#define BEDROOM 1
#define LIVING_ROOM 2
#define KITCHEN 3

// Define the light control commands
#define TURN_ON 1
#define TURN_OFF 2
#define TOGGLE 3

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the maximum number of lights per room
#define MAX_LIGHTS_PER_ROOM 10

// Create a structure to represent a room
typedef struct {
    int room_type;
    int num_lights;
    int lights[MAX_LIGHTS_PER_ROOM];
} room;

// Create a structure to represent the smart home
typedef struct {
    int num_rooms;
    room rooms[MAX_ROOMS];
} smart_home;

// Create a function to initialize the smart home
void initialize_smart_home(smart_home *home) {
    // Set the number of rooms to 0
    home->num_rooms = 0;

    // Initialize each room
    for (int i = 0; i < MAX_ROOMS; i++) {
        home->rooms[i].room_type = 0;
        home->rooms[i].num_lights = 0;

        for (int j = 0; j < MAX_LIGHTS_PER_ROOM; j++) {
            home->rooms[i].lights[j] = OFF;
        }
    }
}

// Create a function to add a room to the smart home
void add_room(smart_home *home, int room_type) {
    // Check if the number of rooms has reached the maximum
    if (home->num_rooms >= MAX_ROOMS) {
        printf("Error: Maximum number of rooms reached.\n");
        return;
    }

    // Set the room type and increment the number of rooms
    home->rooms[home->num_rooms].room_type = room_type;
    home->num_rooms++;
}

// Create a function to add a light to a room
void add_light(smart_home *home, int room_index, int light_index) {
    // Check if the room index is valid
    if (room_index < 0 || room_index >= home->num_rooms) {
        printf("Error: Invalid room index.\n");
        return;
    }

    // Check if the light index is valid
    if (light_index < 0 || light_index >= MAX_LIGHTS_PER_ROOM) {
        printf("Error: Invalid light index.\n");
        return;
    }

    // Increment the number of lights in the room
    home->rooms[room_index].num_lights++;

    // Set the light state to off
    home->rooms[room_index].lights[light_index] = OFF;
}

// Create a function to turn on a light
void turn_on_light(smart_home *home, int room_index, int light_index) {
    // Check if the room index is valid
    if (room_index < 0 || room_index >= home->num_rooms) {
        printf("Error: Invalid room index.\n");
        return;
    }

    // Check if the light index is valid
    if (light_index < 0 || light_index >= home->rooms[room_index].num_lights) {
        printf("Error: Invalid light index.\n");
        return;
    }

    // Turn on the light
    home->rooms[room_index].lights[light_index] = ON;
}

// Create a function to turn off a light
void turn_off_light(smart_home *home, int room_index, int light_index) {
    // Check if the room index is valid
    if (room_index < 0 || room_index >= home->num_rooms) {
        printf("Error: Invalid room index.\n");
        return;
    }

    // Check if the light index is valid
    if (light_index < 0 || light_index >= home->rooms[room_index].num_lights) {
        printf("Error: Invalid light index.\n");
        return;
    }

    // Turn off the light
    home->rooms[room_index].lights[light_index] = OFF;
}

// Create a function to toggle a light
void toggle_light(smart_home *home, int room_index, int light_index) {
    // Check if the room index is valid
    if (room_index < 0 || room_index >= home->num_rooms) {
        printf("Error: Invalid room index.\n");
        return;
    }

    // Check if the light index is valid
    if (light_index < 0 || light_index >= home->rooms[room_index].num_lights) {
        printf("Error: Invalid light index.\n");
        return;
    }

    // Toggle the light
    home->rooms[room_index].lights[light_index] = !home->rooms[room_index].lights[light_index];
}

// Create a function to print the status of the smart home
void print_smart_home_status(smart_home *home) {
    // Print the number of rooms
    printf("Smart home has %d rooms:\n", home->num_rooms);

    // Print the status of each room
    for (int i = 0; i < home->num_rooms; i++) {
        printf("Room %d:\n", i + 1);

        // Print the room type
        switch (home->rooms[i].room_type) {
            case BEDROOM:
                printf("Bedroom");
                break;
            case LIVING_ROOM:
                printf("Living room");
                break;
            case KITCHEN:
                printf("Kitchen");
                break;
        }

        // Print the number of lights in the room
        printf(" has %d lights:\n", home->rooms[i].num_lights);

        // Print the status of each light in the room
        for (int j = 0; j < home->rooms[i].num_lights; j++) {
            printf("Light %d: ", j + 1);

            // Print the light state
            if (home->rooms[i].lights[j] == OFF) {
                printf("Off\n");
            } else {
                printf("On\n");
            }
        }
    }
}

// Create a function to handle the user input
void handle_user_input(smart_home *home) {
    // Get the command from the user
    int command;
    printf("Enter a command (1: Turn on, 2: Turn off, 3: Toggle): ");
    scanf("%d", &command);

    // Get the room index from the user
    int room_index;
    printf("Enter the room index: ");
    scanf("%d", &room_index);

    // Get the light index from the user
    int light_index;
    printf("Enter the light index: ");
    scanf("%d", &light_index);

    // Execute the command
    switch (command) {
        case TURN_ON:
            turn_on_light(home, room_index - 1, light_index - 1);
            break;
        case TURN_OFF:
            turn_off_light(home, room_index - 1, light_index - 1);
            break;
        case TOGGLE:
            toggle_light(home, room_index - 1, light_index - 1);
            break;
    }

    // Print the status of the smart home
    print_smart_home_status(home);
}

// Create the main function
int main() {
    // Create a smart home
    smart_home home;

    // Initialize the smart home
    initialize_smart_home(&home);

    // Add some rooms to the smart home
    add_room(&home, BEDROOM);
    add_room(&home, LIVING_ROOM);
    add_room(&home, KITCHEN);

    // Add some lights to each room
    add_light(&home, 0, 0);
    add_light(&home, 0, 1);
    add_light(&home, 1, 0);
    add_light(&home, 1, 1);
    add_light(&home, 2, 0);
    add_light(&home, 2, 1);

    // Print the status of the smart home
    print_smart_home_status(&home);

    // Handle the user input
    handle_user_input(&home);

    return 0;
}