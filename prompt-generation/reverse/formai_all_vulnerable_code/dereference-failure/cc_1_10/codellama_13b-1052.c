//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: artistic
// Artistic C Database Querying Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
  char name[20];
  int age;
  char gender;
} Person;

void print_person(Person *person) {
  printf("Name: %s\n", person->name);
  printf("Age: %d\n", person->age);
  printf("Gender: %c\n", person->gender);
}

int main() {
  // Declare a database with 5000 entries
  Person *db = (Person *)malloc(5000 * sizeof(Person));

  // Fill the database with random data
  srand(time(NULL));
  for (int i = 0; i < 5000; i++) {
    strcpy(db[i].name, "Person");
    db[i].age = rand() % 100 + 1;
    db[i].gender = (rand() % 2 == 0) ? 'M' : 'F';
  }

  // Query the database
  printf("Enter a name: ");
  char name[20];
  scanf("%s", name);
  printf("Enter an age: ");
  int age;
  scanf("%d", &age);
  printf("Enter a gender: ");
  char gender;
  scanf(" %c", &gender);

  // Find matching entries in the database
  Person *matching_entries = (Person *)malloc(5000 * sizeof(Person));
  int num_matching_entries = 0;
  for (int i = 0; i < 5000; i++) {
    if (strcmp(db[i].name, name) == 0 &&
        db[i].age == age &&
        db[i].gender == gender) {
      matching_entries[num_matching_entries++] = db[i];
    }
  }

  // Print the matching entries
  printf("Matching entries:\n");
  for (int i = 0; i < num_matching_entries; i++) {
    print_person(&matching_entries[i]);
  }

  // Clean up
  free(db);
  free(matching_entries);

  return 0;
}