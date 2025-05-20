//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_LOCATIONS 5

struct location {
    char name[50];
    double latitude;
    double longitude;
};

void print_location(struct location* loc) {
    printf("Name: %s\n", loc->name);
    printf("Latitude: %lf\n", loc->latitude);
    printf("Longitude: %lf\n", loc->longitude);
}

int main() {
    struct location locations[NUM_LOCATIONS];
    int i, choice;
    double distance;

    srand(time(NULL));
    for (i = 0; i < NUM_LOCATIONS; i++) {
        locations[i].latitude = rand() % 90 - 45;
        locations[i].longitude = rand() % 180 - 90;
        sprintf(locations[i].name, "Location %d", i+1);
    }

    while (1) {
        printf("GPS Navigation Simulation\n");
        printf("1. Enter current location\n");
        printf("2. Get directions to a location\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter current latitude: ");
            scanf("%lf", &locations[0].latitude);
            printf("Enter current longitude: ");
            scanf("%lf", &locations[0].longitude);
            break;
        case 2:
            printf("Enter destination location number: ");
            scanf("%d", &i);
            distance = hypot(locations[0].latitude - locations[i].latitude,
                             locations[0].longitude - locations[i].longitude);
            printf("Distance to destination: %lf\n", distance);
            print_location(&locations[i]);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}