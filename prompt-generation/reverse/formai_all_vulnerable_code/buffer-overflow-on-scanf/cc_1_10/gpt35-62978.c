//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <string.h>

typedef struct {
   char name[30];
   int age;
   float height;
   float weight;
} User;

typedef struct {
   float steps;
   float distance;
   float calories;
} Tracker;

void printUser(User u) {
   printf("User name: %s\n", u.name);
   printf("Age: %d\n", u.age);
   printf("Height: %.2f m\n", u.height);
   printf("Weight: %.2f kg\n", u.weight);
}

void printTracker(Tracker t) {
   printf("Steps taken: %.0f\n", t.steps);
   printf("Distance travelled: %.2f km\n", t.distance);
   printf("Calories burned: %.0f\n", t.calories);
}

void updateTracker(Tracker *t, float steps, float height, float weight) {
   t->steps += steps;
   t->distance += steps * height / 100000.0; // assuming 1 step = 1 meter
   t->calories += steps * weight / 1000.0; // assuming 1 kg of body weight burns 1 calorie per km
}

int main() {
   User u;
   Tracker t = {0.0, 0.0, 0.0};
   printf("Enter your name: ");
   scanf("%s", u.name);
   printf("Enter your age: ");
   scanf("%d", &u.age);
   printf("Enter your height in cm: ");
   scanf("%f", &u.height);
   printf("Enter your weight in kg: ");
   scanf("%f", &u.weight);
   printUser(u);
   char choice;
   while (1) {
      printf("Press S to log steps, or Q to quit: ");
      scanf(" %c", &choice);
      if (choice == 'S') {
         float steps;
         printf("Enter the number of steps taken: ");
         scanf("%f", &steps);
         updateTracker(&t, steps, u.height, u.weight);
         printTracker(t);
      } else if (choice == 'Q') {
         break;
      }
   }
   return 0;
}