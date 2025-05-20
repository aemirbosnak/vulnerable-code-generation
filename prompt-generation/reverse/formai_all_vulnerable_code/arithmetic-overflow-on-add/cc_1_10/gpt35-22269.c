//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  srand(time(0));
  int pushups = rand() % 100;
  int situps = rand() % 100;
  int squats = rand() % 100;
  printf("Welcome to your surreal C Fitness Tracker.\n");
  printf("Today's workout includes:\n");
  printf("%d pushups\n", pushups);
  printf("%d situps\n", situps);
  printf("%d squats\n", squats);
  printf("Please begin your workout.\n");
  printf("Every time you complete a set of exercises, enter the number of reps completed:\n");

  int set1_pushups = 0;
  int set1_situps = 0;
  int set1_squats = 0;
  printf("Set 1:\n");
  printf("Pushups: ");
  scanf("%d", &set1_pushups);
  printf("Situps: ");
  scanf("%d", &set1_situps);
  printf("Squats: ");
  scanf("%d", &set1_squats);

  int set2_pushups = 0;
  int set2_situps = 0;
  int set2_squats = 0;
  printf("Set 2:\n");
  printf("Pushups: ");
  scanf("%d", &set2_pushups);
  printf("Situps: ");
  scanf("%d", &set2_situps);
  printf("Squats: ");
  scanf("%d", &set2_squats);

  int set3_pushups = 0;
  int set3_situps = 0;
  int set3_squats = 0;
  printf("Set 3:\n");
  printf("Pushups: ");
  scanf("%d", &set3_pushups);
  printf("Situps: ");
  scanf("%d", &set3_situps);
  printf("Squats: ");
  scanf("%d", &set3_squats);

  printf("You have completed your workout.\n");
  printf("Here's a surreal breakdown of your workout:\n");
  printf("You did %d pushups, which is %d%% of the original number.\n", set1_pushups+set2_pushups+set3_pushups, (set1_pushups+set2_pushups+set3_pushups)*100/pushups);
  printf("You did %d situps, which is %d%% of the original number.\n", set1_situps+set2_situps+set3_situps, (set1_situps+set2_situps+set3_situps)*100/situps);
  printf("You did %d squats, which is %d%% of the original number.\n", set1_squats+set2_squats+set3_squats, (set1_squats+set2_squats+set3_squats)*100/squats);
  printf("Thanks for using the surreal C Fitness Tracker. Stay surreal!\n");

  return 0;
}