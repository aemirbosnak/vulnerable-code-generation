#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <math.h>

int main() {
  int n_sims = 10;
  for (int i = 0; i < n_sims; i++) {
    double t_max = 10.0;
    double dt = 0.1;
    double x0 = 0.0;
    double y0 = 0.0;
    double z0 = 1.0;
    double v_x0 = 1.0;
    double v_y0 = 0.0;
    double v_z0 = 0.0;

    double t = 0.0;
    double x = x0;
    double y = y0;
    double z = z0;
    double v_x = v_x0;
    double v_y = v_y0;
    double v_z = v_z0;

    while (t < t_max && x >= 0 && y >= 0 && z >= 0) {
      double dx = v_x * dt;
      double dy = v_y * dt;
      double dz = v_z * dt;

      x += dx;
      y += dy;
      z -= dz;

      t += dt;
    }

    printf("Simulation %d:\n", i + 1);
    printf("Position at crash: (%f, %f, %f)\n", x, y, z);
    printf("Time to crash: %.2f seconds\n", t);
  }

  return 0;
}
