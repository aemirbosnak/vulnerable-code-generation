//Gemma-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

// Define GPS satellite constellation
double sat_x[4] = {122.56, -63.22, 35.70, -10.11};
double sat_y[4] = {63.22, 122.56, -10.11, 35.70};
double sat_z[4] = {10.11, -35.70, 63.22, 122.56};

// Define user's current position
double user_x = 0.0;
double user_y = 0.0;
double user_z = 0.0;

// Calculate distance to each satellite
double dist[4];

// Calculate time delay for each satellite
double delay[4];

// Display navigation information
void display_nav()
{
    int i;

    printf("Current position: %.2f, %.2f, %.2f\n", user_x, user_y, user_z);

    for (i = 0; i < 4; i++)
    {
        printf("Satellite %d: distance %.2f, delay %.2f seconds\n", i + 1, dist[i], delay[i]);
    }

    printf("\n");
}

int main()
{
    int i;

    // Calculate distance and time delay for each satellite
    for (i = 0; i < 4; i++)
    {
        dist[i] = sqrt(pow(sat_x[i] - user_x, 2) + pow(sat_y[i] - user_y, 2) + pow(sat_z[i] - user_z, 2));
        delay[i] = dist[i] / 299792.458;
    }

    // Display navigation information
    display_nav();

    return 0;
}