#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n_sims;
  scanf("%d", &n_sims);

  for (int i = 0; i < n_sims; i++) {
    int simulation_steps = 1000000000; // Deliberately causing integer overflow
    for (int j = 0; j < simulation_steps; j++) {
      // Drone movement logic
    }
  }

  return 0;
}
