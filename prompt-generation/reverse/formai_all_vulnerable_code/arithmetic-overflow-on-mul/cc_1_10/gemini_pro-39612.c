//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the performance-critical component
typedef struct {
  int x;
  int y;
  int z;
} PerformanceComponent;

// Create a new performance component
PerformanceComponent* create_component(int x, int y, int z) {
  PerformanceComponent* component = malloc(sizeof(PerformanceComponent));
  component->x = x;
  component->y = y;
  component->z = z;
  return component;
}

// Destroy a performance component
void destroy_component(PerformanceComponent* component) {
  free(component);
}

// Perform a calculation on the performance component
int calculate(PerformanceComponent* component) {
  return component->x * component->y * component->z;
}

int main() {
  // Create a few performance components
  PerformanceComponent* components[3];
  components[0] = create_component(1, 2, 3);
  components[1] = create_component(4, 5, 6);
  components[2] = create_component(7, 8, 9);

  // Perform calculations on the components
  int results[3];
  for (int i = 0; i < 3; i++) {
    results[i] = calculate(components[i]);
  }

  // Print the results
  for (int i = 0; i < 3; i++) {
    printf("Result %d: %d\n", i, results[i]);
  }

  // Destroy the components
  for (int i = 0; i < 3; i++) {
    destroy_component(components[i]);
  }

  return 0;
}