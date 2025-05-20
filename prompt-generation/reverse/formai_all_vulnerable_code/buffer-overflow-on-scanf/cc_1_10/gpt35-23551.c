//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int prob, alienDist, milExp, techLevel, total;
  
  srand(time(0));
  alienDist = rand() % 10 + 1; //random distance of aliens (1-10 parsecs)
  
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Please answer the following questions to determine the probability of an alien invasion on Earth.\n");
  
  printf("\nWhat is the level of military experience of the Earth's military forces (0-10)? ");
  scanf("%d", &milExp);
  if(milExp < 0 || milExp > 10) {
    printf("Invalid input. Program terminated.");
    return 0;
  }
  
  printf("\nWhat is the technology level of the Earth's civilization (0-10)? ");
  scanf("%d", &techLevel);
  if(techLevel < 0 || techLevel > 10) {
    printf("Invalid input. Program terminated.");
    return 0;
  }
  
  //probability calculation
  prob = (milExp + techLevel) * alienDist;
  
  printf("\nCalculating...\n");
  
  //probability result
  printf("\nThe calculated probability of an alien invasion on Earth is: %d%%\n", prob);
  
  //probability analysis
  if(prob <= 30) {
    printf("The probability is low. Earth is safe for now!\n");
  }
  else if(prob > 30 && prob <= 70) {
    printf("The probability is moderate. Earth should be vigilant.\n");
  }
  else if(prob > 70) {
    printf("The probability is high. Earth is in danger!\n");
  }
  
  printf("\nThank you for using the Alien Invasion Probability Calculator!\n");
  
  return 0;
}