//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct Record {
  char name[50];
  int age;
  double salary;
} Record;

Record records[MAX_RECORDS];

void insertRecord() {
  Record newRecord;

  printf("Enter name: ");
  scanf("%s", newRecord.name);

  printf("Enter age: ");
  scanf("%d", &newRecord.age);

  printf("Enter salary: ");
  scanf("%lf", &newRecord.salary);

  records[0] = newRecord;
}

void printRecords() {
  for (int i = 0; i < MAX_RECORDS; i++) {
    if (records[i].name[0] != '\0') {
      printf("Name: %s, Age: %d, Salary: %.2lf\n", records[i].name, records[i].age, records[i].salary);
    }
  }
}

int main() {
  int choice;

  printf("Enter 1 to insert a new record, 2 to print records: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      insertRecord();
      break;
    case 2:
      printRecords();
      break;
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}