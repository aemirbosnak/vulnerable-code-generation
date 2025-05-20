//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the database structure
typedef struct {
  int id;
  char *name;
  int age;
} person;

// Create a database of persons
person database[] = {
  {1, "John", 20},
  {2, "Mary", 25},
  {3, "Bob", 30},
  {4, "Alice", 35},
  {5, "Tom", 40},
};

// Define the query function
void query(char *name) {
  // Iterate over the database
  for (int i = 0; i < 5; i++) {
    // Check if the name matches the query
    if (strcmp(database[i].name, name) == 0) {
      // Print the person's information
      printf("ID: %d\n", database[i].id);
      printf("Name: %s\n", database[i].name);
      printf("Age: %d\n", database[i].age);
      break;
    }
  }
}

// Get the user's input
char *getInput() {
  char *name = malloc(256);
  printf("Enter the name of the person you want to query: ");
  scanf("%s", name);
  return name;
}

// Main function
int main() {
  // Get the user's input
  char *name = getInput();

  // Query the database
  query(name);

  // Free the allocated memory
  free(name);

  return 0;
}