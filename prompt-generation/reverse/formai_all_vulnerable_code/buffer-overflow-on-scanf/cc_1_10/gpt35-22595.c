//FormAI DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   char name[50];
   int rollno;
   float marks;
};

void add_student() {
   struct student s;
   FILE *f;
   f = fopen("student_database.txt", "ab+");
   printf("Enter student name: ");
   scanf("%s", s.name);
   printf("Enter student roll number: ");
   scanf("%d", &s.rollno);
   printf("Enter student marks: ");
   scanf("%f", &s.marks);
   fwrite(&s, sizeof(struct student), 1, f);
   fclose(f);
}

void display_student() {
   struct student s;
   FILE *f;
   f = fopen("student_database.txt", "rb");
   printf("Student Details:\n");
   while (fread(&s, sizeof(struct student), 1, f)) {
      printf("Name: %s\nRoll Number: %d\nMarks: %.2f\n\n", s.name, s.rollno, s.marks);
   }
   fclose(f);
}

void search_student() {
   int rollno;
   struct student s;
   FILE *f;
   f = fopen("student_database.txt", "rb");
   printf("Enter student roll number to search: ");
   scanf("%d", &rollno);
   while (fread(&s, sizeof(struct student), 1, f)) {
      if (s.rollno == rollno) {
         printf("Name: %s\nRoll Number: %d\nMarks: %.2f\n\n", s.name, s.rollno, s.marks);
         break;
      }
   }
   fclose(f);
}

int main() {
   int choice;
   do {
      printf("*** Student Database Menu ***\n");
      printf("1. Add Student\n2. Display All\n3. Search by Roll Number\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            add_student();
            break;
         case 2:
            display_student();
            break;
         case 3:
            search_student();
            break;
         case 4:
            printf("Goodbye!\n");
            exit(0);
         default:
            printf("Invalid Choice. Please Try Again.\n");
      }
   } while (choice != 4);
   return 0;
}