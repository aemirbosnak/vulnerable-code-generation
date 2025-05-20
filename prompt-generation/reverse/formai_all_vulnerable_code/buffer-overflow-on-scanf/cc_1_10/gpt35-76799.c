//FormAI DATASET v1.0 Category: Data mining ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define max values for our data
#define MAX_NAME_LEN 25
#define MAX_GRADE_NUM 10

// define structure for students
typedef struct {
  char name[MAX_NAME_LEN];
  int grades[MAX_GRADE_NUM];
  int num_grades;
} student;

// function to get user input for student data
void get_student_data(student *s) {
  printf("Enter student name: ");
  scanf("%s", s->name);
  printf("Enter number of grades: ");
  scanf("%d", &(s->num_grades));
  printf("Enter %d grades (separated by spaces): ", s->num_grades);
  for (int i = 0; i < s->num_grades; i++) {
    scanf("%d", &(s->grades[i]));
  }
}

// function to calculate average grade for a student
double avg_grade(student s) {
  int total = 0;
  for (int i = 0; i < s.num_grades; i++) {
    total += s.grades[i];
  }
  return (double)total / s.num_grades;
}

// function to print student data to console
void print_student(student s) {
  printf("Name: %s\n", s.name);
  printf("Grades: ");
  for (int i = 0; i < s.num_grades; i++) {
    printf("%d ", s.grades[i]);
  }
  printf("\n");
  printf("Average grade: %.2f\n", avg_grade(s));
}

int main() {

  // create an array of student structures
  student class[3];

  // get student data from user
  for (int i = 0; i < 3; i++) {
    printf("Enter data for student %d:\n", i+1);
    get_student_data(&class[i]);
  }

  // print student data to console
  for (int i = 0; i < 3; i++) {
    printf("Student %d:\n", i+1);
    print_student(class[i]);
  }

  return 0;
}