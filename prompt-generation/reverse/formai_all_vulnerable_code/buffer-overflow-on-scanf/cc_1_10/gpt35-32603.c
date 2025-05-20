//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct index_t {
  int id;
  int value;
} Index;

void insert(Index index_array[], int len, int id, int value) {
  Index new_index;
  new_index.id = id;
  new_index.value = value;

  if (len == 0) {
    index_array[0] = new_index;
    return;
  }

  int i;
  for (i = 0; i < len; i++) {
    if (index_array[i].value > value) {
      int j;
      for (j = len; j > i; j--) {
        index_array[j] = index_array[j-1];
      }
      index_array[i] = new_index;
      return;
    }
  }

  index_array[i] = new_index;
}

int search(Index index_array[], int len, int id) {
  int low = 0;
  int high = len - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;
    if (id < index_array[mid].id) {
      high = mid - 1;
    }
    else if (id > index_array[mid].id) {
      low = mid + 1;
    }
    else {
      return mid;
    }
  }

  return -1;
}

int main() {
  Index index_array[100];
  int len = 0;

  printf("Welcome to the unique C Database Indexing System!\n");

  while (1) {
    printf("\nWhat would you like to do?\n");
    printf("1. Insert a new index.\n");
    printf("2. Search for an index.\n");
    printf("3. Exit the program.\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      printf("\nEnter the ID for the new index: ");
      int id;
      scanf("%d", &id);

      printf("Enter the value for the new index: ");
      int value;
      scanf("%d", &value);

      insert(index_array, len, id, value);
      len++;

      printf("\nThe new index has been added to the system.\n");
    }
    else if (choice == 2) {
      printf("\nEnter the ID to search for: ");
      int id;
      scanf("%d", &id);

      int result = search(index_array, len, id);

      if (result == -1) {
        printf("\nSorry, the index was not found.\n");
      }
      else {
        printf("\nThe index was found at position %d.\n", result);
      }
    }
    else if (choice == 3) {
      printf("\nThank you for using the unique C Database Indexing System!\n");
      exit(0);
    }
    else {
      printf("\nSorry, that is an invalid choice. Please try again.\n");
    }
  }

  return 0;
}