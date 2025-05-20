//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    double lat, lon;
    int speed;
    char *destination;
    struct tm current_time;
    time_t now;

    // Initialize the current time
    time(&now);
    localtime_r(&now, &current_time);

    // Print the current time
    printf("Current time: %s\n", asctime(&current_time));

    // Ask the user for their destination
    printf("Where would you like to go? ");
    scanf("%s", destination);

    // Ask the user for their current latitude and longitude
    printf("What is your current latitude? ");
    scanf("%lf", &lat);
    printf("What is your current longitude? ");
    scanf("%lf", &lon);

    // Ask the user for their current speed
    printf("What is your current speed? ");
    scanf("%d", &speed);

    // Ask the user for their preferred mode of transportation
    printf("How would you like to get there? ");
    printf("1. Car\n2. Bicycle\n3. Walking\n");
    scanf("%d", &choice);

    // Calculate the estimated time of arrival based on the user's mode of transportation
    time_t arrival_time;
    switch (choice) {
        case 1:
            arrival_time = now + ((difftime(now, mktime(&current_time)) + (60 * (lat - 37.774929) + 60 * (lon - 122.419416) + speed * 60 * 1.609344)) / speed);
            break;
        case 2:
            arrival_time = now + ((difftime(now, mktime(&current_time)) + (60 * (lat - 37.774929) + 60 * (lon - 122.419416) + speed * 60 * 1.609344) * 2) / speed);
            break;
        case 3:
            arrival_time = now + ((difftime(now, mktime(&current_time)) + (60 * (lat - 37.774929) + 60 * (lon - 122.419416) + speed * 60 * 1.609344) * 3) / speed);
            break;
        default:
            printf("Invalid mode of transportation. ");
            return 1;
    }

    // Print the estimated time of arrival
    printf("You will arrive at %s in approximately %ld seconds. ", destination, arrival_time - now);

    return 0;
}