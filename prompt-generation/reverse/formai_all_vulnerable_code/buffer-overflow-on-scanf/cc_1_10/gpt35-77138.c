//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    
    // Welcome message for the user
    printf("Welcome To The C Drone Remote Control Example Program \n");
    printf("Please Enter The Required Drone Flight Parameters Below: \n");
    
    // Declaring Drone Parameters
    float speed, distance, time, altitude, x, y, z, theta, phi, psi;
    
    // Reading Drone Parameters
    printf("Enter the speed of the drone (in meters/second) : ");
    scanf("%f",&speed);
    
    printf("Enter the distance of the drone to fly (in meters) : ");
    scanf("%f",&distance);
    
    printf("Enter the time for which the drone will fly (in seconds) : ");
    scanf("%f",&time);
    
    printf("Enter the altitude at which the drone will fly (in meters) : ");
    scanf("%f",&altitude);
    
    printf("Enter the x-coordinate of the target point (in meters) : ");
    scanf("%f",&x);
    
    printf("Enter the y-coordinate of the target point (in meters) : ");
    scanf("%f",&y);
    
    printf("Enter the z-coordinate of the target point (in meters) : ");
    scanf("%f",&z);
    
    printf("Enter the theta angle for the drone's orientation (in degrees) : ");
    scanf("%f",&theta);
    
    printf("Enter the phi angle for the drone's orientation (in degrees) : ");
    scanf("%f",&phi);
    
    printf("Enter the psi angle for the drone's orientation (in degrees) : ");
    scanf("%f",&psi);
    
    //Converting angles from degrees to radians
    theta = (theta * M_PI / 180);
    phi = (phi * M_PI / 180);
    psi = (psi * M_PI / 180);

    //Calculating drone position in x, y and z coordinates
    float drone_x = distance * sin(theta);
    float drone_y = distance * sin(phi);
    float drone_z = altitude + distance * cos(theta) * cos(phi);
    
    //Calculating change in drone position
    float del_x = x - drone_x;
    float del_y = y - drone_y;
    float del_z = z - drone_z;
    
    //Calculating the net distance to travel
    float net_distance = sqrt(pow(del_x,2) + pow(del_y,2) + pow(del_z,2));
    
    //Calculating speed in x, y and z directions
    float speed_x = speed * del_x / net_distance;
    float speed_y = speed * del_y / net_distance;
    float speed_z = speed * del_z / net_distance;
    
    //Print the drone position, speed and distance to the target point
    printf("Drone Position : (%.2f, %.2f, %.2f)\n", drone_x, drone_y, drone_z);
    printf("Speed : (%.2fm/s, %.2fm/s, %.2fm/s)\n", speed_x, speed_y, speed_z);
    printf("Distance to the Target Point : %.2fm\n", net_distance);
    
    //Returning the exit code
    return 0;
}