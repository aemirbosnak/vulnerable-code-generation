//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
/* Alan Turing's Mailing List Manager */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A node in the mailing list */
typedef struct node {
  char *email;
  struct node *next;
} node_t;

/* The mailing list */
static node_t *head = NULL;

/* Add an email address to the mailing list */
void add_email(char *email) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->email = strdup(email);
  new_node->next = head;
  head = new_node;
}

/* Remove an email address from the mailing list */
void remove_email(char *email) {
  node_t *current = head;
  node_t *previous = NULL;

  while (current != NULL) {
    if (strcmp(current->email, email) == 0) {
      if (previous == NULL) {
        head = current->next;
      } else {
        previous->next = current->next;
      }
      free(current->email);
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

/* Send a message to all email addresses on the mailing list */
void send_message(char *message) {
  node_t *current = head;

  while (current != NULL) {
    printf("Sending message to %s\n", current->email);
    current = current->next;
  }
}

/* Print the mailing list */
void print_mailing_list() {
  node_t *current = head;

  while (current != NULL) {
    printf("%s\n", current->email);
    current = current->next;
  }
}

/* Main function */
int main() {
  char input[100];

  while (1) {
    printf("Enter a command (add, remove, send, print, quit): ");
    scanf("%s", input);

    if (strcmp(input, "add") == 0) {
      char email[100];
      printf("Enter the email address to add: ");
      scanf("%s", email);
      add_email(email);
    } else if (strcmp(input, "remove") == 0) {
      char email[100];
      printf("Enter the email address to remove: ");
      scanf("%s", email);
      remove_email(email);
    } else if (strcmp(input, "send") == 0) {
      char message[100];
      printf("Enter the message to send: ");
      scanf("%s", message);
      send_message(message);
    } else if (strcmp(input, "print") == 0) {
      print_mailing_list();
    } else if (strcmp(input, "quit") == 0) {
      break;
    } else {
      printf("Invalid command. Please try again.\n");
    }
  }

  return 0;
}