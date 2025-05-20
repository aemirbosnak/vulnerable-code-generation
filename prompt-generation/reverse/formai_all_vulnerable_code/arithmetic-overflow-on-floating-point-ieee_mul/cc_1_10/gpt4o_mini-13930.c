//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational constant
#define PI 3.14159265358979323846

typedef struct {
    double mass; // Mass of the planet
    double radius; // Radius of the planet
    double posX; // X position of the planet
    double posY; // Y position of the planet
} Planet;

typedef struct {
    double mass; // Mass of the object
    double posX; // X position of the object
    double posY; // Y position of the object
    double velX; // X velocity of the object
    double velY; // Y velocity of the object
} Object;

void initializePlanet(Planet *planet, double mass, double radius, double posX, double posY) {
    planet->mass = mass;
    planet->radius = radius;
    planet->posX = posX;
    planet->posY = posY;
}

void initializeObject(Object *obj, double mass, double posX, double posY, double velX, double velY) {
    obj->mass = mass;
    obj->posX = posX;
    obj->posY = posY;
    obj->velX = velX;
    obj->velY = velY;
}

double calculateGravitationalForce(Planet *planet, Object *obj) {
    double distance = sqrt(pow(planet->posX - obj->posX, 2) + pow(planet->posY - obj->posY, 2));
    if (distance < planet->radius) {
        return 0; // Object is inside the planet, no gravitational force
    }
    return (G * planet->mass * obj->mass) / (distance * distance);
}

void updateObjectPosition(Object *obj, double timeStep, double force) {
    // Update velocity
    obj->velY += force / obj->mass * timeStep; // Assuming force acts in negative Y direction
    // Update position
    obj->posY += obj->velY * timeStep;
}

void printState(Object *obj) {
    printf("Object State:\n");
    printf("Mass: %.2f kg\n", obj->mass);
    printf("Position: (%.2f, %.2f) m\n", obj->posX, obj->posY);
    printf("Velocity: (%.2f, %.2f) m/s\n", obj->velX, obj->velY);
}

void simulate(double timeStep, double totalTime, Planet *planet, Object *obj) {
    double elapsedTime = 0.0;
    while (elapsedTime < totalTime) {
        double force = calculateGravitationalForce(planet, obj);
        updateObjectPosition(obj, timeStep, force);
        printState(obj);
        elapsedTime += timeStep;
    }
}

int main() {
    // Configurable Planet and Object
    Planet earth;
    Object satellite;

    double earthMass = 5.972e24; // Mass of Earth
    double earthRadius = 6371e3;  // Radius of Earth

    double satelliteMass = 1000.0; // Mass of satellite
    double satelliteInitialPosX = 0.0;
    double satelliteInitialPosY = 7000e3; // Start some km above surface
    double satelliteInitialVelX = 7.12e3; // Orbital velocity
    double satelliteInitialVelY = 0.0;

    initializePlanet(&earth, earthMass, earthRadius, 0.0, 0.0);
    initializeObject(&satellite, satelliteMass, satelliteInitialPosX, satelliteInitialPosY, satelliteInitialVelX, satelliteInitialVelY);

    double timeStep = 1.0; // seconds
    double totalTime = 600.0; // 600 seconds

    simulate(timeStep, totalTime, &earth, &satellite);

    return 0;
}