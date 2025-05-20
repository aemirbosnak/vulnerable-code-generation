//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: imaginative
// Imaginative C Database Indexing System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store data in the database
typedef struct {
  char* name;
  int age;
  float height;
} Person;

// Function to create a new person
Person* create_person(char* name, int age, float height) {
  Person* person = malloc(sizeof(Person));
  person->name = name;
  person->age = age;
  person->height = height;
  return person;
}

// Function to add a person to the database
void add_person_to_db(Person* person, char* db_file) {
  // Open the database file in append mode
  FILE* fp = fopen(db_file, "a");

  // Write the person's data to the file
  fprintf(fp, "%s %d %f\n", person->name, person->age, person->height);

  // Close the file
  fclose(fp);
}

// Function to search for a person in the database
Person* search_person_in_db(char* name, char* db_file) {
  // Open the database file in read mode
  FILE* fp = fopen(db_file, "r");

  // Read the data from the file
  char line[256];
  while (fgets(line, 256, fp) != NULL) {
    // Split the line into individual fields
    char* field1 = strtok(line, " ");
    char* field2 = strtok(NULL, " ");
    char* field3 = strtok(NULL, " ");

    // Check if the name matches
    if (strcmp(field1, name) == 0) {
      // Create a new person and return it
      Person* person = malloc(sizeof(Person));
      person->name = field1;
      person->age = atoi(field2);
      person->height = atof(field3);
      return person;
    }
  }

  // Close the file
  fclose(fp);

  // If the person is not found, return NULL
  return NULL;
}

// Function to print the data of a person
void print_person(Person* person) {
  printf("Name: %s\n", person->name);
  printf("Age: %d\n", person->age);
  printf("Height: %f\n", person->height);
}

int main() {
  // Create some people
  Person* person1 = create_person("Alice", 25, 1.65);
  Person* person2 = create_person("Bob", 30, 1.80);
  Person* person3 = create_person("Charlie", 35, 1.70);

  // Add the people to the database
  add_person_to_db(person1, "people.txt");
  add_person_to_db(person2, "people.txt");
  add_person_to_db(person3, "people.txt");

  // Search for a person in the database
  Person* found_person = search_person_in_db("Bob", "people.txt");

  // Print the data of the found person
  print_person(found_person);

  return 0;
}