//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numRolls, sides, roll;
  int minSides = 4, maxSides = 1000;
  int minRolls = 1, maxRolls = 10000;
  int i, j;
  char again;
  
  srand(time(NULL));
  
  printf("Welcome to the Cyberpunk Dice Roller!\n");
  printf("Enter the number of sides for your die (between %d and %d): ", minSides, maxSides);
  scanf("%d", &sides);
  
  if (sides < minSides || sides > maxSides) {
    printf("Invalid number of sides, please try again.\n");
    return 0;
  }
  
  printf("Enter the number of times you want to roll the die (between %d and %d): ", minRolls, maxRolls);
  scanf("%d", &numRolls);
  
  if (numRolls < minRolls || numRolls > maxRolls) {
    printf("Invalid number of rolls, please try again.\n");
    return 0;
  }
  
  for (i = 1; i <= numRolls; i++) {
    roll = (rand() % sides) + 1;
    printf("Roll %d: %d\n", i, roll);
  }
  
  do {
    printf("Roll again? (Y/N): ");
    scanf(" %c", &again);
    if (again == 'Y' || again == 'y') {
      printf("Enter the number of times you want to roll the die (between %d and %d): ", minRolls, maxRolls);
      scanf("%d", &numRolls);
      for (j = 1; j <= numRolls; j++) {
        roll = (rand() % sides) + 1;
        printf("Roll %d: %d\n", j, roll);
      }
    }
  } while (again == 'Y' || again == 'y');
  
  printf("Goodbye, hope you enjoyed the Cyberpunk Dice Roller!\n");
  
  return 0;
}