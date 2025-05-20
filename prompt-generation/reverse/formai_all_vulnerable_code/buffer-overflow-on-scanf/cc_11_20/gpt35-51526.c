//FormAI DATASET v1.0 Category: Weather simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initializing variables
  int temp;
  int choice;
  srand((unsigned) time(NULL));

  // Random temperature generation
  temp = rand() % 100 - 50;

  // Weather conditions based on temperature
  if (temp < 0) {
    printf("It's freezing outside!\n");
  } else if (temp < 10) {
    printf("It's chilly outside!\n");
  } else if (temp < 20) {
    printf("It's nice outside!\n");
  } else if (temp < 30) {
    printf("It's warm outside!\n");
  } else {
    printf("It's hot outside!\n");
  }

  // Clothing suggestions based on temperature
  if (temp < 0) {
    printf("Wear a heavy coat, gloves, and a hat!\n");
  } else if (temp < 10) {
    printf("Wear a coat and a scarf!\n");
  } else if (temp < 20) {
    printf("Wear a light jacket!\n");
  } else if (temp < 30) {
    printf("Wear shorts and a t-shirt!\n");
  } else {
    printf("Wear a hat and sunscreen!\n");
  }

  // User input for additional choice
  printf("Do you want to check out the forecast for the next week? (1 for yes, 0 for no)\n");
  scanf("%d", &choice);

  if (choice == 1) {
    printf("Forecast for the next week:\n");

    // Loop for generating random temperatures for next 7 days
    for (int i = 0; i < 7; i++) {
      temp = rand() % 30 + 5;
      printf("Day %d: %d degrees Celsius\n", i + 1, temp);
    }
  }

  return 0;
}