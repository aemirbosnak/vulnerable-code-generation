//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int sides;
  int rolls;
  int i;
  int j;
  int k;
  int count[6];
  int max = 0;
  int min = 6;
  int sum = 0;
  int avg;

  // Get the number of sides from the user.
  printf("How many sides does the die have? ");
  scanf("%d", &sides);

  // Get the number of rolls from the user.
  printf("How many times do you want to roll the die? ");
  scanf("%d", &rolls);

  // Initialize the count array.
  for (i = 0; i < 6; i++) {
    count[i] = 0;
  }

  // Seed the random number generator.
  srand(time(NULL));

  // Roll the die and count the number of times each side comes up.
  for (i = 0; i < rolls; i++) {
    int roll = rand() % sides + 1;
    count[roll - 1]++;
  }

  // Find the maximum and minimum number of times a side came up.
  for (i = 0; i < 6; i++) {
    if (count[i] > max) {
      max = count[i];
    }
    if (count[i] < min) {
      min = count[i];
    }
  }

  // Calculate the sum of the number of times each side came up.
  for (i = 0; i < 6; i++) {
    sum += count[i];
  }

  // Calculate the average number of times a side came up.
  avg = sum / rolls;

  // Print the results.
  printf("\nResults:\n");
  printf("Side\tCount\n");
  for (i = 0; i < 6; i++) {
    printf("%d\t%d\n", i + 1, count[i]);
  }
  printf("\nMaximum:\t%d\n", max);
  printf("Minimum:\t%d\n", min);
  printf("Sum:\t\t%d\n", sum);
  printf("Average:\t%d\n", avg);
  printf("\n");

  return 0;
}