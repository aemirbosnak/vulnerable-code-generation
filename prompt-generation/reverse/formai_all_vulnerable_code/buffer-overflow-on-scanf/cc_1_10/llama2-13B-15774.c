//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

// Function to print a spiral pattern
void printSpiral(int radius, int startAngle, int endAngle) {
  int i, j;

  // Initialize radius and angle variables
  radius = 5;
  startAngle = 0;
  endAngle = 360;

  // Print outer circle
  for (i = 0; i < radius; i++) {
    for (j = 0; j < radius; j++) {
      printf(" ");
    }
    printf("\n");
  }

  // Print spiral pattern
  for (i = startAngle; i < endAngle; i += 10) {
    for (j = 0; j < radius; j++) {
      printf("*");
    }
    printf("\n");
  }

  // Print inner circle
  for (i = 0; i < radius; i++) {
    for (j = 0; j < radius; j++) {
      printf(" ");
    }
    printf("\n");
  }
}

int main() {
  int radius, startAngle, endAngle;

  // Get input from user
  printf("Enter radius: ");
  scanf("%d", &radius);
  printf("Enter start angle: ");
  scanf("%d", &startAngle);
  printf("Enter end angle: ");
  scanf("%d", &endAngle);

  // Print spiral pattern
  printSpiral(radius, startAngle, endAngle);

  return 0;
}