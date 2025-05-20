//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: creative
// C Database Simulation Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
struct record {
  char name[20];
  int age;
  char gender;
};

// Function to add a record to the database
void add_record(struct record *db, int size) {
  printf("Enter name: ");
  scanf("%s", db[size].name);
  printf("Enter age: ");
  scanf("%d", &db[size].age);
  printf("Enter gender: ");
  scanf(" %c", &db[size].gender);
  size++;
}

// Function to search for a record in the database
void search_record(struct record *db, int size) {
  char search_name[20];
  printf("Enter name to search: ");
  scanf("%s", search_name);
  for (int i = 0; i < size; i++) {
    if (strcmp(db[i].name, search_name) == 0) {
      printf("Found record: ");
      printf("Name: %s\n", db[i].name);
      printf("Age: %d\n", db[i].age);
      printf("Gender: %c\n", db[i].gender);
      return;
    }
  }
  printf("Record not found.\n");
}

// Function to delete a record from the database
void delete_record(struct record *db, int size) {
  char delete_name[20];
  printf("Enter name to delete: ");
  scanf("%s", delete_name);
  for (int i = 0; i < size; i++) {
    if (strcmp(db[i].name, delete_name) == 0) {
      for (int j = i; j < size - 1; j++) {
        db[j] = db[j + 1];
      }
      size--;
      return;
    }
  }
  printf("Record not found.\n");
}

// Main function
int main() {
  struct record db[100];
  int size = 0;

  // Add records to the database
  add_record(db, size);
  add_record(db, size);
  add_record(db, size);

  // Search for a record in the database
  search_record(db, size);

  // Delete a record from the database
  delete_record(db, size);

  // Search for a record in the database again
  search_record(db, size);

  return 0;
}