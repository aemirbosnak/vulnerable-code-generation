//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: portable
// Portable C database simulation program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DB_SIZE 1000
#define MAX_NAME_LENGTH 32
#define MAX_DATA_LENGTH 64

// Database structure
typedef struct {
  char name[MAX_NAME_LENGTH];
  char data[MAX_DATA_LENGTH];
} db_entry;

// Database functions
void create_db(db_entry **db, int size) {
  *db = (db_entry *)malloc(size * sizeof(db_entry));
  for (int i = 0; i < size; i++) {
    (*db)[i].name[0] = '\0';
    (*db)[i].data[0] = '\0';
  }
}

void insert_entry(db_entry *db, int index, char *name, char *data) {
  strcpy(db[index].name, name);
  strcpy(db[index].data, data);
}

void update_entry(db_entry *db, int index, char *data) {
  strcpy(db[index].data, data);
}

void delete_entry(db_entry *db, int index) {
  db[index].name[0] = '\0';
  db[index].data[0] = '\0';
}

void print_db(db_entry *db, int size) {
  for (int i = 0; i < size; i++) {
    if (db[i].name[0] != '\0') {
      printf("%s - %s\n", db[i].name, db[i].data);
    }
  }
}

// Main program
int main(void) {
  // Initialize database
  db_entry *db;
  int db_size = 10;
  create_db(&db, db_size);

  // Insert entries
  insert_entry(db, 0, "Alice", "Data for Alice");
  insert_entry(db, 1, "Bob", "Data for Bob");
  insert_entry(db, 2, "Charlie", "Data for Charlie");

  // Update entries
  update_entry(db, 0, "New data for Alice");
  update_entry(db, 2, "New data for Charlie");

  // Delete entries
  delete_entry(db, 1);

  // Print database
  print_db(db, db_size);

  // Free memory
  free(db);

  return 0;
}