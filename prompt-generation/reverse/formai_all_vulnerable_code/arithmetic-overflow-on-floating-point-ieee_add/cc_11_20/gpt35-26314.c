//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXCARS 10   // maximum number of cars on the road
#define MAXSPEED 60  // maximum speed of a car (mph)
#define TIMESTEP 1   // time step of the simulation (seconds)
#define ROADLENGTH 200 // length of the road (miles)

int main()
{
    srand(time(NULL));
    
    // initialization
    int num_cars = rand() % MAXCARS;
    double car_pos[num_cars];
    double car_speed[num_cars];
    int time = 0;
    
    // simulation loop
    while (1)
    {
        // update car positions
        for (int i = 0; i < num_cars; i++)
        {
            car_pos[i] += car_speed[i] * TIMESTEP;
            
            // check for collisions
            for (int j = 0; j < num_cars; j++)
            {
                if (i != j && car_pos[i] == car_pos[j])
                {
                    printf("Collision at time %d\n", time);
                    return 1;
                }
            }
        }
        
        // update car speeds based on position
        for (int i = 0; i < num_cars; i++)
        {
            if (car_pos[i] >= ROADLENGTH)
            {
                car_pos[i] = 0;
            }
            
            double diff = car_pos[(i+1)%num_cars] - car_pos[i];
            
            if (diff <= 0)
            {
                diff += ROADLENGTH;
            }
            
            double desired_speed = diff / TIMESTEP;
            
            if (desired_speed > MAXSPEED)
            {
                desired_speed = MAXSPEED;
            }
            
            double accel = (desired_speed - car_speed[i]) / TIMESTEP;
            
            if (accel > 0.1)
            {
                accel = 0.1;
            }
            
            car_speed[i] += accel;
            
            if (car_speed[i] < 0)
            {
                car_speed[i] = 0;
            }
        }
        
        // print out car positions
        printf("Time: %d\n", time);
        for (int i = 0; i < num_cars; i++)
        {
            printf("Car %d: position %f, speed %f\n", i, car_pos[i], car_speed[i]);
        }
        printf("\n");
        
        // advance time
        time += TIMESTEP;
    }
    
    return 0;
}