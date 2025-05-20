//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
  int num_cards = 0;
  char answer;
  int crystal_ball_prediction;

  printf("Welcome to the Crystal Ball of Zolander!\n");
  printf("Would you like to ask a question? (Y/N): ");
  scanf("%c", &answer);

  if (answer == 'Y')
  {
    printf("Please state your question: ");
    scanf("%s", "");

    // Shuffle the oracle cards
    srand(time(NULL));
    num_cards = rand() % 5 + 1;

    // Read the oracle cards
    crystal_ball_prediction = num_cards;

    // Interpret the oracle cards
    switch (crystal_ball_prediction)
    {
      case 1:
        printf("Your future is bright, my dear.\n");
        break;
      case 2:
        printf("You will find love, but be cautious.\n");
        break;
      case 3:
        printf("Beware of evil forces.\n");
        break;
      case 4:
        printf("You will travel far, but remember your roots.\n");
        break;
      case 5:
        printf("The stars favor you, but fate has a twist.\n");
        break;
    }
  }
  else
  {
    printf("Thank you for visiting the Crystal Ball of Zolander.\n");
  }

  return;
}