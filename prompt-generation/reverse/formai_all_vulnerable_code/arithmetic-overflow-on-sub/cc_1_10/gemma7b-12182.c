//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define quantum 2

typedef struct Node {
  struct Node* next;
  int data;
  int time_slot;
  int state;
} Node;

void insert_node(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->time_slot = 0;
  newNode->state = 0;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  head = newNode;
}

void round_robin(Node* head) {
  time_t start = time(NULL);

  while (head) {
    if (head->state == 0) {
      head->state = 1;
      head->time_slot++;

      if (head->time_slot == quantum) {
        head->state = 0;
        head->time_slot = 0;
        printf("Process %d finished.\n", head->data);
      }
    }

    sleep(0.001);
  }

  time_t end = time(NULL);
  printf("Total time: %f seconds\n", end - start);
}

int main() {
  Node* head = NULL;

  insert_node(head, 1);
  insert_node(head, 2);
  insert_node(head, 3);
  insert_node(head, 4);
  insert_node(head, 5);

  round_robin(head);

  return 0;
}