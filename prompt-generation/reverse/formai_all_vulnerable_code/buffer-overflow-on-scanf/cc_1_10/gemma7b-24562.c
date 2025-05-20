//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  system("clear");
  system("figlet -f pixel -c \"C Fitness Tracker\"");
  printf("Please select an option:\n");
  printf("1. Track Heart Rate\n");
  printf("2. Measure Blood Pressure\n");
  printf("3. Record Weight\n");
  printf("4. Set Goals\n");

  int choice = 0;
  scanf("%d", &choice);

  switch (choice)
  {
    case 1:
      system("clear");
      system("figlet -f pixel -c \"Heart Rate Monitor\"");
      printf("Please enter your current heart rate:");
      int heartRate = 0;
      scanf("%d", &heartRate);
      printf("Your heart rate is: %d BPM\n", heartRate);
      break;

    case 2:
      system("clear");
      system("figlet -f pixel -c \"Blood Pressure Gauge\"");
      printf("Please enter your blood pressure:");
      int bloodPressure = 0;
      scanf("%d", &bloodPressure);
      printf("Your blood pressure is: %d/%d mmHg\n", bloodPressure / 3, bloodPressure % 3);
      break;

    case 3:
      system("clear");
      system("figlet -f pixel -c \"Weight Scale\"");
      printf("Please enter your weight:");
      int weight = 0;
      scanf("%d", &weight);
      printf("Your weight is: %d kg\n", weight);
      break;

    case 4:
      system("clear");
      system("figlet -f pixel -c \"Goal Setter\"");
      printf("Please enter your goal:");
      char goal[20] = "";
      scanf("%s", goal);
      printf("Your goal is: %s\n", goal);
      break;

    default:
      printf("Invalid choice. Please try again.\n");
  }

  system("pause");
  return 0;
}