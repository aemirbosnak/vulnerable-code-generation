//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

// Function to calculate distance between two points on earth
double distance(double lon1, double lat1, double lon2, double lat2)
{
    double dlon, dlat, a, c, dist;

    // Convert to radians
    lon1 = lon1 * PI / 180.0;
    lat1 = lat1 * PI / 180.0;
    lon2 = lon2 * PI / 180.0;
    lat2 = lat2 * PI / 180.0;

    // Calculate distance between two points
    dlon = lon2 - lon1;
    dlat = lat2 - lat1;
    a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    dist = 6371 * c;

    return dist;
}

int main()
{
    double lon1, lat1, lon2, lat2, d;
    int choice;

    // User inputs starting and ending coordinates
    printf("Enter starting position (longitude, latitude):\n");
    scanf("%lf %lf", &lon1, &lat1);
    printf("Enter ending position (longitude, latitude):\n");
    scanf("%lf %lf", &lon2, &lat2);

    // Calculate distance and display to user
    d = distance(lon1, lat1, lon2, lat2);
    printf("Distance between coordinates: %.2f km\n", d);

    // Display menu for user to choose navigation option
    printf("Choose navigation option:\n");
    printf("1. Turn left\n");
    printf("2. Turn right\n");
    printf("3. Go straight\n");

    // Get user choice
    scanf("%d", &choice);

    // Display navigation information based on user choice
    switch (choice)
    {
        case 1:
            printf("Turn left in 100 meters.\n");
            break;
        case 2:
            printf("Turn right in 100 meters.\n");
            break;
        case 3:
            printf("Go straight for %.2f km.\n", d);
            break;
        default:
            printf("Invalid choice.");
    }

    return 0;
}