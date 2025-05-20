//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char *name;
  int score;
} Student;

int main() {
  // Initialize the exam system
  srand(time(NULL));
  int num_students = 10;
  Student students[num_students];
  for (int i = 0; i < num_students; i++) {
    students[i].name = malloc(20);
    sprintf(students[i].name, "Student %d", i + 1);
    students[i].score = rand() % 100;
  }

  // Print the welcome message
  printf("Welcome to the online examination system!\n");

  // Get the student's name
  char *student_name = malloc(20);
  printf("What is your name? ");
  scanf("%s", student_name);

  // Find the student's record
  int student_index = -1;
  for (int i = 0; i < num_students; i++) {
    if (strcmp(students[i].name, student_name) == 0) {
      student_index = i;
      break;
    }
  }

  // If the student is not found, print an error message
  if (student_index == -1) {
    printf("Invalid student name.\n");
    return 1;
  }

  // Print the student's score
  printf("Your score is %d.\n", students[student_index].score);

  // Free the allocated memory
  for (int i = 0; i < num_students; i++) {
    free(students[i].name);
  }
  free(student_name);

  return 0;
}