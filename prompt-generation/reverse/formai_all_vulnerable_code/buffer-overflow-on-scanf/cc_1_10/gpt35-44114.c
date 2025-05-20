//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20

typedef struct student {
   char name[MAX_NAME_LENGTH];
   char id[MAX_ID_LENGTH];
   int age;
   struct student *next;
} Student;

typedef struct index_node {
   char id[MAX_ID_LENGTH];
   Student *student_ptr;
   struct index_node *next;
} IndexNode;

IndexNode *primary_index = NULL;

void add_student();
void list_students();
void search_student();

int main() {

   int input;

   while(1) {
      printf("\nEnter choice:\n");
      printf("1. Add student\n");
      printf("2. List students\n");
      printf("3. Search student\n");
      printf("4. Exit\n");

      scanf("%d", &input);

      switch(input) {
         case 1:
            add_student();
            break;
         case 2:
            list_students();
            break;
         case 3:
            search_student();
            break;
         case 4:
            exit(0);
            break;
         default:
            printf("Invalid choice\n");
            break;
      }
   }

   return 0;
}

void add_student() {

   Student *new_student = (Student*)malloc(sizeof(Student));
   printf("\nEnter student name: ");
   scanf("%s", new_student->name);
   printf("Enter student ID: ");
   scanf("%s", new_student->id);
   printf("Enter student age: ");
   scanf("%d", &new_student->age);
   new_student->next = NULL;

   // Add the student to primary index
   IndexNode *index_ptr = primary_index;
   while(index_ptr != NULL) {
      if(strcmp(new_student->id, index_ptr->id) == 0) {
         printf("\nError: Student with ID %s already exists\n", new_student->id);
         return;
      }
      index_ptr = index_ptr->next;
   }
   IndexNode *new_index_node = (IndexNode*)malloc(sizeof(IndexNode));
   strcpy(new_index_node->id, new_student->id);
   new_index_node->student_ptr = new_student;
   new_index_node->next = primary_index;
   primary_index = new_index_node;

   printf("\nStudent %s added successfully\n", new_student->name);
}

void list_students() {

   printf("\nList of students:\n");
   IndexNode *index_ptr = primary_index;
   while(index_ptr != NULL) {
      printf("Name: %s, ID: %s, Age: %d\n",
            index_ptr->student_ptr->name, index_ptr->id, index_ptr->student_ptr->age);
      index_ptr = index_ptr->next;
   }
}

void search_student() {

   char search_id[MAX_ID_LENGTH];
   printf("\nEnter student ID to search: ");
   scanf("%s", search_id);

   IndexNode *index_ptr = primary_index;
   while(index_ptr != NULL) {
      if(strcmp(search_id, index_ptr->id) == 0) {
         printf("\nStudent found:\n");
         printf("Name: %s, ID: %s, Age: %d\n",
            index_ptr->student_ptr->name, index_ptr->id, index_ptr->student_ptr->age);
         return;
      }
      index_ptr = index_ptr->next;
   }

   printf("\nStudent with ID %s not found\n", search_id);
}