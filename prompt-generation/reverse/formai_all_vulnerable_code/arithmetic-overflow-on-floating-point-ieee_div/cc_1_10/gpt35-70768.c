//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>

int main() {
  float income, expenses, savings;
  
  printf("Welcome to the Personal Finance Planner!\n");
  printf("---------------------------------------\n\n");

  printf("Please enter your monthly income: ");
  scanf("%f", &income);

  printf("Please enter your monthly expenses: ");
  scanf("%f", &expenses);

  savings = income - expenses;
  
  printf("\n******************************\n\n");
  
  if (savings >= 0) {
    printf("Congrats! You have leftover savings of $%.2f!\n", savings);
  } else {
    printf("Uh oh! You are in the negative with a deficit of $%.2f!\n", -savings);
  }
  
  printf("\n******************************\n\n");
  
  printf("Here are some recommended percentages to assign to different areas of your budget:\n\n");

  printf("Housing: 30%% ($%.2f)\n", income * 0.3);
  printf("Transportation: 15%% ($%.2f)\n", income * 0.15);
  printf("Food: 10%% ($%.2f)\n", income * 0.10);
  printf("Savings: 20%% ($%.2f)\n", income * 0.20);
  printf("Entertainment: 10%% ($%.2f)\n", income * 0.10);
  printf("Miscellaneous: 15%% ($%.2f)\n", income * 0.15);
  
  printf("\n******************************\n\n");
  
  float housing, transportation, food, entertainment, miscellaneous;
  
  housing = income * 0.3;
  transportation = income * 0.15;
  food = income * 0.10;
  savings = income * 0.20;
  entertainment = income * 0.10;
  miscellaneous = income * 0.15;
  
  printf("Based on the recommended percentages here is how much you should spend in each category:\n\n");
  
  printf("Housing: $%.2f\n", housing);
  printf("Transportation: $%.2f\n", transportation);
  printf("Food: $%.2f\n", food);
  printf("Savings: $%.2f\n", savings);
  printf("Entertainment: $%.2f\n", entertainment);
  printf("Miscellaneous: $%.2f\n", miscellaneous);
  
  printf("\n******************************\n\n");
  
  float housing_percent, transportation_percent, food_percent, entertainment_percent, miscellaneous_percent;
  
  housing_percent = housing / income * 100;
  transportation_percent = transportation / income * 100;
  food_percent = food / income * 100;
  savings = income * 0.20;
  entertainment_percent = entertainment / income * 100;
  miscellaneous_percent = miscellaneous / income * 100;
  
  printf("Based on your input, here is the percentage of your income you are spending in each category:\n\n");
  
  printf("Housing: %.2f%%\n", housing_percent);
  printf("Transportation: %.2f%%\n", transportation_percent);
  printf("Food: %.2f%%\n", food_percent);
  printf("Savings: %.2f%%\n", savings);
  printf("Entertainment: %.2f%%\n", entertainment_percent);
  printf("Miscellaneous: %.2f%%\n", miscellaneous_percent);
  
  printf("\n******************************\n\n");
  
  float housing_diff, transportation_diff, food_diff, entertainment_diff, miscellaneous_diff;
  
  housing_diff = housing_percent - 30;
  transportation_diff = transportation_percent - 15;
  food_diff = food_percent - 10;
  entertainment_diff = entertainment_percent - 10;
  miscellaneous_diff = miscellaneous_percent - 15;
  
  if (housing_diff > 0) {
    printf("You are over the recommended percentage for Housing by %.2f%%\n", housing_diff);
  } else {
    printf("Great job! You are within the recommended percentage for Housing\n");
  }
  
  if (transportation_diff > 0) {
    printf("You are over the recommended percentage for Transportation by %.2f%%\n", transportation_diff);
  } else {
    printf("Great job! You are within the recommended percentage for Transportation\n");
  }
  
  if (food_diff > 0) {
    printf("You are over the recommended percentage for Food by %.2f%%\n", food_diff);
  } else {
    printf("Great job! You are within the recommended percentage for Food\n");
  }
  
  if (entertainment_diff > 0) {
    printf("You are over the recommended percentage for Entertainment by %.2f%%\n", entertainment_diff);
  } else {
    printf("Great job! You are within the recommended percentage for Entertainment\n");
  }
  
  if (miscellaneous_diff > 0) {
    printf("You are over the recommended percentage for Miscellaneous by %.2f%%\n", miscellaneous_diff);
  } else {
    printf("Great job! You are within the recommended percentage for Miscellaneous\n");
  }
  
  printf("\n******************************\n\n");
  
  float savings_percent;
  
  if (savings >= 0) {
    savings_percent = savings / income * 100;
    printf("You are able to save %.2f%% of your income. Keep up the good work!\n", savings_percent);
  } else {
    savings_percent = expenses / income * 100;
    printf("You are spending %.2f%% of your income and are not able to save anything. Time to review your expenses and find areas to cut back!\n", savings_percent);
  }
  
  return 0;
}