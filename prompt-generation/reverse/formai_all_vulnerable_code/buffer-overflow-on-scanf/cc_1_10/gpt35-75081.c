//FormAI DATASET v1.0 Category: Educational ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Defining a structure to store student details
struct student {
   char name[50];
   int rollNo;
   float marks;
};

// Function prototypes
void printStudentDetails(struct student);
void printErrorMessage(char[]);

// main function
int main() {
   struct student s1, s2;

   // Reading data for student 1
   printf("Enter details for Student 1: \n");
   printf("Enter name: ");
   fgets(s1.name, 50, stdin);
   printf("Enter roll no: ");
   scanf("%d", &s1.rollNo);
   printf("Enter marks: ");
   scanf("%f", &s1.marks);
   getchar();

   // Reading data for student 2
   printf("\nEnter details for Student 2: \n");
   printf("Enter name: ");
   fgets(s2.name, 50, stdin);
   printf("Enter roll no: ");
   scanf("%d", &s2.rollNo);
   printf("Enter marks: ");
   scanf("%f", &s2.marks);
   getchar();

   // Printing student details
   printf("\nStudent Details: \n");
   printStudentDetails(s1);
   printStudentDetails(s2);

   return 0;
}

void printStudentDetails(struct student s) {
   // Checking if marks are valid
   if(s.marks < 0 || s.marks > 100) {
      printErrorMessage("Invalid input! Marks should be between 0 and 100.");
   } else {
      // Printing student details
      printf("Name: %s", s.name);
      printf("Roll no: %d", s.rollNo);
      printf("Marks: %.2f\n", s.marks);
   }
}

void printErrorMessage(char errorMessage[]) {
   // Printing error message
   printf("\nError: %s\n", errorMessage);
   // Exiting the program with error code
   exit(1);
}