//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: Ada Lovelace
// C Mailing List Manager
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a mailing list
struct MailingList {
  char name[100];
  char email[100];
  struct MailingList *next;
};

// Function to add a new email address to the list
void addMailingList(struct MailingList **head, char *name, char *email) {
  struct MailingList *new_node = malloc(sizeof(struct MailingList));
  strcpy(new_node->name, name);
  strcpy(new_node->email, email);
  new_node->next = *head;
  *head = new_node;
}

// Function to remove an email address from the list
void removeMailingList(struct MailingList **head, char *name, char *email) {
  struct MailingList *current = *head;
  struct MailingList *previous = NULL;

  while (current != NULL) {
    if (strcmp(current->name, name) == 0 && strcmp(current->email, email) == 0) {
      if (previous == NULL) {
        *head = current->next;
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

// Function to print the list of email addresses
void printMailingList(struct MailingList *head) {
  struct MailingList *current = head;

  while (current != NULL) {
    printf("%s <%s>\n", current->name, current->email);
    current = current->next;
  }
}

int main() {
  struct MailingList *head = NULL;

  addMailingList(&head, "John Doe", "johndoe@example.com");
  addMailingList(&head, "Jane Doe", "janedoe@example.com");
  addMailingList(&head, "John Smith", "johnsmith@example.com");

  removeMailingList(&head, "John Doe", "johndoe@example.com");

  printMailingList(head);

  return 0;
}