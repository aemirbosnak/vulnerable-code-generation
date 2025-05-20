//GPT-4o-mini DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 100
#define MAX_NAME_LENGTH 50
#define MAX_WAYPOINTS 10
#define MAX_ROUTE_LENGTH 20
#define MOVEMENT_STEP 1

typedef struct {
    char name[MAX_NAME_LENGTH];
    float latitude;
    float longitude;
} Location;

typedef struct {
    Location waypoints[MAX_WAYPOINTS];
    int count;
} Route;

Location locations[MAX_LOCATIONS];
int location_count = 0;

// Function declarations
void add_location(const char *name, float latitude, float longitude);
void display_location(Location loc);
void save_routes(Route route, const char *filename);
Route load_routes(const char *filename);
float calculate_distance(Location loc1, Location loc2);
void display_route(Route route);

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    float latitude, longitude;
    Route route;
    route.count = 0;

    do {
        printf("\nGPS Navigation Simulation\n");
        printf("1. Add a Location\n");
        printf("2. Display Locations\n");
        printf("3. Create a Route\n");
        printf("4. View Route\n");
        printf("5. Save Route\n");
        printf("6. Load Route\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter location name: ");
                scanf("%s", name);
                printf("Enter latitude: ");
                scanf("%f", &latitude);
                printf("Enter longitude: ");
                scanf("%f", &longitude);
                add_location(name, latitude, longitude);
                break;

            case 2:
                for (int i = 0; i < location_count; i++) {
                    display_location(locations[i]);
                }
                break;

            case 3:
                printf("Enter number of waypoints (max %d): ", MAX_WAYPOINTS);
                scanf("%d", &route.count);
                for (int i = 0; i < route.count; i++) {
                    printf("Enter waypoint %d name: ", i + 1);
                    scanf("%s", route.waypoints[i].name);
                    for (int j = 0; j < location_count; j++) {
                        if (strcmp(route.waypoints[i].name, locations[j].name) == 0) {
                            route.waypoints[i] = locations[j];
                            break;
                        }
                    }
                }
                break;

            case 4:
                display_route(route);
                break;

            case 5:
                {
                    char filename[50];
                    printf("Enter filename to save route: ");
                    scanf("%s", filename);
                    save_routes(route, filename);
                }
                break;

            case 6:
                {
                    char filename[50];
                    printf("Enter filename to load route: ");
                    scanf("%s", filename);
                    route = load_routes(filename);
                }
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void add_location(const char *name, float latitude, float longitude) {
    if (location_count < MAX_LOCATIONS) {
        strncpy(locations[location_count].name, name, MAX_NAME_LENGTH);
        locations[location_count].latitude = latitude;
        locations[location_count].longitude = longitude;
        location_count++;
    } else {
        printf("Location limit reached. Cannot add more locations.\n");
    }
}

void display_location(Location loc) {
    printf("Location: %s, Latitude: %.6f, Longitude: %.6f\n", 
        loc.name, loc.latitude, loc.longitude);
}

void save_routes(Route route, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for saving route.\n");
        return;
    }

    fprintf(file, "%d\n", route.count);
    for (int i = 0; i < route.count; i++) {
        fprintf(file, "%s %.6f %.6f\n", route.waypoints[i].name,
                route.waypoints[i].latitude, route.waypoints[i].longitude);
    }

    fclose(file);
    printf("Route saved successfully to %s.\n", filename);
}

Route load_routes(const char *filename) {
    Route route;
    route.count = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for loading route.\n");
        return route;
    }

    fscanf(file, "%d", &route.count);
    for (int i = 0; i < route.count; i++) {
        fscanf(file, "%s %f %f", route.waypoints[i].name,
               &route.waypoints[i].latitude, 
               &route.waypoints[i].longitude);
    }
    
    fclose(file);
    printf("Route loaded successfully from %s.\n", filename);
    return route;
}

void display_route(Route route) {
    printf("Route with %d waypoints:\n", route.count);
    for (int i = 0; i < route.count; i++) {
        display_location(route.waypoints[i]);
    }
}

float calculate_distance(Location loc1, Location loc2) {
    // Placeholder function for distance calculation
    float distance = sqrt(pow(loc1.latitude - loc2.latitude, 2) + 
                           pow(loc1.longitude - loc2.longitude, 2));
    return distance;
}