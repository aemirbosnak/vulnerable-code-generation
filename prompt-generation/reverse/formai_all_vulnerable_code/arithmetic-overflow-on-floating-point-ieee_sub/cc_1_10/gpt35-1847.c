//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <math.h>

// defining global variables for the distance and speed
float distance = 0.0;
float speed = 0.0;

// function to calculate the distance between two coordinates
float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    float radlat1 = M_PI * lat1 / 180.0;
    float radlat2 = M_PI * lat2 / 180.0;
    float theta = lon1 - lon2;
    float radtheta = M_PI * theta / 180.0;
    float dist = sin(radlat1) * sin(radlat2) + cos(radlat1) * cos(radlat2) * cos(radtheta);
    dist = acos(dist);
    dist = dist * 180.0 / M_PI;
    dist = dist * 60.0 * 1.1515;
    dist = dist * 1.609344; // converting to km
    return dist;
}

int main() {
    float lat1, lon1, lat2, lon2;

    // inputting the initial coordinates
    printf("Enter the initial latitude and longitude: ");
    scanf("%f%f", &lat1, &lon1);

    while (1) {
        // inputting the next set of coordinates
        printf("Enter the next latitude and longitude: ");
        scanf("%f%f", &lat2, &lon2);

        // calculating the distance and updating global variable
        distance += calculateDistance(lat1, lon1, lat2, lon2);

        // calculating the speed and updating global variable
        speed = distance / 2.0;

        // outputting the current distance and speed
        printf("Current distance travelled: %.2f km\n", distance);
        printf("Current speed: %.2f km/hour\n", speed);

        // updating the initial coordinates
        lat1 = lat2;
        lon1 = lon2;

        // checking for exit condition
        printf("Do you want to continue? (1/0)");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
    }

    return 0;
}