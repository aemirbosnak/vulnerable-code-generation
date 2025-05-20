//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000

struct event {
  char name[20];
  char ip_address[16];
  char timestamp[20];
};

struct node {
  struct event e;
  struct node* next;
};

void add_event(struct node** list, struct event e) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->e = e;
  new_node->next = *list;
  *list = new_node;
}

void print_events(struct node* list) {
  printf("=== Intrusion Detection System Events ===\n");
  while (list != NULL) {
    printf("[%s] %s accessed from %s\n", list->e.timestamp, list->e.name, list->e.ip_address);
    list = list->next;
  }
}

int main() {
  struct node* event_list = NULL;

  printf("Welcome to the Intrusion Detection System!\n");

  while (1) {
    struct event e;
    printf("Enter event information: (name ip_address timestamp)\n");
    scanf("%s %s %s", e.name, e.ip_address, e.timestamp);

    add_event(&event_list, e);
    printf("Event added.\n");

    if (rand() % 10 == 0) {
      printf("Intrusion detected! System shutting down.\n");
      print_events(event_list);
      exit(0);
    }
  }

  return 0;
}