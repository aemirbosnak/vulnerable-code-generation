//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct Student {
  char name[20];
  int roll_no;
  float marks[3];
  struct Student* next;
};

void insert_student(struct Student** head) {
  struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
  printf("Enter student's name: ");
  scanf("%s", new_student->name);
  printf("Enter student's roll number: ");
  scanf("%d", &new_student->roll_no);
  printf("Enter student's marks: ");
  scanf("%f", &new_student->marks[0]);
  scanf("%f", &new_student->marks[1]);
  scanf("%f", &new_student->marks[2]);
  new_student->next = NULL;

  if (*head == NULL) {
    *head = new_student;
  } else {
    (*head)->next = new_student;
  }
}

void print_students(struct Student* head) {
  while (head) {
    printf("Name: %s, Roll No: %d, Marks: %.1f, %.1f, %.1f\n", head->name, head->roll_no, head->marks[0], head->marks[1], head->marks[2]);
    head = head->next;
  }
}

int main() {
  struct Student* head = NULL;
  char choice;

  while (1) {
    printf("Enter 'i' to insert a student, 'p' to print students, or 'q' to quit: ");
    scanf("%c", &choice);

    switch (choice) {
      case 'i':
        insert_student(&head);
        break;
      case 'p':
        print_students(head);
        break;
      case 'q':
        exit(0);
    }
  }

  return 0;
}