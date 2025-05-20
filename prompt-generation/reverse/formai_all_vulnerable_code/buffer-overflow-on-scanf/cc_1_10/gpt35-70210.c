//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LOCATIONS 50

struct Location {
    int id;
    char name[50];
    double latitude;
    double longitude;
};

// Function prototypes
int add_location(struct Location locations[], int num_locations);
void print_location(struct Location location);
void print_directions(struct Location start, struct Location end);

int main() {
    // Declare variables
    struct Location locations[MAX_LOCATIONS];
    int num_locations = 0;
    char choice;

    while (true) {
        // Display menu options
        printf("GPS Navigation Simulation\n");
        printf("========================\n");
        printf("1. Add Location\n");
        printf("2. Print Locations\n");
        printf("3. Get Directions\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                num_locations = add_location(locations, num_locations);
                break;
            case '2':
                printf("Locations:\n");
                for (int i = 0; i < num_locations; i++) {
                    print_location(locations[i]);
                }
                break;
            case '3': {
                int start_id, end_id;
                printf("Enter start location id: ");
                scanf("%d", &start_id);
                printf("Enter end location id: ");
                scanf("%d", &end_id);

                // Find the start and end locations
                struct Location start_location = {0};
                struct Location end_location = {0};
                for (int i = 0; i < num_locations; i++) {
                    if (locations[i].id == start_id) {
                        start_location = locations[i];
                    }
                    if (locations[i].id == end_id) {
                        end_location = locations[i];
                    }
                }

                // Print directions
                if (start_location.id != 0 && end_location.id != 0) {
                    print_directions(start_location, end_location);
                } else {
                    printf("Invalid start or end location id\n");
                }
                break;
            }
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    }

    return 0;
}

/*
 * Adds a location to the list of locations
 */
int add_location(struct Location locations[], int num_locations) {
    // Check if the maximum number of locations has been reached
    if (num_locations >= MAX_LOCATIONS) {
        printf("Maximum number of locations reached\n");
        return num_locations;
    }

    // Create a new location
    struct Location new_location = {0};
    new_location.id = num_locations + 1;
    printf("Enter location name: ");
    scanf("%s", new_location.name);
    printf("Enter latitude: ");
    scanf("%lf", &new_location.latitude);
    printf("Enter longitude: ");
    scanf("%lf", &new_location.longitude);

    // Add the new location to the list
    locations[num_locations] = new_location;
    num_locations++;

    printf("Location added successfully\n");

    return num_locations;
}

/*
 * Prints the details of a location
 */
void print_location(struct Location location) {
    printf("%d. %s (%lf, %lf)\n", location.id, location.name, location.latitude, location.longitude);
}

/*
 * Prints the directions to get from the start location to the end location
 */
void print_directions(struct Location start, struct Location end) {
    printf("Directions:\n");
    printf("1. Start at %s\n", start.name);
    printf("2. Head %s on Route 1 for %lf miles\n", start.longitude < end.longitude ? "east" : "west", 
           abs(end.longitude - start.longitude));
    printf("3. Turn %s on Route 2 for %lf miles\n", start.latitude < end.latitude ? "north" : "south", 
           abs(end.latitude - start.latitude));
    printf("4. End at %s\n", end.name);
}