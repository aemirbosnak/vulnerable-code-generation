//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Here's our lively mailing list manager!

typedef struct {
  char name[50];
  char email[50];
} subscriber;

subscriber subscribers[100];
int num_subscribers = 0;

void add_subscriber(char* name, char* email) {
  if (num_subscribers < 100) {
    strcpy(subscribers[num_subscribers].name, name);
    strcpy(subscribers[num_subscribers].email, email);
    num_subscribers++;
    printf("Yay! %s has joined the list!\n", name);
  } else {
    printf("Oops! Our list is full. Try again later!\n");
  }
}

void remove_subscriber(char* name) {
  int i;
  for (i = 0; i < num_subscribers; i++) {
    if (strcmp(name, subscribers[i].name) == 0) {
      subscribers[i] = subscribers[num_subscribers - 1];
      num_subscribers--;
      printf("Buh-bye, %s. We'll miss you!\n", name);
      return;
    }
  }
  printf("Hmm... %s isn't on the list. Check the spelling, maybe?\n", name);
}

void print_list() {
  int i;
  printf("Here's our amazing mailing list:\n");
  for (i = 0; i < num_subscribers; i++) {
    printf("%s <%s>\n", subscribers[i].name, subscribers[i].email);
  }
}

int main() {
  int choice;
  char name[50];
  char email[50];

  printf("Welcome to the Mailing List Extravaganza!\n");
  printf("1. Add a subscriber\n");
  printf("2. Remove a subscriber\n");
  printf("3. Print the list\n");
  printf("4. Exit\n");

  while (1) {
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Name: ");
        scanf(" %[^\n]%*c", name);  // Read a line with spaces
        printf("Email: ");
        scanf(" %[^\n]%*c", email);
        add_subscriber(name, email);
        break;
      case 2:
        printf("Name: ");
        scanf(" %[^\n]%*c", name);
        remove_subscriber(name);
        break;
      case 3:
        print_list();
        break;
      case 4:
        printf("Hasta la vista, baby!\n");
        return 0;
      default:
        printf("Oops! Invalid choice. Try again.\n");
        break;
    }
  }

  return 0;
}