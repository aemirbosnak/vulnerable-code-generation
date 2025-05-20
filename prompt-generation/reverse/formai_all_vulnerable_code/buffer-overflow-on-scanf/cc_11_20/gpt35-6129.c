//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
  int id;
  char name[50];
  float salary;
} Record;

int main() {
  Record db[MAX_RECORDS];
  int num_records = 0;
  char choice;

  printf("Welcome to the database simulation program!\n");

  do {
    printf("\nMenu:\n");
    printf("1. Add a record\n");
    printf("2. Find a record by ID\n");
    printf("3. List all records\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch(choice) {
      case '1': // Add a record
        if(num_records >= MAX_RECORDS) {
          printf("ERROR: Database is full\n");
        } else {
          Record new_rec;
          printf("Enter the ID: ");
          scanf("%d", &new_rec.id);
          printf("Enter the name: ");
          scanf("%s", new_rec.name);
          printf("Enter the salary: ");
          scanf("%f", &new_rec.salary);
          db[num_records++] = new_rec;
          printf("Record added successfully!\n");
        }
        break;

      case '2': // Find a record by ID
        if(num_records == 0) {
          printf("ERROR: Database is empty\n");
        } else {
          int search_id;
          printf("Enter the ID to search: ");
          scanf("%d", &search_id);
          int found = 0;
          for(int i=0; i<num_records; i++) {
            if(db[i].id == search_id) {
              printf("Record Found!\n");
              printf("ID: %d, Name: %s, Salary: %0.2f\n", db[i].id, db[i].name, db[i].salary);
              found = 1;
              break;
            }
          }
          if(!found) {
            printf("Record not found!\n");
          }
        }
        break;

      case '3': // List all records
        if(num_records == 0) {
          printf("ERROR: Database is empty\n");
        } else {
          printf("ID\tName\tSalary\n");
          for(int i=0; i<num_records; i++) {
            printf("%d\t%s\t%0.2f\n", db[i].id, db[i].name, db[i].salary);
          }
        }
        break;

      case '4': // Exit
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid choice!\n");
        break;
    }

  } while(choice != '4');

  return 0;
}