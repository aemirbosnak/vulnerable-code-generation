//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  void *data;
  struct node *next;
};

struct queue {
  struct node *head;
  struct node *tail;
};

void queue_init(struct queue *q) {
  q->head = NULL;
  q->tail = NULL;
}

int queue_is_empty(struct queue *q) {
  return q->head == NULL;
}

void queue_enqueue(struct queue *q, void *data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;

  if (q->tail == NULL) {
    q->head = new_node;
    q->tail = new_node;
  } else {
    q->tail->next = new_node;
    q->tail = new_node;
  }
}

void *queue_dequeue(struct queue *q) {
  if (q->head == NULL) {
    return NULL;
  }

  void *data = q->head->data;
  struct node *old_head = q->head;
  q->head = q->head->next;
  free(old_head);
  return data;
}

void queue_print(struct queue *q) {
  struct node *node = q->head;
  while (node != NULL) {
    printf("%s ", (char *)node->data);
    node = node->next;
  }
  printf("\n");
}

int main() {
  struct queue *q = malloc(sizeof(struct queue));
  queue_init(q);

  queue_enqueue(q, "hello");
  queue_enqueue(q, "world");
  queue_enqueue(q, "goodbye");

  queue_print(q);

  void *data = queue_dequeue(q);
  printf("Dequeued: %s\n", (char *)data);

  queue_print(q);

  return 0;
}