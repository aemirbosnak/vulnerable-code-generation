//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
  #include <stdlib.h>

  typedef struct node {
    int data;
    struct node *next;
  } node_t;

  typedef struct queue {
    node_t *head;
    node_t *tail;
  } queue_t;

  void queue_init(queue_t *q) {
    q->head = NULL;
    q->tail = NULL;
  }

  void queue_enqueue(queue_t *q, int data) {
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;

    if (q->tail == NULL) {
      q->head = node;
      q->tail = node;
    } else {
      q->tail->next = node;
      q->tail = node;
    }
  }

  int queue_dequeue(queue_t *q) {
    if (q->head == NULL) {
      return -1;
    }

    node_t *node = q->head;
    int data = node->data;

    q->head = node->next;
    free(node);

    return data;
  }

  int main(void) {
    queue_t q;
    queue_init(&q);

    queue_enqueue(&q, 1);
    queue_enqueue(&q, 2);
    queue_enqueue(&q, 3);

    printf("dequeued: %d\n", queue_dequeue(&q));
    printf("dequeued: %d\n", queue_dequeue(&q));
    printf("dequeued: %d\n", queue_dequeue(&q));

    return 0;
  }