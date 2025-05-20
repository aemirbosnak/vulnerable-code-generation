//FormAI DATASET v1.0 Category: Database simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define the structure of a person */
struct Person {
  int id;
  char name[50];
  int age;
  char city[50];
};

int main() {
  int choice, numPersons, i;
  struct Person *persons;

  printf("Welcome to the Person Database Simulation Program!\n");

  /* get number of persons from user */
  printf("Please enter the number of persons to add to the database: ");
  scanf("%d", &numPersons);

  /* allocate memory for the persons array */
  persons = (struct Person*)malloc(numPersons * sizeof(struct Person));

  /* show menu and get user input */
  while(1) {
    printf("\n--- Menu ---\n");
    printf("1. Add a person\n");
    printf("2. View all persons\n");
    printf("3. Search for a person\n");
    printf("4. Exit program\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        /* add a person */
        printf("\n--- Add a person ---\n");
        for(i=0; i<numPersons; i++) {
          if(persons[i].id == 0) {
            printf("Please enter the following information:\n");
            printf("ID: ");
            scanf("%d", &persons[i].id);
            printf("Name: ");
            scanf("%s", persons[i].name);
            printf("Age: ");
            scanf("%d", &persons[i].age);
            printf("City: ");
            scanf("%s", persons[i].city);
            break;
          }
        }
        break;
      
      case 2:
        /* view all persons */
        printf("\n--- View all persons ---\n");
        for(i=0; i<numPersons; i++) {
          if(persons[i].id != 0) {
            printf("ID: %d\n", persons[i].id);
            printf("Name: %s\n", persons[i].name);
            printf("Age: %d\n", persons[i].age);
            printf("City: %s\n", persons[i].city);
            printf("\n");
          }
        }
        break;
      
      case 3:
        /* search for a person */
        printf("\n--- Search for a person ---\n");
        int idSearch;
        printf("Please enter the ID of the person you would like to search for: ");
        scanf("%d", &idSearch);
        for(i=0; i<numPersons; i++) {
          if(persons[i].id == idSearch) {
            printf("ID: %d\n", persons[i].id);
            printf("Name: %s\n", persons[i].name);
            printf("Age: %d\n", persons[i].age);
            printf("City: %s\n", persons[i].city);
            printf("\n");
            break;
          }
        }
        if(i == numPersons) {
          printf("Person with ID %d not found!\n", idSearch);
        }
        break;
      
      case 4:
        /* exit program */
        printf("\nThank you for using the Person Database Simulation Program! Goodbye!\n");
        free(persons);
        return 0;
      
      default:
        /* invalid choice */
        printf("\nInvalid choice! Please try again.\n");
        break;
    }
  }

  return 0;
}