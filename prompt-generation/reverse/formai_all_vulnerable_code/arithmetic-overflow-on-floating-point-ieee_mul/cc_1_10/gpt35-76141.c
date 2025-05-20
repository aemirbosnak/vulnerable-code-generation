//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float latitude;
    float longitude;
} location;

float calc_distance(location loc1, location loc2) {
    float lat_dist = loc1.latitude - loc2.latitude;
    float long_dist = loc1.longitude - loc2.longitude;
    return sqrt(lat_dist*lat_dist + long_dist*long_dist);
}

int main() {
    srand(time(NULL));

    location destinations[] = {
        {22.3193, 87.3038},
        {19.0760, 72.8777},
        {51.5074, 0.1278},
        {48.8566, 2.3522},
        {35.6895, 139.6917},
        {40.7128, -74.0059},
    };
    int num_destinations = sizeof(destinations)/sizeof(location);

    printf("Welcome! Please input your current location (latitude, longitude):\n");
    location current_location;
    scanf("%f, %f", &current_location.latitude, &current_location.longitude);

    int current_destination_index = rand() % num_destinations;
    location current_destination = destinations[current_destination_index];

    printf("Your current destination is (%.4f, %.4f)\n", current_destination.latitude, current_destination.longitude);

    float total_distance = 0;
    while (1) {
        printf("Please input your current location (latitude, longitude):\n");
        location new_location;
        scanf("%f, %f", &new_location.latitude, &new_location.longitude);

        float distance_to_destination = calc_distance(new_location, current_destination);
        total_distance += distance_to_destination;

        if (distance_to_destination < 0.1) {
            printf("Congratulations! You have reached your destination!\n");
            printf("Total distance travelled: %.2f kms\n", total_distance);
            break;
        }

        printf("Distance to destination: %.2f kms\n", distance_to_destination);

        if (rand()%2 == 0) {
            current_destination_index = (current_destination_index + 1)%num_destinations;
            current_destination = destinations[current_destination_index];
            printf("Your current destination has changed! New destination is (%.4f, %.4f)\n", current_destination.latitude, current_destination.longitude);
        }
    }

    return 0;
}