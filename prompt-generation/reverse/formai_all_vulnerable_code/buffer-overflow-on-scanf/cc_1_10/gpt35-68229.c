//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOCATIONS 3
#define EARTH_RADIUS 6371 //in km

// Structure to store location data
typedef struct {
    char name[20];
    double latitude;
    double longitude;
} location;

// Function to calculate distance between two locations using Haversine formula
double distance(double lat1, double lon1, double lat2, double lon2)
{
    double dlat = (lat2 - lat1) * 3.141592 / 180;
    double dlon = (lon2 - lon1) * 3.141592 / 180;
    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1 * 3.141592 / 180) * cos(lat2 * 3.141592 / 180) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double d = EARTH_RADIUS * c;
    return d;
}

int main()
{
    location locations[MAX_LOCATIONS] = {
        {"New York", 40.7128, -74.0060},
        {"London", 51.5072, -0.1276},
        {"Tokyo", 35.6895, 139.6917}
    };
    int i, j;
    double lat, lon, d, min_d;
    char dest[20];

    printf("GPS Navigation Simulation\n");
    printf("-------------------------\n");
    printf("Current location:\n");
    printf("Latitude: ");
    scanf("%lf", &lat);
    printf("Longitude: ");
    scanf("%lf", &lon);

    printf("Locations:\n");
    for(i=0; i<MAX_LOCATIONS; i++)
        printf("%d. %s (%.4lf, %.4lf)\n", i+1, locations[i].name, locations[i].latitude, locations[i].longitude);

    printf("Enter destination: ");
    scanf("%s", dest);

    // Find the location with minimum distance to the destination
    min_d = distance(lat, lon, locations[0].latitude, locations[0].longitude);
    j = 0;
    for(i=1; i<MAX_LOCATIONS; i++)
    {
        d = distance(lat, lon, locations[i].latitude, locations[i].longitude);
        if(d < min_d)
        {
            min_d = d;
            j = i;
        }
    }

    printf("Nearest location to your current location is %s\n", locations[j].name);

    // Find the location of the destination
    for(i=0; i<MAX_LOCATIONS; i++)
    {
        if(strcmp(dest, locations[i].name) == 0)
        {
            printf("Destination is %s (%.4lf, %.4lf)\n", locations[i].name, locations[i].latitude, locations[i].longitude);
            break;
        }
    }
    
    // Calculate the distance to the destination
    d = distance(locations[j].latitude, locations[j].longitude, locations[i].latitude, locations[i].longitude);
    printf("Distance to the destination: %.2lf km\n", d);
    
    return 0;
}