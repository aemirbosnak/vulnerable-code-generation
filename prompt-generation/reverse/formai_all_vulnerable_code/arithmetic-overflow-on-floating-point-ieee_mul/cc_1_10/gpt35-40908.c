//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define NUM_PLANETS 8
#define G_CONST 6.67408e-11
#define TIME_STEP 3600

// planet struct
typedef struct {
    char name[50];
    double mass;
    double xpos;
    double ypos;
    double xvel;
    double yvel;
} Planet;

// initialize planets
void initPlanets(Planet* planets) {
    // sun
    planets[0].mass = 1.989e+30;
    planets[0].xpos = 0;
    planets[0].ypos = 0;
    planets[0].xvel = 0;
    planets[0].yvel = 0;
    sprintf(planets[0].name, "Sun");
    // mercury
    planets[1].mass = 3.285e+23;
    planets[1].xpos = -4.600e+10;
    planets[1].ypos = 0;
    planets[1].xvel = 0;
    planets[1].yvel = 47360;
    sprintf(planets[1].name, "Mercury");
    // venus
    planets[2].mass = 4.867e+24;
    planets[2].xpos = 0;
    planets[2].ypos = 1.074e+11;
    planets[2].xvel = -35020;
    planets[2].yvel = 0;
    sprintf(planets[2].name, "Venus");
    // earth
    planets[3].mass = 5.972e+24;
    planets[3].xpos = 1.496e+11;
    planets[3].ypos = 0;
    planets[3].xvel = 0;
    planets[3].yvel = 29783;
    sprintf(planets[3].name, "Earth");
    // mars
    planets[4].mass = 6.39e+23;
    planets[4].xpos = 0;
    planets[4].ypos = -2.28e+11;
    planets[4].xvel = 24007;
    planets[4].yvel = 0;
    sprintf(planets[4].name, "Mars");
    // jupiter
    planets[5].mass = 1.898e+27;
    planets[5].xpos = 7.79e+11;
    planets[5].ypos = 0;
    planets[5].xvel = 0;
    planets[5].yvel = 13070;
    sprintf(planets[5].name, "Jupiter");
    // saturn
    planets[6].mass = 5.683e+26;
    planets[6].xpos = 0;
    planets[6].ypos = -1.427e+12;
    planets[6].xvel = 9680;
    planets[6].yvel = 0;
    sprintf(planets[6].name, "Saturn");
    // uranus
    planets[7].mass = 8.681e+25;
    planets[7].xpos = 2.871e+12;
    planets[7].ypos = 0;
    planets[7].xvel = 0;
    planets[7].yvel = 6835;
    sprintf(planets[7].name, "Uranus");
}

// get distance between two planets
double getDistance(Planet planet1, Planet planet2) {
    double xdiff = planet2.xpos - planet1.xpos;
    double ydiff = planet2.ypos - planet1.ypos;
    return sqrt(xdiff*xdiff + ydiff*ydiff);
}

// update the velocity of a planet
void updateVelocity(Planet* planet, double fx, double fy) {
    planet->xvel += fx/planet->mass*TIME_STEP;
    planet->yvel += fy/planet->mass*TIME_STEP;
}

// update the position of a planet
void updatePosition(Planet* planet) {
    planet->xpos += planet->xvel*TIME_STEP;
    planet->ypos += planet->yvel*TIME_STEP;
}

int main() {
    Planet planets[NUM_PLANETS];
    double time = 0;
    double fx, fy, distance;
    int i, j;

    // initialize planets
    initPlanets(planets);

    // simulate the solar system
    while (time <= 31536000*10) { // simulate 10 years
        // calculate the forces between all pairs of planets
        for (i = 0; i < NUM_PLANETS; i++) {
            for (j = 0; j < NUM_PLANETS; j++) {
                if (i != j) {
                    distance = getDistance(planets[i], planets[j]);
                    fx = G_CONST * planets[i].mass * planets[j].mass * (planets[j].xpos - planets[i].xpos) / pow(distance, 3);
                    fy = G_CONST * planets[i].mass * planets[j].mass * (planets[j].ypos - planets[i].ypos) / pow(distance, 3);
                    updateVelocity(&planets[i], fx, fy);
                }
            }
        }

        // update the position of each planet
        for (i = 0; i < NUM_PLANETS; i++) {
            updatePosition(&planets[i]);
        }

        // output the positions of each planet
        printf("Time: %g\n", time);
        for (i = 0; i < NUM_PLANETS; i++) {
            printf("%s Position: (%g, %g)\n", planets[i].name, planets[i].xpos, planets[i].ypos);
        }

        // increment time
        time += TIME_STEP;
    }

    return 0;
}