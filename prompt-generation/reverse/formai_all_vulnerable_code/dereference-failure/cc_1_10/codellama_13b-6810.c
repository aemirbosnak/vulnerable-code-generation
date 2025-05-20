//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: happy
/*
* Unique C Database Indexing System Example Program
* Happy Style
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a record in the database
typedef struct {
  int id;
  char name[50];
  char email[50];
} Record;

// Function to create a new record
Record* createRecord(int id, char* name, char* email) {
  Record* record = (Record*)malloc(sizeof(Record));
  record->id = id;
  strcpy(record->name, name);
  strcpy(record->email, email);
  return record;
}

// Function to print a record
void printRecord(Record* record) {
  printf("Record:\n");
  printf("  ID: %d\n", record->id);
  printf("  Name: %s\n", record->name);
  printf("  Email: %s\n", record->email);
}

// Function to insert a record into the database
void insertRecord(Record* record, Record** records, int* numRecords) {
  // Check if the record already exists
  for (int i = 0; i < *numRecords; i++) {
    if (records[i]->id == record->id) {
      printf("Record already exists!\n");
      return;
    }
  }

  // Insert the record
  records[*numRecords] = record;
  (*numRecords)++;
}

// Function to search for a record by ID
Record* searchRecordById(int id, Record** records, int numRecords) {
  // Search for the record
  for (int i = 0; i < numRecords; i++) {
    if (records[i]->id == id) {
      return records[i];
    }
  }

  // Record not found
  return NULL;
}

// Function to search for a record by name
Record* searchRecordByName(char* name, Record** records, int numRecords) {
  // Search for the record
  for (int i = 0; i < numRecords; i++) {
    if (strcmp(records[i]->name, name) == 0) {
      return records[i];
    }
  }

  // Record not found
  return NULL;
}

// Function to search for a record by email
Record* searchRecordByEmail(char* email, Record** records, int numRecords) {
  // Search for the record
  for (int i = 0; i < numRecords; i++) {
    if (strcmp(records[i]->email, email) == 0) {
      return records[i];
    }
  }

  // Record not found
  return NULL;
}

int main() {
  // Initialize the database
  Record** records = (Record**)malloc(sizeof(Record*) * 10);
  int numRecords = 0;

  // Insert some records
  Record* record1 = createRecord(1, "John", "john@example.com");
  Record* record2 = createRecord(2, "Jane", "jane@example.com");
  Record* record3 = createRecord(3, "Bob", "bob@example.com");
  insertRecord(record1, records, &numRecords);
  insertRecord(record2, records, &numRecords);
  insertRecord(record3, records, &numRecords);

  // Search for a record by ID
  Record* record = searchRecordById(1, records, numRecords);
  if (record != NULL) {
    printRecord(record);
  } else {
    printf("Record not found!\n");
  }

  // Search for a record by name
  record = searchRecordByName("Jane", records, numRecords);
  if (record != NULL) {
    printRecord(record);
  } else {
    printf("Record not found!\n");
  }

  // Search for a record by email
  record = searchRecordByEmail("bob@example.com", records, numRecords);
  if (record != NULL) {
    printRecord(record);
  } else {
    printf("Record not found!\n");
  }

  return 0;
}