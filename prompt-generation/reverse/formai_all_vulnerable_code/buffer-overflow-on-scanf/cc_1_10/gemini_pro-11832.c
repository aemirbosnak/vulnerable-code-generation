//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database structure
typedef struct {
  char name[20];
  int age;
  char location[20];
} survivor;

// Database array
survivor survivors[100];

// Menu options
enum {
  ADD_SURVIVOR,
  REMOVE_SURVIVOR,
  FIND_SURVIVOR,
  LIST_SURVIVORS,
  QUIT
};

// Function prototypes
void add_survivor(survivor *survivors);
void remove_survivor(survivor *survivors);
void find_survivor(survivor *survivors);
void list_survivors(survivor *survivors);

// Main function
int main() {
  // Initialize database
  memset(survivors, 0, sizeof(survivors));

  // Main loop
  while (1) {
    // Display menu
    printf("=== Post-Apocalyptic Survivor Database ===\n");
    printf("1. Add Survivor\n");
    printf("2. Remove Survivor\n");
    printf("3. Find Survivor\n");
    printf("4. List Survivors\n");
    printf("5. Quit\n");

    // Get user input
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform selected action
    switch (choice) {
    case ADD_SURVIVOR:
      add_survivor(survivors);
      break;
    case REMOVE_SURVIVOR:
      remove_survivor(survivors);
      break;
    case FIND_SURVIVOR:
      find_survivor(survivors);
      break;
    case LIST_SURVIVORS:
      list_survivors(survivors);
      break;
    case QUIT:
      printf("Goodbye!\n");
      return 0;
    default:
      printf("Invalid choice.\n");
      break;
    }
  }

  return 0;
}

// Function definitions

void add_survivor(survivor *survivors) {
  // Get survivor information
  char name[20];
  int age;
  char location[20];
  printf("Enter survivor name: ");
  scanf("%s", name);
  printf("Enter survivor age: ");
  scanf("%d", &age);
  printf("Enter survivor location: ");
  scanf("%s", location);

  // Find first empty slot
  int i;
  for (i = 0; i < 100; i++) {
    if (survivors[i].name[0] == '\0') {
      break;
    }
  }

  // Add survivor to database
  if (i < 100) {
    strcpy(survivors[i].name, name);
    survivors[i].age = age;
    strcpy(survivors[i].location, location);
    printf("Survivor added.\n");
  } else {
    printf("Database full.\n");
  }
}

void remove_survivor(survivor *survivors) {
  // Get survivor name
  char name[20];
  printf("Enter survivor name: ");
  scanf("%s", name);

  // Find survivor in database
  int i;
  for (i = 0; i < 100; i++) {
    if (strcmp(survivors[i].name, name) == 0) {
      break;
    }
  }

  // Remove survivor from database
  if (i < 100) {
    memset(&survivors[i], 0, sizeof(survivor));
    printf("Survivor removed.\n");
  } else {
    printf("Survivor not found.\n");
  }
}

void find_survivor(survivor *survivors) {
  // Get survivor name
  char name[20];
  printf("Enter survivor name: ");
  scanf("%s", name);

  // Find survivor in database
  int i;
  for (i = 0; i < 100; i++) {
    if (strcmp(survivors[i].name, name) == 0) {
      break;
    }
  }

  // Display survivor information
  if (i < 100) {
    printf("Survivor found:\n");
    printf("Name: %s\n", survivors[i].name);
    printf("Age: %d\n", survivors[i].age);
    printf("Location: %s\n", survivors[i].location);
  } else {
    printf("Survivor not found.\n");
  }
}

void list_survivors(survivor *survivors) {
  // Display all survivors in database
  int i;
  for (i = 0; i < 100; i++) {
    if (survivors[i].name[0] != '\0') {
      printf("Survivor %d:\n", i + 1);
      printf("Name: %s\n", survivors[i].name);
      printf("Age: %d\n", survivors[i].age);
      printf("Location: %s\n", survivors[i].location);
    }
  }
}