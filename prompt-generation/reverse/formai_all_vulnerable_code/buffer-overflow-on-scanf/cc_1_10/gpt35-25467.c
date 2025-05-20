//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define G 6.67e-11 //Universal Gravitational Constant

struct planet { //Structure for planet data
    
    char name[10]; //Name of the planet
    double mass; //Mass of the planet (kg)
    double radius; //Radius of the planet (m)
    double x; //x position (m)
    double y; //y position (m)
    double vx; //x velocity (m/s)
    double vy; //y velocity (m/s)
    double ax; //x acceleration (m/s^2)
    double ay; //y acceleration (m/s^2)
};

typedef struct planet Planet;

void calculate_acceleration(Planet *p1, Planet *p2) { //Calculate acceleration due to gravity
    
    double r_squared = pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2); //Calculating distance between two planets
    
    double force = G*(p1->mass)*(p2->mass)/r_squared; //Calculating gravitational force
    
    double angle = atan2(p2->y - p1->y, p2->x - p1->x); //Calculating angle
    
    p1->ax += force*cos(angle)/p1->mass; //Calculating x acceleration
    p2->ax -= force*cos(angle)/p2->mass;
    
    p1->ay += force*sin(angle)/p1->mass; //Calculating y acceleration
    p2->ay -= force*sin(angle)/p2->mass;
}

void update_planet(Planet *p, double timestep) { //Update planet position and velocity
    
    p->vx += p->ax*timestep; //Calculating x velocity
    p->vy += p->ay*timestep; //Calculating y velocity
    
    p->x += p->vx*timestep; //Updating x position
    p->y += p->vy*timestep; //Updating y position
    
    p->ax = 0; //Resetting acceleration for next time step
    p->ay = 0;
}

int main() {
    
    int n; //Number of planets in simulation
    printf("Enter number of planets: ");
    scanf("%d", &n);
    
    Planet *planets = (Planet*)malloc(n*sizeof(Planet)); //Dynamic Memory Allocation
    
    for(int i=0; i<n; i++) { //Reading planet data from user
        
        printf("\nPlanet %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s", planets[i].name);
        printf("Enter mass (kg): ");
        scanf("%lf", &planets[i].mass);
        printf("Enter radius (m): ");
        scanf("%lf", &planets[i].radius);
        printf("Enter x position (m): ");
        scanf("%lf", &planets[i].x);
        printf("Enter y position (m): ");
        scanf("%lf", &planets[i].y);
        printf("Enter x velocity (m/s): ");
        scanf("%lf", &planets[i].vx);
        printf("Enter y velocity (m/s): ");
        scanf("%lf", &planets[i].vy);
    }
    
    double timestep; //Size of time step
    printf("\nEnter time step size (s): ");
    scanf("%lf", &timestep);
    
    int duration; //Duration of simulation
    printf("Enter duration of simulation (s): ");
    scanf("%d", &duration);
    
    int steps = duration/timestep; //Number of time steps in simulation
    
    for(int i=0; i<steps; i++) { //Iterating over each time step
        
        for(int j=0; j<n; j++) { //Iterating over each planet
            
            for(int k=0; k<n; k++) { //Iterating over every other planet other than itself
                
                if(j != k) //Skipping if it is the same planet
                    calculate_acceleration(&planets[j], &planets[k]);
            }
        }
        
        for(int j=0; j<n; j++) { //Updating each planet
            
            update_planet(&planets[j], timestep);
        }
    }
    
    printf("\nFinal Positions:\n");
    for(int i=0; i<n; i++) { //Printing final positions of each planet
        
        printf("%s: (%.2lf, %.2lf)\n", planets[i].name, planets[i].x, planets[i].y);
    }
    
    free(planets); //Freeing Memory
    
    return 0;
}