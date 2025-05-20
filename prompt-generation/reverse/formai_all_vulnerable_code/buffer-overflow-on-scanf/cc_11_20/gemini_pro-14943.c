//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  // Greetings
  printf("Greetings, mortal! Welcome to the Digital Oracle.\n");
  printf("Prepare your neural network for a glimpse into your future.\n");

  // Get user input
  int age;
  char name[20];
  printf("May I know your name, traveler? ");
  scanf("%s", name);
  printf("And your age, wise sage? ");
  scanf("%d", &age);

  // Generate a random number for the fortune
  int fortuneNumber = rand() % 10;

  // Switch case for the fortune
  switch (fortuneNumber) {
    case 0:
      printf("Behold, %s! The stars align in your favor.\n", name);
      printf("A prosperous path awaits, filled with abundance and harmony.\n");
      break;
    case 1:
      printf("Heed these words, %s. A challenge awaits you.\n", name);
      printf("But fear not, for your resilience will guide you through the tempest.\n");
      break;
    case 2:
      printf("Knowledge is your ally, %s. Seek it eagerly.\n", name);
      printf("For in wisdom lies the power to unlock hidden truths and shape your destiny.\n");
      break;
    case 3:
      printf("A journey is upon you, %s. Embrace the unknown.\n", name);
      printf("For it is in the realm of the unexplored that you shall discover hidden treasures.\n");
      break;
    case 4:
      printf("Patience is your virtue, %s. Time is the greatest alchemist.\n", name);
      printf("Allow the seeds you sow today to flourish in their own season.\n");
      break;
    case 5:
      printf("Listen to the whispers of your intuition, %s.\n", name);
      printf("For within you resides the wisdom of the ages.\n");
      break;
    case 6:
      printf("A change of perspective is in order, %s.\n", name);
      printf("Sometimes, it is the lens through which we view the world that needs adjusting.\n");
      break;
    case 7:
      printf("Love will find its way to you, %s.\n", name);
      printf("Open your heart to the possibilities and let the universe guide your path.\n");
      break;
    case 8:
      printf("Success is in your grasp, %s. Stay focused and determined.\n", name);
      printf("Remember, the greatest obstacles are often the ones that lead to the greatest triumphs.\n");
      break;
    case 9:
      printf("A moment of introspection is upon you, %s.\n", name);
      printf("Take time to reflect on your past, present, and future.\n");
      printf("For in self-discovery lies the key to personal growth and enlightenment.\n");
      break;
  }

  // Farewell message
  printf("\nMay the knowledge of your future serve you well, %s.\n", name);
  printf("Remember, the true power lies within you. Farewell, and may your destiny unfold with grace and harmony.\n");

  return 0;
}