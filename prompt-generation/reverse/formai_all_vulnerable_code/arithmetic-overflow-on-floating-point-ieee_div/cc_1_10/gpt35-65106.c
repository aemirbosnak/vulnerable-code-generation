//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  float sunRadius = 6.9634e8;
  float mercuryDistance = 5.791*1.496e11;
  float venusDistance = 10.82*1.496e11;
  float earthDistance = 14.96*1.496e11;
  float marsDistance = 22.79*1.496e11;
  float jupiterDistance = 77.83*1.496e11;
  float saturnDistance = 142.7*1.496e11;
  float uranusDistance = 287.1*1.496e11;
  float neptuneDistance = 4495.1*1.496e11;
  
  float mercuryOrbitalSpeed = 47362;
  float venusOrbitalSpeed = 35020;
  float earthOrbitalSpeed = 29783;
  float marsOrbitalSpeed = 24159;
  float jupiterOrbitalSpeed = 13070;
  float saturnOrbitalSpeed = 9690;
  float uranusOrbitalSpeed = 6810;
  float neptuneOrbitalSpeed = 5430;
  
  // Simulation Settings
  float simulationTime = 1e10;
  float timeStep = 86400;
  
  // Calculation Variables
  float x, y, z, vx, vy, vz, r, v;
  float G = 6.6743e-11;
  
  // Initial Conditions - Sun
  x = 0.0;
  y = 0.0;
  z = 0.0;
  vx = 0.0;
  vy = 0.0;
  vz = 0.0;
  
  // Printing out the Solar System
  printf("************************************\n");
  printf("* Welcome to our Solar System!\n");
  printf("* Running simulation...\n");
  printf("************************************\n\n");
  
  // Loop through all the planets and the sun
  for (float time = 0; time <= simulationTime; time += timeStep){
      // Calculate Mercury's position
      r = sqrt(x*x + y*y + z*z);
      v = sqrt(vx*vx + vy*vy + vz*vz);
      float F = G * ((sunRadius*0.055*mercuryDistance)/(r*r));
      float ax = ((-F*x)/r);
      float ay = ((-F*y)/r);
      float az = ((-F*z)/r);
      vx += (ax * timeStep);
      vy += (ay * timeStep);
      vz += (az * timeStep);
      x += (vx * timeStep);
      y += (vy * timeStep);
      z += (vz * timeStep);
      printf("Mercury Position: %f x %f y %f z\n", x/1e9, y/1e9, z/1e9);
  }
}