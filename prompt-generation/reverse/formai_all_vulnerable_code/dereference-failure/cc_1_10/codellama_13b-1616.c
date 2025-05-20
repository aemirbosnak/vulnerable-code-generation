//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
// queue.c
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

typedef struct {
  node_t *head;
  node_t *tail;
} queue_t;

void init_queue(queue_t *q) {
  q->head = NULL;
  q->tail = NULL;
}

void enqueue(queue_t *q, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  if (q->tail == NULL) {
    q->head = new_node;
  } else {
    q->tail->next = new_node;
  }
  q->tail = new_node;
}

int dequeue(queue_t *q) {
  if (q->head == NULL) {
    return -1;
  }

  node_t *old_head = q->head;
  int data = old_head->data;
  q->head = old_head->next;
  free(old_head);
  return data;
}

int is_empty(queue_t *q) {
  return q->head == NULL;
}

int main() {
  queue_t q;
  init_queue(&q);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  enqueue(&q, 4);

  while (!is_empty(&q)) {
    int data = dequeue(&q);
    printf("%d ", data);
  }

  printf("\n");
  return 0;
}