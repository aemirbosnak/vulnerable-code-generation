//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_EMAIL_SIZE 50

typedef struct {
  char name[MAX_EMAIL_SIZE];
  char email[MAX_EMAIL_SIZE];
} email_t;

void print_menu() {
  printf("====================================\n");
  printf("Welcome to the Mailing List Manager!\n");
  printf("====================================\n");
  printf("1. Add email to list\n");
  printf("2. Remove email from list\n");
  printf("3. Print list\n");
  printf("4. Quit\n");
  printf("====================================\n");
}

void add_email(email_t *list, int *list_size) {
  printf("Enter email name: ");
  scanf("%s", list[*list_size].name);
  printf("Enter email address: ");
  scanf("%s", list[*list_size].email);
  (*list_size)++;
}

void remove_email(email_t *list, int *list_size) {
  int index;
  printf("Enter index of email to remove: ");
  scanf("%d", &index);
  if (index < *list_size) {
    for (int i = index; i < *list_size - 1; i++) {
      list[i] = list[i + 1];
    }
    (*list_size)--;
  } else {
    printf("Invalid index.\n");
  }
}

void print_list(email_t *list, int list_size) {
  printf("====================================\n");
  for (int i = 0; i < list_size; i++) {
    printf("%d. %s <%s>\n", i + 1, list[i].name, list[i].email);
  }
  printf("====================================\n");
}

int main() {
  email_t list[MAX_LIST_SIZE];
  int list_size = 0;
  int option;

  while (1) {
    print_menu();
    scanf("%d", &option);

    switch (option) {
    case 1:
      add_email(list, &list_size);
      break;
    case 2:
      remove_email(list, &list_size);
      break;
    case 3:
      print_list(list, list_size);
      break;
    case 4:
      return 0;
    default:
      printf("Invalid option.\n");
      break;
    }
  }

  return 0;
}