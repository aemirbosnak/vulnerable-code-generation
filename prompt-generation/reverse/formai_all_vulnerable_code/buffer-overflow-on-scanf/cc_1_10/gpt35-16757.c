//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    float latitude = 0.0;
    float longitude = 0.0;
    int direction = 0;
    int distance = 0;
    int choice = 0;

    printf("Welcome to GPS Navigation Simulation\n\n");

    while (1)
    {
        printf("Choose an option:\n");
        printf("1. Generate random GPS coordinates\n");
        printf("2. Calculate distance and direction between two GPS coordinates\n");
        printf("3. Exit program\n\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                latitude = ((float) rand() / RAND_MAX) * 90.0;
                longitude = ((float) rand() / RAND_MAX) * 180.0;
                printf("Generated GPS coordinates:\n");
                printf("Latitude: %f\n", latitude);
                printf("Longitude: %f\n\n", longitude);
                break;
            }

            case 2:
            {
                float dest_latitude = 0.0;
                float dest_longitude = 0.0;
                float pi = 3.14159265358979323846;
                float earth_radius = 6371.0;
                float lat1 = latitude * pi / 180.0;
                float lon1 = longitude * pi / 180.0;

                printf("Enter destination GPS coordinates:\n");
                printf("Latitude: ");
                scanf("%f", &dest_latitude);
                printf("Longitude: ");
                scanf("%f", &dest_longitude);

                float lat2 = dest_latitude * pi / 180.0;
                float lon2 = dest_longitude * pi / 180.0;

                float dLat = lat2 - lat1;
                float dLon = lon2 - lon1;
                float a = sin(dLat/2) * sin(dLat/2) + cos(lat1) * cos(lat2) * sin(dLon/2) * sin(dLon/2);
                float c = 2 * atan2(sqrt(a), sqrt(1-a));
                distance = earth_radius * c;

                float y = sin(dLon) * cos(lat2);
                float x = cos(lat1)*sin(lat2) - sin(lat1)*cos(lat2)*cos(dLon);
                direction = (int)(atan2(y, x) * 180.0 / pi);

                printf("Distance to destination: %d km\n", distance);
                printf("Direction to destination: %d degrees\n\n", direction);
                break;
            }

            case 3:
            {
                printf("Exiting GPS Navigation Simulation\n");
                return 0;
            }

            default:
            {
                printf("Invalid choice, please try again\n\n");
                break;
            }
        }
    }
}