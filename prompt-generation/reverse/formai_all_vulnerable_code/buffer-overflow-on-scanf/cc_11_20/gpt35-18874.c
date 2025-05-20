//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define the struct for database tables
typedef struct {
  int id;
  char name[MAX_SIZE];
  int age;
} Person;

int main() {
  // Declare the variables
  int option = 0, count = 0, i = 0, id = 0;
  Person database[MAX_SIZE];
  char name[MAX_SIZE];
  int age = 0;

  // Loop until the user chooses to quit
  while (option != 4) {
    printf("Welcome to the Database Simulation!\n");
    printf("Please select an option:\n");
    printf("1. Add a person to the database\n");
    printf("2. Search for a person in the database\n");
    printf("3. Display all people in the database\n");
    printf("4. Quit\n");

    // Get the user's option
    scanf("%d", &option);

    // Handle the user's option
    switch (option) {
      case 1:
        // Add a person to the database
        printf("Enter the name of the person: ");
        scanf("%s", name);
        printf("Enter the age of the person: ");
        scanf("%d", &age);

        // Add the person to the database
        database[count].id = count + 1;
        strcpy(database[count].name, name);
        database[count].age = age;
        printf("Person added to the database.\n");
        count++;
        break;

      case 2:
        // Search for a person in the database
        printf("Enter the ID of the person to search for: ");
        scanf("%d", &id);

        // Find the person in the database
        for (i = 0; i < count; i++) {
          if (database[i].id == id) {
            printf("Person found:\n");
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            break;
          }
        }

        if (i == count) {
          // Person not found
          printf("Person not found.\n");
        }
        break;

      case 3:
        // Display all people in the database
        if (count == 0) {
          printf("Database is empty.\n");
        } else {
          printf("ID\tName\t\tAge\n");
          for (i = 0; i < count; i++) {
            printf("%d\t%s\t\t%d\n", database[i].id, database[i].name, database[i].age);
          }
        }
        break;

      case 4:
        // Quit the program
        printf("Goodbye!\n");
        break;

      default:
        // Invalid option
        printf("Invalid option selected.\n");
        break;
    }
    printf("\n");
  }
  return 0;
}