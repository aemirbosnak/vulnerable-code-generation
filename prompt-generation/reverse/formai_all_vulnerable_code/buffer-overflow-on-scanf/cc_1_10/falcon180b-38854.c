//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOCATIONS 100
#define MIN_DISTANCE 1
#define MAX_DISTANCE 100

typedef struct {
    int x;
    int y;
    int distance;
} Location;

Location locations[MAX_LOCATIONS];
int num_locations;

void generate_random_locations() {
    srand(time(NULL));
    num_locations = rand() % MAX_LOCATIONS + 1;
    for (int i = 0; i < num_locations; i++) {
        locations[i].x = rand() % 100 + 1;
        locations[i].y = rand() % 100 + 1;
        locations[i].distance = rand() % (MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
    }
}

void print_locations() {
    printf("Locations:\n");
    for (int i = 0; i < num_locations; i++) {
        printf("%d: (%d, %d) - Distance: %d\n", i + 1, locations[i].x, locations[i].y, locations[i].distance);
    }
}

int main() {
    generate_random_locations();
    print_locations();

    int start_location;
    printf("Enter the starting location (1-%d): ", num_locations);
    scanf("%d", &start_location);

    int shortest_distance = MAX_DISTANCE;
    int shortest_index = -1;

    for (int i = 0; i < num_locations; i++) {
        if (locations[i].distance < shortest_distance) {
            shortest_distance = locations[i].distance;
            shortest_index = i;
        }
    }

    printf("The shortest distance is from location %d to location %d (distance: %d)\n", start_location, shortest_index + 1, shortest_distance);

    return 0;
}