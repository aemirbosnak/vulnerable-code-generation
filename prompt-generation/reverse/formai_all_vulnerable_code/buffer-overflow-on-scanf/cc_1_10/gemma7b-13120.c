//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
  system("clear");
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char buff[20];
  strftime(buff, 20, "The time is: %H:%M:%S", tm);
  printf("%s\n", buff);

  char name[20];
  printf("What is your name? ");
  scanf("%s", name);

  int age = 0;
  printf("How old are you, %s? ", name);
  scanf("%d", &age);

  int hr = 0, min = 0, sec = 0;
  printf("Enter the time you want to track: ");
  scanf("%d:%d:%d", &hr, &min, &sec);

  int target_heart_rate = 0;
  printf("Enter your target heart rate: ");
  scanf("%d", &target_heart_rate);

  int heart_rate = 0;
  printf("Enter your current heart rate: ");
  scanf("%d", &heart_rate);

  int status = 0;
  if (heart_rate < target_heart_rate) {
    status = 1;
  } else if (heart_rate > target_heart_rate) {
    status = 2;
  } else {
    status = 3;
  }

  switch (status) {
    case 1:
      printf("Your heart rate is too low. You should increase your activity.\n");
      break;
    case 2:
      printf("Your heart rate is too high. You should rest.\n");
      break;
    case 3:
      printf("Your heart rate is within your target range. Keep up the good work!\n");
      break;
  }

  return 0;
}