//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define EARTH_RADIUS 6371 // in km

struct coordinate {
    double lat; // latitude
    double lon; // longitude
};

double deg_to_rad(double degrees) {
    return degrees * M_PI / 180.0;
}

double calc_distance(struct coordinate coord1, struct coordinate coord2) {
    double lat_rad1 = deg_to_rad(coord1.lat);
    double lat_rad2 = deg_to_rad(coord2.lat);
    double lon_rad1 = deg_to_rad(coord1.lon);
    double lon_rad2 = deg_to_rad(coord2.lon);

    double delta_lat = lat_rad2 - lat_rad1;
    double delta_lon = lon_rad2 - lon_rad1;

    double a = sin(delta_lat/2) * sin(delta_lat/2) + cos(lat_rad1) * cos(lat_rad2) * sin(delta_lon/2) * sin(delta_lon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double distance = EARTH_RADIUS * c;
    
    return distance;
}

int main() {
    struct coordinate coords[3] = {
        {51.5074, -0.1278},
        {40.7128, -74.0060},
        {-33.8651, 151.2099}
    };
    int num_coords = sizeof(coords)/sizeof(coords[0]);

    printf("Welcome to GPS Navigation Simulator!\n");
    printf("Enter a destination coordinate (in lat,lon): ");
    double dest_lat, dest_lon;
    scanf("%lf,%lf", &dest_lat, &dest_lon);
    struct coordinate dest_coord = {dest_lat, dest_lon};
    
    bool destination_reached = false;
    double total_distance = 0;

    while (!destination_reached) {
        double shortest_dist = INFINITY;
        int closest_coord_index;
        for (int i = 0; i < num_coords; i++) {
            double dist = calc_distance(coords[i], dest_coord);
            if (dist < shortest_dist) {
                shortest_dist = dist;
                closest_coord_index = i;
            }
        }

        printf("Next closest coordinate: (%lf,%lf)\n", coords[closest_coord_index].lat, coords[closest_coord_index].lon);

        double dist_to_next_coord = calc_distance(coords[closest_coord_index], dest_coord);
        printf("Distance to next coordinate: %lf km\n", dist_to_next_coord);

        total_distance += dist_to_next_coord;
        printf("Total distance traveled: %lf km\n", total_distance);
        
        if (closest_coord_index == 0) {
            printf("You have reached your destination!\n");
            destination_reached = true;
        } else {
            printf("Do you want to continue to navigate to the next closest coordinate? (y/n): ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'y') {
                struct coordinate new_coords[num_coords-1];
                int j = 0;
                for (int i = 0; i < num_coords; i++) {
                    if (i != closest_coord_index) {
                        new_coords[j] = coords[i];
                        j++;
                    }
                }
                for (int i = 0; i < num_coords-1; i++) {
                    coords[i] = new_coords[i];
                }
                num_coords--;
            } else {
                printf("Exiting GPS Navigation Simulator.\n");
                destination_reached = true;
            }
        }
    }

    return 0;
}