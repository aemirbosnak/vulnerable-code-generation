//FormAI DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Define a structure for storing student records
typedef struct {
   int id;
   char name[30];
   char address[50];
   char phone[15];
   float gpa;
} Student;

// Declare a global array of students
Student students[MAX_SIZE];

// Declare a function for creating an index file
void createIndexFile(char* fileName) {
   FILE* indexFile = fopen("index.txt", "w");
   for (int i = 0; i < MAX_SIZE; i++) {
      fprintf(indexFile, "%d\n", students[i].id);
   }
   fclose(indexFile);
}

// Declare a function for searching the index file and returning the record position
int searchIndexFile(char* fileName, int searchKey) {
   int position = -1;
   FILE* indexFile = fopen("index.txt", "r");
   int id;
   for (int i = 0; i < MAX_SIZE; i++) {
      fscanf(indexFile, "%d", &id);
      if (id == searchKey) {
         position = i;
         break;
      }
   }
   fclose(indexFile);
   return position;
}

// Declare a function for adding a new record to the database
void addRecord() {
   int id;
   char name[30];
   char address[50];
   char phone[15];
   float gpa;
   printf("\nEnter student ID: ");
   scanf("%d", &id);
   int position = searchIndexFile("index.txt", id);
   if (position != -1) {
      printf("\nRecord already exists at position %d\n", position);
   } else {
      printf("\nEnter student name: ");
      scanf("%s", name);
      printf("\nEnter student address: ");
      scanf("%s", address);
      printf("\nEnter student phone number: ");
      scanf("%s", phone);
      printf("\nEnter student GPA: ");
      scanf("%f", &gpa);
      Student s = {id, name, address, phone, gpa};
      students[MAX_SIZE - 1] = s;
      createIndexFile("index.txt");
      printf("\nRecord added successfully!\n");
   }
}

// Declare a function for updating an existing record in the database
void updateRecord() {
   int id;
   char name[30];
   char address[50];
   char phone[15];
   float gpa;
   printf("\nEnter student ID: ");
   scanf("%d", &id);
   int position = searchIndexFile("index.txt", id);
   if (position == -1) {
      printf("\nRecord not found.\n");
   } else {
      printf("\nEnter updated student name: ");
      scanf("%s", name);
      printf("\nEnter updated student address: ");
      scanf("%s", address);
      printf("\nEnter updated student phone number: ");
      scanf("%s", phone);
      printf("\nEnter updated student GPA: ");
      scanf("%f", &gpa);
      Student s = {id, name, address, phone, gpa};
      students[position] = s;
      printf("\nRecord updated successfully!\n");
   }
}

// Declare a function for deleting an existing record from the database
void deleteRecord() {
   int id;
   printf("\nEnter student ID to delete: ");
   scanf("%d", &id);
   int position = searchIndexFile("index.txt", id);
   if (position == -1) {
      printf("\nRecord not found.\n");
   } else {
      for (int i = position; i < MAX_SIZE - 1; i++) {
         students[i] = students[i + 1];
      }
      createIndexFile("index.txt");
      printf("\nRecord deleted successfully!\n");
   }
}

// Declare a function for displaying all records in the database
void displayRecords() {
   printf("\nStudent Records\n");
   printf("---------------\n");
   for (int i = 0; i < MAX_SIZE; i++) {
      printf("\nRecord %d\n", i);
      printf("ID: %d\n", students[i].id);
      printf("Name: %s\n", students[i].name);
      printf("Address: %s\n", students[i].address);
      printf("Phone Number: %s\n", students[i].phone);
      printf("GPA: %.2f\n", students[i].gpa);
   }
   printf("\n");
}

// Declare the main function
int main() {

   int choice;
   printf("Welcome to the Student Database\n");

   do {
      printf("\nChoose an Option\n");
      printf("-----------------\n");
      printf("1. Add a new record\n");
      printf("2. Update an existing record\n");
      printf("3. Delete a record\n");
      printf("4. Display all records\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            addRecord();
            break;
         case 2:
            updateRecord();
            break;
         case 3:
            deleteRecord();
            break;
         case 4:
            displayRecords();
            break;
         case 5:
            printf("\nThank you for using the Student Database\n");
            break;
         default:
            printf("\nInvalid choice. Please try again.\n");
      }
   } while (choice != 5);
   
   return 0;
}