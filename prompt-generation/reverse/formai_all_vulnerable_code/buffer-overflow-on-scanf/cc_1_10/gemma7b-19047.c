//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  system("clear");
  printf("----------------------------------------------------------------------\n");
  printf("   /\_/\n"
       "  |||| |__)\n"
       "  \__) \__)\n"
       "    \___) |\n"
       "----------------------------------------------------------------------\n");

  printf("Welcome to the C Fitness Tracker!\n");
  printf("Please select an option:\n");
  printf("1. Track Heart Rate\n");
  printf("2. Monitor Blood Pressure\n");
  printf("3. Log Weight\n");
  printf("4. Set Goals\n");

  int choice = 0;
  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      printf("Enter your current heart rate:");
      int heart_rate = 0;
      scanf("%d", &heart_rate);
      printf("Your heart rate is: %d", heart_rate);
      break;
    case 2:
      printf("Enter your blood pressure:");
      int blood_pressure = 0;
      scanf("%d", &blood_pressure);
      printf("Your blood pressure is: %d/%d", blood_pressure);
      break;
    case 3:
      printf("Enter your weight:");
      int weight = 0;
      scanf("%d", &weight);
      printf("Your weight is: %d", weight);
      break;
    case 4:
      printf("Enter your goals:");
      char goals[100] = "";
      scanf("%s", goals);
      printf("Your goals are: %s", goals);
      break;
    default:
      printf("Invalid selection.\n");
  }

  system("pause");
  return 0;
}