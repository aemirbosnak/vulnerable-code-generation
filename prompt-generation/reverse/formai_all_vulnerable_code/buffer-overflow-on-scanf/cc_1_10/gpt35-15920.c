//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

// Structure to hold planet data
struct planet 
{
    char name[20];
    double x, y, z;
    double mass;
    double velX, velY, velZ;
    double accX, accY, accZ;
};

// Function to calculate the distance between two planets
double distance(struct planet p1, struct planet p2)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

int main(int argc, char const *argv[]) 
{
    struct planet planets[MAX];
    int numOfPlanets, timeSteps;
    double timeInterval, gravConstant;
    printf("Enter the number of planets: ");
    scanf("%d", &numOfPlanets);

    printf("Enter the time interval: ");
    scanf("%lf", &timeInterval);

    printf("Enter the number of time steps: ");
    scanf("%d", &timeSteps);

    printf("Enter the gravity constant: ");
    scanf("%lf", &gravConstant);

    // Loop to read planet details
    for (int i=0; i<numOfPlanets; i++) 
    {
        printf("Enter planet %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", planets[i].name);
        printf("Position (x,y,z): ");
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
        printf("Mass: ");
        scanf("%lf", &planets[i].mass);
        printf("Velocity (x,y,z): ");
        scanf("%lf %lf %lf", &planets[i].velX, &planets[i].velY, &planets[i].velZ);
    }

    // Simulation loop
    for (int t=0; t<timeSteps; t++) 
    {
        // Loop to calculate planet acceleration and update velocity and position
        for (int i=0; i<numOfPlanets; i++) 
        {
            planets[i].accX = 0;
            planets[i].accY = 0;
            planets[i].accZ = 0;
            for (int j=0; j<numOfPlanets; j++) 
            {
                if (i == j) continue;
                double dist = distance(planets[i], planets[j]);
                double force = gravConstant * planets[i].mass * planets[j].mass / (dist * dist);
                double acc = force / planets[i].mass;
                planets[i].accX += acc * (planets[j].x - planets[i].x) / dist;
                planets[i].accY += acc * (planets[j].y - planets[i].y) / dist;
                planets[i].accZ += acc * (planets[j].z - planets[i].z) / dist;
            }
            planets[i].velX += planets[i].accX * timeInterval;
            planets[i].velY += planets[i].accY * timeInterval;
            planets[i].velZ += planets[i].accZ * timeInterval;
            planets[i].x += planets[i].velX * timeInterval;
            planets[i].y += planets[i].velY * timeInterval;
            planets[i].z += planets[i].velZ * timeInterval;
        }

        // Print planet positions at current time
        printf("Time step: %d\n", t+1);
        for (int i=0; i<numOfPlanets; i++) 
        {
            printf("Planet %s: (%lf,%lf,%lf)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
        }
    }

    return 0;
}