//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complex
#include <stdio.h>
#include <math.h>

#define G 9.81
#define M_EARTH 5.972e24

typedef struct {
   double x, y;
} Vector2;

typedef struct {
   Vector2 pos;
   Vector2 vel;
   double mass;
} CelestialBody;

typedef struct {
   int num_bodies;
   CelestialBody bodies[];
} Universe;

void update_velocity(CelestialBody *body, double dt, Universe *universe) {
   int i;
   double distance_squared, acceleration_magnitude;
   Vector2 acceleration = {0, 0};
   CelestialBody *other_body;
   for (i = 0; i < universe->num_bodies; i++) {
      if (body == &(universe->bodies[i]))
         continue;
      other_body = &(universe->bodies[i]);
      distance_squared = pow((other_body->pos.x - body->pos.x), 2) + 
         pow((other_body->pos.y - body->pos.y), 2);
      acceleration_magnitude = G * other_body->mass / distance_squared;
      acceleration.x += acceleration_magnitude * 
         (other_body->pos.x - body->pos.x) / sqrt(distance_squared);
      acceleration.y += acceleration_magnitude * 
         (other_body->pos.y - body->pos.y) / sqrt(distance_squared);
   }
   body->vel.x += acceleration.x * dt;
   body->vel.y += acceleration.y * dt;
}

void update_position(CelestialBody *body, double dt) {
   body->pos.x += body->vel.x * dt;
   body->pos.y += body->vel.y * dt;
}

void update_universe(Universe *universe, double dt) {
   int i;
   for (i = 0; i < universe->num_bodies; i++) {
      update_velocity(&(universe->bodies[i]), dt, universe);
   }
   for (i = 0; i < universe->num_bodies; i++) {
      update_position(&(universe->bodies[i]), dt);
   }
}

int main() {
   Universe universe;
   universe.num_bodies = 2;
   universe.bodies[0] = (CelestialBody){.pos={0, 0}, .vel={0, 0}, .mass=M_EARTH};
   universe.bodies[1] = (CelestialBody){.pos={1, 0}, .vel={0, 8000}, .mass=1000};
   double dt = 0.01;
   int num_steps = 10000;
   int i;
   for (i = 0; i < num_steps; i++) {
      update_universe(&universe, dt);
   }
   printf("Final Positions and Velocities:\n");
   for (i = 0; i < universe.num_bodies; i++) {
      printf("Body %d:\nPosition = (%f, %f)\nVelocity = (%f, %f)\n\n", i, 
         universe.bodies[i].pos.x, universe.bodies[i].pos.y, 
         universe.bodies[i].vel.x, universe.bodies[i].vel.y);
   }
   return 0;
}