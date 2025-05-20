//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int num;
  char sign;
  srand(time(NULL));

  printf("Would you like to hear your fortune?\n");
  scanf("%c", &sign);

  if (sign == 'Y' || sign == 'y')
  {
    num = rand() % 10;

    switch (num)
    {
      case 0:
        printf("Your future is bright, my dear.\n");
        break;
      case 1:
        printf("Love and prosperity await you.\n");
        break;
      case 2:
        printf("You will find happiness in a new journey.\n");
        break;
      case 3:
        printf("Beware of hidden enemies.\n");
        break;
      case 4:
        printf("A lucky day is coming your way.\n");
        break;
      case 5:
        printf("Your dreams will be fulfilled.\n");
        break;
      case 6:
        printf("You will face challenges, but overcome them.\n");
        break;
      case 7:
        printf("The stars are aligned in your favor.\n");
        break;
      case 8:
        printf("You will experience joy and fulfillment.\n");
        break;
      case 9:
        printf("A new chapter begins.\n");
        break;
      case 10:
        printf("May your wishes be granted.\n");
        break;
    }
  }
  else
  {
    printf("Thank you for your time.\n");
  }

  return 0;
}