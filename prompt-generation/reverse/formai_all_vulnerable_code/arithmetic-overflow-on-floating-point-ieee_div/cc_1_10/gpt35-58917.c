//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: accurate
#include <stdio.h>
#include <math.h>

int main()
{
    float G = 6.6743e-11; // Gravitational constant
    float mass[3] = {5.97e24, 7.34e22, 1000}; // Mass of Earth, Moon, and object in kg
    float dist[2] = {3.844e8, 0}; // Distance from Earth to Moon and initial object location in m
    float vel[2] = {0, 1000}; // Initial velocities of object in m/s

    float time = 0.0; // Starting time in seconds
    float timestep = 1.0; // Time step in seconds
    float x_obj = dist[1]; // x position of object
    float y_obj = 0; // y position of object
    float x_moon = dist[0]; // x position of moon
    float y_moon = 0; // y position of moon
    float x_earth = 0; // x position of earth
    float y_earth = 0; // y position of earth

    while (time < 3600)
    {
        // Calculate distance between object and moon
        float dist_obj_moon = sqrt(pow((x_obj - x_moon), 2) + pow((y_obj - y_moon), 2));

        // Calculate distance between object and earth
        float dist_obj_earth = sqrt(pow((x_obj - x_earth), 2) + pow((y_obj - y_earth), 2));

        // Calculate gravitational forces on object
        float force_moon = (G * mass[2] * mass[1]) / pow(dist_obj_moon, 2);
        float force_earth = (G * mass[2] * mass[0]) / pow(dist_obj_earth, 2);

        // Calculate acceleration of object
        float accel_x = (force_moon * (x_moon - x_obj) / dist_obj_moon) + (force_earth * (x_earth - x_obj) / dist_obj_earth);
        float accel_y = (force_moon * (y_moon - y_obj) / dist_obj_moon) + (force_earth * (y_earth - y_obj) / dist_obj_earth);

        // Calculate new velocities of object
        vel[0] += accel_x * timestep;
        vel[1] += accel_y * timestep;

        // Calculate new position of object
        x_obj += vel[0] * timestep;
        y_obj += vel[1] * timestep;

        // Print current position of object
        printf("Time: %0.2f s - x_pos: %0.2f m, y_pos: %0.2f m\n", time, x_obj, y_obj);

        // Update time
        time += timestep;
    }

    return 0;
}