//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure representing a student record
struct Student {
   int id;
   char name[50];
   char department[50];
   float gpa;
};

// function definition to query the database
void query_database() {

   // open the database file for reading
   FILE* fp = fopen("students.db", "r");

   // exit if the database file does not exist
   if(fp == NULL) {
      printf("Error opening file.\n");
      exit(1);
   }
   
   // create an array to store all the student records
   struct Student students[100];
   
   // read each student record from the database file into the array
   int i = 0;
   while(fscanf(fp, "%d %s %s %f", &students[i].id, students[i].name, students[i].department, &students[i].gpa) == 4) {
      i++;
   }

   // close the database file
   fclose(fp);

   // print out all the records
   printf("ID\tName\t\tDepartment\tGPA\n");
   for(int j = 0; j < i; j++) {
      printf("%d\t%s\t\t%s\t\t%.2f\n", students[j].id, students[j].name, students[j].department, students[j].gpa);
   }

   // prompt the user to enter a department to search for
   char department[50];
   printf("\nEnter the department to search for: ");
   scanf("%s", department);

   // search for all the students in the specified department and print out their records
   printf("\nStudents in the %s department:\n", department);
   for(int j = 0; j < i; j++) {
      if(strcmp(students[j].department, department) == 0) {
         printf("%d\t%s\t\t%s\t\t%.2f\n", students[j].id, students[j].name, students[j].department, students[j].gpa);
      }
   }
}

// main function
int main() {
   // call the function to query the database
   query_database();

   return 0;
}