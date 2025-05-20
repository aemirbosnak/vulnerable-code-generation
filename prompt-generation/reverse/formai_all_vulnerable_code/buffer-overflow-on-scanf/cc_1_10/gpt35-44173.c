//FormAI DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define the structure of a record
struct record {
  int id;
  char name[20];
  char email[40];
};

// Define the structure of an index
struct index {
  int id;
  int pos;
};

// Define an array to hold records and an index
struct record records[MAX_RECORDS];
struct index indexes[MAX_RECORDS];

// Define functionality to add a new record
int add_record(int *num_records) {
  int id, pos;

  // Get the next available ID
  if (*num_records == 0) {
    id = 1;
  } else {
    id = records[*num_records - 1].id + 1;
  }

  // Get the position to insert the record at
  pos = *num_records;

  // Prompt the user for the record details
  printf("Enter name: ");
  scanf("%s", records[pos].name);
  printf("Enter email: ");
  scanf("%s", records[pos].email);

  // Add the record to the database
  records[pos].id = id;
  indexes[pos].id = id;
  indexes[pos].pos = pos;
  (*num_records)++;

  // Return the position of the inserted record
  return pos;
}

// Define functionality to print all records
void print_records(int num_records) {
  int i;

  // Print the header row
  printf("%-5s%-20s%-40s\n", "ID", "Name", "Email");
  printf("------------------------------------------------------------\n");

  // Print each record
  for (i = 0; i < num_records; i++) {
    printf("%-5d%-20s%-40s\n", records[i].id, records[i].name, records[i].email);
  }
}

// Define functionality to search for a record by ID
int search_record(int num_records, int id) {
  int i;

  // Loop through each record until the ID is found
  for (i = 0; i < num_records; i++) {
    if (records[i].id == id) {
      return i;
    }
  }

  // If the ID is not found, return -1
  return -1;
}

// Define functionality to update a record
void update_record(int pos) {
  // Prompt the user for the new record details
  printf("Enter new name: ");
  scanf("%s", records[pos].name);
  printf("Enter new email: ");
  scanf("%s", records[pos].email);
}

// Define functionality to delete a record
void delete_record(int pos, int *num_records) {
  int i;

  // Shift all records after the deleted record to the left
  for (i = pos + 1; i < *num_records; i++) {
    records[i - 1] = records[i];
    indexes[i - 1] = indexes[i];
  }

  // Decrement the number of records in the database
  (*num_records)--;
}

// Define functionality to compare two index values by ID
int compare_by_id(const void *a, const void *b) {
  const struct index *ia = (const struct index *)a;
  const struct index *ib = (const struct index *)b;
  return (ia->id - ib->id);
}

// Define functionality to compare two index values by position
int compare_by_pos(const void *a, const void *b) {
  const struct index *ia = (const struct index *)a;
  const struct index *ib = (const struct index *)b;
  return (ia->pos - ib->pos);
}

// Define functionality to sort the index by ID
void sort_index_by_id(int num_records) {
  qsort(indexes, num_records, sizeof(struct index), compare_by_id);
}

// Define functionality to sort the index by position
void sort_index_by_pos(int num_records) {
  qsort(indexes, num_records, sizeof(struct index), compare_by_pos);
}

// Define function to retrieve the record with the given ID
struct record get_record_by_id(int num_records, int id) {
  int pos;
  struct record rec;

  // Use the index to find the position of the record
  pos = search_record(num_records, id);

  // Retrieve the record from the database
  rec = records[pos];

  return rec;
}

// Define the main function
int main() {
  int choice, num_records = 0, id, pos;

  // Print the menu
  printf("Database Indexing System\n");
  printf("------------------------------------------------------------\n");
  printf("1. Add record\n");
  printf("2. Print records\n");
  printf("3. Search record\n");
  printf("4. Update record\n");
  printf("5. Delete record\n");
  printf("6. Exit\n");
  printf("------------------------------------------------------------\n");

  // Loop until the user chooses to exit
  while (1) {
    // Prompt the user for their choice
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // Add a new record to the database
        if (num_records == MAX_RECORDS) {
          printf("Error: Database full\n");
        } else {
          pos = add_record(&num_records);
          printf("Record added at position %d\n", pos);
        }
        break;
      case 2:
        // Print all records in the database
        print_records(num_records);
        break;
      case 3:
        // Search for a record by ID
        printf("Enter ID to search for: ");
        scanf("%d", &id);
        pos = search_record(num_records, id);
        if (pos == -1) {
          printf("Record not found\n");
        } else {
          printf("Record found at position %d\n", pos);
          struct record rec = get_record_by_id(num_records, id);
          printf("%-5s%-20s%-40s\n", "ID", "Name", "Email");
          printf("------------------------------------------------------------\n");
          printf("%-5d%-20s%-40s\n", rec.id, rec.name, rec.email);
        }
        break;
      case 4:
        // Update a record by ID
        printf("Enter ID to update: ");
        scanf("%d", &id);
        pos = search_record(num_records, id);
        if (pos == -1) {
          printf("Record not found\n");
        } else {
          update_record(pos);
          printf("Record updated\n");
        }
        break;
      case 5:
        // Delete a record by ID
        printf("Enter ID to delete: ");
        scanf("%d", &id);
        pos = search_record(num_records, id);
        if (pos == -1) {
          printf("Record not found\n");
        } else {
          delete_record(pos, &num_records);
          printf("Record deleted\n");
        }
        break;
      case 6:
        // Exit the program
        return 0;
        break;
      default:
        printf("Error: Invalid choice\n");
        break;
    }
  }

  return 0;
}