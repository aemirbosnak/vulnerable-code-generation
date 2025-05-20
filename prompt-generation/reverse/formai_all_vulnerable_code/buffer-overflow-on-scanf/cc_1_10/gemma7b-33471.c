//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 20

typedef struct Student {
  char name[50];
  int rollno;
  float marks;
} Student;

Student students[MAX_STUDENTS];

void addStudent() {
  Student newStudent;
  printf("Enter student name: ");
  scanf("%s", newStudent.name);
  printf("Enter student roll no: ");
  scanf("%d", &newStudent.rollno);
  printf("Enter student marks: ");
  scanf("%f", &newStudent.marks);
  students[MAX_STUDENTS - 1] = newStudent;
}

void displayStudents() {
  for (int i = 0; i < MAX_STUDENTS; i++) {
    Student student = students[i];
    printf("Name: %s\n", student.name);
    printf("Roll No: %d\n", student.rollno);
    printf("Marks: %.2f\n", student.marks);
    printf("\n");
  }
}

int main() {
  int choice;

  printf("Welcome to the Student Management System!\n");
  printf("1. Add Student\n");
  printf("2. Display Students\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      addStudent();
      break;
    case 2:
      displayStudents();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}