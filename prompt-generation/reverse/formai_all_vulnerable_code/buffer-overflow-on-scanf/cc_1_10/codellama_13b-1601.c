//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
// apocalyptic_index.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_ENTRIES 100

typedef struct {
  char name[20];
  char description[50];
  int value;
} db_entry_t;

db_entry_t db[MAX_DB_ENTRIES];

int main() {
  // Initialize the database
  for (int i = 0; i < MAX_DB_ENTRIES; i++) {
    db[i].name[0] = '\0';
    db[i].description[0] = '\0';
    db[i].value = 0;
  }

  // User input
  char name[20];
  char description[50];
  int value;

  printf("Enter a name: ");
  scanf("%s", name);
  printf("Enter a description: ");
  scanf("%s", description);
  printf("Enter a value: ");
  scanf("%d", &value);

  // Find an empty slot in the database
  int empty_slot = -1;
  for (int i = 0; i < MAX_DB_ENTRIES; i++) {
    if (db[i].name[0] == '\0') {
      empty_slot = i;
      break;
    }
  }

  // If there is an empty slot, add the entry to the database
  if (empty_slot != -1) {
    strcpy(db[empty_slot].name, name);
    strcpy(db[empty_slot].description, description);
    db[empty_slot].value = value;
    printf("Entry added successfully!\n");
  } else {
    printf("Database is full!\n");
  }

  // Display the database
  printf("Database:\n");
  for (int i = 0; i < MAX_DB_ENTRIES; i++) {
    if (db[i].name[0] != '\0') {
      printf("%s: %s (%d)\n", db[i].name, db[i].description, db[i].value);
    }
  }

  return 0;
}