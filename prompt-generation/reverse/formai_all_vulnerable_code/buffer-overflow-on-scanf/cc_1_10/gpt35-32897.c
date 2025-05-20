//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
struct database {
  int id;
  char name[50];
  char address[100];
  float salary;
};

// Define the indexing structure
struct index {
  int id;
  int offset;
};

// Declare global variables
int num_records;
struct database *db;
struct index *idx;

// Function to read the database from a file
void read_database(char *filename) {
   FILE *fp = fopen(filename, "rb");
   if(fp == NULL) {
       printf("Error: Unable to open file %s", filename);
       exit(1);
   }
   fread(&num_records, sizeof(int), 1, fp);
   db = (struct database*) malloc(num_records * sizeof(struct database));
   for(int i = 0; i < num_records; i++) {
       fread(&db[i], sizeof(struct database), 1, fp);
   }
   fclose(fp);
}

// Function to build the index
void build_index() {
   idx = (struct index*) malloc(num_records * sizeof(struct index));
   for(int i = 0; i < num_records; i++) {
       idx[i].id = db[i].id;
       idx[i].offset = i;
   }
}

// Function to search for a record by id
void search_by_id(int id) {
   int i = 0;
   while(i < num_records && idx[i].id <= id) {
       if(idx[i].id == id) {
           printf("Record Found: ID=%d Name=%s Address=%s Salary=%.2f\n", db[idx[i].offset].id, db[idx[i].offset].name, db[idx[i].offset].address, db[idx[i].offset].salary);
           return;
       }
       i++;
   }
   printf("Record Not Found\n");
}

// Function to insert a new record
void insert_record(struct database rec) {
   int i = num_records - 1;
   while(i >= 0 && db[i].id > rec.id) {
       db[i+1] = db[i];
       idx[i+1] = idx[i];
       i--;
   }
   db[i+1] = rec;
   idx[i+1].id = rec.id;
   idx[i+1].offset = i+1;
   num_records++;
}

// Function to delete a record by id
void delete_by_id(int id) {
   int i = 0;
   while(i < num_records && idx[i].id <= id) {
       if(idx[i].id == id) {
           for(int j = i; j < num_records-1; j++) {
               db[j] = db[j+1];
               idx[j] = idx[j+1];
           }
           num_records--;
           return;
       }
       i++;
   }
}

// Function to write the database to a file
void write_database(char *filename) {
   FILE *fp = fopen(filename, "wb");
   if(fp == NULL) {
       printf("Error: Unable to create file %s", filename);
       exit(1);
   }
   fwrite(&num_records, sizeof(int), 1, fp);
   for(int i = 0; i < num_records; i++) {
       fwrite(&db[i], sizeof(struct database), 1, fp);
   }
   fclose(fp);
}

// Main function
int main() {
   int choice;
   char filename[] = "employees.dat";
   read_database(filename);
   build_index();
   while(1) {
       printf("\nDatabase Indexing System\n");
       printf("1. Search\n");
       printf("2. Insert\n");
       printf("3. Delete\n");
       printf("4. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);
       switch(choice) {
           case 1: {
               int id;
               printf("Enter the id: ");
               scanf("%d", &id);
               search_by_id(id);
               break;
           }
           case 2: {
               struct database rec;
               printf("Enter the record (id name address salary): ");
               scanf("%d %s %s %f", &rec.id, rec.name, rec.address, &rec.salary);
               insert_record(rec);
               printf("Record inserted successfully\n");
               break;
           }
           case 3: {
               int id;
               printf("Enter the id: ");
               scanf("%d", &id);
               delete_by_id(id);
               printf("Record deleted successfully\n");
               break;
           }
           case 4: {
               write_database(filename);
               exit(0);
           }
           default: {
               printf("Invalid choice\n");
               break;
           }
       }
   }
   return 0;
}