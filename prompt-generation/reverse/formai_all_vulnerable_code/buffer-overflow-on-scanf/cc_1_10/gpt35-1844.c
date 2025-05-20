//FormAI DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct employee {
   char name[50];
   int age;
   float salary;
};

int main() {
   int n = 3, i;
   struct employee employees[n];
   
   // Get employee details from user
   for(i=0; i<n; i++) {
      printf("Enter details of Employee %d:\n", i+1);
      printf("Name: ");
      scanf("%s", employees[i].name);
      printf("Age: ");
      scanf("%d", &employees[i].age);
      printf("Salary: ");
      scanf("%f", &employees[i].salary);
   }

   // Create file pointer
   FILE *file;

   // Open file in write mode
   file = fopen("employees.txt", "w");

   // Check if file exists
   if (file == NULL) {
      printf("Error in opening file!\n");
      exit(1);
   }

   // Write employee details to file
   for(i=0; i<n; i++) {
      fprintf(file, "Employee %d:\n", i+1);
      fprintf(file, "Name: %s\n", employees[i].name);
      fprintf(file, "Age: %d\n", employees[i].age);
      fprintf(file, "Salary: %.2f\n\n", employees[i].salary);
   }

   // Close file
   fclose(file);

   // Open file in read mode
   file = fopen("employees.txt", "r");

   // Check if file exists
   if (file == NULL) {
      printf("Error in opening file!\n");
      exit(1);
   }

   // Read and display employee details from file
   printf("Employee Details:\n\n");
   char c = fgetc(file);
   while (c != EOF) {
      printf("%c", c);
      c = fgetc(file);
   }

   // Close file
   fclose(file);

   return 0;
}