//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Linus Torvalds
// Linus Torvalds style Queue implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
  int data;
  struct node* next;
} node;

typedef struct {
  node* head;
  node* tail;
  int size;
} queue;

void enqueue(queue* q, int data) {
  node* new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  if (q->size == 0) {
    q->head = new_node;
    q->tail = new_node;
  } else {
    q->tail->next = new_node;
    q->tail = new_node;
  }
  q->size++;
}

int dequeue(queue* q) {
  if (q->size == 0) {
    return -1;
  }
  int data = q->head->data;
  node* temp = q->head;
  q->head = q->head->next;
  free(temp);
  q->size--;
  return data;
}

int main() {
  queue q;
  q.head = NULL;
  q.tail = NULL;
  q.size = 0;

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);

  int data = dequeue(&q);
  printf("Dequeued: %d\n", data);

  data = dequeue(&q);
  printf("Dequeued: %d\n", data);

  data = dequeue(&q);
  printf("Dequeued: %d\n", data);

  data = dequeue(&q);
  printf("Dequeued: %d\n", data);

  return 0;
}