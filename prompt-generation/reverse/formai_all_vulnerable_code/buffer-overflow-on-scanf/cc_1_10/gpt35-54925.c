//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

#define MAX_PLANETS 10

#define G 6.673e-11

struct planet {
  char name[50];
  double mass;
  double x, y, z;
  double vx, vy, vz;
};

int main(void) {
  int n_planets, i, j, step;
  double delta_t;
  struct planet planets[MAX_PLANETS];

  printf("Enter the number of planets: ");
  scanf("%d", &n_planets);

  for (i = 0; i < n_planets; i++) {
    printf("Planet %d:\n", i + 1);
    printf("  Name: ");
    scanf("%s", planets[i].name);
    printf("  Mass (kg): ");
    scanf("%lf", &planets[i].mass);
    printf("  Position (x,y,z in m): ");
    scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
    printf("  Velocity (vx,vy,vz in m/s): ");
    scanf("%lf %lf %lf", &planets[i].vx, &planets[i].vy, &planets[i].vz);
  }

  printf("Enter the time step (in seconds): ");
  scanf("%lf", &delta_t);

  printf("Enter the number of time steps: ");
  scanf("%d", &step);

  for (i = 0; i < step; i++) {
    printf("Step %d:\n", i + 1);

    for (j = 0; j < n_planets; j++) {
      int k;
      double ax = 0, ay = 0, az = 0;

      for (k = 0; k < n_planets; k++) {
        if (k != j) {
          double dx = planets[k].x - planets[j].x;
          double dy = planets[k].y - planets[j].y;
          double dz = planets[k].z - planets[j].z;
          double dist = sqrt(dx*dx + dy*dy + dz*dz);
          double force = G*planets[j].mass*planets[k].mass/(dist*dist*dist);

          ax += force*dx;
          ay += force*dy;
          az += force*dz;
        }
      }

      planets[j].vx += ax*delta_t/planets[j].mass;
      planets[j].vy += ay*delta_t/planets[j].mass;
      planets[j].vz += az*delta_t/planets[j].mass;

      planets[j].x += planets[j].vx*delta_t;
      planets[j].y += planets[j].vy*delta_t;
      planets[j].z += planets[j].vz*delta_t;

      printf("  %s: (%e,%e,%e) (%e,%e,%e)\n",
             planets[j].name,
             planets[j].x, planets[j].y, planets[j].z,
             planets[j].vx, planets[j].vy, planets[j].vz);
    }
  }

  return 0;
}