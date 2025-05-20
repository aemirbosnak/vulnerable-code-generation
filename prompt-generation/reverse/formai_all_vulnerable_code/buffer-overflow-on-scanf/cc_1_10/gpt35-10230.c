//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <ctype.h>

int main() {
  char gender, choice;
  int age, height, weight; 
  float bmr, calories;
  
  printf("Welcome to C Fitness Tracker!\n"); 
  
  printf("Please enter your gender (M/F): "); 
  scanf("%c", &gender); 
  gender = toupper(gender);
  
  printf("Please enter your age: "); 
  scanf("%d", &age);
  
  printf("Please enter your height in cm: "); 
  scanf("%d", &height);
  
  printf("Please enter your weight in kg: "); 
  scanf("%d", &weight); 
  
  if(gender == 'M') {
    bmr = 88.4 + (13.4 * weight) + (4.8 * height) - (5.7 * age); 
  } else if(gender == 'F') {
    bmr = 447.6 + (9.2 * weight) + (3.1 * height) - (4.3 * age);
  }
  
  printf("\nYour BMR (basic metabolic rate) is: %.2f\n", bmr); 
  
  printf("\nWhat are your fitness goals?\n"); 
  printf("a) lose weight\n"); 
  printf("b) maintain weight\n"); 
  printf("c) gain weight\n"); 
  
  printf("Enter your choice: "); 
  scanf("%s", &choice);
  choice = tolower(choice);
  
  switch(choice) {
    case 'a':
      calories = bmr * 0.8; 
      printf("\nYou need to consume %.2f calories per day to lose weight.\n", calories); 
      break;
    case 'b':
      calories = bmr * 1.0; 
      printf("\nYou need to consume %.2f calories per day to maintain weight.\n", calories); 
      break;
    case 'c':
      calories = bmr * 1.2; 
      printf("\nYou need to consume %.2f calories per day to gain weight.\n", calories); 
      break;
    default: 
      printf("\nInvalid choice.\n"); 
      break; 
  }
  
  printf("\nGood luck with your fitness journey!\n"); 
  
  return 0; 
}