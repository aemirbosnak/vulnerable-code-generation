//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>

// Define a struct for our data structure.
typedef struct {
  char name[20];
  int age;
  float height;
} Person;

int main() {
  // Create an array of Person structs with some initial data.
  Person people[5] = {
    {"Alice", 25, 1.75},
    {"Bob", 30, 1.80},
    {"Charlie", 35, 1.85},
    {"David", 40, 1.90},
    {"Eve", 45, 1.95}
  };

  // Print out the initial state of our data structure.
  printf("Initial data structure:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s\t%d\t%.2f\n", people[i].name, people[i].age, people[i].height);
  }

  // Let's say we want to remove the third person from the array.
  printf("\nRemoving third person...\n");
  for (int i = 2; i < 5; i++) {
    people[i] = people[i+1];
  }

  // Print out the new state of our data structure.
  printf("\nNew data structure:\n");
  for (int i = 0; i < 4; i++) {
    printf("%s\t%d\t%.2f\n", people[i].name, people[i].age, people[i].height);
  }

  // Let's say we want to add a new person to the array.
  printf("\nAdding new person...\n");
  Person newPerson = {"Frank", 50, 2.00};
  people[4] = newPerson;

  // Print out the new state of our data structure again.
  printf("\nNew data structure:\n");
  for (int i = 0; i < 5; i++) {
    printf("%s\t%d\t%.2f\n", people[i].name, people[i].age, people[i].height);
  }

  // Exit the program.
  return 0;
}