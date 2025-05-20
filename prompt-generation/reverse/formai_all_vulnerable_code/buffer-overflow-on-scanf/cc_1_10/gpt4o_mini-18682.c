//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define PI 3.14159265359
#define NUM_PLANETS 8
#define SUN_GRAVITY 1.989e30  // kg
#define TIME_STEP 86400       // seconds (1 day)

typedef struct {
    char name[20];
    double distance; // AU
    double mass;     // kg
    double angle;    // radians
    double speed;    // radians per day
} Planet;

Planet planets[NUM_PLANETS] = {
    {"Mercury", 0.39, 3.301e23, 0.240, 0.240},
    {"Venus", 0.72, 4.867e24, 0.615, 0.615},
    {"Earth", 1.0, 5.972e24, 0.0, 1.0},
    {"Mars", 1.52, 6.417e23, 1.517, 0.524},
    {"Jupiter", 5.20, 1.898e27, 4.944, 0.083},
    {"Saturn", 9.58, 5.683e26, 0.775, 0.033},
    {"Uranus", 19.22, 8.681e25, 0.182, 0.012},
    {"Neptune", 30.06, 1.024e26, 0.836, 0.006}
};

void printPlanets() {
    printf("======= Solar System Simulation =======\n");
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: Distance: %.2f AU, Angle: %.2f radians\n", 
               planets[i].name, planets[i].distance, planets[i].angle);
    }
    printf("======================================\n");
}

void updatePositions(double time) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].angle += planets[i].speed * time;
        if (planets[i].angle > 2 * PI) {
            planets[i].angle -= 2 * PI;
        }
    }
}

void simulate(int days) {
    for (int day = 0; day < days; day++) {
        printPlanets();
        updatePositions(TIME_STEP);
        sleep(1);  // To visualize, pause simulation for 1 second
    }
}

int main() {
    int daysToSimulate;

    printf("Enter number of days to simulate: ");
    scanf("%d", &daysToSimulate);
    
    if (daysToSimulate <= 0) {
        printf("Negative or zero days will not be simulated!\n");
        return -1;
    }

    simulate(daysToSimulate);
    
    printf("Simulation complete! Safe travels through the cosmos!\n");
    return 0;
}