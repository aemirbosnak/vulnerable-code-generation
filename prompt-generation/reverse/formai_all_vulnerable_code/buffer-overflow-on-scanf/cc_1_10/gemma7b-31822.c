//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

typedef struct MailListEntry {
  char name[MAX_NAME_LENGTH];
  struct MailListEntry* next;
} MailListEntry;

void addEntry(MailListEntry** head) {
  MailListEntry* newEntry = malloc(sizeof(MailListEntry));
  newEntry->next = NULL;

  printf("Enter the recipient's name: ");
  scanf("%s", newEntry->name);

  if (*head == NULL) {
    *head = newEntry;
  } else {
    (*head)->next = newEntry;
  }
}

void printEntries(MailListEntry* head) {
  while (head) {
    printf("Recipient: %s\n", head->name);
    head = head->next;
  }
}

int main() {
  MailListEntry* head = NULL;

  while (1) {
    int choice;

    printf("\nWhat do you want to do? (1) Add, (2) Print, (3) Exit\n");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addEntry(&head);
        break;
      case 2:
        printEntries(head);
        break;
      case 3:
        exit(0);
    }
  }

  return 0;
}