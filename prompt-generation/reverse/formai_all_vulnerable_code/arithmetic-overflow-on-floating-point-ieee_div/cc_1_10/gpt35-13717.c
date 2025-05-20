//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67E-11

struct planet{
    char name[10];
    double mass;
    double x, y;
    double vx, vy;
    double ax, ay;
};

struct planet sun = {"Sun", 1.989E+30, 0, 0, 0, 0};

struct planet planets[] = {
    {"Mercury", 3.30E+23, 5.79E+10, 0, 0, 4.79E+04},
    {"Venus", 4.87E+24, 1.08E+11, 0, 0, 3.50E+04},
    {"Earth", 5.97E+24, 1.50E+11, 0, 0, 2.98E+04},
    {"Mars", 6.39E+23, 2.28E+11, 0, 0, 2.41E+04},
    {"Jupiter", 1.90E+27, 7.78E+11, 0, 0, 1.30E+04},
    {"Saturn", 5.68E+26, 1.43E+12, 0, 0, 9.70E+03},
    {"Uranus", 8.68E+25, 2.87E+12, 0, 0, 6.80E+03},
    {"Neptune", 1.02E+26, 4.50E+12, 0, 0, 5.40E+03}
};

int num_planets = sizeof(planets)/sizeof(struct planet);

double getDistance(struct planet p1, struct planet p2){
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

double getForce(struct planet p1, struct planet p2){
    double r = getDistance(p1, p2);
    return G * p1.mass * p2.mass / (r * r);
}

void resetAccelerations(){
    for (int i = 0; i < num_planets; i++){
        planets[i].ax = 0;
        planets[i].ay = 0;
    }
}

void calculateAccelerations(){
    resetAccelerations();
    for (int i = 0; i < num_planets; i++){
        for (int j = 0; j < num_planets; j++){
            if (i == j) continue;
            double force = getForce(planets[i], planets[j]);
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double angle = atan2(dy, dx);
            planets[i].ax += force * cos(angle) / planets[i].mass;
            planets[i].ay += force * sin(angle) / planets[i].mass;
        }
    }
}

void updateVelocitiesAndPositions(double dt){
    for (int i = 0; i < num_planets; i++){
        planets[i].vx += planets[i].ax * dt;
        planets[i].vy += planets[i].ay * dt;
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
    }
}

void printPlanet(struct planet p){
    printf("%-10s x:%15.2e y:%15.2e vx:%10.2e vy:%10.2e\n", p.name, p.x, p.y, p.vx, p.vy);
}

void printHeader(){
    printf("%-10s %-18s %-18s %-18s %-18s\n", "Planet", "X position", "Y position", "X velocity", "Y velocity");
}

void printPlanets(){
    printHeader();
    for (int i = 0; i < num_planets; i++){
        printPlanet(planets[i]);
    }
}

int main(){
    double dt = 86400.0; // 1 day in seconds
    int num_days = 365 * 10; // run simulation for 10 years
    for (int i = 0; i < num_planets; i++){
        planets[i].x = planets[i].vx * dt;
    }
    for (int i = 0; i < num_days; i++){
        calculateAccelerations();
        updateVelocitiesAndPositions(dt);
    }
    printf("Simulation complete.\n");
    printPlanets();
    return 0;
}