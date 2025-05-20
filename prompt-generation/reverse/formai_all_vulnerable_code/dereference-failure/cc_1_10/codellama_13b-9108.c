//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char *email;
} Subscriber;

typedef struct {
  Subscriber *subscribers;
  int num_subscribers;
} MailingList;

void print_subscribers(MailingList *list) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
  }
}

void add_subscriber(MailingList *list, char *name, char *email) {
  list->subscribers = realloc(list->subscribers, (list->num_subscribers + 1) * sizeof(Subscriber));
  list->subscribers[list->num_subscribers].name = strdup(name);
  list->subscribers[list->num_subscribers].email = strdup(email);
  list->num_subscribers++;
}

void remove_subscriber(MailingList *list, char *name) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      free(list->subscribers[i].name);
      free(list->subscribers[i].email);
      memmove(&list->subscribers[i], &list->subscribers[i + 1], (list->num_subscribers - i - 1) * sizeof(Subscriber));
      list->num_subscribers--;
      break;
    }
  }
}

int main() {
  MailingList list;
  list.subscribers = NULL;
  list.num_subscribers = 0;

  add_subscriber(&list, "John Doe", "johndoe@example.com");
  add_subscriber(&list, "Jane Doe", "janedoe@example.com");
  add_subscriber(&list, "John Smith", "johnsmith@example.com");
  print_subscribers(&list);

  remove_subscriber(&list, "Jane Doe");
  print_subscribers(&list);

  return 0;
}