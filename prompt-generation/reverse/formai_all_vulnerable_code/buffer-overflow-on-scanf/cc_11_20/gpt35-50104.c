//FormAI DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 1000

typedef struct {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
} Person;

int main() {
  Person mailingList[MAX_LIST_SIZE];
  int listSize = 0;

  printf("Welcome to the Mailing List Manager!\n");

  while (1) {
    printf("Enter 'add' to add a person to the mailing list, 'delete' to remove someone, or 'quit' to exit: ");
    char input[10];
    scanf("%s", input);

    if (strcmp(input, "add") == 0) {
      if (listSize == MAX_LIST_SIZE) {
        printf("Sorry, the mailing list is full.\n");
        continue;
      }

      printf("Enter person's name: ");
      char name[MAX_NAME_LENGTH];
      scanf("%s", name);

      printf("Enter person's email: ");
      char email[MAX_EMAIL_LENGTH];
      scanf("%s", email);

      Person newPerson;
      strcpy(newPerson.name, name);
      strcpy(newPerson.email, email);

      mailingList[listSize++] = newPerson;

      printf("%s was added to the mailing list.\n", newPerson.name);
    }
    else if (strcmp(input, "delete") == 0) {
      if (listSize == 0) {
        printf("Sorry, the mailing list is empty.\n");
        continue;
      }

      printf("Enter person's name to delete: ");
      char name[MAX_NAME_LENGTH];
      scanf("%s", name);

      int indexToDelete = -1;

      for (int i = 0; i < listSize; i++) {
        if (strcmp(mailingList[i].name, name) == 0) {
          indexToDelete = i;
          break;
        }
      }

      if (indexToDelete == -1) {
        printf("%s is not on the mailing list.\n", name);
      }
      else {
        for (int i = indexToDelete; i < listSize - 1; i++) {
          mailingList[i] = mailingList[i + 1];
        }

        listSize--;
        printf("%s was removed from the mailing list.\n", name);
      }
    }
    else if (strcmp(input, "quit") == 0) {
      printf("Goodbye!\n");
      break;
    }
    else {
      printf("Sorry, that is not a valid input.\n");
    }
  }

  return 0;
}