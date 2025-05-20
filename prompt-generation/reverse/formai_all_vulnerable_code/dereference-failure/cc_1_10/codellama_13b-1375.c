//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include <limits.h>

  typedef struct {
    int key;
    char value[100];
  } entry_t;

  typedef struct {
    entry_t* entries;
    int size;
    int capacity;
  } database_t;

  database_t* create_database(int capacity) {
    database_t* db = malloc(sizeof(database_t));
    db->entries = malloc(capacity * sizeof(entry_t));
    db->size = 0;
    db->capacity = capacity;
    return db;
  }

  void add_entry(database_t* db, int key, char* value) {
    if (db->size >= db->capacity) {
      db->capacity *= 2;
      db->entries = realloc(db->entries, db->capacity * sizeof(entry_t));
    }
    db->entries[db->size].key = key;
    strcpy(db->entries[db->size].value, value);
    db->size++;
  }

  void print_entry(entry_t* entry) {
    printf("Key: %d, Value: %s\n", entry->key, entry->value);
  }

  void print_database(database_t* db) {
    for (int i = 0; i < db->size; i++) {
      print_entry(&db->entries[i]);
    }
  }

  int main() {
    database_t* db = create_database(10);
    add_entry(db, 1, "John");
    add_entry(db, 2, "Jane");
    add_entry(db, 3, "Bob");
    print_database(db);
    return 0;
  }