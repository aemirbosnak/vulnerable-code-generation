//FormAI DATASET v1.0 Category: Physics simulation ; Style: Linus Torvalds
#include<stdio.h>
#include<math.h>

#define G 6.6743e-11          // Gravitational constant

int main(){

    int n;        // Number of particles
    double m[10], r[10][3], v[10][3], F[10][3]; // Particle mass, position, velocity and force
    
    printf("Enter the number of particles (max. 10): ");
    scanf("%d", &n);
    
    printf("Enter the mass (in kg), position (in m) and velocity (in m/s) of each particle:\n");
    
    for(int i=0; i<n; i++){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &m[i], &r[i][0], &r[i][1], &r[i][2], &v[i][0], &v[i][1], &v[i][2]);
    }
    
    double dt = 0.01;   // Time step
    int t = 0;          // Time
    
    while(t < 100){    // Simulation time
        
        for(int i=0; i<n; i++){ // Initialize force to 0 for each particle
            F[i][0] = 0;
            F[i][1] = 0;
            F[i][2] = 0;
        }
        
        for(int i=0; i<n; i++){     // Calculate force between each pair of particles
            for(int j=0; j<n; j++){
                if(i != j){
                    double rij[3], rij_mag3;
                    
                    rij[0] = r[j][0] - r[i][0];
                    rij[1] = r[j][1] - r[i][1];
                    rij[2] = r[j][2] - r[i][2];
                    
                    rij_mag3 = pow(pow(rij[0], 2) + pow(rij[1], 2) + pow(rij[2], 2), 1.5);
                    
                    double Fij[3];
                    
                    Fij[0] = G * m[i] * m[j] * rij[0] / rij_mag3;
                    Fij[1] = G * m[i] * m[j] * rij[1] / rij_mag3;
                    Fij[2] = G * m[i] * m[j] * rij[2] / rij_mag3;
                    
                    F[i][0] += Fij[0];
                    F[i][1] += Fij[1];
                    F[i][2] += Fij[2];
                }
            }
        }
        
        for(int i=0; i<n; i++){ // Update velocity and position of each particle
            double a[3];
            
            a[0] = F[i][0] / m[i];
            a[1] = F[i][1] / m[i];
            a[2] = F[i][2] / m[i];
            
            v[i][0] += a[0] * dt;
            v[i][1] += a[1] * dt;
            v[i][2] += a[2] * dt;
            
            r[i][0] += v[i][0] * dt;
            r[i][1] += v[i][1] * dt;
            r[i][2] += v[i][2] * dt;
        }
        
        t++;  // Update time
    }
    
    printf("Final positions and velocities of particles:\n");
    
    for(int i=0; i<n; i++){
        printf("Particle %d: (%lf, %lf, %lf) m (%lf, %lf, %lf) m/s\n", i, r[i][0], r[i][1], r[i][2], v[i][0], v[i][1], v[i][2]);
    }
    
    return 0;
}