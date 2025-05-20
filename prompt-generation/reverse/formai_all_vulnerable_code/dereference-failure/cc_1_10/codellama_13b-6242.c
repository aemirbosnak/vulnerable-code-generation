//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
// Mailing List Manager Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure to store email address and name
typedef struct {
  char name[50];
  char email[50];
} subscriber;

// Define structure to store list of subscribers
typedef struct {
  subscriber *subscribers;
  int num_subscribers;
} mailing_list;

// Function to add a subscriber to the list
void add_subscriber(mailing_list *list, subscriber subscriber) {
  list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(subscriber));
  list->subscribers[list->num_subscribers] = subscriber;
  list->num_subscribers++;
}

// Function to remove a subscriber from the list
void remove_subscriber(mailing_list *list, char *email) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].email, email) == 0) {
      memmove(list->subscribers + i, list->subscribers + i + 1, (list->num_subscribers - i - 1) * sizeof(subscriber));
      list->num_subscribers--;
      return;
    }
  }
}

// Function to send a message to all subscribers
void send_message(mailing_list *list, char *message) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    printf("Sending message to %s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
    // send message to subscriber
  }
}

// Example usage
int main() {
  mailing_list list = {NULL, 0};
  subscriber subscriber1 = {"John Doe", "johndoe@example.com"};
  subscriber subscriber2 = {"Jane Doe", "janedoe@example.com"};
  add_subscriber(&list, subscriber1);
  add_subscriber(&list, subscriber2);
  remove_subscriber(&list, "johndoe@example.com");
  send_message(&list, "Hello, subscribers!");
  return 0;
}