//FormAI DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

struct Person {
   char name[50];
   int age;
   float salary;
};

int main() {
   int n;
   printf("Enter the number of persons: ");
   scanf("%d", &n);

   // Allocate memory to store n number of Person structs
   struct Person* people = (struct Person*)malloc(n * sizeof(struct Person));

   // Write data to file
   FILE* file = fopen("people.txt", "w");
   if (file == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   for (int i = 0; i < n; i++) {
      printf("\nEnter details of person %d:\n", i+1);

      printf("Name: ");
      scanf("%s", people[i].name);

      printf("Age: ");
      scanf("%d", &people[i].age);

      printf("Salary: ");
      scanf("%f", &people[i].salary);

      // Write the current person struct to file
      fprintf(file, "%s %d %.2f\n", people[i].name, people[i].age, people[i].salary);
   }

   fclose(file);

   // Read data from file
   file = fopen("people.txt", "r");
   if (file == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   printf("\nDetails of people:\n\n");

   for (int i = 0; i < n; i++) {
      // Read data from file into a temporary struct
      struct Person temp;
      fscanf(file, "%s %d %f", temp.name, &temp.age, &temp.salary);

      // Print the data from the temporary struct
      printf("Name: %s\n", temp.name);
      printf("Age: %d\n", temp.age);
      printf("Salary: %.2f\n\n", temp.salary);
   }

   fclose(file);
   free(people);

   return 0;
}