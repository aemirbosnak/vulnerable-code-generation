//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Struct for the database simulation
typedef struct database {
  int id;
  char name[MAX_SIZE];
  int age;
  char gender[MAX_SIZE];
} database;

// Function prototypes
void insert(database [], int *);
void display(database [], int);
void search(database [], int);
void update(database [], int);
void delete(database [], int *);

// Main function
int main() {
  int choice, count = 0;
  database db[MAX_SIZE];
  
  do {
    puts("\nDATABASE SIMULATION\n");
    puts("1. Insert a new record");
    puts("2. Display all records");
    puts("3. Search a record");
    puts("4. Update a record");
    puts("5. Delete a record");
    puts("6. Exit");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        insert(db, &count);
        break;
      case 2:
        display(db, count);
        break;
      case 3:
        search(db, count);
        break;
      case 4:
        update(db, count);
        break;
      case 5:
        delete(db, &count);
        break;
      case 6:
        puts("Exiting program...");
        break;
      default:
        puts("Invalid choice. Please try again.");
    }
  } while (choice != 6);
  
  return 0;
}

// Function to insert a record
void insert(database db[], int *count) {
  printf("Enter ID: ");
  scanf("%d", &db[*count].id);
  printf("Enter Name: ");
  scanf("%s", db[*count].name);
  printf("Enter Age: ");
  scanf("%d", &db[*count].age);
  printf("Enter Gender: ");
  scanf("%s", db[*count].gender);
  (*count)++;
  puts("\nRecord added successfully.");
}

// Function to display all records
void display(database db[], int count) {
  if (count == 0) {
    puts("\nNo records to display.");
  } else {
    printf("\n%-10s %-20s %-10s %-10s\n", "ID", "Name", "Age", "Gender");
    for (int i = 0; i < count; i++) {
      printf("%-10d %-20s %-10d %-10s\n", db[i].id, db[i].name, db[i].age, db[i].gender);
    }
  }
}

// Function to search for a record
void search(database db[], int count) {
  if (count == 0) {
    puts("\nNo records to search.");
  } else {
    int id, flag = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
      if (db[i].id == id) {
        flag = 1;
        printf("\nRecord found:");
        printf("\nID     : %d", db[i].id);
        printf("\nName   : %s", db[i].name);
        printf("\nAge    : %d", db[i].age);
        printf("\nGender : %s\n", db[i].gender);
      }
    }
    if (flag == 0) {
      printf("\nRecord with ID %d not found.\n", id);
    }
  }
}

// Function to update a record
void update(database db[], int count) {
  if (count == 0) {
    puts("\nNo records to update.");
  } else {
    int id, flag = 0, choice;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
      if (db[i].id == id) {
        flag = 1;
        printf("\nRecord found:");
        printf("\nID     : %d", db[i].id);
        printf("\nName   : %s", db[i].name);
        printf("\nAge    : %d", db[i].age);
        printf("\nGender : %s\n", db[i].gender);
        printf("\nEnter field to update (1-4): ");
        scanf("%d", &choice);
        switch(choice) {
          case 1:
            printf("\nEnter new ID: ");
            scanf("%d", &db[i].id);
            break;
          case 2:
            printf("\nEnter new name: ");
            scanf("%s", db[i].name);
            break;
          case 3:
            printf("\nEnter new age: ");
            scanf("%d", &db[i].age);
            break;
          case 4:
            printf("\nEnter new gender: ");
            scanf("%s", db[i].gender);
            break;
          default:
            puts("\nInvalid choice.");
        }
        printf("\nRecord updated successfully.");
      }
    }
    if (flag == 0) {
      printf("\nRecord with ID %d not found.\n", id);
    }
  }
}

// Function to delete a record
void delete(database db[], int *count) {
  if (*count == 0) {
    puts("\nNo records to delete.");
  } else {
    int id, flag = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
      if (db[i].id == id) {
        flag = 1;
        for (int j = i; j < *count - 1; j++) {
          db[j] = db[j + 1];
        }
        (*count)--;
        printf("\nRecord with ID %d deleted successfully.", id);
        break;
      }
    }
    if (flag == 0) {
      printf("\nRecord with ID %d not found.\n", id);
    }
  }
}