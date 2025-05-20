//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    double latitude;
    double longitude;
} coordinates_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    coordinates_t coordinates;
} location_t;

int num_locations = 0;
location_t locations[MAX_LOCATIONS];

void add_location(char* name, double latitude, double longitude) {
    if (num_locations < MAX_LOCATIONS) {
        strcpy(locations[num_locations].name, name);
        locations[num_locations].coordinates.latitude = latitude;
        locations[num_locations].coordinates.longitude = longitude;
        num_locations++;
        printf("Location added successfully!\n");
    } else {
        printf("Cannot add location. Maximum number of locations reached.\n");
    }
}

void list_locations() {
    if (num_locations == 0) {
        printf("No locations added yet.\n");
    } else {
        printf("List of locations:\n");
        for (int i = 0; i < num_locations; i++) {
            printf("%d. %s (lat: %.2f | long: %.2f)\n", i+1, locations[i].name, locations[i].coordinates.latitude, locations[i].coordinates.longitude);
        }
    }
}

void navigate() {
    if (num_locations < 2) {
        printf("Not enough locations added to navigate.\n");
        return;
    }
    int start_index, end_index;
    printf("Enter starting point index:\n");
    scanf("%d", &start_index);
    start_index--;
    printf("Enter destination index:\n");
    scanf("%d", &end_index);
    end_index--;
    double start_lat = locations[start_index].coordinates.latitude;
    double start_long = locations[start_index].coordinates.longitude;
    double end_lat = locations[end_index].coordinates.latitude;
    double end_long = locations[end_index].coordinates.longitude;
    double distance = sqrt(pow(start_lat - end_lat, 2) + pow(start_long - end_long, 2));
    printf("Distance between %s and %s is %.2f km.\n", locations[start_index].name, locations[end_index].name, distance);
}

int main() {
    char name[MAX_NAME_LENGTH];
    double latitude, longitude;
    int choice;
    while (1) {
        printf("Choose an option:\n");
        printf("1. Add location\n");
        printf("2. List locations\n");
        printf("3. Navigate\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter location name:\n");
                scanf("%s", name);
                printf("Enter latitude:\n");
                scanf("%lf", &latitude);
                printf("Enter longitude:\n");
                scanf("%lf", &longitude);
                add_location(name, latitude, longitude);
                break;
            case 2:
                list_locations();
                break;
            case 3:
                navigate();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}