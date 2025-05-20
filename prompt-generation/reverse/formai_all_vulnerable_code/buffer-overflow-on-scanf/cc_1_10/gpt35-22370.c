//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
  int id;
  char name[50];
  char address[100];
} Record;

int main() {
  Record database[MAX_RECORDS];
  int num_records = 0;
  char command[50];

  while (1) {
    printf("Enter command (add, search, exit): ");
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      // Add a new record
      if (num_records == MAX_RECORDS) {
        printf("ERROR: Database is full\n");
        continue;
      }

      Record new_record;

      printf("Enter ID: ");
      scanf("%d", &new_record.id);

      printf("Enter name: ");
      scanf("%s", new_record.name);

      printf("Enter address: ");
      scanf("%s", new_record.address);

      database[num_records] = new_record;
      num_records++;

      printf("Record added successfully!\n");
    } else if (strcmp(command, "search") == 0) {
      // Search for a record
      int id;

      printf("Enter ID: ");
      scanf("%d", &id);

      int found = 0;

      for (int i = 0; i < num_records; i++) {
        if (database[i].id == id) {
          printf("ID: %d\n", database[i].id);
          printf("Name: %s\n", database[i].name);
          printf("Address: %s\n", database[i].address);
          found = 1;
          break;
        }
      }

      if (!found) {
        printf("Record not found\n");
      }
    } else if (strcmp(command, "exit") == 0) {
      // Quit the program
      break;
    } else {
      printf("Invalid command\n");
    }
  }

  return 0;
}