//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
  int id;
  char name[100];
  int age;
} Record;

int main() {
  Record database[MAX_RECORDS];
  int num_records = 0;

  printf("Welcome to the Database Simulation Program!\n\n");

  while (1) {
    printf("Enter 1 to add a record, 2 to view all records, or 3 to quit: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
      char name[100];
      int age;

      printf("\nEnter name: ");
      scanf("%s", name);

      printf("Enter age: ");
      scanf("%d", &age);

      Record new_record = {num_records + 1, name, age};
      database[num_records] = new_record;
      num_records++;

      printf("\nRecord added successfully.\n\n");
    }
    else if (choice == 2) {
      if (num_records == 0) {
        printf("\nThere are no records to display.\n\n");
        continue;
      }

      printf("\nID\tName\tAge\n\n");
      for (int i = 0; i < num_records; i++) {
        Record curr_record = database[i];
        printf("%d\t%s\t%d\n", curr_record.id, curr_record.name, curr_record.age);
      }
      printf("\n");
    }
    else if (choice == 3) {
      printf("\nThank you for using the Database Simulation Program!\n");
      break;
    }
    else {
      printf("\nInvalid choice. Please try again.\n\n");
    }
  }

  return 0;
}