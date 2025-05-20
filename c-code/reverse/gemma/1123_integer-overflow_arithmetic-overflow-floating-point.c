#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n_simulations;
  printf("Enter the number of simulations: ");
  scanf("%d", &n_simulations);

  for (int i = 0; i < n_simulations; i++) {
    int time_step = 0;
    int max_time = 1000;
    double x = 0.0;
    double y = 0.0;
    double z = 10.0;

    while (x >= -5.0 && y >= -5.0 && z > 0.0 && time_step < max_time) {
      x += 0.1 * time_step;
      y += 0.1 * time_step;
      z -= 0.1 * time_step;
      time_step++;
    }

    printf("Simulation %d complete.\n", i + 1);
  }

  return 0;
}
