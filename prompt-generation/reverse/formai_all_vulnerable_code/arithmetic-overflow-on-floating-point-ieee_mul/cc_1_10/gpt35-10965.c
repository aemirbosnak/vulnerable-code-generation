//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159

// Function to calculate the distance between planets
double distance(double x1,double y1,double z1,double x2,double y2,double z2)
{
    double dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
    return dist;
}

// Function to calculate the gravitational force
double gravity(double m1,double m2,double dist)
{
    double G=6.67e-11;
    double force=G*m1*m2/(dist*dist);
    return force;
}

int main()
{
    // Initialize variables for the sun and planets
    double sun_x=0,sun_y=0,sun_z=0,sun_mass=1.9885e30;
    double mercury_x=57909e3,mercury_y=0,mercury_z=0,mercury_mass=3.3022e23;
    double venus_x=0,venus_y=10816e3,venus_z=0,venus_mass=4.8676e24;
    double earth_x=0,earth_y=14960e3,earth_z=0,earth_mass=5.9722e24;
    double mars_x=-22792e3,mars_y=0,mars_z=0,mars_mass=6.4171e23;

    printf("\t\t--------------------------\n");
    printf("\t\t|     SOLAR SIMULATOR     |\n");
    printf("\t\t--------------------------\n\n");
    int choice;
    printf("Welcome to the Solar Simulator Program.\n");
    printf("Please select an option:\n");
    printf("1. Show the current position of the planets.\n");
    printf("2. Simulate the Solar System over a period of time.\n");
    printf("3. Exit the program.\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("Current Solar System Configuration:\n\n");
        printf("Planet           \tx-axis           \ty-axis           \tz-axis\n");
        printf("-----------------------------------------------------------------\n");
        printf("Sun              \t%.2lf\t\t%.2lf\t\t%.2lf\n",sun_x,sun_y,sun_z);
        printf("Mercury          \t%.2lf\t\t%.2lf\t\t%.2lf\n",mercury_x,mercury_y,mercury_z);
        printf("Venus            \t%.2lf\t\t%.2lf\t\t%.2lf\n",venus_x,venus_y,venus_z);
        printf("Earth            \t%.2lf\t\t%.2lf\t\t%.2lf\n",earth_x,earth_y,earth_z);
        printf("Mars             \t%.2lf\t\t%.2lf\t\t%.2lf\n\n",mars_x,mars_y,mars_z);
    }
    else if(choice==2)
    {
        printf("Please enter the amount of time you would like to simulate (in Earth days):\n");
        double time;
        scanf("%lf",&time);

        // Convert Earth days to seconds
        double seconds=time*(24*60*60);

        // Initialize variables for velocity and acceleration for each planet
        double sun_vx=0,sun_vy=0,sun_vz=0,sun_ax=0,sun_ay=0,sun_az=0;
        double mercury_vx=0,mercury_vy=47.87e3,mercury_vz=0,mercury_ax=0,mercury_ay=0,mercury_az=0;
        double venus_vx=-35.02e3,venus_vy=0,venus_vz=0,venus_ax=0,venus_ay=0,venus_az=0;
        double earth_vx=0,earth_vy=29.78e3,earth_vz=0,earth_ax=0,earth_ay=0,earth_az=0;
        double mars_vx=0,mars_vy=-24.077e3,mars_vz=0,mars_ax=0,mars_ay=0,mars_az=0;

        // Initialize variables for force and distance between planets
        double mercury_dist,mercury_force;
        double venus_dist,venus_force;
        double earth_dist,earth_force;
        double mars_dist,mars_force;

        // Define the time step
        double delta_t=500;

        // Loop over the time period entered by the user
        for(double t=0;t<=seconds;t+=delta_t)
        {
            // Calculate the gravitational forces on each planet
            mercury_dist=distance(mercury_x,mercury_y,mercury_z,sun_x,sun_y,sun_z);
            mercury_force=gravity(mercury_mass,sun_mass,mercury_dist);
            sun_ax=mercury_force*(mercury_x-sun_x)/(mercury_dist*mercury_mass);
            sun_ay=mercury_force*(mercury_y-sun_y)/(mercury_dist*mercury_mass);
            sun_az=mercury_force*(mercury_z-sun_z)/(mercury_dist*mercury_mass);
            mercury_ax=-sun_ax*(sun_mass/mercury_mass);
            mercury_ay=-sun_ay*(sun_mass/mercury_mass);
            mercury_az=-sun_az*(sun_mass/mercury_mass);
            mercury_vx+=mercury_ax*delta_t;
            mercury_vy+=mercury_ay*delta_t;
            mercury_vz+=mercury_az*delta_t;
            mercury_x+=mercury_vx*delta_t;
            mercury_y+=mercury_vy*delta_t;
            mercury_z+=mercury_vz*delta_t;

            venus_dist=distance(venus_x,venus_y,venus_z,sun_x,sun_y,sun_z);
            venus_force=gravity(venus_mass,sun_mass,venus_dist);
            sun_ax+=venus_force*(venus_x-sun_x)/(venus_dist*venus_mass);
            sun_ay+=venus_force*(venus_y-sun_y)/(venus_dist*venus_mass);
            sun_az+=venus_force*(venus_z-sun_z)/(venus_dist*venus_mass);
            venus_ax=-sun_ax*(sun_mass/venus_mass);
            venus_ay=-sun_ay*(sun_mass/venus_mass);
            venus_az=-sun_az*(sun_mass/venus_mass);
            venus_vx+=venus_ax*delta_t;
            venus_vy+=venus_ay*delta_t;
            venus_vz+=venus_az*delta_t;
            venus_x+=venus_vx*delta_t;
            venus_y+=venus_vy*delta_t;
            venus_z+=venus_vz*delta_t;

            earth_dist=distance(earth_x,earth_y,earth_z,sun_x,sun_y,sun_z);
            earth_force=gravity(earth_mass,sun_mass,earth_dist);
            sun_ax+=earth_force*(earth_x-sun_x)/(earth_dist*earth_mass);
            sun_ay+=earth_force*(earth_y-sun_y)/(earth_dist*earth_mass);
            sun_az+=earth_force*(earth_z-sun_z)/(earth_dist*earth_mass);
            earth_ax=-sun_ax*(sun_mass/earth_mass);
            earth_ay=-sun_ay*(sun_mass/earth_mass);
            earth_az=-sun_az*(sun_mass/earth_mass);
            earth_vx+=earth_ax*delta_t;
            earth_vy+=earth_ay*delta_t;
            earth_vz+=earth_az*delta_t;
            earth_x+=earth_vx*delta_t;
            earth_y+=earth_vy*delta_t;
            earth_z+=earth_vz*delta_t;

            mars_dist=distance(mars_x,mars_y,mars_z,sun_x,sun_y,sun_z);
            mars_force=gravity(mars_mass,sun_mass,mars_dist);
            sun_ax+=mars_force*(mars_x-sun_x)/(mars_dist*mars_mass);
            sun_ay+=mars_force*(mars_y-sun_y)/(mars_dist*mars_mass);
            sun_az+=mars_force*(mars_z-sun_z)/(mars_dist*mars_mass);
            mars_ax=-sun_ax*(sun_mass/mars_mass);
            mars_ay=-sun_ay*(sun_mass/mars_mass);
            mars_az=-sun_az*(sun_mass/mars_mass);
            mars_vx+=mars_ax*delta_t;
            mars_vy+=mars_ay*delta_t;
            mars_vz+=mars_az*delta_t;
            mars_x+=mars_vx*delta_t;
            mars_y+=mars_vy*delta_t;
            mars_z+=mars_vz*delta_t;
        }

        // Print the final positions of the planets
        printf("Final Solar System Configuration:\n\n");
        printf("Planet           \tx-axis           \ty-axis           \tz-axis\n");
        printf("-----------------------------------------------------------------\n");
        printf("Sun              \t%.2lf\t\t%.2lf\t\t%.2lf\n",sun_x,sun_y,sun_z);
        printf("Mercury          \t%.2lf\t\t%.2lf\t\t%.2lf\n",mercury_x,mercury_y,mercury_z);
        printf("Venus            \t%.2lf\t\t%.2lf\t\t%.2lf\n",venus_x,venus_y,venus_z);
        printf("Earth            \t%.2lf\t\t%.2lf\t\t%.2lf\n",earth_x,earth_y,earth_z);
        printf("Mars             \t%.2lf\t\t%.2lf\t\t%.2lf\n\n",mars_x,mars_y,mars_z);
    }
    else if(choice==3)
    {
        printf("Thank You for using the Solar Simulator. Goodbye!\n");
    }
    else
    {
        printf("Invalid Choice. Please Try Again.\n");
    }
    return 0;
}