//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include<stdio.h>
#include<stdlib.h>

//Declare a struct to hold fitness tracker data
struct fitness_tracker {
   char user_name[50];
   int age;
   float weight;
   float height;
   float bmi;
   float calories_burned;
   int steps_walked;
   int water_intake;
};

//Function to calculate BMI (Body Mass Index)
float calculate_bmi(float weight, float height) {
   float bmi = weight / (height * height);
   return bmi;
}

//Function to calculate daily calorie requirement
float calculate_calorie_requirement(int age, float weight, float height, char gender, int activity_level) {
   float bmr;
   if(gender == 'M') {
      bmr = 66 + (13.7 * weight) + (5 * height * 100) - (6.8 * age);
   } else {
      bmr = 655 + (9.6 * weight) + (1.8 * height * 100) - (4.7 * age);
   }
   float calorie_requirement;
   switch(activity_level) {
      case 1:
         calorie_requirement = bmr * 1.2;
         break;
      case 2:
         calorie_requirement = bmr * 1.375;
         break;
      case 3:
         calorie_requirement = bmr * 1.55;
         break;
      case 4:
         calorie_requirement = bmr * 1.725;
         break;
      case 5:
         calorie_requirement = bmr * 1.9;
         break;
      default:
         printf("Invalid input for activity level!\n");
         calorie_requirement = 0;
         break;
   }
   return calorie_requirement;
}

//Function to update fitness tracker data
void update_fitness_tracker(struct fitness_tracker *fb) {
   printf("Enter your name: ");
   scanf("%s", fb->user_name);
   printf("Enter your age: ");
   scanf("%d", &fb->age);
   printf("Enter your weight (in kg): ");
   scanf("%f", &fb->weight);
   printf("Enter your height (in meters): ");
   scanf("%f", &fb->height);
   printf("Enter the number of steps you walked today: ");
   scanf("%d", &fb->steps_walked);
   printf("Enter the amount of water you drank today (in ml): ");
   scanf("%d", &fb->water_intake);
   fb->bmi = calculate_bmi(fb->weight, fb->height);
   fb->calories_burned = fb->steps_walked * 0.05 + 0.02 * fb->bmi * fb->weight;
}

//Function to display fitness tracker data
void display_fitness_tracker(struct fitness_tracker fb) {
   printf("\nFitness Tracker Data\n");
   printf("Name: %s\n", fb.user_name);
   printf("Age: %d\n", fb.age);
   printf("Weight: %.2f kg\n", fb.weight);
   printf("Height: %.2f m\n", fb.height);
   printf("BMI: %.2f\n", fb.bmi);
   printf("Calories Burned: %.2f\n", fb.calories_burned);
   printf("Steps Walked: %d\n", fb.steps_walked);
   printf("Water Intake: %d ml\n", fb.water_intake);
}

int main() {
   struct fitness_tracker fb;
   char gender;
   int activity_level;
   printf("*** Fitness Tracker ***\n");
   printf("Please answer the following questions to update your fitness tracker data.\n");
   update_fitness_tracker(&fb);
   printf("\nEnter your gender (M/F): ");
   scanf(" %c", &gender);
   printf("Enter your activity level (1: Sedentary, 2: Light Activity, 3: Moderate Activity, 4: Active, 5: Very Active): ");
   scanf("%d", &activity_level);
   float calorie_requirement = calculate_calorie_requirement(fb.age, fb.weight, fb.height, gender, activity_level);
   display_fitness_tracker(fb);
   printf("\nYour daily calorie requirement is: %.2f\n", calorie_requirement);
   return 0;
}