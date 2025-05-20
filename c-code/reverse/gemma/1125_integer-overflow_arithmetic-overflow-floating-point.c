#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int simulation_count, time_step;
  printf("Enter the number of simulations: ");
  scanf("%d", &simulation_count);

  printf("Enter the time step: ");
  scanf("%d", &time_step);

  int trajectory_points = (simulation_count * time_step) + 1;
  double *x_trajectory = malloc(trajectory_points * sizeof(double));
  double *y_trajectory = malloc(trajectory_points * sizeof(double));

  // Calculate the trajectory points
  for (int i = 0; i < trajectory_points; i++) {
    x_trajectory[i] = 10 * i;
    y_trajectory[i] = 5 * i;
  }

  // Print the trajectory points
  for (int i = 0; i < trajectory_points; i++) {
    printf("x: %.2lf, y: %.2lf\n", x_trajectory[i], y_trajectory[i]);
  }

  free(x_trajectory);
  free(y_trajectory);

  return 0;
}
