//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function to convert decimal degrees to radians
double deg2rad(double degrees)
{
    return degrees * M_PI / 180;
}

// Function to convert radians to decimal degrees
double rad2deg(double radians)
{
    return radians * 180 / M_PI;
}

// Function to convert latitude and longitude to their respective radians
void convertCoords(double *latitude, double *longitude)
{
    double lat_radians = deg2rad(*latitude);
    double long_radians = deg2rad(*longitude);

    *latitude = lat_radians;
    *longitude = long_radians;
}

// Function to convert radians to latitude and longitude
void convertCoordsBack(double *latitude, double *longitude)
{
    double lat_degrees = rad2deg(*latitude);
    double long_degrees = rad2deg(*longitude);

    *latitude = lat_degrees;
    *longitude = long_degrees;
}

// Function to calculate the distance between two points in kilometers
double distance(double lat1, double long1, double lat2, double long2)
{
    double radius = 6371; // Radius of the Earth in kilometers

    double dLat = rad2deg(lat2 - lat1);
    double dLong = rad2deg(long2 - long1);
    double a = sin(dLat / 2) * sin(dLat / 2) +
            cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
            sin(dLong / 2) * sin(dLong / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = radius * c;

    return distance;
}

// Function to calculate the bearing between two points in degrees
double bearing(double lat1, double long1, double lat2, double long2)
{
    double radius = 6371; // Radius of the Earth in kilometers

    double dLat = rad2deg(lat2 - lat1);
    double dLong = rad2deg(long2 - long1);
    double lat1_radians = deg2rad(lat1);
    double lat2_radians = deg2rad(lat2);
    double dLon = rad2deg(long2 - long1);
    double y = sin(dLat) * cos(lat1_radians);
    double x = cos(deg2rad(lat1)) * sin(lat2_radians) -
            sin(deg2rad(lat1)) * cos(lat2_radians) *
            cos(dLon);
    double bearing = atan2(y, x) * 180 / M_PI;

    if (bearing < 0)
        bearing += 360;

    return bearing;
}

// Function to calculate the distance between two points in meters
double distanceMeters(double lat1, double long1, double lat2, double long2)
{
    double radius = 6371; // Radius of the Earth in kilometers

    double dLat = rad2deg(lat2 - lat1);
    double dLong = rad2deg(long2 - long1);
    double a = sin(dLat / 2) * sin(dLat / 2) +
            cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
            sin(dLong / 2) * sin(dLong / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = radius * c * 1000;

    return distance;
}

// Function to calculate the bearing between two points in degrees
double bearingMeters(double lat1, double long1, double lat2, double long2)
{
    double radius = 6371; // Radius of the Earth in kilometers

    double dLat = rad2deg(lat2 - lat1);
    double dLong = rad2deg(long2 - long1);
    double lat1_radians = deg2rad(lat1);
    double lat2_radians = deg2rad(lat2);
    double dLon = rad2deg(long2 - long1);
    double y = sin(dLat) * cos(lat1_radians);
    double x = cos(deg2rad(lat1)) * sin(lat2_radians) -
            sin(deg2rad(lat1)) * cos(lat2_radians) *
            cos(dLon);
    double bearing = atan2(y, x) * 180 / M_PI;

    if (bearing < 0)
        bearing += 360;

    return bearing;
}

int main()
{
    double latitude, longitude;
    printf("Enter latitude: ");
    scanf("%lf", &latitude);
    printf("Enter longitude: ");
    scanf("%lf", &longitude);

    double latitude_rad, longitude_rad;
    convertCoords(&latitude_rad, &longitude_rad);

    printf("Latitude: %.4lf\n", latitude_rad);
    printf("Longitude: %.4lf\n", longitude_rad);

    printf("Distance in km: %.2lf\n", distance(latitude, longitude, 50.12345, 10.67890));
    printf("Bearing in degrees: %.2lf\n", bearing(latitude, longitude, 50.12345, 10.67890));
    printf("Distance in meters: %.2lf\n", distanceMeters(latitude, longitude, 50.12345, 10.67890));
    printf("Bearing in meters: %.2lf\n", bearingMeters(latitude, longitude, 50.12345, 10.67890));

    convertCoordsBack(&latitude, &longitude);
    printf("Latitude: %.4lf\n", latitude);
    printf("Longitude: %.4lf\n", longitude);

    return 0;
}