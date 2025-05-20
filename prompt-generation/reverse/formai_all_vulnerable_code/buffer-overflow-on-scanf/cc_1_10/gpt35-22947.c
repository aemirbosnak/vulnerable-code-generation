//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159

struct location {
    float latitude;
    float longitude;
};

float calculate_distance(struct location a, struct location b) {
    float lat1 = a.latitude * PI / 180;
    float long1 = a.longitude * PI / 180;
    float lat2 = b.latitude * PI / 180;
    float long2 = b.longitude * PI / 180;

    float dlat = lat2 - lat1;
    float dlong = long2 - long1;

    float dist = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlong/2) * sin(dlong/2);
    dist = 2 * atan2(sqrt(dist), sqrt(1-dist));
    return 6371 * dist;
}

void display_location(struct location l) {
    printf("Latitude: %f, Longitude: %f\n", l.latitude, l.longitude);
}

int main() {
    struct location locations[6];

    // initialize locations
    locations[0].latitude = 40.748817;
    locations[0].longitude = -73.985428;
    locations[1].latitude = 37.774929;
    locations[1].longitude = -122.419416;
    locations[2].latitude = 34.052235;
    locations[2].longitude = -118.243683;
    locations[3].latitude = 25.761681;
    locations[3].longitude = -80.191788;
    locations[4].latitude = 51.509865;
    locations[4].longitude = -0.118092;
    locations[5].latitude = -33.868819;
    locations[5].longitude = 151.209295;

    int current_location = 0;

    while (1) {
        printf("Current location: ");
        display_location(locations[current_location]);

        printf("Choose a destination:\n");
        printf("1. New York\n");
        printf("2. San Francisco\n");
        printf("3. Los Angeles\n");
        printf("4. Miami\n");
        printf("5. London\n");
        printf("6. Sydney\n");
        printf("Enter your choice (0 to exit): ");

        int choice;
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice >= 1 && choice <= 6) {
            // calculate distance to destination
            float distance = calculate_distance(locations[current_location], locations[choice]);

            printf("Distance to destination: %.2f km\n\n", distance);

            // update current location to destination
            current_location = choice;
        } else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}