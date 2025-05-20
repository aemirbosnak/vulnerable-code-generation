//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LOCATIONS 10

/* Define a struct to hold a GPS location */
typedef struct {
    double latitude;
    double longitude;
} Location;

/* Define a function to calculate the distance between two locations */
double distance(Location a, Location b) {
    double lat1 = a.latitude * M_PI / 180;
    double lat2 = b.latitude * M_PI / 180;
    double lon1 = a.longitude * M_PI / 180;
    double lon2 = b.longitude * M_PI / 180;

    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double hav = sin(dlat/2) * sin(dlat/2) +
                 cos(lat1) * cos(lat2) *
                 sin(dlon/2) * sin(dlon/2);

    double d = 2 * atan2(sqrt(hav), sqrt(1 - hav));

    return d * 6371; /* Earth's radius in km */
}

/* Define a function to find the closest location to a given location */
int closest(Location loc, Location locations[], int num_locations) {
    int index = 0;
    double min_dist = distance(loc, locations[0]);

    for (int i = 1; i < num_locations; i++) {
        double dist = distance(loc, locations[i]);
        if (dist < min_dist) {
            index = i;
            min_dist = dist;
        }
    }

    return index;
}

int main() {
    /* Define some sample locations */
    Location home = { 40.7589, -73.9851 };
    Location work = { 40.7127, -74.0060 };
    Location gym = { 40.7433, -73.9846 };
    Location park = { 40.7829, -73.9654 };
    Location store = { 40.7215, -74.0046 };
    Location library = { 40.7641, -73.9835 };
    Location museum = { 40.7794, -73.9632 };
    Location theater = { 40.7589, -73.9851 };
    Location restaurant = { 40.7230, -74.0064 };
    Location bar = { 40.7259, -74.0037 };

    /* Put all the locations in an array */
    Location locations[MAX_LOCATIONS] = { home, work, gym, park, store,
                                           library, museum, theater,
                                           restaurant, bar };

    /* Ask the user for their current location */
    Location current;
    printf("Enter your current latitude and longitude (separated by a space): ");
    scanf("%lf %lf", &current.latitude, &current.longitude);

    /* Find the closest location to the user */
    int closest_index = closest(current, locations, MAX_LOCATIONS);
    Location closest_location = locations[closest_index];

    /* Print the name of the closest location */
    if (closest_index == 0) {
        printf("You are at home!\n");
    } else if (closest_index == 1) {
        printf("You are at work!\n");
    } else if (closest_index == 2) {
        printf("You are at the gym!\n");
    } else if (closest_index == 3) {
        printf("You are at the park!\n");
    } else if (closest_index == 4) {
        printf("You are at the store!\n");
    } else if (closest_index == 5) {
        printf("You are at the library!\n");
    } else if (closest_index == 6) {
        printf("You are at the museum!\n");
    } else if (closest_index == 7) {
        printf("You are at the theater!\n");
    } else if (closest_index == 8) {
        printf("You are at the restaurant!\n");
    } else if (closest_index == 9) {
        printf("You are at the bar!\n");
    }

    /* Ask the user where they want to go */
    printf("Where would you like to go? (enter the name of a location): ");
    char destination[20];
    scanf("%s", destination);

    /* Find the location of the user's destination */
    Location dest;
    if (strcmp(destination, "home") == 0) {
        dest = home;
    } else if (strcmp(destination, "work") == 0) {
        dest = work;
    } else if (strcmp(destination, "gym") == 0) {
        dest = gym;
    } else if (strcmp(destination, "park") == 0) {
        dest = park;
    } else if (strcmp(destination, "store") == 0) {
        dest = store;
    } else if (strcmp(destination, "library") == 0) {
        dest = library;
    } else if (strcmp(destination, "museum") == 0) {
        dest = museum;
    } else if (strcmp(destination, "theater") == 0) {
        dest = theater;
    } else if (strcmp(destination, "restaurant") == 0) {
        dest = restaurant;
    } else if (strcmp(destination, "bar") == 0) {
        dest = bar;
    }

    /* Calculate the distance between the user's current location and their destination */
    double d = distance(current, dest);
    printf("Your destination is %.2lf km away.\n", d);

    return 0;
}