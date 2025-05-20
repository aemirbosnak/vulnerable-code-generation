//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 100
#define MAX_STEPS 20

struct location {
    double longitude;
    double latitude;
};

void generate_location(struct location* loc_ptr) {
    srand(time(NULL));
    loc_ptr->longitude = (double)(rand() % 361 - 180);
    loc_ptr->latitude = (double)(rand() % 181 - 90);
}

void simulate_c_gps_navigation(struct location* locations, int num_locations, int num_steps) {
    int i, j;
    double current_longitude, current_latitude, next_longitude, next_latitude, distance;
    
    printf("Starting GPS Navigation Simulation...\n\n");
    
    // randomly generate starting location
    generate_location(&locations[0]);
    current_longitude = locations[0].longitude;
    current_latitude = locations[0].latitude;
    
    printf("Starting location: %.2f, %.2f\n", current_longitude, current_latitude);
    
    // simulate navigation
    for (i = 1; i <= num_steps; i++) {
        j = rand() % num_locations;
        next_longitude = locations[j].longitude;
        next_latitude = locations[j].latitude;
        
        // calculate distance between current and next location
        distance = sqrt(pow(next_longitude - current_longitude, 2) + pow(next_latitude - current_latitude, 2));
        
        // update current location
        current_longitude = next_longitude;
        current_latitude = next_latitude;
        
        printf("Step %d: %.2f km to location %.2f, %.2f\n", i, distance, current_longitude, current_latitude);
    }
    
    printf("\nGPS Navigation Simulation Ended.\n");
}

int main() {
    struct location locations[MAX_LOCATIONS];
    int num_locations, num_steps;
    int i;
    
    printf("Welcome to C GPS Navigation Simulation!\n\n");
    
    // ask for number of locations and steps
    printf("How many locations do you have? (maximum %d) ", MAX_LOCATIONS);
    scanf("%d", &num_locations);
    
    if (num_locations <= 0 || num_locations > MAX_LOCATIONS) {
        printf("\nError: Invalid number of locations. Program will now exit.\n");
        exit(1);
    }
    
    printf("How many steps do you want to simulate? (maximum %d) ", MAX_STEPS);
    scanf("%d", &num_steps);
    
    if (num_steps <= 0 || num_steps > MAX_STEPS) {
        printf("\nError: Invalid number of steps. Program will now exit.\n");
        exit(1);
    }
    
    // randomly generate locations
    printf("\nGenerating random locations...\n\n");
    
    for (i = 0; i < num_locations; i++) {
        generate_location(&locations[i]);
        printf("Location %d: %.2f, %.2f\n", i + 1, locations[i].longitude, locations[i].latitude);
    }
    
    printf("\n");
    
    // simulate GPS navigation
    simulate_c_gps_navigation(locations, num_locations, num_steps);
    
    return 0;
}