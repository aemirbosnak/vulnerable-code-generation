//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_DATA_LENGTH 1000

typedef struct {
  char key[MAX_KEY_LENGTH];
  char data[MAX_DATA_LENGTH];
} DataRecord;

typedef struct {
  DataRecord** records;
  int capacity;
  int size;
} Database;

Database* createDatabase(int capacity) {
  Database* db = malloc(sizeof(Database));
  db->records = malloc(capacity * sizeof(DataRecord*));
  db->capacity = capacity;
  db->size = 0;
  return db;
}

void addRecord(Database* db, DataRecord* record) {
  if (db->size >= db->capacity) {
    // database is full, increase capacity
    db->capacity *= 2;
    db->records = realloc(db->records, db->capacity * sizeof(DataRecord*));
  }
  db->records[db->size] = record;
  db->size++;
}

DataRecord* findRecord(Database* db, char* key) {
  for (int i = 0; i < db->size; i++) {
    if (strcmp(db->records[i]->key, key) == 0) {
      return db->records[i];
    }
  }
  return NULL;
}

void deleteRecord(Database* db, char* key) {
  int index = findRecord(db, key);
  if (index != -1) {
    // delete record at index
    free(db->records[index]);
    for (int i = index; i < db->size - 1; i++) {
      db->records[i] = db->records[i + 1];
    }
    db->size--;
  }
}

void printDatabase(Database* db) {
  for (int i = 0; i < db->size; i++) {
    printf("Key: %s, Data: %s\n", db->records[i]->key, db->records[i]->data);
  }
}

int main() {
  Database* db = createDatabase(10);

  // add records
  DataRecord* record1 = malloc(sizeof(DataRecord));
  strcpy(record1->key, "key1");
  strcpy(record1->data, "data1");
  addRecord(db, record1);

  DataRecord* record2 = malloc(sizeof(DataRecord));
  strcpy(record2->key, "key2");
  strcpy(record2->data, "data2");
  addRecord(db, record2);

  DataRecord* record3 = malloc(sizeof(DataRecord));
  strcpy(record3->key, "key3");
  strcpy(record3->data, "data3");
  addRecord(db, record3);

  // delete a record
  deleteRecord(db, "key2");

  // print database
  printDatabase(db);

  return 0;
}