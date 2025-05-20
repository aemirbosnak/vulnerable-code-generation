#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int baggage_count = 0;
  int baggage_limit = 100;
  int user_input;

  printf("Enter the number of bags you want to check:");
  scanf("%d", &user_input);

  if (user_input > baggage_limit) {
    printf("Error: Number of bags exceeds limit.");
  } else {
    baggage_count = user_input;
    int baggage_weights[baggage_count];

    for (int i = 0; i < baggage_count; i++) {
      printf("Enter the weight of each bag (in kg): ");
      scanf("%d", &baggage_weights[i]);
    }

    int total_weight = 0;
    for (int i = 0; i < baggage_count; i++) {
      total_weight += baggage_weights[i];
    }

    if (total_weight > baggage_limit * 0.8) {
      printf("Error: Total weight exceeds baggage limit.");
    } else {
      printf("Total weight: %d kg", total_weight);
    }
  }

  return 0;
}
