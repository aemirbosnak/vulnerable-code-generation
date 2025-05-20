//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
  char name[20], activity[20];
  int age, calories = 0, steps = 0;

  printf("Greetings weary traveller! What be your name?\n");
  scanf("%s", name);
  printf("Ahh, welcome %s! What be your age?\n", name);
  scanf("%d", &age);

  printf("\n%s, ye must stay fit to face the challenges of this world. What shall be your activity for the day?\n", name);
  printf("Your options are: running, lifting, or sword fighting.\n");
  scanf("%s", activity);

  // Determine activity
  if (strcmp(activity, "running") == 0)
  {
    steps = 5000;
    calories = 300;
  }
  else if (strcmp(activity, "lifting") == 0)
  {
    steps = 2500;
    calories = 200;
  }
  else if (strcmp(activity, "sword fighting") == 0)
  {
    steps = 1000;
    calories = 150;
  }
  else
  {
    printf("That is not a valid activity. Try again.");
    return 0;
  }

  // Calculate activity benefits
  int distance = steps / 2;
  int strength = (calories / 2) + (age / 2);

  // Display results
  printf("\n%s, your journey for the day: %s\n", name, activity);
  printf("Distance travelled: %d meters\n", distance);
  printf("Calories burned: %d\n", calories);
  printf("Strength gained: %d\n", strength);

  return 0;
}