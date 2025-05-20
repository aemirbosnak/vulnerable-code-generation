//FormAI DATASET v1.0 Category: Computer Biology ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_ATOMS 100
#define MAX_TIME 10000

struct Atom {
    double x, y, z;
    double vx, vy, vz;
};

int main() {
    struct Atom molecule[MAX_ATOMS];
    double dt = 0.01; // time step
    double time, L;
    int n_atoms, n_steps;
    int i, j, k;

    // read input from file
    FILE *input_file = fopen("molecule.in", "r");
    fscanf(input_file, "%lf %d", &L, &n_atoms);
    for(i=0; i<n_atoms; i++) {
        fscanf(input_file, "%lf %lf %lf", &molecule[i].x, &molecule[i].y, &molecule[i].z);
        molecule[i].vx = molecule[i].vy = molecule[i].vz = 0.0;
    }
    fclose(input_file);

    // simulate molecular dynamics
    n_steps = MAX_TIME/dt;
    for(k=0; k<n_steps; k++) {
        time = k*dt;

        for(i=0; i<n_atoms; i++) {
            // compute forces
            double fx, fy, fz;
            fx = fy = fz = 0.0;
            for(j=0; j<n_atoms; j++) {
                if(i==j) continue;

                double dx, dy, dz, r, r2, r6, r12, f;
                dx = molecule[j].x - molecule[i].x;
                dy = molecule[j].y - molecule[i].y;
                dz = molecule[j].z - molecule[i].z;
                r2 = dx*dx + dy*dy + dz*dz;
                r = sqrt(r2);
                r6 = pow(r,6.0);
                r12 = pow(r6,2.0);
                f = 48.0/r12 - 24.0/r6;
                fx += f*dx;
                fy += f*dy;
                fz += f*dz;
            }

            // update velocities
            molecule[i].vx += fx*dt;
            molecule[i].vy += fy*dt;
            molecule[i].vz += fz*dt;
        }

        for(i=0; i<n_atoms; i++) {
            // update positions
            molecule[i].x += molecule[i].vx*dt;
            molecule[i].y += molecule[i].vy*dt;
            molecule[i].z += molecule[i].vz*dt;

            // apply periodic boundary conditions
            if(molecule[i].x >= L) molecule[i].x -= L;
            if(molecule[i].y >= L) molecule[i].y -= L;
            if(molecule[i].z >= L) molecule[i].z -= L;
            if(molecule[i].x < 0) molecule[i].x += L;
            if(molecule[i].y < 0) molecule[i].y += L;
            if(molecule[i].z < 0) molecule[i].z += L;
        }

        // write output to file
        char filename[100];
        sprintf(filename, "output/%05d.xyz", k);
        FILE *output_file = fopen(filename, "w");
        fprintf(output_file, "%d\n", n_atoms);
        fprintf(output_file, "time = %lf\n", time);
        for(i=0; i<n_atoms; i++) {
            fprintf(output_file, "C %lf %lf %lf\n", molecule[i].x, molecule[i].y, molecule[i].z);
        }
        fclose(output_file);
    }

    return 0;
}