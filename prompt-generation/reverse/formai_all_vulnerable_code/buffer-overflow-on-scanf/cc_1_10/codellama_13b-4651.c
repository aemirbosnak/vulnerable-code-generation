//Code Llama-13B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
#include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    int main() {
      // Welcome message
      printf("Welcome to the Alien Invasion Probability Calculator!\n");
      printf("Let's calculate the probability of an alien invasion!\n");

      // Ask for user input
      int population, technology, military, mining, exploration, alien_count;
      printf("Enter the current population of Earth: ");
      scanf("%d", &population);
      printf("Enter the current technology level: ");
      scanf("%d", &technology);
      printf("Enter the military strength: ");
      scanf("%d", &military);
      printf("Enter the mining capacity: ");
      scanf("%d", &mining);
      printf("Enter the exploration level: ");
      scanf("%d", &exploration);

      // Calculate the probability of an alien invasion
      srand(time(NULL));
      int probability = 0;
      for (int i = 0; i < 100; i++) {
        int alien_population = rand() % 1000 + 1;
        int alien_technology = rand() % 100 + 1;
        int alien_military = rand() % 100 + 1;
        int alien_mining = rand() % 100 + 1;
        int alien_exploration = rand() % 100 + 1;
        if (alien_population > population ||
            alien_technology > technology ||
            alien_military > military ||
            alien_mining > mining ||
            alien_exploration > exploration) {
          probability++;
        }
      }
      probability = (probability * 100) / 100;

      // Display the result
      printf("The probability of an alien invasion is %d%%.\n", probability);
      if (probability > 50) {
        printf("Uh oh, the aliens are getting closer! You should start preparing for an invasion!\n");
      } else {
        printf("All clear, the aliens seem to be far away for now.\n");
      }

      return 0;
    }