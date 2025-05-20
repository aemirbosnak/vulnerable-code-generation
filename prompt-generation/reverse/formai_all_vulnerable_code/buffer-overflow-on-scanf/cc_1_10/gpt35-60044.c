//FormAI DATASET v1.0 Category: Data mining ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct Student {
  int id;
  char name[20];
  float gpa;
};

int main() {
  int n, search_id;
  struct Student *students;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  students = (struct Student*) malloc(n * sizeof(struct Student));

  printf("Enter the details of the students:\n");

  for(int i = 0; i < n; i++) {
    printf("\nStudent %d:\n", i+1);
    printf("ID: ");
    scanf("%d", &(students+i)->id);
    printf("Name: ");
    scanf("%s", &(students+i)->name);
    printf("GPA: ");
    scanf("%f", &(students+i)->gpa);
  }

  printf("\nEnter the ID of student to search: ");
  scanf("%d", &search_id);

  int student_found = 0;
  for(int i = 0; i < n; i++) {
    if((students+i)->id == search_id) {
      printf("\nDetails of student with ID %d:\n", search_id);
      printf("Name: %s\n", (students+i)->name);
      printf("GPA: %0.2f\n", (students+i)->gpa);
      student_found = 1;
      break;
    }
  }

  if(student_found == 0)
    printf("\nStudent with ID %d not found!\n", search_id);

  free(students);

  return 0;
}