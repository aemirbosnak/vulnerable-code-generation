#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n_sims;
  printf("Enter the number of simulations: ");
  scanf("%d", &n_sims);

  for (int i = 0; i < n_sims; i++) {
    int time_step = 0;
    float x = 0.0f, y = 0.0f, z = 0.0f;
    float acceleration_g = 9.8f;

    while (x < 10.0f) {
      time_step++;
      x += acceleration_g * (float)time_step / 1000.0f;
      y += acceleration_g * (float)time_step / 1000.0f;
      z += acceleration_g * (float)time_step / 1000.0f;

      if (time_step % 1000 == 0) {
        printf("Time step: %d, Position: (%.2f, %.2f, %.2f)\n", time_step, x, y, z);
      }
    }

    printf("Simulation complete.\n");
  }

  return 0;
}
