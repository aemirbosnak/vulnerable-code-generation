//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Get excited!
#define EXCLAMATION_MARK "!"
#define WELCOME_MESSAGE "Welcome to the GPS Navigation Simulation" EXCLAMATION_MARK
#define INSTRUCTIONS "Follow the instructions on the screen." EXCLAMATION_MARK

// Locations
typedef enum {
    HOME,
    WORK,
    STORE,
    RESTAURANT,
    PARK,
    OTHER
} Location;

// Directions
typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

// GPS data
typedef struct {
    Location current_location;
    Direction current_direction;
} GPSData;

// Function prototypes
void welcome_user();
void display_instructions();
void simulate_navigation(GPSData *gps_data);
Location get_random_location();
Direction get_random_direction();

int main() {
    // Welcome the user
    welcome_user();

    // Display the instructions
    display_instructions();

    // Create the GPS data structure
    GPSData gps_data = { HOME, NORTH };

    // Simulate the navigation
    simulate_navigation(&gps_data);

    return 0;
}

void welcome_user() {
    printf("%s\n", WELCOME_MESSAGE);
}

void display_instructions() {
    printf("%s\n", INSTRUCTIONS);
    printf("1. Enter the number corresponding to your current location.\n");
    printf("2. Enter the number corresponding to your desired direction.\n");
    printf("3. Repeat steps 1 and 2 until you reach your destination.\n");
    printf("4. Enter 0 to exit the simulation.\n");
}

void simulate_navigation(GPSData *gps_data) {
    int input_location, input_direction;

    // Loop until the user exits the simulation
    while (1) {
        // Get the user's input
        printf("Enter your current location (0-5): ");
        scanf("%d", &input_location);
        printf("Enter your desired direction (0-3): ");
        scanf("%d", &input_direction);

        // Check if the user wants to exit the simulation
        if (input_location == 0 || input_direction == 0) {
            printf("Exiting the simulation. Goodbye!" EXCLAMATION_MARK);
            break;
        }

        // Update the GPS data
        gps_data->current_location = (Location)input_location;
        gps_data->current_direction = (Direction)input_direction;

        // Get a random destination
        Location destination = get_random_location();

        // Check if the user has reached their destination
        if (gps_data->current_location == destination) {
            printf("Congratulations! You have reached your destination." EXCLAMATION_MARK);
        } else {
            // Get a random direction to the destination
            Direction direction_to_destination = get_random_direction();

            // Check if the user is going in the right direction
            if (gps_data->current_direction == direction_to_destination) {
                printf("You are going in the right direction!" EXCLAMATION_MARK);
            } else {
                printf("Oops! You are going in the wrong direction. Turn %s." EXCLAMATION_MARK, (gps_data->current_direction == NORTH) ? "south" : ((gps_data->current_direction == EAST) ? "west" : ((gps_data->current_direction == SOUTH) ? "north" : "east")));
            }
        }
    }
}

Location get_random_location() {
    return (Location)(rand() % 6);
}

Direction get_random_direction() {
    return (Direction)(rand() % 4);
}