//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int hours, minutes, seconds, total_seconds;
   int current_hour, current_min, current_sec, elapsed_seconds;
   float calories_burned, distance_covered;
   char name[20];
   int age, weight, height;
   float BMI;
   
   // get user information
   printf("Welcome to Fitness Tracker!\n");
   printf("Please enter your name: ");
   scanf("%s", name);
   printf("Please enter your age: ");
   scanf("%d", &age);
   printf("Please enter your weight in pounds: ");
   scanf("%d", &weight);
   printf("Please enter your height in inches: ");
   scanf("%d", &height);
   
   BMI = (weight * 703) / (height * height);
   printf("Your Body Mass Index (BMI) is %.2f\n", BMI);
   
   // get workout time
   printf("Please enter your workout time in hours, minutes, and seconds.\n");
   printf("Hours: ");
   scanf("%d", &hours);
   printf("Minutes: ");
   scanf("%d", &minutes);
   printf("Seconds: ");
   scanf("%d", &seconds);
   
   // calculate total seconds
   total_seconds = hours * 3600 + minutes * 60 + seconds;
   
   // simulate workout
   printf("Starting workout...\n");
   srand(time(NULL));
   for(int i = 0; i < total_seconds; i++) {
      // print elapsed time
      elapsed_seconds = i + 1;
      current_hour = elapsed_seconds / 3600;
      current_min = (elapsed_seconds % 3600) / 60;
      current_sec = elapsed_seconds % 60;
      printf("Time elapsed: %d:%02d:%02d\n", current_hour, current_min, current_sec);
      
      // calculate calories burned and distance covered
      calories_burned = ((weight * 2.2) / 3600) * 8;
      distance_covered = (rand() % 5 + 1) / 10.0;
      printf("Calories burned: %.2f\n", calories_burned);
      printf("Distance covered: %.2f miles\n", distance_covered);
      
      // rest for one second
      sleep(1);
   }
   
   printf("Workout complete!\n");
   return 0;
}