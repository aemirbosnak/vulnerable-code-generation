//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
  #include <stdlib.h>

  // Define a struct to represent a node in the queue
  struct node {
      int value;
      struct node* next;
  };

  // Define a struct to represent the queue
  struct queue {
      struct node* head;
      struct node* tail;
  };

  // Initialize a new queue
  struct queue* init_queue() {
      struct queue* q = malloc(sizeof(struct queue));
      q->head = NULL;
      q->tail = NULL;
      return q;
  }

  // Add a new element to the end of the queue
  void enqueue(struct queue* q, int value) {
      struct node* n = malloc(sizeof(struct node));
      n->value = value;
      n->next = NULL;

      if (q->head == NULL) {
          q->head = n;
      } else {
          q->tail->next = n;
      }
      q->tail = n;
  }

  // Remove and return the first element from the queue
  int dequeue(struct queue* q) {
      if (q->head == NULL) {
          return -1;
      }
      struct node* n = q->head;
      int value = n->value;
      q->head = n->next;
      free(n);
      return value;
  }

  // Check if the queue is empty
  int is_empty(struct queue* q) {
      return q->head == NULL;
  }

  // Free all memory associated with the queue
  void free_queue(struct queue* q) {
      while (q->head != NULL) {
          struct node* n = q->head;
          q->head = n->next;
          free(n);
      }
      free(q);
  }

  // Test the queue implementation
  int main() {
      struct queue* q = init_queue();
      enqueue(q, 1);
      enqueue(q, 2);
      enqueue(q, 3);
      printf("Dequeued: %d\n", dequeue(q));
      printf("Dequeued: %d\n", dequeue(q));
      printf("Dequeued: %d\n", dequeue(q));
      free_queue(q);
      return 0;
  }