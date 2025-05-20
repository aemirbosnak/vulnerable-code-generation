//FormAI DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
  int id; //Unique identifier
  char name[30]; //Name of person
  int age; //Age of person
  float salary; //Salary of person
} Person;

typedef struct {
  int offset; //The offset to where the record is stored
  int key; //The indexed value
} IndexRecord;

typedef struct {
  int num_records; //Number of records in the database
  Person records[MAX_RECORDS]; //Array of records
  IndexRecord indexes[MAX_RECORDS]; //Array of index records
} Database;

void addRecord(Database *db, Person person) {
  //Add new record to the database
  int index = db->num_records;

  db->records[index] = person;

  //Sort the index array
  int i;
  for (i = 0; i < db->num_records; i++) {
    if (person.id < db->indexes[i].key || i == index) {
      int j;
      for (j = db->num_records - 1; j >= i; j--) {
        db->indexes[j+1] = db->indexes[j];
      }
      db->indexes[i].key = person.id;
      db->indexes[i].offset = index;
      break;
    }
  }
  if (i == db->num_records) { //If record is larger than any other, add to end
    db->indexes[i].key = person.id;
    db->indexes[i].offset = index;
  }

  db->num_records++;
}

void displayRecords(Database *db) {
  //Display all records in the database
  printf("\nID\tName\tAge\tSalary\n");
  int i;
  for (i = 0; i < db->num_records; i++) {
    Person person = db->records[db->indexes[i].offset];
    printf("%d\t%s\t%d\t%.2f\n", person.id, person.name, person.age, person.salary);
  }
}

int searchRecord(Database *db, int id) {
  //Search the database for a record with a given ID
  int i;
  for (i = 0; i < db->num_records; i++) {
    if (id == db->indexes[i].key) {
      return db->indexes[i].offset;
    }
  }
  return -1;
}

void displayRecord(Database *db, int index) {
  //Display a single record given the index of that record
  if (index < 0 || index >= db->num_records) {
    printf("Record not found.\n");
    return;
  }
  Person person = db->records[index];
  printf("\nID\tName\tAge\tSalary\n");
  printf("%d\t%s\t%d\t%.2f\n", person.id, person.name, person.age, person.salary);
}

int main() {
  Database db;
  db.num_records = 0;

  while (1) {
    printf("\n1 - Add record\n");
    printf("2 - Display all records\n");
    printf("3 - Search record\n");
    printf("4 - Exit\n");
    printf("Enter option: ");

    int opt;
    scanf("%d", &opt);

    switch (opt) {
      case 1:
        {
          Person person;
          printf("Enter ID: ");
          scanf("%d", &person.id);
          printf("Enter name: ");
          scanf("%s", person.name);
          printf("Enter age: ");
          scanf("%d", &person.age);
          printf("Enter salary: ");
          scanf("%f", &person.salary);

          addRecord(&db, person);
          break;
        }
      case 2:
        {
          displayRecords(&db);
          break;
        }
      case 3:
        {
          int id;
          printf("Enter ID to search: ");
          scanf("%d", &id);
          int index = searchRecord(&db, id);
          displayRecord(&db, index);
          break;
        }
      case 4:
        {
          exit(0);
        }
      default:
        {
          printf("Invalid option. Try again.\n");
          continue;
        }
    }
  }

  return 0;
}