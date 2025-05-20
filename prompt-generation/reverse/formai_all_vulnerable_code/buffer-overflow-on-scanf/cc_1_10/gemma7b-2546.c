//Gemma-7B DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

typedef struct _User {
  char name[MAX_NAME_LENGTH];
  int age;
  struct _User* next;
} User;

int main() {
  User* head = NULL;
  User* tail = NULL;
  char command[256];

  // Loop until the user enters "exit"
  while (strcmp(command, "exit") != 0) {
    // Get the user's command
    printf("Enter a command: ");
    scanf("%s", command);

    // Create a new user if necessary
    if (strcmp(command, "add") == 0) {
      User* newUser = malloc(sizeof(User));
      printf("Enter your name: ");
      scanf("%s", newUser->name);
      printf("Enter your age: ");
      scanf("%d", &newUser->age);
      newUser->next = NULL;

      // If the list is empty, make the new user the head
      if (head == NULL) {
        head = newUser;
        tail = newUser;
      } else {
        tail->next = newUser;
        tail = newUser;
      }
    }

    // Print the list of users
    if (strcmp(command, "list") == 0) {
      for (User* current = head; current; current = current->next) {
        printf("%s (age: %d)\n", current->name, current->age);
      }
    }

    // Print the user's information
    if (strcmp(command, "info") == 0) {
      printf("Enter your name: ");
      scanf("%s", command);

      for (User* current = head; current; current = current->next) {
        if (strcmp(current->name, command) == 0) {
          printf("Name: %s\n", current->name);
          printf("Age: %d\n", current->age);
        }
      }
    }
  }

  return 0;
}