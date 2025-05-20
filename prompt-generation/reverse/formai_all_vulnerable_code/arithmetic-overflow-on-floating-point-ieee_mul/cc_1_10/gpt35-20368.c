//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define G 6.67E-11 //Universal gravitational constant
#define M_sun 1.98892E30 //Mass of the Sun
#define AU 1.49598E11 //1 Astronomical Unit

//Defining a structure to store the properties of each planet
struct Planet {
    char name[20];
    double mass; //in kg
    double radius; //in m
    double xpos; //x-coordinate in m
    double ypos; //y-coordinate in m
    double zpos; //z-coordinate in m
    double xvel; //x-velocity in m/s
    double yvel; //y-velocity in m/s
    double zvel; //z-velocity in m/s
};

int main() {
    struct Planet sun = {"Sun", M_sun, 696340000, 0, 0, 0, 0, 0, 0};
    struct Planet mercury = {"Mercury", 3.285E23, 2439700, 0, 57909000000, 0, 47300, 0, 0};
    struct Planet venus = {"Venus", 4.867E24, 6051800, 0, 108160000000, 0, 35000, 0, 0};
    struct Planet earth = {"Earth", 5.972E24, 6371000, 0, 149600000000, 0, 29783, 0, 0};
    struct Planet mars = {"Mars", 6.39E23, 3396200, 0, 227939000000, 0, 24100, 0, 0};
    struct Planet jupiter = {"Jupiter", 1.898E27, 71492000, 0, 778330000000, 0, 13070, 0, 0};
    struct Planet saturn = {"Saturn", 5.683E26, 60268000, 0, 1429400000000, 0, 9680, 0, 0};
    struct Planet uranus = {"Uranus", 8.681E25, 25559000, 0, 2870990000000, 0, 6810, 0, 0};
    struct Planet neptune = {"Neptune", 1.024E26, 24764000, 0, 4504300000000, 0, 5430, 0, 0};

    struct Planet planets[9] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};

    double time_step = 86400; //1 day time step
    double time = 0; //initial time
    double distance, force, acceleration;

    int i, j;
    while (1) { //infinite loop
        for (i=0; i<9; i++) { //loop over planets
            planets[i].xpos += planets[i].xvel * time_step; //update x-coordinate
            planets[i].ypos += planets[i].yvel * time_step; //update y-coordinate
            planets[i].zpos += planets[i].zvel * time_step; //update z-coordinate
            planets[i].xvel += planets[i].xvel * time_step * 100000; //update x-velocity due to centripetal acceleration
            planets[i].yvel += planets[i].yvel * time_step * 100000; //update y-velocity due to centripetal acceleration
            planets[i].zvel += planets[i].zvel * time_step * 100000; //update z-velocity due to centripetal acceleration
            for (j=i+1; j<9; j++) { //loop over other planets
                distance = sqrt(pow((planets[i].xpos - planets[j].xpos), 2) +
                                pow((planets[i].ypos - planets[j].ypos), 2) +
                                pow((planets[i].zpos - planets[j].zpos), 2)); //calculate distance between planets
                force = G * planets[i].mass * planets[j].mass / pow(distance, 2); //calculate force between planets
                acceleration = force / planets[i].mass; //calculate acceleration of planet i
                planets[i].xvel -= acceleration * (planets[i].xpos - planets[j].xpos) / distance * time_step; //update x-velocity due to gravitational force
                planets[i].yvel -= acceleration * (planets[i].ypos - planets[j].ypos) / distance * time_step; //update y-velocity due to gravitational force
                planets[i].zvel -= acceleration * (planets[i].zpos - planets[j].zpos) / distance * time_step; //update z-velocity due to gravitational force
                acceleration = force / planets[j].mass; //calculate acceleration of planet j
                planets[j].xvel += acceleration * (planets[i].xpos - planets[j].xpos) / distance * time_step; //update x-velocity due to gravitational force
                planets[j].yvel += acceleration * (planets[i].ypos - planets[j].ypos) / distance * time_step; //update y-velocity due to gravitational force
                planets[j].zvel += acceleration * (planets[i].zpos - planets[j].zpos) / distance * time_step; //update z-velocity due to gravitational force
            }
        }
        time += time_step; //update time
        printf("Time: %lf days\n", time/86400); //print time in days
        for (i=0; i<9; i++) { //loop over planets
            printf("%s: Position(%lf, %lf, %lf) Velocity(%lf, %lf, %lf)\n", planets[i].name, planets[i].xpos/AU, planets[i].ypos/AU, planets[i].zpos/AU, planets[i].xvel, planets[i].yvel, planets[i].zvel); //print planet properties
        }
    }
    return 0;
}