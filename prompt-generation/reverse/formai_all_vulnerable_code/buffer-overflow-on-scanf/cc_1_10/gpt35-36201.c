//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: protected
#include <stdio.h>
#include <string.h>

// Constants
#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 20

// Structures
typedef struct {
    char name[MAX_NAME_LENGTH];
    double latitude;  // in degrees
    double longitude; // in degrees
} Location;

typedef struct {
    int num_locations;
    Location locations[MAX_LOCATIONS];
} Route;

// Function prototypes
void print_menu();
void get_location_name(char name[]);
double get_coordinate(char coordinate_type[], char coordinate_name[]);
void add_location(Route *route);
void display_locations(Route *route);
void search_location(Route *route);

int main() {
    Route route = {0};

    char choice;
    do {
        print_menu();
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                add_location(&route);
                break;
            case 'd':
                display_locations(&route);
                break;
            case 's':
                search_location(&route);
                break;
            case 'q':
                printf("Exiting GPS simulation...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 'q');

    return 0;
}

void print_menu() {
    printf("\nGPS Simulation Menu\n");
    printf("---------------------------------\n");
    printf("a. Add a location\n");
    printf("d. Display all locations\n");
    printf("s. Search for a location\n");
    printf("q. Quit\n");
    printf("Enter choice: ");
}

void get_location_name(char name[]) {
    printf("Enter location name: ");
    scanf("%s", name);
}

double get_coordinate(char coordinate_type[], char coordinate_name[]) {
    double coordinate;
    do {
        printf("Enter %s %s (must be between -180.0 and 180.0): ", coordinate_type, coordinate_name);
        scanf("%lf", &coordinate);
    } while (coordinate < -180.0 || coordinate > 180.0);
    return coordinate;
}

void add_location(Route *route) {
    if (route->num_locations == MAX_LOCATIONS) {
        printf("Route is full. Cannot add more locations.\n");
        return;
    }

    Location new_location;
    get_location_name(new_location.name);
    new_location.latitude = get_coordinate("latitude", "in degrees");
    new_location.longitude = get_coordinate("longitude", "in degrees");

    route->locations[route->num_locations++] = new_location;
    printf("Location added successfully.\n");
}

void display_locations(Route *route) {
    if (route->num_locations == 0) {
        printf("Route is empty. Cannot display locations.\n");
        return;
    }

    printf("%-20s%-20s%-20s\n", "Location", "Latitude", "Longitude");
    for (int i = 0; i < route->num_locations; i++) {
        Location location = route->locations[i];
        printf("%-20s%-20.2lf%-20.2lf\n", location.name, location.latitude, location.longitude);
    }
}

void search_location(Route *route) {
    if (route->num_locations == 0) {
        printf("Route is empty. Cannot search for locations.\n");
        return;
    }

    char search_name[MAX_NAME_LENGTH];
    get_location_name(search_name);

    for (int i = 0; i < route->num_locations; i++) {
        Location location = route->locations[i];
        if (strcmp(search_name, location.name) == 0) {
            printf("Location found:\n");
            printf("%-20s%-20.2lf%-20.2lf\n", location.name, location.latitude, location.longitude);
            return;
        }
    }

    printf("Location not found.\n");
}