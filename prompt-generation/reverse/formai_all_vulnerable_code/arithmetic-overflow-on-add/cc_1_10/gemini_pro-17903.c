//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
  char *name;
  time_t start;
  time_t end;
  struct node *next;
} node_t;

node_t *head = NULL;

void add_appointment(char *name, time_t start, time_t end) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->name = strdup(name);
  new_node->start = start;
  new_node->end = end;
  new_node->next = head;
  head = new_node;
}

void print_appointments() {
  node_t *current = head;
  while (current != NULL) {
    printf("%s: %s - %s\n", current->name, ctime(&current->start), ctime(&current->end));
    current = current->next;
  }
}

void free_appointments() {
  node_t *current = head;
  while (current != NULL) {
    node_t *next = current->next;
    free(current->name);
    free(current);
    current = next;
  }
}

int main() {
  add_appointment("John Smith", time(NULL), time(NULL) + 3600);
  add_appointment("Jane Doe", time(NULL) + 3600, time(NULL) + 7200);
  add_appointment("Bill Jones", time(NULL) + 7200, time(NULL) + 10800);

  print_appointments();

  free_appointments();

  return 0;
}