//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_RECORDS 100

struct Record {
  int id;
  char name[MAX_LENGTH];
  int age;
};

int main() {
  struct Record database[MAX_RECORDS];
  int num_records = 0;
  int i, j;

  while (1) {
    // Print menu and get user choice
    printf("\n1. Add record\n");
    printf("2. Remove record\n");
    printf("3. Show all records\n");
    printf("4. Exit\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Perform user's chosen action
    switch (choice) {
      case 1:
        // Add new record
        if (num_records >= MAX_RECORDS) {
          printf("Database is full\n");
        } else {
          printf("Enter record ID: ");
          scanf("%d", &database[num_records].id);
          printf("Enter record name: ");
          scanf("%s", database[num_records].name);
          printf("Enter record age: ");
          scanf("%d", &database[num_records].age);
          num_records++;
        }
        break;

      case 2:
        // Remove record
        printf("Enter ID of record to remove: ");
        int remove_id;
        scanf("%d", &remove_id);
        for (i = 0; i < num_records; i++) {
          if (database[i].id == remove_id) {
            // Shift all records after this one down by one
            for (j = i; j < num_records - 1; j++) {
              database[j] = database[j+1];
            }
            num_records--;
            break;
          }
        }
        break;

      case 3:
        // Show all records
        printf("\nID\tName\tAge\n");
        for (i = 0; i < num_records; i++) {
          printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
        }
        break;

      case 4:
        // Exit program
        return 0;

      default:
        printf("Invalid choice\n");
        break;
    }
  }
}