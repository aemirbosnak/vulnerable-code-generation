//FormAI DATASET v1.0 Category: Unit converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  char units[3][10] = { "jawns", "tacos", "bananas" };
  double matrix[3][3] = {{1, 6.6, 12}, {0.15, 1, 25}, {0.083, 0.04, 1}};
  double amount = 0;
  char from[10], to[10];
  int from_idx = -1, to_idx = -1;

  printf("Welcome to the Surreal C Unit Converter!\n");
  printf("You can convert between jawns, tacos, and bananas!\n");

  while (from_idx == -1) {
    printf("Enter the unit you are converting from: ");
    scanf("%s", &from);
    int i;
    for (i = 0; i < 3; i++) {
      if (strcmp(units[i], from) == 0){
        from_idx = i;
        break;
      }
    }
    if (from_idx == -1) {
      printf("Sorry, we do not support that unit.\n");
    }
  }

  while (to_idx == -1) {
    printf("Enter the unit you are converting to: ");
    scanf("%s", &to);
    int i;
    for (i = 0; i < 3; i++) {
      if (strcmp(units[i], to) == 0){
        to_idx = i;
        break;
      }
    }
    if (to_idx == -1) {
      printf("Sorry, we do not support that unit.\n");
    }
  }

  printf("Enter the amount you are converting: ");
  scanf("%lf", &amount);

  double result = matrix[from_idx][to_idx] * amount;
  printf("%.2f %s is equal to %.2f %s.\n", amount, units[from_idx], result, units[to_idx]);

  return 0;
}