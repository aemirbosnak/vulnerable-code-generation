//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define G 6.6743e-11

struct Planet {
  char name[20];
  double mass; //in kg
  double x, y, z; //in m
  double vx, vy, vz; //in m/s
  double fx, fy, fz; //in N
};

void reset_forces(struct Planet* planets, int n) {
  int i;
  for(i=0; i<n; i++) {
    planets[i].fx = 0;
    planets[i].fy = 0;
    planets[i].fz = 0;
  }
}

void calculate_forces(struct Planet* planets, int n) {
  int i, j;
  double dx, dy, dz, distance, force;
  for(i=0; i<n-1; i++) {
    for(j=i+1; j<n; j++) {
      dx = planets[j].x - planets[i].x;
      dy = planets[j].y - planets[i].y;
      dz = planets[j].z - planets[i].z;
      distance = sqrt(dx*dx + dy*dy + dz*dz);
      force = G * planets[i].mass * planets[j].mass / (distance*distance);
      planets[i].fx += force * dx / distance;
      planets[i].fy += force * dy / distance;
      planets[i].fz += force * dz / distance;
      planets[j].fx -= force * dx / distance;
      planets[j].fy -= force * dy / distance;
      planets[j].fz -= force * dz / distance;
    }
  }
}

void calculate_velocities(struct Planet* planets, int n, double dt) {
  int i;
  for(i=0; i<n; i++) {
    planets[i].vx += planets[i].fx / planets[i].mass * dt;
    planets[i].vy += planets[i].fy / planets[i].mass * dt;
    planets[i].vz += planets[i].fz / planets[i].mass * dt;
  }
}

void calculate_positions(struct Planet* planets, int n, double dt) {
  int i;
  for(i=0; i<n; i++) {
    planets[i].x += planets[i].vx * dt;
    planets[i].y += planets[i].vy * dt;
    planets[i].z += planets[i].vz * dt;
  } 
}

int main() {
  int i, n, steps;
  double dt;
  printf("Enter the number of planets: ");
  scanf("%d", &n);
  struct Planet* planets = (struct Planet*) malloc(n * sizeof(struct Planet));
  for(i=0; i<n; i++) {
    printf("Enter the name of planet %d: ", i+1);
    scanf("%s", planets[i].name);
    printf("Enter the mass of planet %d in kg: ", i+1);
    scanf("%lf", &planets[i].mass);
    printf("Enter the initial x,y, and z coordinates of planet %d in m: ", i+1);
    scanf("%lf%lf%lf", &planets[i].x, &planets[i].y, &planets[i].z);
    printf("Enter the initial x,y, and z components of velocity of planet %d in m/s: ", i+1);
    scanf("%lf%lf%lf", &planets[i].vx, &planets[i].vy, &planets[i].vz);
  }
  printf("Enter the time step in seconds: ");
  scanf("%lf", &dt);
  printf("Enter the number of time steps: ");
  scanf("%d", &steps);
  for(i=0; i<steps; i++) {
    reset_forces(planets, n);
    calculate_forces(planets, n);
    calculate_velocities(planets, n, dt);
    calculate_positions(planets, n, dt);
  }
  for(i=0; i<n; i++) {
    printf("Final position of planet %s: (%.3f,%.3f,%.3f) m\n", 
           planets[i].name, planets[i].x, planets[i].y, planets[i].z);
  }
  free(planets);
  return 0;
}