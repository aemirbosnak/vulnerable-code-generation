//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the Earth's radius in kilometers
#define EARTH_RADIUS 6371.0

// Define the maximum speed in kilometers per hour
#define MAX_SPEED 120.0

// Define the maximum acceleration in kilometers per hour per second
#define MAX_ACCELERATION 10.0

// Define the maximum deceleration in kilometers per hour per second
#define MAX_DECELERATION 10.0

// Define the time step in seconds
#define TIME_STEP 2.0

// Define the number of points in the trajectory
#define NUM_POINTS 500

// Define the structure of a GPS point
typedef struct {
    double latitude;
    double longitude;
    double altitude;
} GPSPoint;

// Define the function to calculate the distance between two GPS points
double distance(GPSPoint point1, GPSPoint point2)
{
    // Convert the latitudes and longitudes to radians
    double lat1 = point1.latitude * M_PI / 180.0;
    double lon1 = point1.longitude * M_PI / 180.0;
    double lat2 = point2.latitude * M_PI / 180.0;
    double lon2 = point2.longitude * M_PI / 180.0;

    // Calculate the distance between the two points
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

// Define the function to generate a GPS trajectory
void generate_trajectory(GPSPoint points[], int num_points)
{
    // Set the initial position of the GPS receiver
    points[0].latitude = 52.375929;
    points[0].longitude = -1.229639;
    points[0].altitude = 0.0;

    // Set the initial speed of the GPS receiver
    double speed = 0.0;

    // Set the initial acceleration of the GPS receiver
    double acceleration = 0.0;

    // Set the initial deceleration of the GPS receiver
    double deceleration = 0.0;

    // Loop through the points in the trajectory
    for (int i = 1; i < num_points; i++)
    {
        // Calculate the distance between the current point and the previous point
        double distance_to_previous_point = distance(points[i - 1], points[i]);

        // Calculate the time it takes to travel the distance between the current point and the previous point
        double time_to_previous_point = distance_to_previous_point / speed;

        // Calculate the acceleration required to reach the current speed from the previous speed
        acceleration = (speed - speed) / time_to_previous_point;

        // Calculate the deceleration required to reach the current speed from the previous speed
        deceleration = (speed - speed) / time_to_previous_point;

        // Limit the acceleration and deceleration to the maximum values
        if (acceleration > MAX_ACCELERATION)
        {
            acceleration = MAX_ACCELERATION;
        }
        if (deceleration < MAX_DECELERATION)
        {
            deceleration = MAX_DECELERATION;
        }

        // Update the speed of the GPS receiver
        speed += acceleration * TIME_STEP;

        // Update the position of the GPS receiver
        points[i].latitude = points[i - 1].latitude + speed * cos(points[i - 1].latitude) * TIME_STEP;
        points[i].longitude = points[i - 1].longitude + speed * sin(points[i - 1].latitude) / cos(points[i - 1].latitude) * TIME_STEP;

        // Update the altitude of the GPS receiver
        points[i].altitude = points[i - 1].altitude + 0.0;
    }
}

// Define the main function
int main()
{
    // Create an array of GPS points to store the trajectory
    GPSPoint points[NUM_POINTS];

    // Generate the GPS trajectory
    generate_trajectory(points, NUM_POINTS);

    // Print the GPS trajectory to a file
    FILE *fp = fopen("gps_trajectory.txt", "w");
    for (int i = 0; i < NUM_POINTS; i++)
    {
        fprintf(fp, "%f,%f,%f\n", points[i].latitude, points[i].longitude, points[i].altitude);
    }
    fclose(fp);

    return 0;
}