//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
  #include <stdlib.h>

  struct Node {
    int data;
    struct Node *next;
  };

  struct Queue {
    struct Node *front;
    struct Node *rear;
  };

  void enqueue(struct Queue *q, int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (q->rear == NULL) {
      q->front = temp;
      q->rear = temp;
    } else {
      q->rear->next = temp;
      q->rear = temp;
    }
  }

  int dequeue(struct Queue *q) {
    if (q->front == NULL) {
      return -1;
    }

    int data = q->front->data;
    struct Node *temp = q->front;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
      q->rear = NULL;
    }

    return data;
  }

  void display(struct Queue *q) {
    struct Node *temp = q->front;

    while (temp != NULL) {
      printf("%d ", temp->data);
      temp = temp->next;
    }

    printf("\n");
  }

  int main() {
    struct Queue q;
    q.front = NULL;
    q.rear = NULL;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    display(&q);

    int data = dequeue(&q);
    printf("Dequeued data: %d\n", data);

    display(&q);

    return 0;
  }