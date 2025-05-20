//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: innovative
#include<stdio.h>
#include<math.h>
#define G 6.67e-11 //Gravitational constant
#define pi 3.1416   //Value of pi

//Structure to store planet details
typedef struct 
{
    double mass;     //mass of planet
    double radius;   //radius of planet
    double x,y,z;    //coordinates of planet
    double vx,vy,vz; //velocity of planet 
} Planet;

//Function to calculate distance between two planets
double distance(Planet p1, Planet p2)
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    double z = p1.z - p2.z;
    return sqrt(x*x + y*y + z*z);
}

//Function to calculate gravitational force acting on a planet
void gravitational_force(Planet* p1, Planet* p2)
{
    double force = (G * p1->mass * p2->mass) / pow(distance(*p1, *p2), 2);
    double x = p2->x - p1->x;
    double y = p2->y - p1->y;
    double z = p2->z - p1->z;
    double angle = atan2(y, x);
    double fx = force * cos(angle);
    double fy = force * sin(angle);
    double fz = force * sin(acos(z/distance(*p1, *p2)));   
    p1->vx += fx/p1->mass;
    p1->vy += fy/p1->mass;
    p1->vz += fz/p1->mass;
}

//Function to update velocity and position of a planet
void update_position(Planet* p, double dt)
{
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

//Function to simulate the planet gravity system
void simulate(Planet planets[], int n, double dt, int timesteps)
{
    for(int t=0; t<timesteps; t++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                gravitational_force(&planets[i], &planets[j]);
            }
        }
        for(int i=0; i<n; i++)
        {
            update_position(&planets[i], dt);
        }
    }
}

int main()
{
    Planet planets[3];  //Create 3 planets
    //Initialize planet details
    planets[0].mass = 5.97e24;
    planets[0].radius = 6371e3;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;
    planets[1].mass = 3.3e23;
    planets[1].radius = 1737.1e3;
    planets[1].x = 384400e3;
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 1018;
    planets[1].vz = 0;
    planets[2].mass = 4.9e24;
    planets[2].radius = 3390e3;
    planets[2].x = 0;
    planets[2].y = 0;
    planets[2].z = 2279e3;
    planets[2].vx = -2008.7;
    planets[2].vy = 0;
    planets[2].vz = 0;

    //Simulate the system for 1000 seconds and 1000 timesteps
    simulate(planets, 3, 1, 1000);

    //Print the final positions of the planets
    printf("Final positions of the planets:\n");
    for(int i=0; i<3; i++)
    {
        printf("Planet %d - x: %.3f km, y: %.3f km, z: %.3f km\n", i+1, planets[i].x/1000, planets[i].y/1000, planets[i].z/1000);
    }

    return 0;
}