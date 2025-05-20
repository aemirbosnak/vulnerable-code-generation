//FormAI DATASET v1.0 Category: Database simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// defining structs for the database simulation
typedef struct {
  int id;
  char name[50];
  int age;
  char occupation[50];
} Person;

typedef struct {
  int num_people;
  Person *people;
} Database;

// function to add a person to the database
void add_person(Database *db) {
  Person new_person;

  printf("Enter name: ");
  scanf("%s", new_person.name);

  printf("Enter age: ");
  scanf("%d", &new_person.age);

  printf("Enter occupation: ");
  scanf("%s", new_person.occupation);

  // assigning a unique ID to the person
  srand(time(NULL));
  new_person.id = rand() % 1000000;

  // reallocating memory for the new person in the database
  db->num_people++;
  db->people = (Person*) realloc(db->people, sizeof(Person) * db->num_people);
  db->people[db->num_people-1] = new_person;

  printf("\nNew person added to the database!\n\n");
}

// function to print all people in the database
void print_database(Database db) {
  printf("\n");
  printf("ID\tName\t\tAge\tOccupation\n");
  printf("----------------------------------------------\n");

  for(int i=0; i<db.num_people; i++) {
    printf("%d\t%s\t\t%d\t%s\n", db.people[i].id, db.people[i].name, db.people[i].age, db.people[i].occupation);
  }

  printf("\n");
}

int main() {
  Database db;
  db.num_people = 0;
  db.people = NULL;

  int choice;

  printf("\n-------------------------CYBERPUNK DATABASE SIMULATION-------------------------\n\n");

  do {
    printf("1. Add Person\n");
    printf("2. Print Database\n");
    printf("3. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_person(&db);
        break;
      case 2:
        print_database(db);
        break;
      case 3:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Please enter again.\n");
    }

  } while(choice != 3);

  // freeing memory allocated for database
  free(db.people);
  
  return 0;
}