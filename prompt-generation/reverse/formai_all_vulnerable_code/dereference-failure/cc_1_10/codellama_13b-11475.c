//Code Llama-13B DATASET v1.0 Category: Data structures visualization ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures
typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct queue {
  Node *front;
  Node *rear;
} Queue;

// Functions
void print_queue(Queue *q) {
  Node *curr = q->front;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void enqueue(Queue *q, int data) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (q->rear == NULL) {
    q->front = new_node;
    q->rear = new_node;
  } else {
    q->rear->next = new_node;
    q->rear = new_node;
  }
}

int dequeue(Queue *q) {
  if (q->front == NULL) {
    return -1;
  }

  int data = q->front->data;
  Node *temp = q->front;
  q->front = q->front->next;
  free(temp);

  return data;
}

void peek(Queue *q) {
  if (q->front == NULL) {
    printf("Queue is empty\n");
  } else {
    printf("Front element: %d\n", q->front->data);
  }
}

int main() {
  Queue *q = malloc(sizeof(Queue));
  q->front = NULL;
  q->rear = NULL;

  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);

  print_queue(q);

  peek(q);

  int data = dequeue(q);
  printf("Dequeued element: %d\n", data);

  print_queue(q);

  return 0;
}