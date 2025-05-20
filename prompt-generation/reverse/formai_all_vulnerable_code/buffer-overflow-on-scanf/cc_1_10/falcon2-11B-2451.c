//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: optimized
#include<stdio.h>
#include<string.h>

int main()
{
    char destination[20];
    int distance = 0;

    printf("Enter destination: ");
    scanf("%s", destination);

    distance = getDistance(destination);

    printf("The distance from your current location to %s is %d miles\n", destination, distance);

    return 0;
}


int getDistance(char* destination)
{
    int distance = 0;
    int latitude = 0;
    int longitude = 0;

    char* lat_str = "38.8957";
    char* long_str = "-77.0365";

    int latitude_tmp = atoi(lat_str);
    int longitude_tmp = atoi(long_str);

    if(strcmp(destination, lat_str) == 0)
    {
        latitude = latitude_tmp;
        longitude = longitude_tmp;
    }
    else if(strcmp(destination, long_str) == 0)
    {
        latitude = latitude_tmp;
        longitude = longitude_tmp;
    }
    else
    {
        printf("Invalid destination.\n");
        return -1;
    }

    double delta_lat = latitude - latitude_tmp;
    double delta_lon = longitude - longitude_tmp;

    distance = 0.621371 * (delta_lat * delta_lat + delta_lon * delta_lon);

    return distance;
}