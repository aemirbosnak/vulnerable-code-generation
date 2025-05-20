//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); //seed the random number generator with the current time
  int pushups = rand() % 100; //generate a random number of pushups for the day
  int squats = rand() % 50; //generate a random number of squats for the day
  int crunches = rand() % 75; //generate a random number of crunches for the day

  printf("Welcome to the Surrealist Fitness Tracker!\n");
  printf("Today's workout:\n");
  printf("%d pushups\n", pushups);
  printf("%d squats\n", squats);
  printf("%d crunches\n", crunches);

  printf("How did you feel during your workout? (1-5)\n");
  int mood;
  scanf("%d", &mood);

  printf("Wow! You did an amazing job!\n");

  if (pushups >= 50 && squats >= 30 && crunches >= 50) {
    printf("You crushed your workout today, keep up the great work!\n");
  } else {
    printf("Keep pushing yourself and you'll reach your fitness goals in no time!\n");
  }

  printf("Would you like to track your progress? (Y/N)\n");
  char answer;
  scanf(" %c", &answer);

  if (answer == 'Y') {
    printf("Great! Let's log your workout...\n");
  } else {
    printf("No problem, you can always come back and log your workouts later!\n");
    return 0;
  }

  printf("What is your age?\n");
  int age;
  scanf("%d", &age);

  printf("What is your gender? (M/F)\n");
  char gender;
  scanf(" %c", &gender);

  printf("What was your weight before the workout? (lb)\n");
  float weight_before;
  scanf("%f", &weight_before);

  printf("What is your weight after the workout? (lb)\n");
  float weight_after;
  scanf("%f", &weight_after);

  float calories_burned = ((0.0175 * age + 0.654)*weight_before + (0.0356 * age + 0.726)*((float)pushups + (float)squats + (float)crunches) / 2.2 - (0.015 * age + 0.561))*1.2;

  printf("You burned approximately %.2f calories during your workout!\n", calories_burned);

  if (gender == 'M') {
    float bmr = 10*weight_before + 6.25*(float)age - 5*25 + 5;
    printf("Your BMR (Basal Metabolic Rate) is %.2f calories/day\n", bmr);
  } else if (gender == 'F') {
    float bmr = 10*weight_before + 6.25*(float)age - 5*25 - 161;
    printf("Your BMR (Basal Metabolic Rate) is %.2f calories/day\n", bmr);
  } else {
    printf("Error: Invalid gender\n");
    return 0;
  }

  printf("Thanks for using the Surrealist Fitness Tracker! We hope to see you again soon!\n");

  return 0;
}