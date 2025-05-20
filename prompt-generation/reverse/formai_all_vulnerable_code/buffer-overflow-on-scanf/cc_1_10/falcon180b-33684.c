//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371
#define DEG_TO_RAD 0.017453292519943295
#define RAD_TO_DEG 57.29577951308232

typedef struct {
    double lat;
    double lon;
} coordinate;

coordinate current_location;
coordinate destination;

void get_current_location()
{
    printf("Enter your current latitude and longitude (in degrees): ");
    scanf("%lf %lf", &current_location.lat, &current_location.lon);
    current_location.lat = current_location.lat * DEG_TO_RAD;
    current_location.lon = current_location.lon * DEG_TO_RAD;
}

void get_destination()
{
    printf("Enter your destination latitude and longitude (in degrees): ");
    scanf("%lf %lf", &destination.lat, &destination.lon);
    destination.lat = destination.lat * DEG_TO_RAD;
    destination.lon = destination.lon * DEG_TO_RAD;
}

double calculate_distance(coordinate point1, coordinate point2)
{
    double dlat = point2.lat - point1.lat;
    double dlon = point2.lon - point1.lon;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(point1.lat * DEG_TO_RAD) * cos(point2.lat * DEG_TO_RAD) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;
    return distance;
}

void get_time(int *hours, int *minutes, int *seconds)
{
    time_t current_time;
    time(&current_time);
    struct tm *time_info = localtime(&current_time);
    *hours = time_info->tm_hour;
    *minutes = time_info->tm_min;
    *seconds = time_info->tm_sec;
}

int main()
{
    printf("GPS Navigation System\n");
    get_current_location();
    get_destination();

    double distance = calculate_distance(current_location, destination);

    int hours, minutes, seconds;
    get_time(&hours, &minutes, &seconds);

    printf("Current time: %02d:%02d:%02d\n", hours, minutes, seconds);
    printf("Distance to destination: %.2lf km\n", distance);

    return 0;
}