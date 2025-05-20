//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOCATIONS 1000

typedef struct location {
    char name[50];
    double latitude;
    double longitude;
} Location;

int main() {
    Location locations[MAX_LOCATIONS];
    int num_locations = 0;
    int choice = 0;
    double current_latitude = 0;
    double current_longitude = 0;
    double distance = 0;
    int nearest_index = -1;
    int i;

    while (1) {
        printf("GPS Navigation Simulation:\n");
        printf("1. Add Location\n");
        printf("2. Show All Locations\n");
        printf("3. Find Nearest Location\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_locations >= MAX_LOCATIONS) {
                    printf("Error: Maximum Locations Reached!\n\n");
                    break;
                }

                printf("Enter Location Name: ");
                scanf("%s", locations[num_locations].name);

                printf("Enter Latitude: ");
                scanf("%lf", &locations[num_locations].latitude);

                printf("Enter Longitude: ");
                scanf("%lf", &locations[num_locations].longitude);

                num_locations++;
                printf("\n");
                break;

            case 2:
                printf("All Locations:\n\n");

                for (i = 0; i < num_locations; i++) {
                    printf("%s (%lf, %lf)\n", locations[i].name, locations[i].latitude, locations[i].longitude);
                }

                printf("\n");
                break;

            case 3:
                if (num_locations == 0) {
                    printf("Error: No Locations Found!\n\n");
                    break;
                }

                printf("Enter Current Latitude: ");
                scanf("%lf", &current_latitude);

                printf("Enter Current Longitude: ");
                scanf("%lf", &current_longitude);

                nearest_index = -1;
                distance = INFINITY;

                for (i = 0; i < num_locations; i++) {
                    double dx = current_latitude - locations[i].latitude;
                    double dy = current_longitude - locations[i].longitude;
                    double temp_distance = sqrt(dx * dx + dy * dy);

                    if (temp_distance < distance) {
                        nearest_index = i;
                        distance = temp_distance;
                    }
                }

                printf("\nNearest Location:\n");
                printf("%s (%lf, %lf)\n", locations[nearest_index].name, locations[nearest_index].latitude, locations[nearest_index].longitude);
                printf("Distance: %lf km\n\n", distance);
                break;

            case 4:
                printf("Thanks for Using GPS Navigation Simulation!\n");
                exit(0);

            default:
                printf("Error: Invalid Choice!\n\n");
                break;
        }
    }
}