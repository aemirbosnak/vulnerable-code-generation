//FormAI DATASET v1.0 Category: Database querying ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a struct to store database records
struct Record {
  int id;
  char name[50];
  char address[100];
  float salary;
};

// Function to insert a record into the database
void insert_record(struct Record* records, int* num_records) {
  printf("Enter employee details:\n");
  struct Record new_record;
  printf("ID: ");
  scanf("%d", &new_record.id);
  printf("Name: ");
  scanf("%s", new_record.name);
  printf("Address: ");
  scanf("%s", new_record.address);
  printf("Salary: ");
  scanf("%f", &new_record.salary);

  records[*num_records] = new_record;
  (*num_records)++;
}

// Function to print all records in the database
void print_records(struct Record* records, int num_records) {
  printf("ID\tName\tAddress\tSalary\n");
  for (int i = 0; i < num_records; i++) {
    printf("%d\t%s\t%s\t$%.2f\n", records[i].id, records[i].name, records[i].address, records[i].salary);
  }
}

// Function to search for records in the database by name
void search_by_name(struct Record* records, int num_records) {
  char name[50];
  printf("Enter name to search for: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < num_records; i++) {
    if (strcmp(records[i].name, name) == 0) {
      printf("Record with name %s found:\n", name);
      printf("ID: %d\nName: %s\nAddress: %s\nSalary: $%.2f\n", records[i].id, records[i].name, records[i].address, records[i].salary);
      found = 1;
    }
  }

  if (!found) {
    printf("No records found for name %s\n", name);
  }
}

int main() {
  struct Record records[100];
  int num_records = 0;

  printf("Employee Database Querying Program\n");
  while (1) {
    printf("\nOptions:\n");
    printf("1. Insert Record\n");
    printf("2. Print All Records\n");
    printf("3. Search by Name\n");
    printf("4. Exit Program\n");
    int choice;
    printf("Enter Choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        insert_record(records, &num_records);
        break;
      case 2:
        print_records(records, num_records);
        break;
      case 3:
        search_by_name(records, num_records);
        break;
      case 4:
        printf("Exiting program...\n");
        exit(0);
      default:
        printf("Invalid choice, please try again\n");
    }
  }

  return 0;
}