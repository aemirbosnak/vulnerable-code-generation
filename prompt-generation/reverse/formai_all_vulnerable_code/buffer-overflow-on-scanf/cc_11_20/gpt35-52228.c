//FormAI DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the Happy Database!\n\n");

  // Initialize database with some initial values
  int database[10] = {1, 3, 7, 8};

  while (1) {
    printf("What would you like to do?\n");
    printf("[1] Add a value to the database\n");
    printf("[2] Remove a value from the database\n");
    printf("[3] Print the current contents of the database\n");
    printf("[4] Quit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("What value would you like to add to the database?\n");
        int add_value;
        scanf("%d", &add_value);

        // Add the value to the database if there's room
        int added = 0;
        for (int i = 0; i < 10; i++) {
          if (database[i] == 0) {
            database[i] = add_value;
            added = 1;
            break;
          }
        }
        if (added) {
          printf("Value %d added to the database!\n", add_value);
        } else {
          printf("Sorry, the database is full and cannot add any more values.\n");
        }
        break;

      case 2:
        printf("What value would you like to remove from the database?\n");
        int remove_value;
        scanf("%d", &remove_value);

        // Remove the value from the database if it exists
        int removed = 0;
        for (int i = 0; i < 10; i++) {
          if (database[i] == remove_value) {
            database[i] = 0;
            removed = 1;
            break;
          }
        }
        if (removed) {
          printf("Value %d removed from the database!\n", remove_value);
        } else {
          printf("Sorry, the value %d does not exist in the database and cannot be removed.\n", remove_value);
        }
        break;

      case 3:
        printf("Current contents of the database:\n");
        for (int i = 0; i < 10; i++) {
          if (database[i] != 0) {
            printf("%d ", database[i]);
          }
        }
        printf("\n");
        break;

      case 4:
        printf("Thank you for using the Happy Database! Have a nice day!\n");
        return 0;

      default:
        printf("Invalid choice. Please choose a number between 1 and 4.\n");
        break;
    }

    printf("\n");
  }
}