//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

//define the maximum size of the locations array
#define MAX_LOCATIONS 100

//create a struct for each location
struct location {
    char* name;
    float longitude;
    float latitude;
};

//declare an array of locations
struct location locations[MAX_LOCATIONS];

//declare the current location and destination
int current_location = 0;
int destination = 0;

//function to calculate the distance between two points
float calculate_distance(float lat1, float long1, float lat2, float long2) {
    float delta_lat = lat2 - lat1;
    float delta_long = long2 - long1;
    return sqrt(delta_lat*delta_lat + delta_long*delta_long);
}

//function to display the available locations
void display_locations() {
    printf("Available Locations:\n");
    for(int i = 0; i < MAX_LOCATIONS && locations[i].name != NULL; i++) {
        printf("%d. %s\n", i+1, locations[i].name);
    }
}

//function to set the current location
void set_current_location() {
    printf("Enter your current location:\n");
    display_locations();
    scanf("%d", &current_location);
    printf("Current location set to: %s\n", locations[current_location-1].name);
}

//function to set the destination
void set_destination() {
    printf("Enter your destination:\n");
    display_locations();
    scanf("%d", &destination);
    printf("Destination set to: %s\n", locations[destination-1].name);
}

//function to show the route from current location to destination
void show_route() {
    printf("Route from %s to %s:\n", locations[current_location-1].name, locations[destination-1].name);
    for(int i = current_location; i <= destination; i++) {
        if(i == current_location) {
            printf("Start at %s\n", locations[i-1].name);
        } else if(i == destination) {
            printf("Finish at %s\n", locations[i-1].name);
        } else {
            printf("Continue to %s\n", locations[i-1].name);
        }
    }
}

int main() {
    //initialize the array of locations
    locations[0].name = "Empire State Building";
    locations[0].longitude = -73.9857;
    locations[0].latitude = 40.7484;
    
    locations[1].name = "Statue of Liberty";
    locations[1].longitude = -74.0445;
    locations[1].latitude = 40.6892;
    
    locations[2].name = "Times Square";
    locations[2].longitude = -73.9855;
    locations[2].latitude = 40.7580;
    
    locations[3].name = "Central Park";
    locations[3].longitude = -73.9653;
    locations[3].latitude = 40.7829;

    //display a welcome message
    printf("Welcome to the Happy GPS Navigation Simulation!\n");

    //set the current location
    set_current_location();

    //set the destination
    set_destination();

    //show the route
    show_route();

    //calculate and display the distance between the two points
    float distance = calculate_distance(locations[current_location-1].latitude, locations[current_location-1].longitude, locations[destination-1].latitude, locations[destination-1].longitude);
    printf("Total distance: %.2f miles\n", distance);

    return 0;
}