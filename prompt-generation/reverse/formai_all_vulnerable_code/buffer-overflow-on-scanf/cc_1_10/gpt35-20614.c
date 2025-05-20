//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: automated
#include <stdio.h>

void clear() {
  system("@cls||clear");
}

int main() {
  int distance = 0;
  int energy = 100;
  int shields = 100;

  printf("Welcome to Procedural Space Adventure!\n");
  while (distance < 1000) {
    printf("Current distance from Earth: %d\n", distance);
    printf("Current energy level: %d\n", energy);
    printf("Current shield level: %d\n", shields);
    printf("Choose your next move:\n");
    printf("1. Fly at normal speed (costs 10 energy)\n");
    printf("2. Boost speed (costs 30 energy)\n");
    printf("3. Rest to regenerate energy (costs 20 distance)\n");
    printf("4. Activate shields (costs 50 energy)\n");
    int choice = 0;
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Flying at normal speed...\n");
        distance += 20;
        energy -= 10;
        break;
      case 2:
        printf("Boosting speed...\n");
        distance += 50;
        energy -= 30;
        break;
      case 3:
        printf("Resting to regenerate energy...\n");
        distance += 20;
        energy += 50;
        if (energy > 100) {
          energy = 100;
        }
        break;
      case 4:
        printf("Activating shields...\n");
        shields -= 50;
        break;        
      default:
        printf("Invalid choice. Try again.\n");            
    }
    if (energy < 0 || shields < 0) {
      printf("You have run out of energy or shields. Game over!\n");
      break;
    }
    clear();
  }
  if (distance >= 1000) {
    printf("Congratulations! You have reached your destination!\n");
  }
  return 0;
}