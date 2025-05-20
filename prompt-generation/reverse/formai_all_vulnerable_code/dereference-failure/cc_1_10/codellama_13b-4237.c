//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAILING_LIST 100
#define MAX_EMAIL_LENGTH 100

struct mailing_list {
  char email[MAX_EMAIL_LENGTH];
  struct mailing_list* next;
};

struct mailing_list* head;

void add_to_mailing_list(char* email) {
  struct mailing_list* new_node = malloc(sizeof(struct mailing_list));
  strcpy(new_node->email, email);
  new_node->next = head;
  head = new_node;
}

void print_mailing_list() {
  struct mailing_list* current = head;
  while (current != NULL) {
    printf("%s\n", current->email);
    current = current->next;
  }
}

void remove_from_mailing_list(char* email) {
  struct mailing_list* current = head;
  struct mailing_list* previous = NULL;
  while (current != NULL) {
    if (strcmp(current->email, email) == 0) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      break;
    }
    previous = current;
    current = current->next;
  }
}

int main() {
  add_to_mailing_list("john@example.com");
  add_to_mailing_list("jane@example.com");
  add_to_mailing_list("bob@example.com");
  print_mailing_list();
  remove_from_mailing_list("john@example.com");
  print_mailing_list();
  return 0;
}