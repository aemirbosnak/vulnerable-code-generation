//FormAI DATASET v1.0 Category: Database simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 100

typedef struct {
  char name[30];
  int age;
  char gender;
} Person;

void print_record(Person p) {
  printf("Name: %s, Age: %d, Gender: %c\n", p.name, p.age, p.gender);
}

void print_records(Person records[], int count) {
  printf("Printing all records...\n");
  for (int i = 0; i < count; i++) {
    print_record(records[i]);
  }
}

void add_record(Person records[], int *count) {
  if (*count >= MAX_RECORDS) {
    printf("Max number of records reached\n");
    return;
  }

  Person new_person;
  char temp_gender;

  printf("Enter name: ");
  scanf("%s", new_person.name);
  printf("Enter age: ");
  scanf("%d", &new_person.age);
  printf("Enter gender (M/F): ");
  scanf(" %c", &temp_gender);

  new_person.gender = tolower(temp_gender);

  records[*count] = new_person;
  (*count)++;

  printf("Record added successfully\n");
}

void search_records(Person records[], int count) {
  char search_name[30];
  printf("Enter name to search: ");
  scanf("%s", search_name);

  int matching_records = 0;
  for (int i = 0; i < count; i++) {
    if (strcmp(records[i].name, search_name) == 0) {
      print_record(records[i]);
      matching_records++;
    }
  }

  if (matching_records == 0) {
    printf("No records found for %s\n", search_name);
  } else {
    printf("Found %d record(s) for %s\n", matching_records, search_name);
  }
}

int main() {
  Person records[MAX_RECORDS];
  int count = 0;
  int choice;

  printf("***Person Records Database Simulation***\n");

  do {
    printf("\n1. Print all records\n");
    printf("2. Add a new record\n");
    printf("3. Search for a record\n");
    printf("4. Quit\n");

    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        print_records(records, count);
        break;
      case 2:
        add_record(records, &count);
        break;
      case 3:
        search_records(records, count);
        break;
      case 4:
        printf("Exiting program\n");
        break;
      default:
        printf("Invalid choice\n");
    }
  } while (choice != 4);

  return 0;
}