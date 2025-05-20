//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: genious
#include<stdio.h>
#include<math.h>

#define PI 3.14159265

int main()
{
    int option;
    double userLatitude, userLongitude, destLatitude, destLongitude, distance;
    double latDiff, longDiff, alpha, theta, x, y;

    printf("Welcome to GPS Navigation Simulation\n");
    printf("Enter your current location (in degrees): \n");
    printf("Latitude: ");
    scanf("%lf", &userLatitude);
    printf("Longitude: ");
    scanf("%lf", &userLongitude);
    printf("Enter your destination location (in degrees): \n");
    printf("Latitude: ");
    scanf("%lf", &destLatitude);
    printf("Longitude: ");
    scanf("%lf", &destLongitude);

    latDiff = (destLatitude - userLatitude) * PI / 180.0;
    longDiff = (destLongitude - userLongitude) * PI / 180.0;

    alpha = sin(latDiff / 2.0) * sin(latDiff / 2.0) + cos(userLatitude * PI / 180.0) * cos(destLatitude * PI / 180.0) * sin(longDiff / 2.0) * sin(longDiff / 2.0);
    theta = 2.0 * atan2(sqrt(alpha), sqrt(1 - alpha));
    distance = 6371.0 * theta; /* Multiplying by Earth's radius to get distance in kilometers */

    printf("Distance between the two locations is: %.2lf km\n", distance);

    printf("Please select a navigation option:\n");
    printf("1. Turn-by-turn directions\n");
    printf("2. Map view\n");
    printf("Option: ");
    scanf("%d", &option);

    if(option == 1)
    {
        printf("Here are your turn-by-turn directions:\n");
        printf("1. Head west on Main Street for 2 km.\n");
        printf("2. Turn right onto Elm Street and continue for 500 meters.\n");
        printf("3. Turn left onto Maple Avenue and continue for 1.5 km.\n");
        printf("4. Your destination will be on the right.\n");
    }
    else if(option == 2)
    {
        printf("Map view:\n");

        x = distance * 1000.0 * sin(longDiff) * cos(destLatitude * PI / 180.0);
        y = distance * 1000.0 * (cos(userLatitude * PI / 180.0) * sin(destLatitude * PI / 180.0) - sin(userLatitude * PI / 180.0) * cos(destLatitude * PI / 180.0) * cos(longDiff));

        printf("------------------------------------------\n");
        printf("|                              N         |\n");
        printf("|                              |         |\n");
        printf("|                              |         |\n");
        printf("|                     W -------+------- E|\n");
        printf("|                              |         |\n");
        printf("|                              |         |\n");
        printf("|                              S         |\n");
        printf("|                                        |\n");
        printf("|                             ( %.2lfkm )    |\n", distance);
        printf("|                                        |\n");
        printf("|                                        |\n");
        printf("------------------------------------------\n");
        printf("Current location: (%.6lf°N, %.6lf°E)\n", userLatitude, userLongitude);
        printf("Destination location: (%.6lf°N, %.6lf°E)\n", destLatitude, destLongitude);
        printf("Destination is %lf km north and %lf km east of current location.\n", y/1000.0, x/1000.0);
    }
    else
    {
        printf("Invalid option selected.\n");
    }
    return 0;
}