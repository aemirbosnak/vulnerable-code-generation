//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAYPOINTS 100

typedef struct {
    char name[20];
    double lat;
    double lon;
} Waypoint;

int main() {
    Waypoint waypoints[MAX_WAYPOINTS];
    int num_waypoints = 0;

    printf("Welcome! This program simulates GPS navigation.\n");
    
    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("1. Add a waypoint\n");
        printf("2. List waypoints\n");
        printf("3. Navigate\n");
        printf("4. Exit\n> ");
        char input[10];
        fgets(input, 10, stdin);

        if (strncmp(input, "1", 1) == 0) {
            if (num_waypoints >= MAX_WAYPOINTS) {
                printf("Maximum number of waypoints exceeded.\n");
            } else {
                printf("Enter waypoint name: ");
                fgets(waypoints[num_waypoints].name, 20, stdin);
                printf("Enter latitude: ");
                scanf("%lf", &waypoints[num_waypoints].lat);
                printf("Enter longitude: ");
                scanf("%lf", &waypoints[num_waypoints].lon);
                getchar(); // consume the newline character
                num_waypoints++;
                printf("Waypoint added.\n");
            }
        } else if (strncmp(input, "2", 1) == 0) {
            printf("Waypoints:\n");
            for (int i = 0; i < num_waypoints; i++) {
                printf("%d. %s (%lf, %lf)\n", i + 1, waypoints[i].name,
                waypoints[i].lat, waypoints[i].lon);
            }
        } else if (strncmp(input, "3", 1) == 0) {
            if (num_waypoints == 0) {
                printf("No waypoints have been added.\n");
            } else {
                printf("Enter current latitude: ");
                double curr_lat;
                scanf("%lf", &curr_lat);
                printf("Enter current longitude: ");
                double curr_lon;
                scanf("%lf", &curr_lon);
                double min_dist = -1;
                int min_idx = -1;
                for (int i = 0; i < num_waypoints; i++) {
                    double dist = sqrt(pow(curr_lat - waypoints[i].lat, 2)
                     + pow(curr_lon - waypoints[i].lon, 2));
                    if (min_dist == -1 || dist < min_dist) {
                        min_dist = dist;
                        min_idx = i;
                    }
                }
                
                char dir_lat = waypoints[min_idx].lat > curr_lat ? 'N' : 'S';
                char dir_lon = waypoints[min_idx].lon > curr_lon ? 'E' : 'W';
                printf("Next waypoint is %s. Travel %lf km %c and %lf km %c.\n",
                 waypoints[min_idx].name, fabs(curr_lat - waypoints[min_idx].lat),
                 dir_lat, fabs(curr_lon - waypoints[min_idx].lon), dir_lon);
            }
        } else if (strncmp(input, "4", 1) == 0) {
            printf("Goodbye!\n");
            exit(0);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}