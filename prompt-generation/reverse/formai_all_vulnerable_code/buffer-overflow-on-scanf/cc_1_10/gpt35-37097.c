//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11     // gravitational constant
#define TIMESTEP 3600  // time interval

typedef struct planet {
   char name[20];
   double mass;
   double radius;
   double position[3];  // x, y, z
   double velocity[3];  // vx, vy, vz
} planet;

planet getPlanet() {
   planet p;
   printf("Enter planet name: ");
   scanf("%s", p.name);
   printf("Enter planet mass (in kg): ");
   scanf("%lf", &p.mass);
   printf("Enter planet radius (in m): ");
   scanf("%lf", &p.radius);
   printf("Enter planet position (x y z, in m): ");
   scanf("%lf %lf %lf", &p.position[0], &p.position[1], &p.position[2]);
   printf("Enter planet velocity (vx vy vz, in m/s): ");
   scanf("%lf %lf %lf", &p.velocity[0], &p.velocity[1], &p.velocity[2]);
   return p;
}

/**
  * Calculate the distance between two planets.
  * p1 and p2 are planet structs.
  **/
double getDistance(planet p1, planet p2) {
   double deltaX = p1.position[0] - p2.position[0];
   double deltaY = p1.position[1] - p2.position[1];
   double deltaZ = p1.position[2] - p2.position[2];
   return sqrt(deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ);
}

/**
  * Calculate the force between two planets.
  * p1 and p2 are planet structs.
  **/
double getForce(planet p1, planet p2) {
   double r = getDistance(p1, p2);
   return G * p1.mass * p2.mass / (r * r);
}

/**
  * Calculate the acceleration of a planet.
  * p is the planet struct.
  * planets is an array of planet structs.
  * numPlanets is the number of planets in the array.
  **/
double* getAcceleration(planet p, planet* planets, int numPlanets) {
   double a[3] = {0, 0, 0};  // x, y, z
   for (int i = 0; i < numPlanets; i++) {
      if (strcmp(p.name, planets[i].name) != 0) {  // avoid self-interaction
         double f = getForce(p, planets[i]);
         double deltaX = p.position[0] - planets[i].position[0];
         double deltaY = p.position[1] - planets[i].position[1];
         double deltaZ = p.position[2] - planets[i].position[2];
         double r = getDistance(p, planets[i]);
         a[0] += -f * deltaX / (p.mass * r);
         a[1] += -f * deltaY / (p.mass * r);
         a[2] += -f * deltaZ / (p.mass * r);
      }
   }
   double* acc = malloc(3 * sizeof(double));
   acc[0] = a[0];
   acc[1] = a[1];
   acc[2] = a[2];
   return acc;
}

/**
  * Calculate the velocity of a planet.
  * p is the planet struct.
  * acc is an array of acceleration values.
  **/
double* getVelocity(planet p, double* acc) {
   double v[3] = {p.velocity[0] + acc[0] * TIMESTEP,
                  p.velocity[1] + acc[1] * TIMESTEP,
                  p.velocity[2] + acc[2] * TIMESTEP};
   double* vel = malloc(3 * sizeof(double));
   vel[0] = v[0];
   vel[1] = v[1];
   vel[2] = v[2];
   return vel;
}

/**
  * Calculate the position of a planet.
  * p is the planet struct.
  * vel is an array of velocity values.
  **/
double* getPosition(planet p, double* vel) {
   double pos[3] = {p.position[0] + vel[0] * TIMESTEP,
                    p.position[1] + vel[1] * TIMESTEP,
                    p.position[2] + vel[2] * TIMESTEP};
   double* posPtr = malloc(3 * sizeof(double));
   posPtr[0] = pos[0];
   posPtr[1] = pos[1];
   posPtr[2] = pos[2];
   return posPtr;
}

/**
  * Update the position, velocity, and acceleration of all planets.
  * planets is an array of planet structs.
  * numPlanets is the number of planets in the array.
  **/
void updateAll(planet* planets, int numPlanets) {
   for (int i = 0; i < numPlanets; i++) {
      double* acc = getAcceleration(planets[i], planets, numPlanets);
      double* vel = getVelocity(planets[i], acc);
      double* pos = getPosition(planets[i], vel);
      for (int j = 0; j < 3; j++) {
         planets[i].velocity[j] = vel[j];
         planets[i].position[j] = pos[j];
      }
      free(acc);
      free(vel);
      free(pos);
   }
}

/**
  * Print out information about all planets.
  * planets is an array of planet structs.
  * numPlanets is the number of planets in the array.
  **/
void printPlanets(planet* planets, int numPlanets) {
   printf("\nTime: %d\n", TIMESTEP);
   for (int i = 0; i < numPlanets; i++) {
      printf("%s:\n", planets[i].name);
      printf("   mass: %7.2e kg\n", planets[i].mass);
      printf(" radius: %7.2e m\n", planets[i].radius);
      printf("position: (%7.2e, %7.2e, %7.2e) m\n",
             planets[i].position[0], planets[i].position[1], planets[i].position[2]);
      printf("velocity: (%7.2e, %7.2e, %7.2e) m/s\n",
             planets[i].velocity[0], planets[i].velocity[1], planets[i].velocity[2]);
   }
}

int main() {
   int numPlanets;
   printf("Enter number of planets: ");
   scanf("%d", &numPlanets);

   planet* planets = malloc(numPlanets * sizeof(planet));

   for (int i = 0; i < numPlanets; i++) {
      planets[i] = getPlanet();
   }

   printf("\nInitial state:");
   printPlanets(planets, numPlanets);

   for (int i = 0; i < 10; i++) {  // simulate 10 iterations
      updateAll(planets, numPlanets);
      printf("\nState after iteration %d:", i + 1);
      printPlanets(planets, numPlanets);
   }

   free(planets);
   return 0;
}