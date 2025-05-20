//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complete
#include <stdio.h>
#include <math.h>

#define MAX_PLANETS 10
#define TIME_STEP 0.1
#define GRAV_CONST 6.674 * pow(10,-11)

typedef struct {
  double x;
  double y;
  double z;
} Vector;

typedef struct {
  Vector pos;
  Vector vel;
  Vector force;
  double mass;
} Planet;

void calculate_force(Planet planets[], int num_planets, int index) {
  int i;
  planets[index].force.x = 0;
  planets[index].force.y = 0;
  planets[index].force.z = 0;
  for (i = 0; i < num_planets; i++) {
    if (i != index) {
      double dx = planets[i].pos.x - planets[index].pos.x;
      double dy = planets[i].pos.y - planets[index].pos.y;
      double dz = planets[i].pos.z - planets[index].pos.z;
      double r = sqrt(dx*dx + dy*dy + dz*dz);
      double f = (GRAV_CONST * planets[i].mass * planets[index].mass) / (r*r);
      planets[index].force.x += f * dx / r;
      planets[index].force.y += f * dy / r;
      planets[index].force.z += f * dz / r;
    }
  }
}

void update_planet(Planet *planet) {
  planet->vel.x += planet->force.x / planet->mass * TIME_STEP;
  planet->vel.y += planet->force.y / planet->mass * TIME_STEP;
  planet->vel.z += planet->force.z / planet->mass * TIME_STEP;
  planet->pos.x += planet->vel.x * TIME_STEP;
  planet->pos.y += planet->vel.y * TIME_STEP;
  planet->pos.z += planet->vel.z * TIME_STEP;
}

void update_all_planets(Planet planets[], int num_planets) {
  int i;
  for (i = 0; i < num_planets; i++) {
    calculate_force(planets, num_planets, i);
  }
  for (i = 0; i < num_planets; i++) {
    update_planet(&planets[i]);
  }
}

double calc_total_energy(Planet planets[], int num_planets) {
  double total_energy = 0;
  int i, j;
  for (i = 0; i < num_planets; i++) {
    double kinetic_energy = 0.5 * planets[i].mass * 
      (planets[i].vel.x * planets[i].vel.x + 
          planets[i].vel.y * planets[i].vel.y + 
          planets[i].vel.z * planets[i].vel.z);
    total_energy += kinetic_energy;
    for (j = i+1; j < num_planets; j++) {
      double dx = planets[i].pos.x - planets[j].pos.x;
      double dy = planets[i].pos.y - planets[j].pos.y;
      double dz = planets[i].pos.z - planets[j].pos.z;
      double dist = sqrt(dx*dx + dy*dy + dz*dz);
      double potential_energy = -GRAV_CONST * planets[i].mass * planets[j].mass / dist;
      total_energy += potential_energy;
    }
  }
  return total_energy;
}

void print_planet(Planet planet) {
  printf("Position: (%f, %f, %f)\n", planet.pos.x, planet.pos.y, planet.pos.z);
  printf("Velocity: (%f, %f, %f)\n", planet.vel.x, planet.vel.y, planet.vel.z);
  printf("Mass: %f\n", planet.mass);
}

int main() {
  Planet planets[MAX_PLANETS];
  int num_planets;
  printf("Please enter the number of planets (1-10): ");
  scanf("%d", &num_planets);
  if (num_planets < 1 || num_planets > 10) {
    printf("Invalid number of planets. Please try again.\n");
    return 1;
  }
  int i;
  for (i = 0; i < num_planets; i++) {
    printf("Please enter information for planet %d:\n", i+1);
    printf("Position (x y z): ");
    scanf("%lf %lf %lf", &planets[i].pos.x, &planets[i].pos.y, &planets[i].pos.z);
    printf("Velocity (x y z): ");
    scanf("%lf %lf %lf", &planets[i].vel.x, &planets[i].vel.y, &planets[i].vel.z);
    printf("Mass: ");
    scanf("%lf", &planets[i].mass);
  }
  double total_energy = calc_total_energy(planets, num_planets);
  printf("Initial total energy: %f\n", total_energy);
  printf("Time evolution:\n");
  for (i = 0; i < 1000; i++) {
    update_all_planets(planets, num_planets);
    total_energy = calc_total_energy(planets, num_planets);
    printf("Step %d: total energy = %f\n", i, total_energy);
  }
  return 0;
}