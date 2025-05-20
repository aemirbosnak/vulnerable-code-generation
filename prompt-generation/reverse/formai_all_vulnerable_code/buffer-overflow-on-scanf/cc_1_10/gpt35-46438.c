//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
   int steps;
   float distance;
   int calories;
   bool is_sleeping;
   bool is_exercising;
} FitnessData;

FitnessData current_data;

void reset_data() {
   current_data.steps = 0;
   current_data.distance = 0.0;
   current_data.calories = 0;
   current_data.is_sleeping = false;
   current_data.is_exercising = false;
}

void* start_sleeping(void* arg) {
   int* minutes = (int*) arg;
   current_data.is_sleeping = true;
   int sleep_time = *minutes * 60;
   time_t start_time = time(NULL);
   while(time(NULL) < start_time + sleep_time);
   current_data.is_sleeping = false;
   printf("You slept for %d minutes.\n", *minutes);
}

void* start_exercising(void* arg) {
   int* minutes = (int*) arg;
   current_data.is_exercising = true;
   int exercise_time = *minutes * 60;
   time_t start_time = time(NULL);
   while(time(NULL) < start_time + exercise_time) {
       current_data.steps += rand() % 100;
       current_data.distance += ((rand() % 20) / 10.0);
       current_data.calories += (rand() % 100);
   }
   current_data.is_exercising = false;
   printf("You exercised for %d minutes.\n", *minutes);
}

int main() {
   reset_data();
   int action, minutes;
   srand(time(NULL));

   while(true) {
       printf("Select an action:\n");
       printf("1. Sleep\n");
       printf("2. Exercise\n");
       printf("3. View current fitness data\n");
       printf("4. Quit\n");
       scanf("%d", &action);
       switch(action) {
           case 1:
               printf("How many minutes did you sleep?\n");
               scanf("%d", &minutes);
               start_sleeping(&minutes);
               break;
           case 2:
               printf("How many minutes did you exercise?\n");
               scanf("%d", &minutes);
               start_exercising(&minutes);
               break;
           case 3:
               printf("Current fitness data:\n");
               printf("Steps: %d\n", current_data.steps);
               printf("Distance: %.2f miles\n", current_data.distance);
               printf("Calories burned: %d\n", current_data.calories);
               printf("Sleeping: %s\n", current_data.is_sleeping ? "Yes" : "No");
               printf("Exercising: %s\n", current_data.is_exercising ? "Yes" : "No");
               break;
           case 4:
               printf("Goodbye!\n");
               exit(0);
               break;
           default:
               printf("Invalid action.\n");
               break;
       }
   }
}