//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: accurate
#include <stdio.h>
#include <math.h>

/* Planetary data */
#define SOLAR_MASS     (1.98892e30)
#define EARTH_MASS     (5.9742e24)
#define JUPITER_MASS   (1.8987e27)
#define PLANET_DATA(...)          \
   { __VA_ARGS__ }
#define PLANET(name, mass, rx, ry, vx, vy) \
   PLANET_DATA(name, mass, rx, ry, vx, vy)

struct planet_data {
    const char *name;
    double mass;
    double rx;
    double ry;
    double vx;
    double vy;
};

struct planet_data planets[] = {
   PLANET("Sun",         SOLAR_MASS,    0,       0,   0,           0          ),
   PLANET("Mercury",     0.0553 * EARTH_MASS,
                                        0,   0.3871,   0,   47.87 * 1000),
   PLANET("Venus",       0.815 * EARTH_MASS,
                                        0,   0.7233,   0,   35.02 * 1000),
   PLANET("Earth",       EARTH_MASS,    0,       1,   29.79 * 1000, 0),
   PLANET("Mars",        0.107 * EARTH_MASS,
                                        0,       1.524,   0,   24.13 * 1000),
   PLANET("Jupiter",     JUPITER_MASS,  0,       5.203,   0,   13.07 * 1000),
   PLANET("Saturn",      95.2 * EARTH_MASS,
                                        0,       9.539,   0,     9.69 * 1000),
   PLANET("Uranus",      14.5 * EARTH_MASS,
                                        0,      19.18,    0,     6.81 * 1000),
   PLANET("Neptune",     17.1 * EARTH_MASS,
                                        0,      30.07,    0,     5.43 * 1000),
};

#define NUM_PLANETS (sizeof planets / sizeof(struct planet_data))

#define G 6.6742e-11

/* Compute the force exerted by planet j on planet i */
void compute_force(int i, int j, double fx[], double fy[], double *total_e)
{
   double dx = planets[j].rx - planets[i].rx;
   double dy = planets[j].ry - planets[i].ry;
   double dist = hypot(dx, dy);

   if (dist == 0) {
      /* collision - just zero out the force */
      fx[i] += 0;
      fy[i] += 0;
      return;
   }

   double F = G * planets[i].mass * planets[j].mass / (dist * dist);
   *total_e += F * dist;
   double theta = atan2(dy, dx);
   fx[i] += F * cos(theta);
   fy[i] += F * sin(theta);
}

void update_velocities(double fx[], double fy[], double delta_t)
{
   int i;

   for (i = 0; i < NUM_PLANETS; i++) {
      planets[i].vx += delta_t * fx[i] / planets[i].mass;
      planets[i].vy += delta_t * fy[i] / planets[i].mass;
   }
}

void update_positions(double delta_t)
{
   int i;

   for (i = 0; i < NUM_PLANETS; i++) {
      planets[i].rx += delta_t * planets[i].vx;
      planets[i].ry += delta_t * planets[i].vy;
   }
}

void print_planets(void)
{
   int i;

   for (i = 0; i < NUM_PLANETS; i++)
      printf("%s: r = (%g, %g), v = (%g, %g)\n", planets[i].name,
             planets[i].rx, planets[i].ry, planets[i].vx, planets[i].vy);
}

int main()
{
   double fx[NUM_PLANETS];
   double fy[NUM_PLANETS];
   double total_e = 0;
   double delta_t = 0.01;

   int i, j;

   for (i = 0; i < NUM_PLANETS; i++) {
      for (j = 0; j < NUM_PLANETS; j++) {
         fx[i] = 0;
         fy[i] = 0;
         compute_force(i, j, fx, fy, &total_e);
      }
   }

   printf("Initial: Total energy = %e\n", total_e);
   print_planets();

   for (i = 0; i < 10000; i++) {
      total_e = 0;
      for (j = 0; j < NUM_PLANETS; j++) {
         fx[j] = fy[j] = 0;
         for (i = 0; i < NUM_PLANETS; i++) {
            compute_force(j, i, fx, fy, &total_e);
         }
      }

      update_velocities(fx, fy, delta_t);
      update_positions(delta_t);
   }

   printf("Final: Total energy = %e\n", total_e);
   print_planets();

   return 0;
}