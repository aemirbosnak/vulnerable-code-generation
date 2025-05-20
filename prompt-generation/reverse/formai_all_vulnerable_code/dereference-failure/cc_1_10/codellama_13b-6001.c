//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 32
#define MAX_ADDRESS_LEN 64

typedef struct {
  char name[MAX_NAME_LEN];
  char address[MAX_ADDRESS_LEN];
} person_t;

typedef struct {
  person_t *people;
  int size;
} database_t;

database_t *create_database(int size) {
  database_t *db = malloc(sizeof(database_t));
  db->people = malloc(size * sizeof(person_t));
  db->size = size;
  return db;
}

void insert_person(database_t *db, person_t *person) {
  int i;
  for (i = 0; i < db->size; i++) {
    if (strcmp(db->people[i].name, person->name) == 0) {
      printf("Person already exists in the database\n");
      return;
    }
  }
  strcpy(db->people[db->size].name, person->name);
  strcpy(db->people[db->size].address, person->address);
  db->size++;
}

person_t *find_person(database_t *db, char *name) {
  int i;
  for (i = 0; i < db->size; i++) {
    if (strcmp(db->people[i].name, name) == 0) {
      return &db->people[i];
    }
  }
  return NULL;
}

void print_database(database_t *db) {
  int i;
  for (i = 0; i < db->size; i++) {
    printf("%s: %s\n", db->people[i].name, db->people[i].address);
  }
}

int main() {
  database_t *db = create_database(10);

  person_t person1 = {"John", "123 Main St"};
  person_t person2 = {"Jane", "456 Elm St"};
  person_t person3 = {"Bob", "789 Oak St"};

  insert_person(db, &person1);
  insert_person(db, &person2);
  insert_person(db, &person3);

  print_database(db);

  person_t *found = find_person(db, "Bob");
  if (found != NULL) {
    printf("Found Bob: %s\n", found->address);
  } else {
    printf("Bob not found\n");
  }

  return 0;
}