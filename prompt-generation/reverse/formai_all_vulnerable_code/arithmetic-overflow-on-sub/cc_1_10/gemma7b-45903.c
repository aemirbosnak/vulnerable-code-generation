//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

void insert(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

void scheduler(Node* head) {
  time_t start = time(NULL);
  srand(start);

  int quantum = rand() % MAX;
  Node* current = head;

  while (current) {
    printf("Process: %d, Time: %d\n", current->data, quantum);
    sleep(quantum);
    quantum = rand() % MAX;
    current = current->next;
  }

  time_t end = time(NULL);
  printf("Total time: %d\n", end - start);
}

int main() {
  Node* head = NULL;
  insert(head, 1);
  insert(head, 2);
  insert(head, 3);
  insert(head, 4);
  insert(head, 5);

  scheduler(head);

  return 0;
}