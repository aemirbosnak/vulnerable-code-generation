//FormAI DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 100

struct Person {
  char name[MAX_NAME];
  char email[MAX_EMAIL];
  long phone;
  struct Person *next;
};

void add_person(struct Person **head) {
  struct Person *person = malloc(sizeof(struct Person));

  printf("Enter name: ");
  fgets(person->name, MAX_NAME, stdin);
  person->name[strlen(person->name) - 1] = '\0';

  printf("Enter email: ");
  fgets(person->email, MAX_EMAIL, stdin);
  person->email[strlen(person->email) - 1] = '\0';

  printf("Enter phone number: ");
  scanf("%ld", &person->phone);
  getchar();

  // Inserting the new person into the beginning of the list
  person->next = *head;
  *head = person;
}

void search_person(struct Person *head, char *name) {
  struct Person *person = head;

  while (person != NULL) {
    if (strcmp(person->name, name) == 0) {
      printf("Name: %s\nEmail: %s\nPhone number: %ld\n", person->name, person->email, person->phone);
      return;
    }

    person = person->next;
  }

  printf("Person not found.\n");
}

int main() {
  struct Person *head = NULL;
  int choice;
  char name[MAX_NAME];

  while (1) {
    printf("1. Add person\n2. Search person\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice) {
      case 1:
        add_person(&head);
        break;
      case 2:
        printf("Enter name to search: ");
        fgets(name, MAX_NAME, stdin);
        name[strlen(name) - 1] = '\0';
        search_person(head, name);
        break;
      case 3:
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}