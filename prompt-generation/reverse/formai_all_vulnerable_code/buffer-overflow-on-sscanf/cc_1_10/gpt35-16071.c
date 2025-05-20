//FormAI DATASET v1.0 Category: Data mining ; Style: future-proof
#include <stdio.h>

#define NUM_RECORDS 1000

typedef struct {
   int id;
   char name[20];
   char address[50];
   double salary;
} Employee;

int main() {
   Employee employees[NUM_RECORDS];
   FILE *data;

   data = fopen("employee_data.csv", "r");
   if (data == NULL) {
      printf("Error opening file!\n");
      return 1;
   }

   char buffer[1024];
   int count = 0;
   while (fgets(buffer, 1024, data) != NULL && count < NUM_RECORDS) {
      sscanf(buffer, "%d,%[^,],%[^,],%lf", 
             &employees[count].id, 
             employees[count].name, 
             employees[count].address, 
             &employees[count].salary);
      count++;
   }

   fclose(data);

   // Example data mining step: Finding employees with salaries > $100,000
   Employee *high_earners[NUM_RECORDS];
   int num_high_earners = 0;
   for (int i = 0; i < NUM_RECORDS; i++) {
      if (employees[i].salary > 100000) {
         high_earners[num_high_earners] = &employees[i];
         num_high_earners++;
      }
   }

   printf("Found %d employees with salaries > $100,000:\n", num_high_earners);
   for (int i = 0; i < num_high_earners; i++) {
      printf("%-10d %-20s %-50s $%.2lf\n", 
             high_earners[i]->id, 
             high_earners[i]->name,
             high_earners[i]->address,
             high_earners[i]->salary);
   }

   return 0;
}