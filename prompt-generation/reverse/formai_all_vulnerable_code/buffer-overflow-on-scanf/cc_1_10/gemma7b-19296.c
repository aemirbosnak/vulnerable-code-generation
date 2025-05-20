//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

typedef struct student {
  char name[20];
  int roll_no;
  float marks;
} student;

student students[MAX_STUDENTS];

void insert_student(student *s) {
  printf("Enter student name: ");
  scanf("%s", s->name);

  printf("Enter student roll no: ");
  scanf("%d", &s->roll_no);

  printf("Enter student marks: ");
  scanf("%f", &s->marks);
}

void display_students() {
  for (int i = 0; i < MAX_STUDENTS; i++) {
    printf("Name: %s, Roll No: %d, Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
  }
}

int main() {
  int choice;

  printf("1. Insert Student\n");
  printf("2. Display Students\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      insert_student(&students[0]);
      break;
    case 2:
      display_students();
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}