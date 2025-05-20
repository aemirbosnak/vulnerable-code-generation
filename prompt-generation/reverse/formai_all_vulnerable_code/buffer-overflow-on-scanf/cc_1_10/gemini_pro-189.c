//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DATA_POINTS 100000

struct data_point {
  double x;
  double y;
};

struct regression_line {
  double slope;
  double intercept;
};

struct regression_line calculate_regression_line(struct data_point *data_points, int num_data_points) {
  double sum_x = 0;
  double sum_y = 0;
  double sum_x_squared = 0;
  double sum_x_y = 0;

  for (int i = 0; i < num_data_points; i++) {
    sum_x += data_points[i].x;
    sum_y += data_points[i].y;
    sum_x_squared += data_points[i].x * data_points[i].x;
    sum_x_y += data_points[i].x * data_points[i].y;
  }

  double slope = (num_data_points * sum_x_y - sum_x * sum_y) / (num_data_points * sum_x_squared - sum_x * sum_x);
  double intercept = (sum_y - slope * sum_x) / num_data_points;

  struct regression_line regression_line = {slope, intercept};
  return regression_line;
}

int main() {
  int num_data_points;
  scanf("%d", &num_data_points);

  if (num_data_points > MAX_DATA_POINTS) {
    printf("Error: Too many data points\n");
    return 1;
  }

  struct data_point *data_points = malloc(sizeof(struct data_point) * num_data_points);
  if (data_points == NULL) {
    printf("Error: Out of memory\n");
    return 1;
  }

  for (int i = 0; i < num_data_points; i++) {
    scanf("%lf %lf", &data_points[i].x, &data_points[i].y);
  }

  struct regression_line regression_line = calculate_regression_line(data_points, num_data_points);

  printf("Slope: %.2f\n", regression_line.slope);
  printf("Intercept: %.2f\n", regression_line.intercept);

  free(data_points);
  return 0;
}