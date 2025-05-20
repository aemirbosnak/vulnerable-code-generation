//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANSWERS 10

int main()
{
  char name[20];
  int age;
  char fortune[MAX_ANSWERS];
  int i;

  printf("Please provide your name: ");
  scanf("%s", name);

  printf("Please provide your age: ");
  scanf("%d", &age);

  i = 0;
  for (i = 0; i < MAX_ANSWERS; i++)
  {
    fortune[i] = '\0';
  }

  if (age < 18)
  {
    fortune[0] = "You are young, but your future is bright.";
    fortune[1] = "You will travel the world.";
    fortune[2] = "You will have many friends.";
  }
  else if (age >= 18 && age < 60)
  {
    fortune[0] = "You are in a good place in life.";
    fortune[1] = "You will find happiness.";
    fortune[2] = "You will have a successful career.";
  }
  else
  {
    fortune[0] = "You have lived a long and fulfilling life.";
    fortune[1] = "You will leave a legacy.";
    fortune[2] = "You will be remembered for your kindness.";
  }

  printf("Your fortune is: \n");
  for (i = 0; fortune[i] != '\0'; i++)
  {
    printf("%s\n", fortune[i]);
  }

  return 0;
}