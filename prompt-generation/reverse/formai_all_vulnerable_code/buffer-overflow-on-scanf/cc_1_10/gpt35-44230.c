//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define Pi 3.141592653589793
#define G 6.67428e-11 // the gravitational constant

// the particle structure
struct particle {
    double x, y, z; // the position of the particle
    double vx, vy, vz; // the velocity of the particle
    double ax, ay, az; // the acceleration of the particle
    double mass; // the mass of the particle
    double radius; // the radius of the particle
};

typedef struct particle Particle;

// function to calculate the distance between two particles
double distance(Particle p1, Particle p2) {
    double dx, dy, dz, r;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    dz = p2.z - p1.z;
    r = sqrt(dx*dx + dy*dy + dz*dz);
    return r;
}

// function to calculate the gravitational force between two particles
double force(Particle p1, Particle p2) {
    double r, f;
    r = distance(p1, p2);
    f = (G * p1.mass * p2.mass) / (r*r);
    return f;
}

int main() {
    int i, j, n; // loop variables
    double t, dt; // time variables
    Particle *particles; // the particle array
    Particle *p1, *p2; // pointers to particles
    double dx, dy, dz, r, f; // variables for force calculation
    double ax, ay, az; // variables for acceleration update
    double vx, vy, vz; // variables for velocity update

    // read the number of particles from input
    scanf("%d", &n);

    // allocate memory for the particle array
    particles = (Particle*) malloc(n * sizeof(Particle));

    // read the initial state of the particles from input
    for(i=0; i<n; i++) {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
            &particles[i].x, &particles[i].y, &particles[i].z,
            &particles[i].vx, &particles[i].vy, &particles[i].vz,
            &particles[i].mass, &particles[i].radius
        );
    }

    // initialize the time and the time step
    t = 0.0;
    dt = 0.01;

    // simulation loop
    while(1) {

        // calculate the forces on each particle
        for(i=0; i<n; i++) {
            particles[i].ax = 0.0;
            particles[i].ay = 0.0;
            particles[i].az = 0.0;
            p1 = &particles[i];
            for(j=0; j<n; j++) {
                if(i==j) continue;
                p2 = &particles[j];
                f = force(*p1, *p2);
                dx = p2->x - p1->x;
                dy = p2->y - p1->y;
                dz = p2->z - p1->z;
                r = distance(*p1, *p2);
                ax = f * dx / r / p1->mass;
                ay = f * dy / r / p1->mass;
                az = f * dz / r / p1->mass;
                particles[i].ax += ax;
                particles[i].ay += ay;
                particles[i].az += az;
            }
        }

        // update the velocities
        for(i=0; i<n; i++) {
            vx = particles[i].vx + particles[i].ax*dt;
            vy = particles[i].vy + particles[i].ay*dt;
            vz = particles[i].vz + particles[i].az*dt;
            particles[i].vx = vx;
            particles[i].vy = vy;
            particles[i].vz = vz;
        }

        // update the positions
        for(i=0; i<n; i++) {
            particles[i].x += particles[i].vx*dt;
            particles[i].y += particles[i].vy*dt;
            particles[i].z += particles[i].vz*dt;
        }

        // update the time
        t += dt;

        // print the current state of the particles
        for(i=0; i<n; i++) {
            printf("%lf %lf %lf %lf %lf %lf %lf %lf\n",
                particles[i].x, particles[i].y, particles[i].z,
                particles[i].vx, particles[i].vy, particles[i].vz,
                particles[i].mass, particles[i].radius
            );
        }

        // exit if simulation is complete
        if(t >= 1000.0) break;
    }

    // free the memory allocated for the particle array
    free(particles);

    return 0;
}