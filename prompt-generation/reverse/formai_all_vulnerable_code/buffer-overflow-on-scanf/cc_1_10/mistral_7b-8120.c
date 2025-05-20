//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: invasive
#include <stdio.h> #include <stdlib.h> #include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_OF_STUDENTS 100

typedef struct Student {
 char name[MAX_NAME_LEN];
 int roll_number;
 struct Student* next;
} Student;

Student* head = NULL;

void add_student(char* name, int roll_number) {
 Student* new_student = (Student*)malloc(sizeof(Student));
 if (new_student == NULL) {
 printf("Memory error! Unable to allocate memory for new student.\n");
 return;
 }
 strcpy(new_student->name, name);
 new_student->roll_number = roll_number;
 new_student->next = head;
 head = new_student;
}

void print_student_list() {
 Student* current = head;
 if (head == NULL) {
 printf("Student list is empty.\n");
 return;
 }
 printf("Student List:\n");
 while (current != NULL) {
 printf("%d. %s (%d)\n", current->roll_number, current->name, current->roll_number);
 current = current->next;
 }
}

void delete_student_by_roll_number(int roll_number) {
 Student* current = head;
 Student* previous = NULL;
 if (head == NULL) {
 printf("Student list is empty.\n");
 return;
 }
 if (head->roll_number == roll_number) {
 head = head->next;
 free(current);
 return;
 }
 while (current != NULL && current->roll_number != roll_number) {
 previous = current;
 current = current->next;
 }
 if (current == NULL) {
 printf("Student with roll number %d not found.\n", roll_number);
 return;
 }
 previous->next = current->next;
 free(current);
}

int main() {
 int i;
 char name[MAX_NAME_LEN];
 int roll_number;
 for (i = 0; i < MAX_NUM_OF_STUDENTS; i++) {
 printf("Enter name and roll number for student %d: ", i + 1);
 scanf("%s", name);
 scanf("%d", &roll_number);
 add_student(name, roll_number);
 }
 print_student_list();
 int roll_to_delete;
 printf("Enter roll number of student to delete: ");
 scanf("%d", &roll_to_delete);
 delete_student_by_roll_number(roll_to_delete);
 print_student_list();
 return 0;
}