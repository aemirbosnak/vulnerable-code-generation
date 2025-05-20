//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 //Gravitational constant
#define DELTA_T 3600 //Simulation step size (seconds)
#define SECONDS_IN_DAY 86400 //Number of seconds in a day
#define DAYS_IN_YEAR 365.25 //Number of days in a year


//Data structure for celestial bodies
typedef struct
{
    char name[20];
    double mass; //in kg
    double radius; //in m
    double position[3]; //in m
    double velocity[3]; //in m/s
} CelestialBody;

//Function to calculate gravitational force
void calculate_force(CelestialBody *b1, CelestialBody *b2, double force[3])
{
    double distance, f;
    int i;
    distance = 0;
    for (i = 0; i < 3; i++)
    {
        distance += pow((b1->position[i] - b2->position[i]), 2);
    }
    distance = sqrt(distance);
    f = (G * b1->mass * b2->mass) / pow(distance, 2);
    for (i = 0; i < 3; i++)
    {
        force[i] = f * (b2->position[i] - b1->position[i]) / distance;
    }
}

//Function to update position and velocity of a celestial body
void update_body(CelestialBody *b, double force[3])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        b->velocity[i] += force[i] * DELTA_T / b->mass;
        b->position[i] += b->velocity[i] * DELTA_T;
    }
}

int main()
{
    CelestialBody sun = {"Sun", 1.989e30, 696340000, {0, 0, 0}, {0, 0, 0}};
    CelestialBody earth = {"Earth", 5.97e24, 6371000, {147095000000, 0, 0}, {0, 30300, 0}};
    CelestialBody moon = {"Moon", 7.35e22, 1737100, {147100000000, 0, 0}, {0, 30760, 0}};
    double force1[3], force2[3];
    double time = 0;
    int i;

    //Simulation loop
    while (1)
    {
        //Calculate gravitational forces
        calculate_force(&sun, &earth, force1);
        calculate_force(&earth, &moon, force2);

        //Update positions and velocities
        update_body(&sun, force1);
        update_body(&earth, force2);
        update_body(&moon, force2);

        //Print current positions
        printf("Time: %lf days\n", time / SECONDS_IN_DAY);
        printf("Sun position: (%lf, %lf, %lf) m\n", sun.position[0], sun.position[1], sun.position[2]);
        printf("Earth position: (%lf, %lf, %lf) m\n", earth.position[0], earth.position[1], earth.position[2]);
        printf("Moon position: (%lf, %lf, %lf) m\n", moon.position[0], moon.position[1], moon.position[2]);

        //Check if earth and moon are aligned with the sun
        if (earth.position[1] > 0 && moon.position[1] > 0)
        {
            printf("Lunar eclipse!\n");
        }
        if (earth.position[1] < 0 && moon.position[1] < 0)
        {
            printf("Solar eclipse!\n");
        }

        //Check if one year has passed
        if ((int)(time / SECONDS_IN_DAY) % (int)DAYS_IN_YEAR == 0 && time > 0)
        {
            printf("One more year has passed!\n");
        }

        //Wait for 1 day
        time += DELTA_T;
        if (getchar() == 'q')
        {
            break;
        }
    }

    return 0;
}