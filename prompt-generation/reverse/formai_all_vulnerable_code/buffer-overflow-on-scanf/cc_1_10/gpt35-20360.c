//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RAD_TO_DEG 57.2957795130823208768
#define MAX_LOCATIONS 10

struct location {
    char name[50];
    double latitude;
    double longitude;
};

void print_menu() {
    printf("=====================================\n");
    printf("            GPS Navigation           \n");
    printf("=====================================\n");
    printf("\n");
    printf("1 - Add a new location\n");
    printf("2 - Show all locations\n");
    printf("3 - Get directions to a location\n");
    printf("4 - Exit\n");
    printf("\n");
    printf("Choose an option: ");
}

double deg_to_rad(double deg) {
    return deg / RAD_TO_DEG;
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = deg_to_rad(lat2 - lat1);
    double dlon = deg_to_rad(lon2 - lon1);

    double a = sin(dlat/2) * sin(dlat/2) + cos(deg_to_rad(lat1)) * cos(deg_to_rad(lat2)) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = 6371 * c; // Earth's radius

    return d;
}

int main() {
    int choice;
    int num_locations = 0;
    struct location locations[MAX_LOCATIONS];

    do {
        print_menu();
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (num_locations >= MAX_LOCATIONS) {
                    printf("Maximum number of locations reached.\n");
                    break;
                }

                printf("Name: ");
                scanf("%s", locations[num_locations].name);

                printf("Latitude: ");
                scanf("%lf", &locations[num_locations].latitude);

                printf("Longitude: ");
                scanf("%lf", &locations[num_locations].longitude);

                num_locations++;

                printf("Location added successfully.\n");
                break;
            case 2:
                if (num_locations == 0) {
                    printf("No locations found.\n");
                    break;
                }

                printf("Name\t\tLatitude\tLongitude\n");
                printf("------------------------------------------------\n");

                for (int i = 0; i < num_locations; i++) {
                    printf("%s\t\t%lf\t%lf\n", locations[i].name, locations[i].latitude, locations[i].longitude);
                }

                printf("------------------------------------------------\n");
                break;
            case 3: {
                if (num_locations == 0) {
                    printf("No locations found.\n");
                    break;
                }

                char start_location[50];
                char end_location[50];

                printf("Starting location: ");
                scanf("%s", start_location);

                printf("Ending location: ");
                scanf("%s", end_location);

                double start_lat, start_lon, end_lat, end_lon;
                int start_found = 0, end_found = 0;

                for (int i = 0; i < num_locations; i++) {
                    if (strcmp(locations[i].name, start_location) == 0) {
                        start_lat = locations[i].latitude;
                        start_lon = locations[i].longitude;
                        start_found = 1;
                    }

                    if (strcmp(locations[i].name, end_location) == 0) {
                        end_lat = locations[i].latitude;
                        end_lon = locations[i].longitude;
                        end_found = 1;
                    }
                }

                if (!start_found) {
                    printf("Starting location \"%s\" not found.\n", start_location);
                    break;
                }

                if (!end_found) {
                    printf("Ending location \"%s\" not found.\n", end_location);
                    break;
                }

                double d = distance(start_lat, start_lon, end_lat, end_lon);

                printf("\nDirections from %s to %s:\n", start_location, end_location);
                printf("------------------------------------------------\n");
                printf("Distance: %.2lf km\n", d);
                printf("Direction: ");

                if (end_lon >= start_lon) {
                    double angle = atan2(end_lat - start_lat, end_lon - start_lon) * RAD_TO_DEG;
                    printf("%.0lf degrees east of north\n", angle);
                } else {
                    double angle = atan2(end_lat - start_lat, start_lon - end_lon) * RAD_TO_DEG;
                    printf("%.0lf degrees west of north\n", angle);
                }

                printf("------------------------------------------------\n");
                break;
            }
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}