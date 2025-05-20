//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int alien_probability, military_strength, alien_ships, military_units, i;
  
  srand(time(0));
  
  printf("\nWelcome to the Alien Invasion Probability Calculator!\n");
  printf("Please enter the alien invasion probability (0-100): ");
  scanf("%d", &alien_probability);
  
  if(alien_probability < 0 || alien_probability > 100)
  {
    printf("\nInvalid input. Please enter a probability between 0 and 100.\n");
    return 0;
  }
  
  printf("\nPlease enter the total military strength (in millions): ");
  scanf("%d", &military_strength);
  
  if(military_strength <= 0)
  {
    printf("\nInvalid input. Please enter a positive number greater than 0.\n");
    return 0;
  }
  
  alien_ships = (rand() % 10000) + 5000;
  military_units = military_strength * 1000000;
  
  printf("\nAlien Ships: %d\n", alien_ships);
  printf("Military Units: %d\n\n", military_units);
  
  printf("Calculating invasion probability...\n\n");
  printf("--------------------------------------------------\n");
  printf("|   Attack Range   |   Victory Probability (%)   |\n");
  printf("--------------------------------------------------\n");
  
  for(i = 0; i <= 5; i++)
  {
    float attack_range = (float)(alien_ships * (i + 1)) / (float)1000;
    float victory_probability = ((float)alien_probability / 100) * ((float)military_units / attack_range);
    
    printf("|      %.2f        |            %.2f             |\n", attack_range, victory_probability);
  }
  
  printf("--------------------------------------------------\n\n");
  
  printf("The invasion probability has been calculated.\n");
  
  return 0;
}