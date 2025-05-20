//FormAI DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>

int main(void) {
  
  printf("Welcome to the Safe Style Educational Program\n\n");

  // Define variables
  char name[30];
  int age;
  float gpa;
  char gender;

  // Ask for user input
  printf("Please enter your name: ");
  scanf("%s", name);

  printf("Please enter your age: ");
  scanf("%d", &age);

  printf("Please enter your GPA: ");
  scanf("%f", &gpa);

  printf("Please enter your gender (M/F): ");
  scanf(" %c", &gender);

  // Print out user information
  printf("\n\nPrinting out user information...\n");
  printf("\nName: %s", name);
  printf("\nAge: %d", age);
  printf("\nGPA: %.2f", gpa);
  printf("\nGender: %c", gender);

  // Calculate year in school based on age
  int year;
  if (age >= 20){
    year = 4;
  }
  else if (age >= 18){
    year = 3;
  }
  else if (age >= 16){
    year = 2;
  }
  else{
    year = 1;
  }

  // Print out year in school
  printf("\n\nCalculated year in school...\n");
  printf("\nYear in School: %d", year);

  // Calculate eligibility for honor roll based on GPA
  char honor_roll;
  if (gpa >= 3.5){
    honor_roll = 'Y';
  }
  else{
    honor_roll = 'N';
  }

  // Print out eligibility for honor roll
  printf("\n\nCalculated eligibility for honor roll...\n");
  printf("\nEligible for Honor Roll (Y/N): %c", honor_roll);

  // Determine pronoun based on gender
  char pronoun[10];
  if (gender == 'M'){
    strcpy(pronoun, "He");
  }
  else{
    strcpy(pronoun, "She");
  }

  // Print out personalized message
  printf("\n\nPrinting personalized message...\n");
  printf("\n%s is a %d year student with a %.2f GPA.", name, year, gpa);
  printf("\n%s is %s eligible for the Honor Roll.", pronoun, (honor_roll == 'Y') ? "" : "not");

  return 0;
}