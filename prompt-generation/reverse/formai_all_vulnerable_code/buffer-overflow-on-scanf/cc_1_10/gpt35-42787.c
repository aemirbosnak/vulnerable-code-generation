//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: protected
#include<stdio.h>
#include<string.h>

// Function to calculate distance between two points
float distance(float lat1, float long1, float lat2, float long2)
{
    float d;
    lat1 = lat1 * 3.14159 / 180.0;
    long1 = long1 * 3.14159 / 180.0;
    lat2 = lat2 * 3.14159 / 180.0;
    long2 = long2 * 3.14159 / 180.0;

    d = 3963.0 * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long2 - long1));
    return d;
}

int main()
{
    char city[20];
    printf("Enter the city name: ");
    scanf("%s", city);

    float lat[5], lon[5];
    char cities[5][20] = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};
    lat[0] = 40.7128;
    lon[0] = -74.0060;
    lat[1] = 34.0522;
    lon[1] = -118.2437;
    lat[2] = 41.8781;
    lon[2] = -87.6298;
    lat[3] = 29.7604;
    lon[3] = -95.3698;
    lat[4] = 33.4484;
    lon[4] = -112.0740;

    float d[5];
    int i, index = 0;
    for (i = 0; i < 5; i++)
    {
        d[i] = distance(lat[i], lon[i], lat[0], lon[0]);
        if (strcmp(city, cities[i]) == 0)
        {
            index = i;
        }
    }

    printf("The distance between New York and %s is %.2f miles.\n", city, d[index]);

    return 0;
}