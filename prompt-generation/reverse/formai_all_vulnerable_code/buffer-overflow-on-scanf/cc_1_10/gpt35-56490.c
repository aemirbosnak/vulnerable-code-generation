//FormAI DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to hold the information of a person
typedef struct Person {
  char name[50];
  int age;
  char gender[10];
} Person;

// Function to add a new person to the database
void addPerson(Person* database[], int* count) {
  // Allocate memory for a new person
  Person* newPerson = (Person*) malloc(sizeof(Person));
  
  // Get the information of the new person
  printf("Enter name: ");
  scanf("%s", newPerson->name);
  printf("Enter age: ");
  scanf("%d", &newPerson->age);
  printf("Enter gender: ");
  scanf("%s", newPerson->gender);
  
  // Add the new person to the database
  database[*count] = newPerson;
  (*count)++;
  
  printf("New person added successfully!\n");
}

// Function to remove a person from the database
void removePerson(Person* database[], int* count) {
  char nameToRemove[50];
  bool found = false;
  
  // Get the name of the person to remove
  printf("Enter name of person to remove: ");
  scanf("%s", nameToRemove);
  
  // Search for the person in the database
  for (int i = 0; i < *count; i++) {
    if (strcmp(database[i]->name, nameToRemove) == 0) {
      // Free the memory of the person
      free(database[i]);
      
      // Remove the person from the database
      for (int j = i; j < *count - 1; j++) {
        database[j] = database[j+1];
      }
      (*count)--;
      
      found = true;
      break;
    }
  }
  
  if (found) {
    printf("Person removed successfully!\n");
  } else {
    printf("Person not found in database.\n");
  }
}

// Function to print all the people in the database
void printAllPeople(Person* database[], int count) {
  printf("People in the database:\n");
  
  for (int i = 0; i < count; i++) {
    printf("%d. Name: %s, Age: %d, Gender: %s\n",
           i+1, database[i]->name, database[i]->age, database[i]->gender);
  }
}

int main() {
  // Initialize the database
  Person* database[100];
  int count = 0;
  
  // Display the options to the user
  printf("Welcome to the Database Simulation Program!\n");
  printf("Choose an option:\n");
  printf("1. Add a new person\n");
  printf("2. Remove a person\n");
  printf("3. Print all people\n");
  printf("4. Quit\n");
  
  int choice;
  bool quit = false;
  
  // Loop until the user quits
  while (!quit) {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        addPerson(database, &count);
        break;
      case 2:
        removePerson(database, &count);
        break;
      case 3:
        printAllPeople(database, count);
        break;
      case 4:
        quit = true;
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  }
  
  // Free the memory of all the people in the database
  for (int i = 0; i < count; i++) {
    free(database[i]);
  }
  
  return 0;
}