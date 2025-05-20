//FormAI DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records in database
#define MAX_NAME_LENGTH 20 // Maximum length of name
#define MAX_PHONE_LENGTH 10 // Maximum length of phone

typedef struct {
   int id;
   char name[MAX_NAME_LENGTH];
   char phone[MAX_PHONE_LENGTH];
} Record;

typedef struct {
   Record records[MAX_RECORDS];
   int size;
} Database;

// Function prototypes
void displayMenu();
void addRecord(Database *db);
void deleteRecord(Database *db, int id);
void searchRecord(Database *db, int id);
void displayAllRecords(Database *db);

// Main function
int main() {
   Database db = {0}; // Initialize database with zero records
   int option = 0;

   do {
      displayMenu();
      scanf("%d", &option);

      switch (option) {
      case 1:
         addRecord(&db);
         break;

      case 2:
         {
            int id;
            printf("Enter the ID of the record to be deleted: ");
            scanf("%d", &id);
            deleteRecord(&db, id);
         }
         break;

      case 3:
         {
            int id;
            printf("Enter the ID of the record to be searched: ");
            scanf("%d", &id);
            searchRecord(&db, id);
         }
         break;

      case 4:
         displayAllRecords(&db);
         break;

      case 5:
         printf("Exiting program...\n\n");
         exit(0);

      default:
         printf("Invalid option.\n\n");
         break;
      }
   } while (option != 5);

   return 0;
}

// Display menu
void displayMenu() {
   printf("===== Database Menu =====\n");
   printf("1. Add record\n");
   printf("2. Delete record\n");
   printf("3. Search record\n");
   printf("4. Display all records\n");
   printf("5. Exit program\n\n");
   printf("Enter your choice: ");
}

// Add record
void addRecord(Database *db) {
   if (db->size == MAX_RECORDS) {
      printf("Cannot add more records. Database is full.\n\n");
      return;
   }

   printf("Enter record ID (integer): ");
   scanf("%d", &db->records[db->size].id);

   printf("Enter name: ");
   scanf("%s", db->records[db->size].name);

   printf("Enter phone number: ");
   scanf("%s", db->records[db->size].phone);

   db->size++;

   printf("Record added successfully.\n\n");
}

// Delete record
void deleteRecord(Database *db, int id) {
   int i, j, found = 0;

   for (i = 0; i < db->size; i++) {
      if (db->records[i].id == id) {
         found = 1;
         break;
      }
   }

   if (!found) {
      printf("Record with ID %d does not exist.\n\n", id);
      return;
   }

   for (j = i; j < db->size - 1; j++) {
      db->records[j] = db->records[j + 1];
   }

   db->size--;

   printf("Record with ID %d deleted successfully.\n\n", id);
}

// Search record
void searchRecord(Database *db, int id) {
   int i, found = 0;

   for (i = 0; i < db->size; i++) {
      if (db->records[i].id == id) {
         found = 1;
         break;
      }
   }

   if (!found) {
      printf("Record with ID %d does not exist.\n\n", id);
      return;
   }

   printf("Record with ID %d found:\n", id);
   printf("Name: %s\n", db->records[i].name);
   printf("Phone number: %s\n\n", db->records[i].phone);
}

// Display all records
void displayAllRecords(Database *db) {
   int i;

   if (db->size == 0) {
      printf("Database is empty.\n\n");
      return;
   }

   printf("===== All Records =====\n");

   for (i = 0; i < db->size; i++) {
      printf("ID: %d, Name: %s, Phone number: %s\n", db->records[i].id, db->records[i].name, db->records[i].phone);
   }

   printf("\n");
}