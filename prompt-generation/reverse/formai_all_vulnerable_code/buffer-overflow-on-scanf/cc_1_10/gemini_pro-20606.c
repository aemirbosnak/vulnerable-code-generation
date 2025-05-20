//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main() {
  char name[50];
  int age;
  char gender;
  char qualification[50];
  float gpa;
  int num_courses;
  char courses[10][50];
  int grades[10];

  // Welcome the user
  printf("** Welcome to the Online Examination System! **\n");
  printf("Please enter your personal information:\n");

  // Get the user's name
  printf("Name: ");
  scanf("%s", name);

  // Get the user's age
  printf("Age: ");
  scanf("%d", &age);

  // Get the user's gender
  printf("Gender (M/F): ");
  scanf(" %c", &gender);

  // Get the user's qualification
  printf("Qualification: ");
  scanf(" %s", qualification);

  // Get the user's GPA
  printf("GPA: ");
  scanf("%f", &gpa);

  // Get the number of courses taken
  printf("Number of courses taken: ");
  scanf("%d", &num_courses);

  // Get the names of the courses taken
  printf("Enter the names of the courses taken:\n");
  for (int i = 0; i < num_courses; i++) {
    printf("%d. ", i + 1);
    scanf(" %s", courses[i]);
  }

  // Get the grades for the courses taken
  printf("Enter the grades for the courses taken:\n");
  for (int i = 0; i < num_courses; i++) {
    printf("%d. ", i + 1);
    scanf(" %d", &grades[i]);
  }

  // Calculate the user's overall GPA
  float overall_gpa = 0;
  for (int i = 0; i < num_courses; i++) {
    overall_gpa += grades[i] / (float)num_courses;
  }

  // Calculate the user's ranking
  int ranking;
  if (overall_gpa >= 3.5) {
    ranking = 1;
  } else if (overall_gpa >= 3.0) {
    ranking = 2;
  } else if (overall_gpa >= 2.5) {
    ranking = 3;
  } else {
    ranking = 4;
  }

  // Print the user's results
  printf("\n** Results **\n");
  printf("Name: %s\n", name);
  printf("Age: %d\n", age);
  printf("Gender: %c\n", gender);
  printf("Qualification: %s\n", qualification);
  printf("GPA: %f\n", gpa);
  printf("Overall GPA: %f\n", overall_gpa);
  printf("Ranking: %d\n", ranking);

  // Congratulate the user
  printf("Congratulations, %s! You have successfully completed the online examination.\n", name);
  printf("We wish you all the best in your future endeavors.\n");
  printf("** Thank you for taking the exam! **\n");
  return 0;
}