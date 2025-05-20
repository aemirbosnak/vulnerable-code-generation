//FormAI DATASET v1.0 Category: Database querying ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Global database structure
struct database {
   char name[20];
   int age;
   char occupation[20];
} data[3]; // Considering 3 records in database

// Function prototypes
void insert_record();
void delete_record();
void search_record();

int main() {
   int choice;

   do {
      printf("\nMENU:\n");
      printf("1. Insert a record\n");
      printf("2. Delete a record\n");
      printf("3. Search for a record\n");
      printf("4. Exit\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            insert_record();
            break;
         case 2:
            delete_record();
            break;
         case 3:
            search_record();
            break;
         case 4:
            printf("Exiting...\n");
            break;
         default:
            printf("Invalid input!");
      }
   } while(choice != 4);

   return 0;
}

// Function to insert a record in database
void insert_record() {
   int i;

   for(i = 0; i < 3; i++) { // Assuming there are only 3 records in database
      if(data[i].age == 0) { // Checking for empty space
         printf("Enter name: ");
         scanf("%s", data[i].name);
         printf("Enter age: ");
         scanf("%d", &data[i].age);
         printf("Enter occupation: ");
         scanf("%s", data[i].occupation);

         printf("\nRecord inserted successfully!\n");

         break;
      }
   }

   if(i == 3) {
      printf("\nDatabase is full!\n");
   }
}

// Function to delete a record from database
void delete_record() {
   char name[20];
   int i, flag = 0;

   printf("Enter the name of record you want to delete: ");
   scanf("%s", name);

   for(i = 0; i < 3; i++) { // Assuming there are only 3 records in database
      if(strcmp(data[i].name, name) == 0) { // Checking for matching name
         data[i].age = 0;
         strcpy(data[i].name, "");
         strcpy(data[i].occupation, "");

         printf("\nRecord deleted successfully!\n");

         flag = 1;
         break;
      }
   }

   if(flag == 0) {
      printf("\nRecord not found!\n");
   }
}

// Function to search for a record in database
void search_record() {
   char name[20];
   int i, flag = 0;

   printf("Enter the name of record you want to search: ");
   scanf("%s", name);

   for(i = 0; i < 3; i++) { // Assuming there are only 3 records in database
      if(strcmp(data[i].name, name) == 0) { // Checking for matching name
         printf("\nRecord found!\n");
         printf("Name: %s\n", data[i].name);
         printf("Age: %d\n", data[i].age);
         printf("Occupation: %s\n", data[i].occupation);

         flag = 1;
         break;
      }
   }

   if(flag == 0) {
      printf("\nRecord not found!\n");
   }
}