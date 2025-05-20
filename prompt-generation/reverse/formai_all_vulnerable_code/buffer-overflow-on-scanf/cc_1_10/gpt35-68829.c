//FormAI DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>

int main() {
  printf("Welcome to Energy Blast!\n");
  printf("In this game, you will use your energy to blast away obstacles and enemies.\n");
  printf("Are you ready to start? (1 for Yes / 0 for No)\n");

  int start;
  scanf("%d", &start);

  if (start == 0) {
    printf("Goodbye!\n");
    return 0;
  }

  int energy = 100;
  int score = 0;

  printf("You have %d energy.\n", energy);
  printf("Use your energy wisely. Press 'b' to blast obstacles and 'e' to blast enemies.\n");

  while (energy > 0) {
    char input;
    scanf(" %c", &input);

    if (input == 'b') {
      printf("Blasting obstacles...\n");
      energy -= 10;
      score += 5;

      if (energy <= 0) {
        printf("You ran out of energy!\n");
        printf("Final score: %d\n", score);
        return 0;
      }

      printf("You have %d energy left.\n", energy);
      printf("Score: %d\n", score);
    }
    else if (input == 'e') {
      printf("Blasting enemies...\n");
      energy -= 20;
      score += 10;

      if (energy <= 0) {
        printf("You ran out of energy!\n");
        printf("Final score: %d\n", score);
        return 0;
      }

      printf("You have %d energy left.\n", energy);
      printf("Score: %d\n", score);
    }
    else {
      printf("Invalid input. Use 'b' to blast obstacles and 'e' to blast enemies.\n");
    }
  }

  return 0;
}