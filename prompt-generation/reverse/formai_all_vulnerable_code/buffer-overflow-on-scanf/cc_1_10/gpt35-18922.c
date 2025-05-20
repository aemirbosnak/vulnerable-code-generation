//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>

int main() {
  int steps = 0;
  int calories = 0;
  int heartRate = 0;
  int sleepHours = 0;
  char answer;

  printf("Welcome to the C Fitness Tracker!\n\n");

  fflush(stdin);
  printf("Did you take any steps today? (y/n): ");
  scanf("%c", &answer);

  if (answer == 'y') {
    printf("How many steps did you take?: ");
    scanf("%d", &steps);
    calories = steps / 20;
    printf("You burned %d calories!\n\n", calories);
  }

  fflush(stdin);
  printf("Did you take your heart rate? (y/n): ");
  scanf("%c", &answer);

  if (answer == 'y') {
    printf("What was your heart rate?: ");
    scanf("%d", &heartRate);

    if (heartRate < 60) {
      printf("Your heart rate is too low. Please consult a doctor.\n\n");
    } else if (heartRate > 100) {
      printf("Your heart rate is too high. Please consult a doctor.\n\n");
    } else {
      printf("Your heart rate is normal. Keep up the good work!\n\n");
    }
  }

  fflush(stdin);
  printf("Did you sleep well last night? (y/n): ");
  scanf("%c", &answer);

  if (answer == 'y') {
    printf("How many hours did you sleep?: ");
    scanf("%d", &sleepHours);

    if (sleepHours < 6) {
      printf("You need to get more rest!\n\n");
    } else if (sleepHours > 8) {
      printf("You got plenty of sleep! Nice job!\n\n");
    } else {
      printf("You got just the right amount of sleep!\n\n");
    }
  }

  return 0;
}