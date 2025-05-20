//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10

typedef struct Student {
  char name[20];
  int roll_no;
  float marks;
  struct Student* next;
} Student;

Student* insert_at_tail(Student* head) {
  Student* new_node = (Student*)malloc(sizeof(Student));
  printf("Enter name: ");
  scanf("%s", new_node->name);
  printf("Enter roll no: ");
  scanf("%d", &new_node->roll_no);
  printf("Enter marks: ");
  scanf("%f", &new_node->marks);

  if (head == NULL) {
    head = new_node;
  } else {
    head->next = new_node;
  }

  return head;
}

void display_students(Student* head) {
  while (head) {
    printf("Name: %s, Roll No: %d, Marks: %.2f\n", head->name, head->roll_no, head->marks);
    head = head->next;
  }
}

int main() {
  Student* head = NULL;
  int choice;

  while (1) {
    printf("1. Insert at tail\n");
    printf("2. Display students\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        head = insert_at_tail(head);
        break;
      case 2:
        display_students(head);
        break;
      default:
        printf("Invalid choice\n");
    }

    printf("Do you want to continue? (Y/N): ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'N') {
      break;
    }
  }

  return 0;
}