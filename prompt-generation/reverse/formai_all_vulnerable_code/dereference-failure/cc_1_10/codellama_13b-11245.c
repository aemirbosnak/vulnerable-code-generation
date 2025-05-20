//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: introspective
// mailing_list_manager.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Subscriber {
  char name[50];
  char email[50];
};

struct MailingList {
  int num_subscribers;
  struct Subscriber *subscribers;
};

void add_subscriber(struct MailingList *list, struct Subscriber subscriber) {
  list->num_subscribers++;
  list->subscribers = realloc(list->subscribers, list->num_subscribers * sizeof(struct Subscriber));
  list->subscribers[list->num_subscribers - 1] = subscriber;
}

void remove_subscriber(struct MailingList *list, char *name) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    if (strcmp(list->subscribers[i].name, name) == 0) {
      list->num_subscribers--;
      list->subscribers = realloc(list->subscribers, list->num_subscribers * sizeof(struct Subscriber));
      memmove(&list->subscribers[i], &list->subscribers[i + 1], (list->num_subscribers - i) * sizeof(struct Subscriber));
      break;
    }
  }
}

void print_subscribers(struct MailingList *list) {
  int i;
  for (i = 0; i < list->num_subscribers; i++) {
    printf("%s <%s>\n", list->subscribers[i].name, list->subscribers[i].email);
  }
}

int main(void) {
  struct MailingList list = {0};
  struct Subscriber subscriber1 = {"John Doe", "johndoe@example.com"};
  struct Subscriber subscriber2 = {"Jane Doe", "janedoe@example.com"};
  struct Subscriber subscriber3 = {"Jim Doe", "jimdoe@example.com"};

  add_subscriber(&list, subscriber1);
  add_subscriber(&list, subscriber2);
  add_subscriber(&list, subscriber3);

  print_subscribers(&list);

  remove_subscriber(&list, "Jane Doe");

  print_subscribers(&list);

  return 0;
}